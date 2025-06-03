#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include<stdlib.h>
#include<string.h>
#include"utilidades.h"

#define TAM_COLA        30
#define COLA_LLENA      1
#define COLA_VACIA      2

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearCola(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, unsigned tamDato);
int ponerEnCola(tCola* cola, const void* dato, unsigned tamDato);
int sacarDeCola(tCola* cola, void* dato, unsigned tamDato);
int verPrimero(const tCola* cola, void* dato, unsigned tamDato);
void vaciarCola(tCola* cola);

#endif // COLA_H_INCLUDED
