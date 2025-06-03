# Estructuras de datos empleadas 

## Mazo de cartas

Para tratar con los mazos de cartas del juego (un mazo principal y uno de descarte), se propuso utilizar un híbrido entre lista y pila estática. 
Tenemos una estructura donde conocemos la cantidad de elementos que puede almacenar y donde siempre sacamosde esta el último elemento que ingresó, pero que a su vez debe poder ser recorrida para realizar una operación de mezclado. En definitiva, contamos con una lista de 40 elementos de tipo *tCarta* sobre la cual operamos con primitivas tanto de pila (verTope, apilar, desapilar, pilaVacia) como propias de la implementación del mazo (mezclarMazo, cargarMazo). De esta manera, nos permite trabajar con una misma estructura sin necesidad de consultar arrays auxiliares para el mezclado.

## Ranking de jugadores

La funcionalidad **"Ver Ranking"** consulta un endpoint que devuelve, en un array, cuántas partidas ganó cada jugador que se enfrentó a la computadora. Al parsear cada dato presente en la respuesta de la API a una estructura, se los inserta de manera ordenada en una **Lista Simplemente Enlazada**, de manera tal que los jugadores queden ordenados de mayor a menor en función del número de partidas ganadas. Una vez finalizada la lectura de los datos, se mapea la lista (ya ordenada) para mostrar el ranking completo. 

## Historial de turnos

Para almacenar la información de cada turno (quién jugó qué carta y cuántos puntos acumuló) y el resultado final de la partida para su registro en un informe, se utilizó una **Cola Simplemente Enlazada** a la cual se le fueron cargando los datos pertinentes como estructuras de tipo *tTurno*.
De esta manera, al finalizar la partida, los datos quedan ordenados del primero hasta el último y solo hace falta quitarlos de la cola de uno en uno para recuperarlos y guardarlos en el archivo de texto del informe. El último jugador en usar una carta siempre será el ganador, así que no es necesario guardar un parámetro adicional que indique quién ganó la partida, siempre será el nombre contenido en el último nodo de la cola;

