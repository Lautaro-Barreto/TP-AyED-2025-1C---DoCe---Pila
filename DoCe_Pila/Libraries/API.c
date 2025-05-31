#include"API.h"

int compararRanking(const void*a,const void*b){
    return (*(tRespuesta*)b).cantidadPartidasGanadas - (*(tRespuesta*)a).cantidadPartidasGanadas ;
}

void mostrarRanking(const void*a){
    printf("Nombre del jugador: %s\nCantidad de partidas ganadas: %d\n\n",(*(tRespuesta*)a).nombreJugador,(*(tRespuesta*)a).cantidadPartidasGanadas);
}

// Función que maneja la respuesta de la solicitud HTTP
size_t manejarRespuesta(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *respuesta, *pRes;
    int i = 1, lenPrimCamp, lenSegCamp;
    tRespuesta jugador;
    tLista ranking;

    //printf("\nRespuesta cruda:\n%.*s\n", (int)realsize, (char *)contents);

    if(strcmp((char*)contents,"[]") == 0){
        printf("\nAún no ha habido jugadores. Intenta jugando una partida !\n");
        return realsize;
    }

    respuesta = (char*)malloc((int)realsize);
    if(!respuesta)
        return SIN_MEM;

    memcpy(respuesta,contents,realsize);
    *(respuesta+(int)realsize) = '\0'; //Segun la documentacion de libcurl, contents NO es un null terminated value
    pRes = respuesta;

    ///Obtenemos la longitud de los campos para poder desplazar el puntero a lo largo del buffer
    lenPrimCamp = strlen(PRIM_CAMP_REQ);
    lenSegCamp  = strlen(SEG_CAMP_REQ);

    ///Parsear datos objeto a objeto del array
    crearLista(&ranking);
    printf("\n\nRanking de jugadores:\n\n");
    pRes = strrchr(respuesta,'}'); ///Vamos parseando de adelante para atrás
    while(pRes != NULL){

        *pRes = '\0';
        pRes--;
        sscanf(pRes,"%d",&jugador.cantidadPartidasGanadas);
        pRes-= lenSegCamp;
        *pRes = '\0';
        pRes = strrchr(respuesta,'"');
        pRes++;
        sscanf(pRes,"%[^\"]",jugador.nombreJugador);
        pRes-= lenPrimCamp;
        *pRes = '\0';

        //printf("jugador parseado nro %d: %s %d\n",i,jugador.nombreJugador,jugador.cantidadPartidasGanadas);
        if(insertarOrdenado(&ranking,&jugador,sizeof(tRespuesta),compararRanking,1) == SIN_MEM)
            return realsize;

        i++;
        pRes = strrchr(respuesta,'}'); //Si no hay más }, significa que ya parseamos el último objeto
    }
    mapear(&ranking, mostrarRanking);
    vaciarLista(&ranking);
    return realsize;
}

int obtenerConfigApi(tApiConfig *apiConfig, char* nomArchConfig){

    char buf[100], *pBuf;

    FILE*archConf = fopen(nomArchConfig,"rt");
    if(!archConf)
        return ERR_ARCH;

    fgets(buf,100,archConf);
    pBuf = strrchr(buf,' ');
    sscanf(pBuf+1,"%s",apiConfig->codigoGrupo);
    pBuf--;
    while(*pBuf != ' ')
        pBuf--;
    *pBuf = '\0';
    sscanf(buf,"%s",apiConfig->url);

    fclose(archConf);
    return TODO_OK;
}

int obtenerRankings(){  ///GET

    tApiConfig apiConfig;
    CURL*curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        if(obtenerConfigApi(&apiConfig,ARCHIVO_CONFIG) == TODO_OK){

            ///Agregamos el codigo de grupo a la url para consultar el endpoint pertinente
            strcat(apiConfig.url,"/");
            strcat(apiConfig.url,apiConfig.codigoGrupo);

            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, manejarRespuesta);
            curl_easy_setopt(curl, CURLOPT_URL,apiConfig.url);
            curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
            res =  curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "Fallo la request: %s\n",curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
        }
        else{
            printf("Error al leer el archivo de configuracion de la API."
                   "Restaurando archivo...");
            if(restaurarArchivoConf(ARCHIVO_CONFIG)!=TODO_OK)
                return ERR_ARCH;
        }
    }
    return TODO_OK;
}

int guardarRanking(char* nombreJugador, unsigned vencedor){

    tApiConfig apiConfig;
    CURL*curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    char request[1024] = "";

    curl = curl_easy_init();
    if(curl){
        if(obtenerConfigApi(&apiConfig,ARCHIVO_CONFIG) == TODO_OK){

            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);

            ///Seteamos los headers de la request para que el contenido sea reconocido como JSON
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            ///seteamos la url de la api
            curl_easy_setopt(curl, CURLOPT_URL, apiConfig.url);

            ///le damos a los datos el formato de la request
            darFormatoARequest(request,nombreJugador,apiConfig.codigoGrupo,vencedor);

            ///Hacemos el POST
            curl_easy_setopt(curl,CURLOPT_CUSTOMREQUEST,"POST");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
            res =  curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "Fallo la request: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
        }
        else{
            printf("Error al leer el archivo de configuracion de la API."
                   "Restaurando archivo...");
            if(restaurarArchivoConf(ARCHIVO_CONFIG)!=TODO_OK)
                return ERR_ARCH;
        }

    }
    return TODO_OK;
}  ///POST

char* darFormatoARequest(char *body, char* nombreJugador, char* codigoGrupo, unsigned vencedor){

    //FORMATO (tried and tested): "{\"CodigoGrupo\":\"apilar\",\"jugador\":{\"nombre\":\"Juan\",\"vencedor\":1}}"
    strcat(body,"{\"CodigoGrupo\":\"");
    strcat(body, codigoGrupo);
    strcat(body,"\",\"jugador\":{\"nombre\":\"");
    strcat(body, nombreJugador);
    strcat(body, "\",\"vencedor\":");
    switch(vencedor){
        case 0:
            strcat(body,"0}}");
            break;
        case 1:
            strcat(body,"1}}");
    }
    return body;
}

int restaurarArchivoConf(char *nomArch){

    FILE *archConf = fopen(nomArch,"wt");
    if(!archConf)
        return ERR_ARCH;
    fprintf(archConf,"https://algoritmos-api.azurewebsites.net/api/doce | apilar");
    fclose(archConf);
    return TODO_OK;
}
