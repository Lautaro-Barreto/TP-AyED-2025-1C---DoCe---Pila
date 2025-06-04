# DoCe

## Reglas
- Cada jugador siempre tendra tres cartas en mano.
- Cada jugador debe siempre jugar una carta en su turno.
- El primer jugador en llegar a doce puntos gana la partida.
- Con respecto a las cartas:
  -   Cartas Mas Uno/Dos: suman puntos al jugador que las utiliza.
  -   Cartas Menos Uno/Dos: restan puntos al rival, pero solo hasta que el puntaje del rival llegue a cero.
  -   Cartas Repetir turno: permite al jugador que la utiliza robar una carta y repetir su turno.
  -   Cartas Espejo: te permite anular y devolver el último efecto recibído.
- Puntos Perdidos: indica los puntos que te han sido arrebatados por la ultima carta negativa de tu rival (Menos Uno, Menos Dos o espejo).
  - Si el jugador tiene 0 puntos perdidos, las cartas espejo solo se descartaran.
  - Si tienes 1 o más puntos perdidos, al utilizar una carta espejo se te devolveran dichos puntos y se restaran al rival.
  - Los puntos perdidos de un jugador se reinician a 0 al recuperarlos con una carta espejo.
  - Puedes ver los puntos perdidos de tu oponente, así que piensa cuando jugar -1/-2.

## Cómo jugar
1. Seleccionar la opción "Jugar" (tecla 'A')
2. Ingrese su nombre, puede utilizar caracteres especiales y el máximo es de 25 caracteres.
3. Ingrese la dificultad de la IA (Fácil, medio o difícil).
4. El primero turno se determina de manera aleatoria, se muestran los puntajes junto con los nombre de los respectivos jugadores.
5. Durante el turno del jugador, se mostrarán las cartas que tiene en mano y se pedirá seleccionar una carta.
7. Durante el turno de la IA se mostrará la carta jugada por esta.

## Dificultades
- Fácil: La maquina juega de manera aleatoria
- Medio:
  - No usa una carta de "sacar puntos" si el oponente tiene 0 puntos.
  - Prioriza cartas que suman puntos si está cerca de ganar (cuando tiene 8 o más puntos).
- Difícil:
  - Si el jugador está cerca de ganar, prioriza cartas de "Repetir turno" o de restar puntos.
  - Usa cartas Espejo en caso de recibir una carta negativa del oponente.
  - Prefiere repetir turno solo si tiene más de una carta buena en mano (las cartas de sumar puntos o repetir turno son consideradas "cartas buenas").

## Requisitos
Este proyecto funciona con la biblioteca Curl. Si no cuenta con ella en su computadora, siga estas instrucciones, en caso de ejecutarlo utilizando el IDE Codeblocks:

1. Descargar curl desde: https://curl.se/windows (En caso de no usar Windows, https://curl.se/download.html).
2. Descomprimir el zip y pasar esa carpeta a una ubicación segura.
3. Agregar dentro de PATH (como variable de entorno) la ubicación a la carpeta “bin”.
4. En Codeblocks: Settings > Compiler > Linker Settings: agregar ubicación a “lib\libcurl.dll.a”.
5. En Codeblocks: Settings > Compiler > Search directories > Compiler y Resource compiler: agregar ubicación a “include”.
6. En Codeblocks: Settings > Compiler > Search directories > Linker: agregar ubicación a “lib”.

Alternativamente, y a fines de simplificar la ejecución del juego, el proyecto cuenta con los archivos de la biblioteca ya incorporados dentro de la carpeta *Libraries*. Abriendo el archivo *DoCe_Pila.cbp* con el IDE CodeBlocks, es posible obtener y correr los ejecutables del juego haciendo click sobre la pestaña *build and run*.
