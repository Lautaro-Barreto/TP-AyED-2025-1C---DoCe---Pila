#include "DoCe.h"

/*
*----------------TO-DO-LIST---------------*

partida()
|
|-> mezclarMazo()
|-> repartirCartas() -> desapilar 1 para cada 1 hasta que ambos tengan 3
|-> loop
     |-> turnoJugador()
     |		|-> mostrarCartas()
     |		|-> usarCarta()
     |		|-> jugador.puntaje == 12 ? Si sí, gana y sale del loop. Si no, sigue.
     |		|-> El MAZO está VACÍO ? Si sí, mezclarDescarteYusarDeMazo(). Si no, sigue normal.
     |		|-> robarDelMazo() -> desapilar de pila
     |
     |-> turnoIA()---> un switch de tres salidas con cada camino segun la dificultad
            |-> (jugar una carta según nivel de dificultad)
          	|-> IA.puntaje == 12? Si sí, gana y sale del loop. Si no, sigue.
          	|-> El MAZO está VACÍO ? Si sí, mezclarDescarteYusarDeMazo(). Si no, sigue normal.
            |-> robarDelMazo() -> desapilar de pila
            |-> vuelve a empezar el loop

verRanking ---> API

guardarResultado ---> API

*/

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

    partida(dificultad, nombreJugador);
}

void partida(unsigned dificultad, const char* nombreJugador){

    char fin = '0';
    tJugador jugador;
    tIA ia;
    tPilaEstatica mazo;
    tPilaEstatica descarte;

    ia.dificultad = dificultad;
    strcpy(jugador.nombre,nombreJugador);
    jugador.puntaje = 0;

    ///Preparativos antes de comenzar el juego
    crearPila(&mazo);
    mezclarMazo(&mazo);
    repartirCartas(&mazo, &jugador, &ia);

    ///loop
    while(fin != '1'){
       turnoJugador(&jugador, &mazo, &descarte);
       //jugador.puntaje == 12 ? Ganó, salir : Seguir
       //turnoIA
       //ia.puntaje == 12 ? Ganó, salir : Seguir
    }
    //guardarResultado()
}

///Solucion prematura para que todo lo demas funcione, quizas luego implemente un algoritmo
///para mezclar tipo el Fisher-Yates (?)
void mezclarMazo(tPilaEstatica* mazo){

    ///A cada pos del vector le corresponde una ID de carta
    unsigned cartas[] = {6, 10, 8, 6, 6, 4};
    unsigned idCarta, cartasApiladas = 0;

    //IDs de cartas:
    //MAS_DOS         0
    //MAS_UNO         1
    //MENOS_UNO       2
    //MENOS_DOS       3
    //REPETIR_TURNO   4
    //ESPEJO          5

    srand(time(0));

    while(cartasApiladas < 40){

        do{
            idCarta = rand() % 6;
        }while(cartas[idCarta] == 0);

        apilar(mazo,&idCarta,sizeof(unsigned));
        cartas[idCarta]--;
        cartasApiladas++;
    }
}

void repartirCartas(tPilaEstatica* mazo, tJugador* jugador, tIA* ia){
    unsigned i;
    for(i = 0 ; i < 3 ; i++){
        desapilar(mazo,&jugador->mano[i],sizeof(unsigned));
        desapilar(mazo,&ia->mano[i],sizeof(unsigned));
    }
}

void mostrarCartasJugador(tJugador jugador){
    unsigned i;
    printf("Mano de %s: \n\n", jugador.nombre);
    for(i = 0 ; i < 3 ; i++){
        switch(jugador.mano[i]){
        case MAS_DOS:
            printf("%u- Mas dos puntos\n",i+1);
            break;
        case MAS_UNO:
            printf("%u- Mas un punto\n",i+1);
            break;
        case MENOS_UNO:
            printf("%u- Menos un punto al oponente\n",i+1);
            break;
        case MENOS_DOS:
            printf("%u- Menos dos puntos al oponente\n",i+1);
            break;
        case REPETIR_TURNO:
            printf("%u- Repetir turno\n",i+1);
            break;
        case ESPEJO:
            printf("%u- Espejo\n",i+1);
            break;
        }
    }
    printf("Puntaje: %d",jugador.puntaje);
}

void turnoJugador(tJugador* jugador, tPilaEstatica* mazo, tPilaEstatica* descarte){
    mostrarCartasJugador(*jugador);
    fflush(stdin);
    getchar();
}
