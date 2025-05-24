#include"mazo.h"

void crearMazo(tMazo*mazo)
{
    mazo->tope = TAM_MAZO;
}

int ponerEnMazo(tMazo* mazo, const tCarta* carta,unsigned tam)
{
    if(mazo->tope == 0)
        return MAZO_LLENO;

    mazo->tope--;
    memcpy(&mazo->mazo[mazo->tope],carta,sizeof(tCarta));

    return TODO_OK;
}

int robarCarta(tMazo*mazo,void*dest,unsigned tam)
{
    if(mazo->tope == TAM_MAZO)
        return MAZO_VACIO;

    memcpy(dest,&mazo->mazo[mazo->tope],tam);
    mazo->tope++;
    return TODO_OK;
}

int llenarMazo(tMazo*mazo)
{
    const tCartaConfig*config;
    int indConf,apiladas,cantTipos,copias;
    tCarta carta;

    if(mazo->tope == 0)
        return MAZO_LLENO;

    config = obtenerConfig();

    if(MAX_CARTAS != obtenerCartasTotales())
        return CANT_CARTAS_INVALIDA;

    cantTipos = obtenerCantTipos();

    for(indConf=0; indConf < cantTipos; indConf++)
    {
        copias = (config+indConf)->cantidad;
        for(apiladas=0; apiladas<copias; apiladas++)
        {
            carta.codigo = (config+indConf)->codigo;
            strcpy(carta.descrip,(config+indConf)->descrip);
            carta.valor = (config+indConf)->valor;
            ponerEnMazo(mazo,&carta,sizeof(tCarta));
        }
    }

    return TODO_OK;
}

void mezclarMazo(tMazo*mazo)
{
    int indAlea, indice, tam = sizeof(tCarta);

    srand(time(NULL));
    for(indice = mazo->tope; indice < TAM_MAZO; indice++)
    {
        indAlea=rand()%MAX_CARTAS;
        if(indice!=indAlea)
            intercambiar(&mazo->mazo[indice],&mazo->mazo[indAlea],tam);
    }
}

void mostrarMazo(tMazo*mazo)
{
    int i;

    for(i = mazo->tope; i < TAM_MAZO ;i++)
    {
        printf("%s\n",mazo->mazo[i].descrip);
    }
}

