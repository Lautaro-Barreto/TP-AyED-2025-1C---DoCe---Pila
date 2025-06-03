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
int jugarMedio(tJugador*maquina,int*puntHum,int ultCart)
{
    int indMano;

    if( maquina->puntaje>=CERCA_DE_GANAR && (indMano=buscarPor(maquina->mano,esMas,NULL))<TAM_MANO )
        return indMano;
    if( *puntHum>0 && ( (indMano=buscarPor(maquina->mano,esMenos,NULL))<TAM_MANO ||
       ( ultCart<0 && (indMano=buscarPor(maquina->mano,esEspe,NULL))<TAM_MANO ) ) )
        return indMano;
    if( (indMano=buscarPor(maquina->mano,esCartaBuena,NULL))<TAM_MANO )
        return indMano;
    else
        return rand()%TAM_MANO;
}
//int jugarDificil(tJugador*maquina,int*puntHum,int valUltCart)
//{
//    int indMano;
//
//    if( maquina->puntaje>=PUNTAJE_GANADOR &&  )
//}
int buscarPor(tCarta*mano,condicion cond,const void*param)
{
    int i;
    for(i=0;i<TAM_MANO;i++)
    {
        if( cond(mano+i,param) )
            return i;
    }
    return i;
}
int esMas(const tCarta*p,const void*param)
{
    return p->valor>0;
}
int esMenos(const tCarta*p,const void*param)
{
    return p->valor<0;
}
int esEspe(const tCarta*p,const void*param)
{
    return p->codigo==ESPEJO;
}
int esRepTur(const tCarta*p,const void*param)
{
    return p->codigo==REPETIR_TURNO;
}
int esCartaBuena(const tCarta*p,const void*param)
{
    return p->codigo==REPETIR_TURNO || p->valor>0;
}
int noEsEspe(const tCarta*p,const void*param)
{
    return p->codigo!=ESPEJO;
}
int valMayorIgual(const tCarta*p,const void* param)
{
    return p->valor>=*(int*)param;
}
