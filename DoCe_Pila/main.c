#include <stdio.h>
#include <stdlib.h>

#include"Libraries/DoCe.h"

int main()
{
    tMazo m;
    crearMazo(&m);
    llenarMazo(&m);
    recorrerMazo(&m);
    puts("\nMAZO MEZCLADO");
    mezclarMazo(&m);
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
