#ifndef DOCE_H_INCLUDED
#define DOCE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#include"pila.h"
//#include"cola.h"
#include"listaSimple.h"
#include"carta.h"
#include"mazo.h"

#define GANO     6
#define SIGUE    7

///Cantidades que nos importan
#define TAM_MANO         3
#define TAM_MAZO        40
#define TAM_NOM         26

/*idea:
Que a cada tipo de carta le corresponda un numero (0 1 2 3 4 5)
de esta forma, cuando se evalua el efecto de cada carta se chequea el numero asociado al tipo de carta
Tambi�n podr�a servir para hacer la funci�n de mezclar el mazo. Pnesaba que, usando un vector de 6 posiciones
donde cada una representa un contador de cada tipo de carta, podemos elegir aleatoriamente un numero del 0 al 5, restarle 1
al contador que est� en dicha posicion del vector y apilar una carta con el numero que le corresponde
*/

/**Por favor, si van a declarar una estructura usen la notaci�n tNombre (ej: tLista, tNodo) as� todas se escriben igual**/

typedef struct{
    char nombre[TAM_NOM];
    unsigned mano[TAM_MANO];
    unsigned puntaje;
}tJugador;

typedef struct{
    unsigned dificultad;
    unsigned mano[TAM_MANO];
    unsigned puntaje;
}tIA;

int menu();
void jugar();
void ingresarNombre (char*bufferNombre,unsigned tamBuffer);
int ingresarDificultad ();
void partida(unsigned dificultad, const char* nombreJugador);
void repartirCartas(tPilaEstatica* mazo, tJugador* jugador, tIA* ia);
void mostrarCartasJugador(tJugador jugador);
int turnoJugador(tJugador* jugador, tPilaEstatica* mazo, tPilaEstatica* descarte);
int turnoIa(tIA* ia, tPilaEstatica* mazo, tPilaEstatica* descarte);
/// guardarResultado()
/// verRanking()

#endif // DOCE_H_INCLUDED
