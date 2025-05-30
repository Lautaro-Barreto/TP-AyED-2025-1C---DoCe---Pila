#ifndef API_H_INCLUDED
#define API_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#include"curl/include/curl/curl.h"

#define CODIGO_GRUPO "apilar"
#define URL_API_TP   "https://algoritmos-api.azurewebsites.net/api/doce/apilar"

int obtenerRankings(); ///GET
int guardarRanking(char* nombreJugador, unsigned vencedor);  ///POST
int resetearDatos();   ///DELETE
void curlTest();

#endif // API_H_INCLUDED
