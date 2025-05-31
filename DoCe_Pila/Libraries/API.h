#ifndef API_H_INCLUDED
#define API_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#include"curl/include/curl/curl.h"
#include"utilidades.h"

#define ERR_JSON        -5
#define ARCHIVO_CONFIG  "apiconfig.txt"
#define ERR_ARCH        -4
#define CODIGO_GRUPO    "apilar"
#define URL_API_TP      "https://algoritmos-api.azurewebsites.net/api/doce/apilar"

typedef struct{
    char url[100];
    char codigoGrupo[10];
}tApiConfig;

int obtenerConfigApi(tApiConfig *apiConfig, char* nomArchConfig);
int obtenerRankings(); ///GET
int guardarRanking(char* nombreJugador, unsigned vencedor);  ///POST
char* darFormatoARequest(char *body, char* nombreJugador, char* codigoGrupo, unsigned vencedor);

#endif // API_H_INCLUDED
