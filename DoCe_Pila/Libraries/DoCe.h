#ifndef DOCE_H_INCLUDED
#define DOCE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#include"pila.h"
#include"carta.h"
#include"jugador.h"
#include"mazo.h"
#include"API.h"
#include"math.h"
#include"maquina.h"

#define GANO 6
#define SIGUE 7
#define JUGADOR 0
#define MAQUINA 1
#define CONFIRMAR 1
#define CANCELAR 0
#define PUNTAJE_GANADOR 12

/**Por favor, si van a declarar una estructura usen la notación tNombre (ej: tLista, tNodo) así todas se escriben igual**/

int menu();
void jugar();
int ingresarDificultad ();
void partida(unsigned turnoDe, tJugador*jugador,
             tJugador*maquina, tMazo*principal, tMazo*descar,algoritmo jugar);
void repartirCartas(tMazo* mazo, tJugador* jugador, tJugador* ia);
int elegirCarta ();
int evaluarEleccion(tCarta* elegida,int puntajeIA, eEfecto ultCartIA);
void aplicarEfecto(tCarta* elegida,int*puntJug,int valorUltCar,int*puntRival,unsigned*turnoDe);
void mostrarEstPart(tJugador*,tJugador*);

#endif // DOCE_H_INCLUDED
