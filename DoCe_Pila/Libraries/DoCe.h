#ifndef DOCE_H_INCLUDED
#define DOCE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>

#include"pila.h"
#include"cola.h"
#include"listaSimple.h"

///Cantidades que nos importan
#define CANT_CARTAS     3
#define TAM_MAZO        40
#define TAM_NOM         26

///ID de cada carta
#define MAS_DOS         0
#define MAS_UNO         1
#define MENOS_UNO       2
#define MENOS_DOS       3
#define REPETIR_TURNO   4
#define ESPEJO          5

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
    unsigned mano[CANT_CARTAS];
    unsigned puntaje;
}tJugador;

typedef struct{
    unsigned dificultad;
    unsigned mano[CANT_CARTAS];
    unsigned puntaje;
}tIA;

int menu();
void jugar();
void partida(unsigned dificultad, const char* nombreJugador);
void mezclarMazo(tPilaEstatica* mazo);
/// MezclarDescarte(tPilaEstatica* descarte, tPilaEstatica* mazo);
void repartirCartas(tPilaEstatica* mazo, tJugador* jugador, tIA* ia);
void mostrarCartasJugador(tJugador jugador);
void turnoJugador(tJugador* jugador, tPilaEstatica* mazo, tPilaEstatica* descarte);
/// turnoIa(*tIA, tPilaEstatica* mazo, tPilaEstatica* descarte);
/// guardarResultado()
/// verRanking()

#endif // DOCE_H_INCLUDED
