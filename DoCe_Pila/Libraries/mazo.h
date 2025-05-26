#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include"carta.h"
#include<string.h>
#include<time.h>
#include"utilidades.h"

#define CANT_CARTAS_INVALIDA -1
#define MAZO_VACIO -2
#define MAZO_LLENO -3

typedef struct
{
    tCarta mazo[MAX_CARTAS];
    int cantCartas;
}tMazo;

void crearMazo(tMazo*p);
int llenarMazo(tMazo*p);
void mezclarMazo(tMazo*p);
void intercambiar(void*a,void*b,size_t tam);//esta función me parece que tiene que ir a para en utilidades.h
int robarCarta(tMazo*p,void*dest,unsigned tam);
int ponerEnMazo(tMazo*p,const void*dato,unsigned tam);
//funciones para pruebas y verificaciones, bien feas
typedef void(fMost)(const void*);
void recorrerMazo(tMazo*);
#endif // MAZO_H_INCLUDED
