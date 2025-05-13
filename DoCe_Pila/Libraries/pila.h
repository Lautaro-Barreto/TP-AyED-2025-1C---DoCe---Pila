#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM_PILA 340
#define PILA_LLENA 1
#define PILA_VACIA 2

#include<string.h>
#include"utilidades.h"

typedef struct{
    char pila[TAM_PILA];
    unsigned tope;
}tPilaEstatica;

///Pila Estática///
void crearPila(tPilaEstatica* pila);
int apilar(tPilaEstatica* pila,const void*dato,unsigned tam);
void vaciarPila(tPilaEstatica* pila);
int desapilar(tPilaEstatica * pila,void*dato,unsigned tam);
int pilaLlena(const tPilaEstatica* pila, unsigned tam);///El tamaño de lo que quiero poner para ver si entra
int pilaVacia(const tPilaEstatica* pila);
int verTope(const tPilaEstatica* pila,void* dato, unsigned tam);///En dato voy a guardar el tope

#endif // PILA_H_INCLUDED
