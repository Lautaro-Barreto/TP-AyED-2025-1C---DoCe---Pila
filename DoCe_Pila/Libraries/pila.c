#include"pila.h"

/*--------------------------------------------------------
*                       PILA ESTÁTICA
*---------------------------------------------------------*/

void crearPila(tPilaEstatica* pila){
    pila->tope = TAM_PILA;
}

int apilar(tPilaEstatica* pila,const void*dato,unsigned tam){

    if(tam+sizeof(unsigned)>pila->tope)
        return 0;

    pila->tope -= tam;
    memcpy(pila->pila + pila->tope,dato,tam);
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope,&tam,sizeof(unsigned));
    return 1;
}

void vaciarPila(tPilaEstatica* pila){
    pila->tope = TAM_PILA;
}

int desapilar(tPilaEstatica* pila,void*dato,unsigned tam){

    unsigned tamanioRecup;
    if(pila->tope == TAM_PILA)
        return 0;

    memcpy(&tamanioRecup,pila->pila + pila->tope,sizeof(unsigned));
    pila->tope += sizeof(unsigned);
    memcpy(dato,pila->pila + pila->tope,MINIMO(tam,tamanioRecup));
    pila->tope += tamanioRecup;
    return 1;
}

int pilaLlena(const tPilaEstatica* pila, unsigned tam){
    return tam+sizeof(tam) > pila->tope ? 1:0;
}

int pilaVacia(const tPilaEstatica* pila){
    return pila->tope == TAM_PILA ? 1:0;
}

int verTope(const tPilaEstatica* pila,void* dato, unsigned tam){

    unsigned tamRecup;

    if(pila->tope == TAM_PILA)
        return 0;

    memcpy(&tamRecup,pila->pila + pila->tope,sizeof(unsigned));
    memcpy(dato,pila->pila + pila->tope + sizeof(unsigned),MINIMO(tam,tamRecup));
    return 1;
}
