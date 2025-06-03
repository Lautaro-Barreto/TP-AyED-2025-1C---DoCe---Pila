#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED

#include"jugador.h"

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define CANT_DIFICULTADES 3

typedef int(*algoritmo)(tJugador*,int*,int);

int jugarFacil(tJugador*,int*,int);

#endif // MAQUINA_H_INCLUDED
