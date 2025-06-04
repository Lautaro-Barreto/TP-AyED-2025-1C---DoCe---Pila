# Estructuras de datos empleadas 

## Mazo de cartas

Para tratar con los mazos de cartas del juego (un mazo principal y uno de descarte), se propuso utilizar un híbrido entre lista y pila estática. 
Tenemos una estructura donde conocemos la cantidad de elementos que puede almacenar y de la cual siempre retiramos el último elemento que ingresó, pero que a su vez debe poder ser recorrida para realizar una operación de mezclado. En definitiva, contamos con una lista de 40 elementos de tipo *tCarta* sobre la cual operamos con primitivas tanto de pila (verTope, apilar, desapilar, pilaVacia) como propias de la implementación del mazo (mezclarMazo, cargarMazo). De esta manera, nos permite trabajar con una misma estructura sin necesidad de emplear arrays auxiliares para el mezclado.
La función *mezclarMazo* hace uso del Algoritmo de Fisher-Yates, en el cual se recorre un array intercambiando cada elemento en la posición en la que nos paramos con aquel ubicado en un índice válido generado al azar, hasta que se llega al final del vector. El resultado es un mazo desordenado o, en nuestro caso, mezclado.

## Ranking de jugadores

La funcionalidad **"Ver Ranking"** consulta un endpoint que devuelve, en un array, cuántas partidas ganó cada jugador que se enfrentó a la computadora. Al parsear cada dato presente en la respuesta de la API a una estructura, se los inserta de manera ordenada en una **Lista Simplemente Enlazada**, de manera tal que los jugadores queden ordenados de mayor a menor en función del número de partidas ganadas. Una vez finalizada la lectura de los datos, se mapea la lista (ya ordenada) para mostrar el ranking completo. 

## Historial de turnos

Para almacenar la información de cada turno (quién jugó qué carta y cuántos puntos acumuló) y el resultado final de la partida para su registro en un informe, se utilizó una **Cola Simplemente Enlazada** a la cual se le fueron cargando los datos pertinentes como estructuras de tipo *tTurno*.
De esta manera, al finalizar la partida, los datos quedan ordenados del primero hasta el último y solo hace falta quitarlos de la cola de uno en uno para recuperarlos y guardarlos en el archivo de texto del informe. El último jugador en usar una carta siempre será el ganador, así que no es necesario guardar un parámetro adicional que indique quién ganó la partida, siempre será el nombre contenido en el último nodo de la cola.

# Estrategias de desarrollo del proyecto

El proyecto fue modularizado lo más que se pudo, llegándose a dividir cada parte importante del sistema en su propio archivo por separado, cada uno con sus definiciones de funciones y macro reemplazos pertinentes.  Aquellas definiciones que resultaron comunes para varios archivos fueron agrupadas bajo el nombre de *"utilidades.h"*

Cada parte  del juego fue desarrollada bajo el nombre que la representa, séase, cartas, mazo, API, jugador, o IA. También, se dispone de bibliotecas útiles desarrolladas por nosotros (listaSimple, cola) y por terceros (libcurl).

## Del mazo al código: Las Cartas

Para simplificar el manejo de la información asociada a cada carta (Nombre, efecto a aplicar al rival), se decidió construir una estructura **tCarta**, la cual cuenta con todos los datos necesarios en un solo lugar listos para ser accedidos por las funciones que así lo requieran. 
Para poblar el mazo con las cartas en cuestión, se hace uso de un array de estructuras adicionales llamadas **tCartaConfig**. Las mismas se encargan de almacenar la información que le permite al programa saber cuántas cartas de cada tipo serán ingresadas al mazo. Modificando estos valores y la definición de tamaño del mazo es posible cambiar la disponibilidad de cada carta.
Evaluando cada carta individual, las funciones saben qué valor positivo o negativo aplica al puntaje del jugador rival.

De las tres opciones del menú inicial (Jugar, Ver Ranking, Salir), la opción *Jugar* desencadena una sucesión de dos funciones en particular. La primera de ellas, *jugar()*, representa un punto previo al loop del juego. En esta etapa, el usuario ingresa el nombre por el cual será llamado por el sistema y selecciona el nivel de dificultad de la máquina. El sistema, por su parte, inicializa el mazo de descarte y el principal. A este último lo llena secuencialmente con las cantidades de cartas establecidas por las definiciones de configuración de cartas y luego lo mezcla. 
Estas acciones cargan las estructuras de datos que pasarán a ser utilizadas por la función *partida()*, donde se da el loop principal del juego.

## Dentro de la partida

El bucle del juego se repite hasta que uno de los dos jugadores alcanza la puntuación 12 (que le da nombre al juego propiamente dicho). Dentro del loop, se evalúa a quién corresponde el turno actual (valor que para el primero se decide de manera aleatoria usando la hora actual como semilla) negando las definiciones pertinentes (MAQUINA equivale a 1, mientras que JUGADOR equivale a 0).

El jugador actual debe elegir una carta, y, a continuación, su valor será evaluado por una función que aplica los cambios pertinentes a los puntajes o al turno actual. La carta pasa a formar parte del mazo de descarte, empleándose una primitiva de pila (apilar) aplicada al contexto del juego (ponerEnMazo).

Al finalizar cada turno, se le entrega una carta al jugador correspondiente, haciendo uso de la función *robarCarta* (contextualización de la primitiva *desapilar*) mientras siga habiendo elementos en éste. En caso contrario, las posiciones del mazo de descarte se ven alteradas por una función de mezclado, y pasa a intercambiar lugares con el mazo principal, tantas veces como sea requerido por la partida. 

A su vez, una estructura *tTurno* almacena cada carta jugada, por quién y cuántos puntos le permitió acumular, datos que son puestos en una estructura de datos de tipo cola para ser, al finalizar la partida, desencolados y volcados en orden dentro de un archivo de texto a modo de informe.

Una vez que se llegó al final del juego, los resultados se guardan en el archivo de informe y, a su vez, son enviados a la API para que queden registrados en la nube.

## Man VS Machine

### El Jugador

*acá explico algo sobre cómo está compuesta la estructura tJugador*

### La IA y sus niveles de dificultad

Nuestro oponente, la máquina, es al igual que el jugador humano una estructura de tipo tJugador. No obstante, su comportamiento se encuentra definido por una de las tres opciones de dificultad seleccionadas antes de iniciar la partida. Al seleccionarla, estamos asignándole a la función que evalúa qué carta jugará una función específica de comportamiento. 

- En el más básico de todos, *fácil*, el índice de la carta a jugar por la máquina es un número aleatorio entre 0 y 3.
- explicar medio 
- explicar dificil

## La API

El programa se comunica con distintos endpoints de una misma API subida a la plataforma Microsoft Azure. Mediante esta, se gestionan los rankings de jugadores. La configuración de la misma se levanta desde un archivo de texto que, en caso de no ser encontrado por el programa, será generado nuevamente para su posterior lectura.
Al ser el cuerpo de la solicitud conocido, se optó por desglosar los datos obtenidos en las request de manera manual dentro del código.

En instancias preliminares, se utilizó la herramienta Postman para probar el funcionamiento y las respuestas de la API, mediante solicitudes de tipo GET, POST y DELETE.

Dentro del código:
- GET -> Se envía la request mediante las funciones de la biblioteca libcurl y los datos recibidos en forma de array de objetos de formato JSON son parseados manualmente objeto a objeto hacia una estructura e insertados en orden en una lista.
- POST -> Utilizando un string, se le da el formato de JSON de forma manual, guardando el nombre del jugador y un número que corresponde a si fue o no el ganador.