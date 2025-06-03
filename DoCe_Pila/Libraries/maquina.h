#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED

#include"jugador.h"

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define CANT_DIFICULTADES 3
#define CERCA_DE_GANAR 8

typedef int(*algoritmo)(tJugador*,int*,int);
typedef int(*condicion)(const tCarta*);

algoritmo elegirMaq(int);
int jugarFacil(tJugador*,int*,int);
int jugarMedio(tJugador*,int*,int);
int buscarPor(tCarta*mano,condicion cond);
int esMas(const tCarta*);
int esMenos(const tCarta*);
int esEspe(const tCarta*);
int esRepTur(const tCarta*);
int noEsEspe(const tCarta*);

#endif // MAQUINA_H_INCLUDED
