#include "listaSimple.h"

void crearLista(lista*l)
{
    *l=NULL;
}
void vaciarLista(lista*pl)
{
    estNodo*elim;

    while( *pl!=NULL )
    {
        elim=*pl;
        *pl=elim->sig;
        free(elim->info);
        free(elim);
    }
}
int esListaVacia(const lista*pl)
{
    return *pl==NULL;
}
int esListaLlena(const lista*pl)
{
    return 0;
}
int inserPrimSinDupli(lista*pl,const void*info,size_t tamInfo,comparar comp)
{
    estNodo*nue;
    estNodo**prim=pl;
    int result=1;

    while( *pl!=NULL && (result=comp((*pl)->info,info)) )
        pl=&(*pl)->sig;

    if(result==0)
        return DUPLICADO;

    nue=malloc(sizeof(estNodo));
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
void recorrerIzqDer(const lista*pl,imprimir imp)
{
    while(*pl!=NULL)
    {
        imp((*pl)->info);
        pl=&(*pl)->sig;
    }
}
void mapear(const lista*pl,accion acc,const void*parametro)
{
    while(*pl!=NULL)
    {
        acc( (*pl)->info,parametro );
        pl=&(*pl)->sig;
    }
}
