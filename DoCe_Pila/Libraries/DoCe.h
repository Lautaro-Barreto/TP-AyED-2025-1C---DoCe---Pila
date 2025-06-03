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

/*idea:
Que a cada tipo de carta le corresponda un numero (0 1 2 3 4 5)
de esta forma, cuando se evalua el efecto de cada carta se chequea el numero asociado al tipo de carta
También podría servir para hacer la función de mezclar el mazo. Pnesaba que, usando un vector de 6 posiciones
donde cada una representa un contador de cada tipo de carta, podemos elegir aleatoriamente un numero del 0 al 5, restarle 1
al contador que está en dicha posicion del vector y apilar una carta con el numero que le corresponde
*/

/**Por favor, si van a declarar una estructura usen la notación tNombre (ej: tLista, tNodo) así todas se escriben igual**/

int menu();
void jugar();
int ingresarDificultad ();
void partida(unsigned turnoDe, tJugador*jugador,
             tJugador*maquina, tMazo*principal, tMazo*descar,algoritmo jugar);
void repartirCartas(tMazo* mazo, tJugador* jugador, tJugador* ia);
int elegirCarta ();
int evaluarEleccion(tCarta* elegida,int puntajeIA, eEfecto ultCartIA);
void aplicarEfecto(eEfecto carta,int valorCarta,int valorCartaRival,int*puntJug,int*puntRival,unsigned*turnoDe);
/// guardarResultado()
/// verRanking()

#endif // DOCE_H_INCLUDED
