#include "jugador.h"

void ingresarNombre (char*bufferEntra,unsigned tamEntrada)
{
    int pasada=0;
    char*entrada;
    do
    {
        if(pasada)
            printf("\nEl nombre ingresado no es valido");
        pasada=printf("\nIngrese el nombre del jugador (Maximo %d caracteres): ",tamEntrada); //el valor de pasada dejara de ser cero y sabre que entro por lo menos una vez
        fgets(bufferEntra,tamEntrada,stdin);
        entrada=strchr(bufferEntra,'\n');
        if(entrada)
            *entrada='\0';
        else
            while( getchar()!='\n');
    }while(!strlen(bufferEntra));
}

void mostrarJugador(const tJugador* jugador,fMost imprimirCarta)
{
    unsigned i;

    printf("Jugador: %s\nPuntaje:%d\nMano: \n\n", jugador->nombre,jugador->puntaje);
    for(i = 0 ; i < TAM_MANO ; i++)
        {
            printf("%d-",i);
            imprimirCarta(&jugador->mano[i]);
            printf("\n");
        }
}
