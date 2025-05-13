#include"pila.h"

/*--------------------------------------------------------
*                       PILA ESTÁTICA
*---------------------------------------------------------*/

void crearPila(tPilaEstatica* pila){
    pila->tope = TAM_PILA;
}

int apilar(tPilaEstatica* pila,const void*dato,unsigned tam){

    if(tam + sizeof(unsigned) > pila->tope)
        return PILA_LLENA;

    pila->tope -= tam;
    memcpy(pila->pila + pila->tope,dato,tam);
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope,&tam,sizeof(unsigned));
    return TODO_OK;
}

void vaciarPila(tPilaEstatica* pila){
    pila->tope = TAM_PILA;
}

int desapilar(tPilaEstatica* pila,void*dato,unsigned tam){

    unsigned tamanioRecup;
    if(pila->tope == TAM_PILA)
        return PILA_VACIA;

    memcpy(&tamanioRecup,pila->pila + pila->tope,sizeof(unsigned));
    pila->tope += sizeof(unsigned);
    memcpy(dato,pila->pila + pila->tope,MINIMO(tam,tamanioRecup));
    pila->tope += tamanioRecup;
    return TODO_OK;
}

int pilaLlena(const tPilaEstatica* pila, unsigned tam){
    return tam+sizeof(tam) > pila->tope ? PILA_LLENA:0;
}

int pilaVacia(const tPilaEstatica* pila){
    return pila->tope == TAM_PILA ? PILA_VACIA:0;
}

int verTope(const tPilaEstatica* pila,void* dato, unsigned tam){

    unsigned tamRecup;

    if(pila->tope == TAM_PILA)
        return PILA_VACIA;

    memcpy(&tamRecup,pila->pila + pila->tope,sizeof(unsigned));
    memcpy(dato,pila->pila + pila->tope + sizeof(unsigned),MINIMO(tam,tamRecup));
    return TODO_OK;
}
