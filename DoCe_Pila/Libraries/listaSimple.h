#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define DUPLICADO 1
#define TODO_OK 0
#define SIN_MEMORIA -1
#define LISTA_VACIA -2
#define LISTA_LLENA -3

typedef struct nodo
{
    void*info;
    size_t tam;
    struct nodo*sig;
}estNodo;

typedef estNodo*lista;
typedef int(*comparar)(const void*,const void*);
typedef void(*imprimir)(const void*);
typedef void(*accion)(void*dato,const void*parametro);

void crearLista(lista*);
void vaciarLista(lista*);
int esListaVacia(const lista*);
int esListaLlena(const lista*);
int inserPrimSinDupli(lista*pl,const void*info,size_t tamInfo,comparar);
void recorrerIzqDer(const lista*pl,imprimir);
void mapear(const lista*pl,accion,const void*parametro);

#endif // LISTASIMPLE_H_INCLUDED
