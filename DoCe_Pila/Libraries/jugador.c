#include "jugador.h"

void ingresarNombre (char*bufferEntra,unsigned tamEntrada)
{
    int pasada=0;
    char*entrada;
    do
    {
        if(pasada)
            printf("\nEl nombre ingresado no es valido");
        pasada=printf("\nIngrese el nombre del jugador (Maximo %d caracteres): ",tamEntrada-1); //el valor de pasada dejara de ser cero y sabre que entro por lo menos una vez
        fgets(bufferEntra,tamEntrada,stdin);
        entrada=strchr(bufferEntra,'\n');
        if(entrada)
            *entrada='\0';
        else
            while( getchar()!='\n');
    }while(!strlen(bufferEntra));
}

void mostrarMano(const tJugador* jugador,fMost imprimirCarta)
{
    unsigned i;

    printf("\t-Turno de %s-\nTus cartas: \n\n", jugador->nombre);
    for(i = 0 ; i < TAM_MANO ; i++)
        {
            printf("%d-",i);
            imprimirCarta(&jugador->mano[i]);
        }
}
void crearJugador(tJugador*j)
{
    j->puntaje=j->puntPerdidos=0;
}
