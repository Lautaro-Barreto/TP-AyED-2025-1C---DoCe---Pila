#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>

#define TAM_MAZO 40

typedef enum
{
    MAS_DOS,
    MAS_UNO,
    MENOS_UNO,
    MENOS_DOS,
    REPETIR_TURNO,
    ESPEJO
}eEfecto;//La 'e' es por enum para diferenciarlo de las estrcuturas
typedef enum
{
    CANT_MAS_DOS=6,
    CANT_MAS_UNO=10,
    CANT_MENOS_UNO=8,
    CANT_MENOS_DOS=6,
    CANT_REPETIR_TURNO=6,
    CANT_ESPEJO=4,
    TAM_DESCRIP=15 //Este valor no se si dejarlo aca (por nomemclatura)
} eCant;
typedef struct
{
    eEfecto codigo; //Una ID para saber que hace la carta
    char descrip[TAM_DESCRIP]; //Para una posible función mostrarCarta(tCarta*)
    int valor; //Cero cuando la carta no afecte el puntaje
}tCarta;
typedef struct
{
    eEfecto codigo;
    char descrip[TAM_DESCRIP];
    int valor;
    eCant cantidad;
}tCartaConfig;

void mostrarCarta(const void*p);
const tCartaConfig*obtenerConfig();
int obtenerCantTipos();
int obtenerCartasTotales();
#endif // CARTA_H_INCLUDED
