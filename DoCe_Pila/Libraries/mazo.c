#include"mazo.h"

void crearMazo(tMazo*p)
{
    p->tope=0;
}
int llenarMazo(tMazo*p)
{
    const tCartaConfig*config=obtenerConfig();
    int indConf,tope,apiladas,plantillas,copias;

    if(MAX_CARTAS!=obtenerCartasTotales())
        return CANT_CARTAS_INVALIDA;
    plantillas=obtenerCantTipos();
    for(indConf=tope=0; indConf<plantillas; indConf++)
    {
        copias=(config+indConf)->cantidad;
        for(apiladas=0; apiladas<copias; apiladas++,tope++)
        {
            p->mazo[tope]=(config+indConf)->codigo;
        }
    }
    return OK;
}
void mezclarMazo(tMazo*p)
{
    int indAlea,indice,tam=sizeof(p->mazo[0]);

    srand(time(NULL));
    for(indice=p->tope; indice>=0; indice--)
    {
        indAlea=rand()%MAX_CARTAS;
        if(indice!=indAlea)
            intercambiar(&p->mazo[indice],&p->mazo[indAlea],tam);
    }
}
void intercambiar(void*a,void*b,size_t tam)
{
    char temp[tam];

    memcpy(temp,a,tam);
    memcpy(a,b,tam);
    memcpy(b,temp,tam);
}
int robarCarta(tMazo*p,void*dest,unsigned tam)
{
    if(p->tope<0)
        return MAZO_VACIO;
    memcpy(dest,&p->mazo[p->tope],tam);
    p->tope--;
    return OK;
}
void recorrerMazo(tMazo*p)//funci�n de prueba y bien fea.
{
    for(p->tope=0;p->tope<MAX_CARTAS;p->tope++)
    {
        printf("%d\n",p->mazo[p->tope]);
    }
}
