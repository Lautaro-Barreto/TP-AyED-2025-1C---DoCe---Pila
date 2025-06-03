#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED


/*--------------------------------------------------------
     Cosas que se repiten en varias bibliotecas
*---------------------------------------------------------*/

#define TODO_OK 0

#define MINIMO(x,y) ((x)<(y)?(x):(y))
#define SIN_MEM -10

typedef struct sNodo{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

#endif // UTILIDADES_H_INCLUDED
