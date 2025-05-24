#include"utilidades.h"

void intercambiar(void*a,void*b,unsigned tam)
{
    char temp[tam];

    memcpy(temp,a,tam);
    memcpy(a,b,tam);
    memcpy(b,temp,tam);
}
