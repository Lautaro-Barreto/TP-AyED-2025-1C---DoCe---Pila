#include <stdio.h>
#include <stdlib.h>

#include"Libraries/DoCe.h"

int main()
{
    char opc = 0;
    srand(time(NULL));

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
