#include"mazo.h"

void crearMazo(tMazo*p)
{
    p->tope=0;
}
int inicializarMazo(tMazo*p)
{
    const tCartaConfig*config=obtenerConfig();
    int indConfig,indMazo,cantInsert,cantTipos,cant;

    if(MAX_CARTAS!=obtenerCartasTotales())
        return CANT_CARTAS_INVALIDA;
    cantTipos=obtenerCantTipos();
    for(indConfig=indMazo=0; indConfig<cantTipos; indConfig++)
    {
        cant=(config+indConfig)->cantidad;
        for(cantInsert=0; cantInsert<cant; cantInsert++,indMazo++)
        {
            p->mazo[indMazo].valor=(config+indConfig)->valor;//estás tres líneas las podríamos convertir
            p->mazo[indMazo].codigo=(config+indConfig)->codigo;//en una función (insertarEnPosición)
            strcpy(p->mazo[indMazo].descrip,(config+indConfig)->descrip);//para que la función sea más generica
        }
    }
    return OK;
}
void recorrerMazo(tMazo*p)//función de prueba y bien fea.
{
    for(p->tope=0;p->tope<MAX_CARTAS;p->tope++)
    {
        mostrarCarta(&(p->mazo[p->tope]));
        putchar('\n');
    }
}
