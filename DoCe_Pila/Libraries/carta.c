#include "carta.h"

static const tCartaConfig valoresBase[]={//¿esto podría hacerse de otra forma?
    {MAS_UNO,"Mas uno",1,CANT_MAS_UNO},
    {MAS_DOS,"Mas dos",2,CANT_MAS_DOS},
    {MENOS_DOS,"Menos dos",-2,CANT_MENOS_DOS},
    {MENOS_UNO,"Menos uno",-1,CANT_MENOS_UNO},
    {REPETIR_TURNO,"Repetir turno",0,CANT_REPETIR_TURNO},
    {ESPEJO,"Espejo",0,CANT_ESPEJO}
};
const tCartaConfig*obtenerConfig()
{
    return valoresBase;
}
void mostrarCarta(const void*p)
{
    tCarta*carta=(tCarta*)p;
    if(carta)
        printf("%s",carta->descrip);
}
int obtenerCantTipos()
{
    return sizeof(valoresBase)/sizeof(tCartaConfig);
}
int obtenerCartasTotales()
{
    int total,cantTipo=sizeof(valoresBase)/sizeof(tCartaConfig),indice;
    for(total=0,indice=0; indice<cantTipo; indice++)
        total+=(valoresBase+indice)->cantidad;
    return total;
}
