#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED

#include"jugador.h"

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define CANT_DIFICULTADES 3
#define CERCA_DE_GANAR 8

typedef int(*algoritmo)(tJugador*,int*,int);
typedef int(*condicion)(const tCarta*,const void*param);

algoritmo elegirMaq(int);
int jugarFacil(tJugador*,int*,int);
int jugarMedio(tJugador*,int*,int);
int jugarDificil(tJugador*,int*,int);
int buscarPor(tCarta*mano,condicion cond,const void*);
int esMas(const tCarta*,const void*);
int esMenos(const tCarta*,const void*);
int esEspe(const tCarta*,const void*);
int esCartaBuena(const tCarta*,const void*);
int esRepTur(const tCarta*,const void*);
int noEsEspe(const tCarta*,const void*);
int valMayorIgual(const tCarta*p,const void* param);

#endif // MAQUINA_H_INCLUDED
