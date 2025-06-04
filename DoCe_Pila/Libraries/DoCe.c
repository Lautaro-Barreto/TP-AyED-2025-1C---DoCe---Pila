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
    while( getchar()!='\n');
    system("cls");
    }while(opc<'A' || opc>'C');

    return opc;
}

void jugar(){
    tJugador humano,maquina;
    tMazo mazoActivo,mazoDesc;
    algoritmo alg;

    crearJugador(&humano);
    crearJugador(&maquina);
    ingresarNombre(humano.nombre,TAM_NOM_JUG);
    strcpy(maquina.nombre,"IA");

    alg=elegirMaq( ingresarDificultad() );

    crearMazo(&mazoActivo);
    crearMazo(&mazoDesc);

    llenarMazo(&mazoActivo);
    mezclarMazo(&mazoActivo);
    repartirCartas(&mazoActivo,&humano,&maquina);

    partida(rand()%2, &humano, &maquina, &mazoActivo, &mazoDesc, alg);
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
        if(dificultad<FACIL || dificultad>CANT_DIFICULTADES)
            puts("Valor invalido, ingrese 1,2 o 3");
    }
    while(dificultad<FACIL || dificultad>CANT_DIFICULTADES);
    return dificultad;
}
int elegirCarta ()
{
    int opc=-1;

    printf("\nElija una carta (0-2)\n");
    do
    {
        fflush(stdin);
        printf("Eleccion:");
        scanf("%d",&opc);
        while( getchar()!='\n' );
        if(opc<0 || opc>TAM_MANO-1)
            printf("Valor invalido, ingrese un valor entre 0-2\n");
    }
    while(opc<0 || opc>TAM_MANO-1);
    return opc;
}

int evaluarEleccion(tCarta* elegida,int puntPerd,int puntajeIA)
{
    int entrada=CONFIRMAR;

    if( elegida->valor<0 && puntajeIA<(-elegida->valor) )
    {
        printf("Seguro que quieres jugar esa carta?\n"
               "El puntaje de tu rival es %d (Si=1 No=0)",puntajeIA);
        entrada=-1;//¿Numeritos magico?
    }

    if( elegida->codigo==ESPEJO && puntPerd==0 )
    {
        printf("Seguro que quieres descargar la carta espejo? Si=1 No=0\n");
        entrada=-1;
    }

    while( entrada!=CONFIRMAR && entrada!=CANCELAR )
    {
        printf("Eleccion: ");
        scanf("%d",&entrada);
        while( getchar()!='\n' );

        if(entrada!=CONFIRMAR && entrada!=CANCELAR)
            printf("Ese valor no es valido\n");
    }

    return entrada;
}

void aplicarEfecto(tJugador* act,int indice,tJugador*rival,unsigned*turnoDe)
{
    tCarta*elegida=&act->mano[indice];

    switch(elegida->codigo)
    {
    case MAS_DOS:
    case MAS_UNO:
        act->puntaje+=elegida->valor;
//        *puntJug+=elegida->valor;
        break;
    case MENOS_UNO:
    case MENOS_DOS:
        rival->puntPerdidos=MINIMO(rival->puntaje,-elegida->valor);
        rival->puntaje-=rival->puntPerdidos;
//            if( (*puntRival+=elegida->valor)<0 )
//                *puntRival=0;
        break;
    case ESPEJO:
        if( act->puntPerdidos>0 )
        {
            act->puntaje+=act->puntPerdidos;
            rival->puntPerdidos=MINIMO(rival->puntaje,act->puntPerdidos);
            rival->puntaje-=rival->puntPerdidos;
            act->puntPerdidos=0;
        }
//        if( valorUltCar<0 )
//        {
//            *puntJug-=valorUltCar;
//            if( (*puntRival+=valorUltCar) < 0 )
//                *puntRival=0;
//        }
        break;
    case REPETIR_TURNO:
        *turnoDe=!*turnoDe;
        break;
    }
}

void partida(unsigned turnoDe,tJugador*humano,
             tJugador*maquina,tMazo*principal,tMazo*descarte,algoritmo selecCarta)
{
    unsigned tamCart=sizeof(tCarta), indice, puntosAntes=0;
    int verificar, humanoGano;
    tMazo*temporal;
    tCola historial;
    tTurno turnoActual;
    tJugador*jugadorAct,*rival;

    crearCola(&historial);
    system("cls");
    mostrarEstPart(humano,maquina);
    while( humano->puntaje<PUNTAJE_GANADOR && maquina->puntaje<PUNTAJE_GANADOR )
    {
        if( turnoDe==JUGADOR )
        {
            jugadorAct=humano;
            rival=maquina;
            do
            {
                mostrarMano(humano,mostrarCarta);
//                printf("\nPuntosPerdidosHum=%d\n",humano->puntPerdidos);
                indice=elegirCarta();
                verificar=evaluarEleccion(&humano->mano[indice], humano->puntPerdidos, maquina->puntaje);
            }while( verificar!=CONFIRMAR );
        }
        else
        {
            jugadorAct=maquina;
            rival=humano;
            indice=selecCarta(maquina,humano->puntaje);
            printf("\n\t-Turno de la Maquina, %s juega un: %s\n\n",
                   maquina->nombre,maquina->mano[indice].descrip);
        }
        puntosAntes = jugadorAct->puntaje;
        aplicarEfecto(jugadorAct,indice,rival,&turnoDe);
        mostrarEstPart(humano,maquina);
        ponerEnMazo(descarte, &jugadorAct->mano[indice], tamCart);

        if( robarCarta(principal, &jugadorAct->mano[indice], tamCart)!= TODO_OK )
        {
            mezclarMazo(descarte);
            temporal=principal;
            principal=descarte;
            descarte=temporal;
            robarCarta(principal, &jugadorAct->mano[indice], tamCart);
        }
        turnoActual.jugador = *jugadorAct;
        turnoActual.esTurnoDe = turnoDe;
        turnoActual.puntosAcumulados = jugadorAct->puntaje - puntosAntes;
        verTopeMazo(descarte,&turnoActual.ultCartaJugada,tamCart);
        ponerEnCola(&historial,&turnoActual,sizeof(tTurno));
        turnoDe=!turnoDe;
    }
    if(humano->puntaje<PUNTAJE_GANADOR){
        humanoGano = 0;
        printf("\nGANADOR: La IA");
    }

    else{
         humanoGano = 1;
         printf("\nGANADOR: %s",humano->nombre);
    }

    if(generarInforme(&historial)!=TODO_OK)
        puts("\nError al generar el informe.\n");
    vaciarCola(&historial);
    guardarRanking(humano->nombre,humanoGano);
}

void repartirCartas(tMazo* mazo, tJugador* jugador, tJugador* ia)
{
    unsigned i,tam=sizeof(jugador->mano[0]);

    for(i = 0 ; i < TAM_MANO ; i++){
        robarCarta(mazo,&jugador->mano[i],tam);
        robarCarta(mazo,&ia->mano[i],tam);
    }
}

void mostrarEstPart(tJugador*hum,tJugador*maq)
{
    int largo=MINIMO(strlen(hum->nombre),strlen(maq->nombre));

    printf("\nPuntaje de %*s:%02d\tPuntos perdidos:%d\nPuntaje de %*s:%02d\tPuntos perdidos:%d\n\n",
           largo,hum->nombre,hum->puntaje,hum->puntPerdidos,
           largo,maq->nombre,maq->puntaje,maq->puntPerdidos);
}

int generarInforme(tCola* historial){

    char nomArch[TAM_NOMARCH] = "informe-juego_", aux[TAM_NOMARCH];
    time_t t = time(0);
    struct tm fechaYHora = *localtime(&t);
    tTurno turno;
    int i = 1;

    ///Le damos el formato de la fecha y hora actual al nombre del archivo
    sprintf(aux,"%d",fechaYHora.tm_year + 1900);
    strcat(nomArch,aux);
    strcat(nomArch,"-"); ///Año
    sprintf(aux,"%d",fechaYHora.tm_mon);
    strcat(nomArch,aux);
    strcat(nomArch,"-"); ///Mes
    sprintf(aux,"%d",fechaYHora.tm_mday);
    strcat(nomArch,aux);
    strcat(nomArch,"-"); //Dia
    sprintf(aux,"%d",fechaYHora.tm_hour);
    strcat(nomArch,aux);
    strcat(nomArch,"-"); //Hora
    sprintf(aux,"%d",fechaYHora.tm_min);
    strcat(nomArch,aux);
    strcat(nomArch,".txt"); //Minuto


    FILE*archInforme = fopen(nomArch,"wt");
    if(!archInforme)
        return ERR_ARCH;

    while(historial->pri){
        sacarDeCola(historial,&turno,sizeof(tTurno));
        fprintf(archInforme,"Turno %d:\n%s jugó \"%s\" y acumuló %d puntos\n\n",i,turno.jugador.nombre,turno.ultCartaJugada.descrip,turno.puntosAcumulados);
        i++;
    }

    fprintf(archInforme,"\nGANADOR: %s\n",turno.jugador.nombre);

    fclose(archInforme);
    return TODO_OK;
}
