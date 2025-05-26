#include "DoCe.h"

/** Si quieren que la mano del jugador y de la ia sean listas de 3 cartas, haganlo (?)*/

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
    while( getchar()!='\n');
    system("cls");
    }while(opc<'A' || opc>'C');

    return opc;
}

void jugar(){
    unsigned dificultad;//¿Acá podríamos poner directamente al tJugador?
    tJugador humano;

    ingresarNombre(humano.nombre,TAM_NOM_JUG);
    dificultad=ingresarDificultad();
    partida(dificultad, humano.nombre);
}

int ingresarDificultad ()
{
    int dificultad=0,descartados;

    puts("\nSeleccione el nivel de dificultad: \n\n"
         "1) Facil\n"
         "2) Medio\n"
         "3) Dificil\n"
         );
    do
    {
        scanf("%d",&dificultad);
        while((descartados=getchar())!='\n');
        if(dificultad<1 || dificultad>3)
            puts("Valor invalido, ingrese 1,2 o 3");
    }
    while(dificultad<1 || dificultad>3);
    return dificultad;
}

void partida(unsigned dificultad, const char* nombreJugador){

//    char fin = '0';
//    tJugador jugador;
//    tIA ia;
//    tPilaEstatica mazo;
//    tPilaEstatica descarte;
//
//    ia.dificultad = dificultad;
//    strcpy(jugador.nombre,nombreJugador);
//    jugador.puntaje = 0;
//
//    ///Preparativos antes de comenzar el juego
//    crearPila(&mazo);
//    mezclarMazo(&mazo);

////Se usa para probar mezclar mazo
//    for(int i=0;i<TAM_MAZO;i++){
//        int aux;
//        desapilar(&mazo,&aux,sizeof(unsigned));
//        printf("%d ",aux);
//    }
//    system("pause");


//    repartirCartas(&mazo, &jugador, &ia);


    ///loop
//    while(fin != '1'){
//       if(turnoJugador(&jugador, &mazo, &descarte) == GANO)
//            fin = '0';
//       else
//        if(turnoIa(&ia,&mazo,&descarte) == GANO)
//            fin = '0';
//    }

    //guardarResultado()
}

void repartirCartas(tMazo* mazo, tJugador* jugador, tJugador* ia)
{
    unsigned i,tam=sizeof(jugador->mano[0]);

    for(i = 0 ; i < TAM_MANO ; i++){
        robarCarta(mazo,&jugador->mano[i],tam);
        robarCarta(mazo,&ia->mano[i],tam);
    }
}

///Completar - Nico
//int turnoJugador(tJugador* jugador, tPilaEstatica* mazo, tPilaEstatica* descarte){
//    mostrarCartasJugador(*jugador);
//
//    fflush(stdin);
//    getchar(); //estas dos lineas eran para ver algo nomas, quitalas cuando hagas esta parte(?)
//
//    //jugador.puntaje == 12 ? Ganó, salir por GANO : salir por SIGUE
//}
//
///Completar - Matías
//int turnoIa(tIA* ia, tPilaEstatica* mazo, tPilaEstatica* descarte){
//}
//
///completar - Federico: guardarResultado() y verRanking() (la parte de conexión con la API)
