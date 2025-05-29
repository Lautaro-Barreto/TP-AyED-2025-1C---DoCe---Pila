#include "carta.h"

static const tCartaConfig cartasBase[]={//¿esto podría hacerse de otra forma?
    {MAS_DOS,"Mas dos",2,CANT_MAS_DOS},
    {MAS_UNO,"Mas uno",1,CANT_MAS_UNO},
    {MENOS_UNO,"Menos uno",-1,CANT_MENOS_UNO},
    {MENOS_DOS,"Menos dos",-2,CANT_MENOS_DOS},
    {REPETIR_TURNO,"Repetir turno",0,CANT_REPETIR_TURNO},
    {ESPEJO,"Espejo",0,CANT_ESPEJO}
};
const tCartaConfig*obtenerConfig()
{
    return cartasBase;
}
void mostrarCarta(const void*p)
{
    tCarta*carta=(tCarta*)p;
    if(carta)
        printf("%s\n",carta->descrip);
}
int obtenerCantTipos()
{
    return sizeof(cartasBase)/sizeof(tCartaConfig);
}
int obtenerCartasTotales()
{
    int total,cantTipo=sizeof(cartasBase)/sizeof(tCartaConfig),indice;
    for(total=0,indice=0; indice<cantTipo; indice++)
        total+=(cartasBase+indice)->cantidad;
    return total;
}
