#include "maquina.h"

algoritmo elegirMaq(int dificultad)
{
    switch(dificultad)
    {
    case(FACIL):
    case(DIFICIL):
            return jugarFacil;
    case(MEDIO):
            return jugarMedio;
    default:
        return jugarFacil;
    }
}
int jugarFacil(tJugador*maquina,int*p,int param)
{
    return rand()%TAM_MANO;
}
int jugarMedio(tJugador*maquina,int*puntHum,int param)
{
    int indMano;

    if( maquina->puntaje>=CERCA_DE_GANAR && (indMano=buscarPor(maquina->mano,esMas))<TAM_MANO )
        return indMano;
    else
    {
        if( *puntHum>0 && (indMano=buscarPor(maquina->mano,esMenos))<TAM_MANO )
            return indMano;
        if( (indMano=buscarPor(maquina->mano,noEsEspe))<TAM_MANO )
            return indMano;
        return rand()%TAM_MANO;
    }
}
int buscarPor(tCarta*mano,condicion cond)
{
    int i;
    for(i=0;i<TAM_MANO;i++)
    {
        if( cond(mano+i) )
            return i;
    }
    return i;
}
int esMas(const tCarta*p)
{
    return p->valor>0;
}
int esMenos(const tCarta*p)
{
    return p->valor<0;
}
int esEspe(const tCarta*p)
{
    return p->codigo==ESPEJO;
}
int esRepTur(const tCarta*p)
{
    return p->codigo==REPETIR_TURNO;
}
int noEsEspe(const tCarta*p)
{
    return p->codigo!=ESPEJO;
}
