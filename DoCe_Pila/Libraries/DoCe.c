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
    unsigned dificultad;//Si se les ocurren nombre "más significativos", cambienlos sin dudar
    tJugador humano,maquina;
    tMazo mazoActivo,mazoDesc;

    ingresarNombre(humano.nombre,TAM_NOM_JUG);

    dificultad=ingresarDificultad();

    crearMazo(&mazoActivo);
    crearMazo(&mazoDesc);

    llenarMazo(&mazoActivo);
    mezclarMazo(&mazoActivo);
    repartirCartas(&mazoActivo,&humano,&maquina);

    humano.puntaje=maquina.puntaje=0;

    partida(dificultad, rand()%2, &humano, &maquina, &mazoActivo, &mazoDesc);//numerito mágico porque solo son dos jugadores...
}

int ingresarDificultad ()
{
    int dificultad=0;

    puts("\nSeleccione el nivel de dificultad: \n\n"
         "1) Facil\n"
         "2) Medio\n"
         "3) Dificil\n"
         );
    do
    {
        scanf("%d",&dificultad);
        while( getchar()!='\n' );
        if(dificultad<1 || dificultad>3)
            puts("Valor invalido, ingrese 1,2 o 3");
    }
    while(dificultad<1 || dificultad>3);
    return dificultad;
}
int seleccionarCarta ()
{
    int opc=0;

    printf("\nElija una carta\n");
    do
    {
        scanf("%d",&opc);
        while( getchar()!='\n' );
        if(opc<0 || opc>2)//estos numeritos magicos me planteo cambiarlos luego
            printf("Valor invalido, ingrese un valor entre 0-2\n");
    }
    while(opc<0 || opc>2);
    return opc;
}

void partida(unsigned dificultad,unsigned turnoDe,tJugador*jugador,
             tJugador*maquina,tMazo*principal,tMazo*descarte)
{
    unsigned tamCart=sizeof(tCarta), cartJug, cartMaq, *ultInd;
    tMazo*temporal;
    tJugador*jugadorAct;//para facilitar las operaciones con el mazo

    while( jugador->puntaje<PUNTAJE_GANADOR && maquina->puntaje<PUNTAJE_GANADOR )
    {
        if( turnoDe==JUGADOR )
        {
            jugadorAct=jugador;
            cartJug=seleccionarCarta();

            ultInd=&cartJug;
        }
        else
        {
            jugadorAct=maquina;
//            seleccionCartaIA()
            cartMaq=0;//línea temporal
            ultInd=&cartMaq;
        }
//        procesarCarta
        ponerEnMazo(descarte, &jugadorAct->mano[*ultInd], tamCart);
        if( robarCarta(principal, &jugador->mano[*ultInd], tamCart)!=TODO_OK )
        {
            mezclarMazo(descarte);
            temporal=principal;
            principal=descarte;
            descarte=temporal;
            robarCarta(principal, &jugador->mano[*ultInd], tamCart);
        }
        turnoDe=!turnoDe;
    }
}

void repartirCartas(tMazo* mazo, tJugador* jugador, tJugador* ia)
{
    unsigned i,tam=sizeof(jugador->mano[0]);

    for(i = 0 ; i < TAM_MANO ; i++){
        robarCarta(mazo,&jugador->mano[i],tam);
        robarCarta(mazo,&ia->mano[i],tam);
    }
}

///Completar
//int turnoJugador(tJugador* jugador, tPilaEstatica* mazo, tPilaEstatica* descarte){
//    mostrarCartasJugador(*jugador);
//
//    fflush(stdin);
//    getchar(); //estas dos lineas eran para ver algo nomas, quitalas cuando hagas esta parte(?)
//
//    //jugador.puntaje == 12 ? Ganó, salir por GANO : salir por SIGUE
//}
//
///Completar
//int turnoIa(tIA* ia, tPilaEstatica* mazo, tPilaEstatica* descarte){
//}
//
///completar: guardarResultado() y verRanking() (la parte de conexión con la API)
