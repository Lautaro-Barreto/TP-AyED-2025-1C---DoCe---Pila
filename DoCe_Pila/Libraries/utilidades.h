#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED


/*--------------------------------------------------------
     Cosas que se repiten en varias bibliotecas
*---------------------------------------------------------*/

#define TODO_OK      3

#define MINIMO( x , y ) (( x ) <= ( y ) ? ( x ) : ( y ) )

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

#endif // UTILIDADES_H_INCLUDED
