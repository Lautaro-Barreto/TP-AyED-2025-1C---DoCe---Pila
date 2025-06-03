#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "carta.h"
#include "string.h"

#define TAM_MANO 3
#define TAM_NOM_JUG 26

typedef struct{
    char nombre[TAM_NOM_JUG];
    tCarta mano[TAM_MANO];
    int puntaje;
    unsigned puntPerdidos;
}tJugador;

typedef void(fMost)(const void*);

void ingresarNombre (char*bufferNombre,unsigned tamBuffer);
void mostrarMano(const tJugador* jugador,fMost imprimirCarta);
void crearJugador(tJugador*);

#endif // JUGADOR_H_INCLUDED
