#include "listaSimple.h"

void crearLista(tLista* pl){
    *pl = NULL;
}

int listaVacia(tLista* pl){
    return *pl == NULL ? LISTA_VACIA : 0;
}

int listaLlena(tLista* pl){
    return 0;
}

int insertarAlPrincipio(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado){

    tNodo* nue, **pri = pl;
    int comp = 0;

    while(*pl && (comp=cmp((*pl)->info,dato)!=0) )
        pl = &(*pl)->sig;

    if(!duplicado && *pl && comp == 0)
        return DUPLICADO;

    pl = pri;

    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->info = malloc(tamDato);
    if(!nue->info){
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info,dato,tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;
    *pl = nue;
    return TODO_OK;
}

int insertarAlFinal(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado){

    tNodo* nue;
    int comp = 0;

    while(*pl && (comp=cmp((*pl)->info,dato)!=0) )
        pl = &(*pl)->sig;

    if(!duplicado && *pl && comp == 0)
        return DUPLICADO;

    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->info = malloc(tamDato);
    if(!nue->info){
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info,dato,tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;
    *pl = nue;
    return TODO_OK;
}

int insertarOrdenado(tLista* pl, void* dato, unsigned tamDato, comparar cmp, unsigned duplicado){

    tNodo* nue;
    int comp = -1;

    while(*pl && (comp = cmp((*pl)->info,dato))<0 )
        pl = &(*pl)->sig;

    if(*pl && comp == 0 && !duplicado )
        return DUPLICADO;

    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->info = malloc(tamDato);
    if(!nue->info){
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info,dato,tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}

int eliminarNodo(tLista*pl, void* dato, comparar cmp){

    tNodo* elim;
    int comp;

    while(*pl && (comp=cmp((*pl)->info,dato))!=0)
        pl = &(*pl)->sig;

    if(!*pl)
        return NO_ENCONTRADO;

    elim = *pl;
    *pl = elim->sig;
    free(elim->info);
    free(elim);

    return TODO_OK;
}

void mapear(tLista* pl, accion acc){
    while(*pl){
        acc( (*pl)->info );
        pl = &(*pl)->sig;
    }
}

void vaciarLista(tLista* pl){

    tNodo* elim;
    while(*pl){
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
    *pl = NULL;
}

void ordenarLista(tLista* pl, comparar cmp){

    tNodo** pMenor;
    tNodo* menor;

    while(*pl){
        pMenor = buscarMenor(pl, cmp);
        if(menor != *pl){
            menor = *pMenor;
            *pMenor = menor->sig;
            menor->sig = *pl;
            *pl = menor;
        }
        pl = &(*pl)->sig;
    }
}

tNodo** buscarMenor(tLista*pl, comparar cmp){

    tNodo** menor = pl;
    pl = &(*pl)->sig;
    while(*pl){
        if( cmp((*pl)->info, (*menor)->info) < 0  )
            menor = pl;
        pl = &(*pl)->sig;
    }
    return menor;
}
