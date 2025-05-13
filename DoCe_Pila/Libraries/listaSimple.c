#include "listaSimple.h"

/*--------------------------------------------------------
*                 LISTA SIMPLEMENTE ENLAZADA
*---------------------------------------------------------*/

void crearLista(tLista*pl)
{
    *pl=NULL;
}
void vaciarLista(tLista*pl)
{
    tNodo*elim;

    while( *pl!=NULL )
    {
        elim=*pl;
        *pl= elim->sig;
        free(elim->info);
        free(elim);
    }
}
int listaVacia(const tLista*pl)
{
    return *pl==NULL;
}
int listaLlena(const tLista*pl)
{
    return 0;
}
int inserPrimSinDupli(tLista*pl,const void*info,size_t tamInfo,comparar comp)
{
    tNodo*nue;
    tNodo**prim=pl;
    int result=1;

    while( *pl!=NULL && (result=comp((*pl)->info,info)) )
        pl=&(*pl)->sig;

    if(result==0)
        return DUPLICADO;

    nue=malloc(sizeof(tNodo));
    if( nue==NULL || (nue->info=malloc(tamInfo))==NULL )
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info,info,tamInfo);
    nue->sig=*prim;
    *prim=nue;
    nue->tam=tamInfo;
    return TODO_OK;
}
void recorrerIzqDer(const tLista*pl,imprimir imp)
{
    while(*pl!=NULL)
    {
        imp((*pl)->info);
        pl=&(*pl)->sig;
    }
}
void mapear(const tLista*pl, accion acc)
{
    while(*pl!=NULL)
    {
        acc((*pl)->info);
        pl=&(*pl)->sig;
    }
}
