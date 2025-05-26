#include"mazo.h"

void crearMazo(tMazo*p)
{
    p->cantCartas=0;
}
int llenarMazo(tMazo*p)
{
    const tCartaConfig*config=obtenerConfig();
    tCarta carta;
    int indConf,tope,apiladas,cantTipos,copiasDeTipo;//indConf = indice del vector
                                                //con las configuración de las cartas
    if(MAX_CARTAS!=obtenerCartasTotales())
        return CANT_CARTAS_INVALIDA;

    cantTipos=obtenerCantTipos();
    for(indConf=tope=0; indConf<cantTipos; indConf++)//el mazo está vacio, por lo tanto tope=0
    {                   // el tope es tanto la cantidad cartas como la posición donde se insertara
        copiasDeTipo=(config+indConf)->cantidad;
        for(apiladas=0; apiladas<copiasDeTipo; apiladas++,tope++)
        {
            carta.codigo=(config+indConf)->codigo;
            carta.valor=(config+indConf)->valor;
            strncpy(carta.descrip,(config+indConf)->descrip,TAM_DESCRIP);
            ponerEnMazo( p, &carta, sizeof(tCarta));
        }
    }
    p->cantCartas=tope;
    return TODO_OK;
}
void mezclarMazo(tMazo*p)
{
    int indiceRand,indice,tam=sizeof(p->mazo[0]);

    srand(time(NULL));
    for(indice=p->cantCartas-1; indice>=0; indice--)
    {
        indiceRand=rand()%p->cantCartas;
        if(indice!=indiceRand)
            intercambiar(&p->mazo[indice],&p->mazo[indiceRand],tam);
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
    if(p->cantCartas<1)
        return MAZO_VACIO;

    memcpy(dest,&p->mazo[p->cantCartas-1],tam);
    p->cantCartas--;
    return TODO_OK;
}
int ponerEnMazo(tMazo* mazo, const void* carta,unsigned tam)
{
    if(mazo->cantCartas >= MAX_CARTAS)
        return MAZO_LLENO;

    mazo->cantCartas++;
    memcpy(&mazo->mazo[mazo->cantCartas-1],carta,tam);

    return TODO_OK;
}
void recorrerMazo(tMazo*p)//FUNCIÓN PARA PRUEBAS
{
    int ind;
    for(ind=0;ind<p->cantCartas;ind++)
    {
        mostrarCarta(&p->mazo[ind]);
        putchar('\n');
    }
}
