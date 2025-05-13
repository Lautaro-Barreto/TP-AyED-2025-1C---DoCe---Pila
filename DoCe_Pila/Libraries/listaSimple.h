#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include"utilidades.h"

#define DUPLICADO 1
#define SIN_MEMORIA -1
#define LISTA_VACIA -2
#define LISTA_LLENA -3

typedef tNodo*tLista;
typedef int(*comparar)(const void*,const void*);
typedef void(*accion)(const void*);
typedef void(*imprimir)(const void*);

void crearLista(tLista*);
void vaciarLista(tLista*);
int listaVacia(const tLista*);
int listaLlena(const tLista*);
int inserPrimSinDupli(tLista*pl,const void*info,size_t tamInfo,comparar);
void recorrerIzqDer(const tLista*pl,imprimir);
void mapear(const tLista* pl, accion acc);

#endif // LISTASIMPLE_H_INCLUDED
