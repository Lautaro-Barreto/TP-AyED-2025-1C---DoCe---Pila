#ifndef API_H_INCLUDED
#define API_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#include"curl/include/curl/curl.h"
#include"utilidades.h"
#include"listaSimple.h"

#define ARCHIVO_CONFIG  "apiconfig.txt"
#define ERR_ARCH        -4
#define CODIGO_GRUPO    "apilar"
#define URL_API_TP      "https://algoritmos-api.azurewebsites.net/api/doce/apilar"
#define TAM_NOM         26
#define PRIM_CAMP_REQ   ",{\"nombreJugador\":\""
#define SEG_CAMP_REQ    "\",\"cantidadPartidasGanadas\":"

typedef struct{
    char url[100];
    char codigoGrupo[10];
}tApiConfig;

typedef struct{
    char nombreJugador[TAM_NOM];
    int cantidadPartidasGanadas;
}tRespuesta;

int compararRanking(const void*a,const void*b);
void mostrarRanking(const void*a);
size_t manejarRespuesta(void *contents, size_t size, size_t nmemb, void *userp);
int obtenerConfigApi(tApiConfig *apiConfig, char* nomArchConfig);
int obtenerRankings(); ///GET
int guardarRanking(char* nombreJugador, unsigned vencedor);  ///POST
char* darFormatoARequest(char *body, char* nombreJugador, char* codigoGrupo, unsigned vencedor);
int restaurarArchivoConf(char *nomArch);

#endif // API_H_INCLUDED
