# DoCe

## Reglas
- Cada jugador siempre tendra tres cartas en mano.
- Cada jugador debe siempre jugar una carta en su turno.
- El primer jugador en llegar a doce puntos gana la partida.
- Con respecto a las cartas:
  -   Cartas Mas Uno/Dos: suman puntos al jugador que las utiliza.
  -   Cartas Menos Uno/Dos: restan puntos al rival, pero solo hasta que el puntaje del rival llegue a cero.
  -   Cartas Repetir turno: permite al jugador que la utiliza robar una carta y repetir su turno.
  -   Cartas Espejo: si se juegan tras recibir un carta Menos, se suman al puntaje del lanzador la cantidad de puntos de la carta Menos y también se restan al puntaje del rival.

## Cómo jugar
1. Seleccionar la opción "Jugar" (tecla 'A')
2. Ingrese su nombre, puede utilizar caracteres especiales y el máximo es de 25 caracteres).
3. Ingrese la dificultad de la IA (Fácil, medio o difícil).
4. El primero turno se determina de manera aleatoria, se muestran los puntajes junto con los nombre de los respectivos jugadores.
5. Durante el turno del jugador, se mostrar las cartas que tiene en mano y se pedira seleccionar una carta.
7. Durante el turno de la IA se mostrara la carta jugada por esta.

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
Este proyecto funciona con curl, si no lo tiene, seguir estas instrucciones, en caso de ejecutarlo utilizando el IDE Codeblocks:

1. Descargar curl desde: https://curl.se/windows (En caso de no usar Windows, https://curl.se/download.html).
2. Descomprimir el zip y pasar esa carpeta a una ubicación segura.
3. Agregar dentro de PATH (como variable de entorno) la ubicación a la carpeta “bin”.
4. En Codeblocks: Settings > Compiler > Linker Settings: agregar ubicación a “lib\libcurl.dll.a”.
5. En Codeblocks: Settings > Compiler > Search directories > Compiler y Resource compiler: agregar ubicación a “include”.
6. En Codeblocks: Settings > Compiler > Search directories > Linker: agregar ubicación a “lib”.
