#include"API.h"

// Función que maneja la respuesta de la solicitud HTTP
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
size_t realsize = size * nmemb;
printf("%.*s", (int)realsize, (char *)contents);
return realsize;
}

int obtenerConfigApi(tApiConfig *apiConfig, char* nomArchConfig){

    char buf[100], *pBuf;

    FILE*fp = fopen(nomArchConfig,"rt");
    if(!fp)
        return ERR_ARCH;

    fgets(buf,100,fp);
    pBuf = strrchr(buf,' ');
    sscanf(pBuf+1,"%s",apiConfig->codigoGrupo);
    pBuf--;
    while(*pBuf != ' ')
        pBuf--;
    *pBuf = '\0';
    sscanf(buf,"%s",apiConfig->url);

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
            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);
            curl_easy_setopt(curl, CURLOPT_URL,apiConfig.url);
            curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
            res =  curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
        }
    }
    return TODO_OK;
}

int guardarRanking(char* nombreJugador, unsigned vencedor){

    tApiConfig apiConfig;
    CURL*curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    char linea[1024];
    FILE*fp = fopen("request.txt","rt"); ///test
    if(!fp)
        return ERR_ARCH;

    fgets(linea,100,fp);


    curl = curl_easy_init();
    if(curl){
        if(obtenerConfigApi(&apiConfig,ARCHIVO_CONFIG) == TODO_OK){

            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);

            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_setopt(curl, CURLOPT_URL, "https://algoritmos-api.azurewebsites.net/api/doce");

            curl_easy_setopt(curl,CURLOPT_CUSTOMREQUEST,"POST");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"CodigoGrupo\":\"apilar\",\"jugador\":{\"nombre\":\"Juan\",\"vencedor\":1}}");
            res =  curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
        }

    }
    return TODO_OK;
}  ///POST

/*
{
"CodigoGrupo": "apilar",
"jugador":
{
"nombre":"Juan",
"vencedor":0
}
}
*/
//"{\"CodigoGrupo\": \"apilar\",\"jugador\":{\"nombre\":\"Juan\",\"vencedor\":0}}"
