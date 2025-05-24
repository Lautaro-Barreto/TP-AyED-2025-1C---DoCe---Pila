#ifndef DOCE_H_INCLUDED
#define DOCE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#include"carta.h"
#include"mazo.h"

#define GANO     6
#define SIGUE    7

#define TAM_MANO         3
#define TAM_NOM         26

/*idea:
Que a cada tipo de carta le corresponda un numero (0 1 2 3 4 5)
de esta forma, cuando se evalua el efecto de cada carta se chequea el numero asociado al tipo de carta
También podría servir para hacer la función de mezclar el mazo. Pnesaba que, usando un vector de 6 posiciones
donde cada una representa un contador de cada tipo de carta, podemos elegir aleatoriamente un numero del 0 al 5, restarle 1
al contador que está en dicha posicion del vector y apilar una carta con el numero que le corresponde
*/

/**Por favor, si van a declarar una estructura usen la notación tNombre (ej: tLista, tNodo) así todas se escriben igual**/

typedef struct{
    char nombre[TAM_NOM];
    tCarta mano[TAM_MANO];
    unsigned puntaje;
}tJugador;

typedef struct{
    unsigned dificultad;
    tCarta mano[TAM_MANO];
    unsigned puntaje;
}tIA;

int menu();
void jugar();
void ingresarNombre (char*bufferNombre,unsigned tamBuffer);
int ingresarDificultad ();
void partida(unsigned dificultad, const char* nombreJugador);
void repartirCartas(tMazo* mazo, tJugador* jugador, tIA* ia);
void mostrarCartasJugador(tJugador jugador);
int turnoJugador(tJugador* jugador, tMazo* mazo, tMazo* descarte);
int turnoIa(tIA* ia, tMazo* mazo, tMazo* descarte);
/// guardarResultado()
/// verRanking()

#endif // DOCE_H_INCLUDED
