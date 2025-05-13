#include <stdio.h>
#include <stdlib.h>

#include"Libraries/DoCe.h"

int main()
{
    char opc = 0;

    while(opc != 'C'){
        opc = menu();

        switch(opc){
        case 'A':
            puts("Elegiste JUGAR");
            ///jugar();
            break;
        case 'B':
            puts("Elegiste VER RANKING");
            ///verRanking();
            break;
        case 'C':
            puts("Elegiste SALIR");
            break;
        }
    }
    return 0;
}
