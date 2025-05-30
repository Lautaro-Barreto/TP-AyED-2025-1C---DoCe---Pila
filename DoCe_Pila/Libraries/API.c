#include"API.h"

int obtenerRankings(){
} ///GET
int guardarRanking(char* nombreJugador, unsigned vencedor){
}  ///POST
int resetearDatos(){
}   ///DELETE
void curlTest(){
    CURL*curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);
        curl_easy_setopt(curl, CURLOPT_URL,"https://example.com");
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
        res =  curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
}
