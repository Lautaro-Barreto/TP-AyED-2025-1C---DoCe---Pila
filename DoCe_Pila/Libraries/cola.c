#include"cola.h"

void crearCola(tCola* cola){
    cola->pri = NULL;
}

int colaVacia(const tCola* cola){
    return cola->pri == NULL;
}

int colaLlena(const tCola* cola, unsigned tamDato){
    return 0;
}

int ponerEnCola(tCola* cola, const void* dato, unsigned tamDato){

    tNodo* nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo)
        return SIN_MEM;

    nuevo->info = malloc(tamDato);
    if(!nuevo->info){
        free(nuevo);
        return SIN_MEM;
    }

    memcpy(nuevo->info,dato,tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = NULL;

    if(cola->pri == NULL)
        cola->pri = nuevo;
    else
        cola->ult->sig = nuevo;

    cola->ult = nuevo;
    return TODO_OK;
}

int sacarDeCola(tCola* cola, void* dato, unsigned tamDato){

    tNodo* elim = cola->pri;

    if(cola->pri == NULL)
        return COLA_VACIA;

    memcpy(dato, cola->pri->info, MINIMO(tamDato,cola->pri->tamInfo));
    cola->pri = cola->pri->sig;
    free(elim->info);
    free(elim);
    return TODO_OK;
}

int verPrimero(const tCola* cola, void* dato, unsigned tamDato){

    if(cola->pri == NULL)
        return COLA_VACIA;
    memcpy(dato, cola->pri->info, MINIMO(tamDato,cola->pri->tamInfo));
    return TODO_OK;
}

void vaciarCola(tCola* cola){

    tNodo* elim;
    while(cola->pri){
        elim = cola->pri;
        cola->pri = elim->sig;
        free(elim->info);
        free(elim);
    }
}


