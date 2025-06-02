
 /* -----------------------------------------------------------
   |               LISTA SIMPLEMENTE ENLAZADA                  |
    -----------------------------------------------------------    */


#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"utilidades.h"

#define NO_ENCONTRADO   2
#define LISTA_VACIA     3
#define DUPLICADO       5

typedef struct sNodo{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;
typedef void (*accion)(const void*);
typedef int (*comparar)(const void*,const void*);

///Primitivas
void crearLista(tLista* pl);
int listaVacia(tLista* pl);
int listaLlena(tLista* pl);
int insertarAlPrincipio(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado);
int insertarAlFinal(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado);
int insertarOrdenado(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado);
int eliminarNodo(tLista*pl, void* dato, comparar cmp);
void mapear(tLista* pl, accion acc);
void vaciarLista(tLista* pl);
void ordenarLista(tLista* pl, comparar cmp);
tNodo** buscarMenor(tLista*pl, comparar cmp);

#endif // LISTASIMPLE_H_INCLUDED
