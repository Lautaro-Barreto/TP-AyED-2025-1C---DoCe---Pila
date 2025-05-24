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
    char nombreJugador[TAM_NOM];

    ingresarNombre(nombreJugador,TAM_NOM);
    dificultad=ingresarDificultad();
    partida(dificultad, nombreJugador);
}

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
