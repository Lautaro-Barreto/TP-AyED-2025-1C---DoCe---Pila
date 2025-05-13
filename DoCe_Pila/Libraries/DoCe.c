#include "DoCe.h"

int menu(){

    char opc;

    do{
    printf("DoCe\n\n"
           "[A] Jugar\n"
           "[B] Ver ranking\n"
           "[C] Salir\n\n"
           "Seleccione una opcion: ");
    fflush(stdin);
    opc = getchar();
    opc = toupper(opc);
    system("cls");
    }while(opc<'A' || opc>'C');

    return opc;
}

void jugar(){

    unsigned dificultad;
    char nombreJugador[26];

    printf("\nIngrese el nombre del jugador: ");
    scanf("%s",nombreJugador);
    puts("\nSeleccione el nivel de dificultad contra la maquina: \n\n"
         "1) Facil\n"
         "2) Medio\n"
         "3) Dificil\n"
         );

    do{
    scanf("%d",&dificultad);
    }while(dificultad<1 || dificultad>3);

    //partida(dificultad,nombreJugador);
}

