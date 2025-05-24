#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include"carta.h"
#include"utilidades.h"
#include<string.h>
#include<time.h>

#define CANT_CARTAS_INVALIDA -1
#define MAZO_VACIO           -2
#define MAZO_LLENO           -3
#define TAM_MAZO              40

typedef struct
{
    tCarta mazo[MAX_CARTAS];
    int tope;
}tMazo;

void crearMazo(tMazo*mazo);
int ponerEnMazo(tMazo* mazo,const tCarta* carta,unsigned tam);
int robarCarta(tMazo*p,void*dest,unsigned tam);
int llenarMazo(tMazo*mazo);
void mezclarMazo(tMazo*mazo);

//funciones para pruebas y verificaciones, bien feas
typedef void(fMost)(const void*);
void mostrarMazo(tMazo*);

#endif // MAZO_H_INCLUDED
