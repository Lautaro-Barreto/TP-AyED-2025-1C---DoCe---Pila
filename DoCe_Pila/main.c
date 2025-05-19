#include <stdio.h>
#include <stdlib.h>

#include"Libraries/DoCe.h"

int main()
{
    tMazo m;
    crearMazo(&m);
    inicializarMazo(&m);
    recorrerMazo(&m);
    mezclarMazo(&m);
    puts("\nMazo mezclado\n");
    recorrerMazo(&m);
    char opc = 0;

    while(opc != 'C'){
        opc = menu();

        switch(opc){
        case 'A':
            puts("Elegiste JUGAR");
            jugar();
            break;
        case 'B':
            puts("Elegiste VER RANKING");
            ///verRanking();
            break;
        case 'C':
            puts("¡ Gracias por jugar !");
            break;
        }
    }
    return 0;
}
