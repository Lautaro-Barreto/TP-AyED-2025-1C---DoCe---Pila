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
    unsigned dificultad;//Con esta variable determinamos que IA juega (Facil/medio/dificil) o eso tengo pensado
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

    partida(rand()%2, &humano, &maquina, &mazoActivo, &mazoDesc);//tenemos que agregar a la IA
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
int elegirCarta ()
{
    int opc=0;

    printf("\nElija una carta: ");
    do
    {
        fflush(stdin);
        scanf("%d",&opc);
        while( getchar()!='\n' );
        if(opc<0 || opc>TAM_MANO-1)
            printf("Valor invalido, ingrese un valor entre 0-2\n");
    }
    while(opc<0 || opc>2);
    return opc;
}
int evaluarEleccion(tCarta* elegida,int puntajeIA, eEfecto ultCartIA)//avisa al jugador que su jugada
{                                                                            //puede no tener el efecto deseado
    int entrada=CONFIRMAR;

    if( (elegida->codigo==MENOS_DOS || elegida->codigo==MENOS_UNO) && puntajeIA<abs(elegida->valor) )
    {
        printf("Seguro que quieres jugar esa carta?\n"
               "El puntaje de tu rival es %d (Si=1 No=0)",puntajeIA);
        entrada=-1;//¿Numeritos magico?
    }

    if( elegida->codigo==ESPEJO && (ultCartIA!=MENOS_DOS || ultCartIA!=MENOS_UNO) )
    {
        printf("Seguro que quieres descargar la carta espejo? Si=1 No=0\n");
        entrada=-1;
    }

    while( entrada!=CONFIRMAR && entrada!=CANCELAR )
    {
        scanf("%d",&entrada);
        while( getchar()!='\n' );

        if(entrada!=CONFIRMAR && entrada!=CANCELAR)
            printf("Ese valor no es valido\n");
    }

    return entrada;
}
void aplicarEfecto(eEfecto carta,int valorCarta,int valorCartaRival,int*puntJug,int*puntRival,unsigned*turnoDe)
{//¿por qué no usaste un swithc? Porque pensaba en la posibilidad
    if( valorCarta>0 )//de que puedan agregarse cartas +n/-n. Pero si quieren cambiarlo haganlo
        *puntJug+=valorCarta;
    if( valorCarta<0 && (*puntRival=+valorCarta)<0 )
        *puntRival=0;
    if( carta==REPETIR_TURNO )
        *turnoDe=!*turnoDe;
    if( valorCartaRival<0 )
    {
        *puntJug=-valorCartaRival;
        *puntRival=+valorCartaRival;
    }
}
void partida(unsigned turnoDe,tJugador*humano,
             tJugador*maquina,tMazo*principal,tMazo*descarte)
{
    unsigned tamCart=sizeof(tCarta), indice;
    int verificar;
    tMazo*temporal;
    eEfecto ultDescar=REPETIR_TURNO;
    int ultValDesc=0;
    tJugador*jugadorAct,*rival;//para facilitar las operaciones con el mazo

    while( humano->puntaje<PUNTAJE_GANADOR && maquina->puntaje<PUNTAJE_GANADOR )
    {
        if( turnoDe==JUGADOR )
        {
            jugadorAct=humano;
            rival=maquina;
            do
            {
                mostrarJugador(humano,mostrarCarta);
                indice=elegirCarta();
                verificar=evaluarEleccion(&humano->mano[indice], maquina->puntaje,
                                ultDescar);
            }while( verificar!=CONFIRMAR );
        }
        else
        {
            jugadorAct=maquina;
            rival=humano;
//            seleccionCartaIA()
            indice=0;
        }
        aplicarEfecto(jugadorAct->mano[indice].codigo,jugadorAct->mano[indice].valor,
                      ultValDesc,&jugadorAct->puntaje,&rival->puntaje,&turnoDe);
        ponerEnMazo(descarte, &jugadorAct->mano[indice], tamCart);
        ultDescar=jugadorAct->mano[indice].codigo;
        ultValDesc=jugadorAct->mano[indice].valor;

        if( robarCarta(principal, &jugadorAct->mano[indice], tamCart)!=TODO_OK )
        {
            mezclarMazo(descarte);
            temporal=principal;
            principal=descarte;
            descarte=temporal;
            robarCarta(principal, &jugadorAct->mano[indice], tamCart);
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
//int turnoIa(tIA* ia, tPilaEstatica* mazo, tPilaEstatica* descarte){
//}
//
///completar: guardarResultado() y verRanking() (la parte de conexión con la API)
