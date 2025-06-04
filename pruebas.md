## Pruebas de comportamiento de la IA en dificultad "Difícil"

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando la IA tiene más de 8 puntos| Se espera que la IA priorice cartas que suman puntos (+1/+2) | La IA se centra en jugar cartas de tipo *sumar* que la acerquen a los 12 puntos | 

![Prueba1](/imgs/ejiaporganar1.jpg)
![Prueba2](/imgs/ejiaporganar2.jpg)
![Prueba3](/imgs/ejiaporganar3.jpg)
![Prueba4](/imgs/ejiaporganar4.jpg)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando el jugador tiene más de 8 puntos| Se espera que la IA priorice cartas que restan puntos (+1/+2) para frenar a su oponente | La IA se centra en jugar cartas de tipo *restar* para alejar al jugador de la victoria | 

![PruebaJugador1](/imgs/ejjugadorporganar1.jpg)
![PruebaJugador2](/imgs/ejjugadorporganar2.jpg)
![PruebaJugador3](/imgs/ejjugadorporganar3.png)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando el jugador juega una carta negativa | Se espera que la IA juegue la carta *espejo* (si cuenta con ella) para devolverle el espejo al jugador | La IA juega la carta espejo que se encuentra en su mano |

![espejo1](/imgs/ejespejo1.jpg)


| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar bajo qué condiciones la IA decide utilizar una carta de *repetir turno* | Se espera que la IA juegue una carta de *repetir turno* cuando en su mano hay más de una carta buena | La IA juega una carta de *repetir turno* e inmediatamente después juega una carta para sumar puntos a sí misma |

![repetirturno](/imgs/ejrepetirturno1.jpg)
![repetirturno2](/imgs/ejrepetirturno2.jpg)

# Pruebas de los efectos de las cartas

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando se juega una carta de tipo *restar* cuando el oponente tiene untala cantidad de puntos que al realizar la resta debería dar negativo | Se espera que los puntos del oponente nunca sean menores a cero | Al restar -2 a 1 o -1/-2 a 0, los puntos no se restan más allá de cero. El sistema muestra un mensaje avisando que la jugada que el jugador piensa hacer no tendrá el efecto que espera | 

![NoBajaDeCero](/imgs//ejunomenosdos.png)
![ejemploDeMensaje](/imgs//ejmsj.png)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando un jugador utiliza una carta de tipo *repetir turno* | Se espera que el programa vuelva a mostrar la mano del jugador, con una nueva carta tomada del mazo para reemplazar la que ya usó | Se muestra otra vez el menú donde se ven las cartas disponibles del jugador. Donde había un *repetir turno*, ahora hay una carta distinta |

![repetirTurnoHumano](/imgs/ejrepetirturnojugador.png)

# Pruebas sobre los mazos

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando se vacía el mazo principal | Se espera que el mazo de descarte sea mezclado y usado como el nuevo mazo principal | Se muestra un mensaje que indica que el mazo principal se vació y que el descarte está siendo utilizado en su lugar | 

![Mensaje](/imgs/mazovacio.png)

## Pruebas de generación de informes

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre con el informe al finalizar la partida | Se espera que se genere un archivo de texto con la fecha y hora actual, quién jugó cuál carta en cada turno y cuál fue el ganador de la partida | Se obtuvo un archivo de texto con el formato de nombre informe-juego_YYYY-MM-DD-HH-mm.txt |

![PruebaInforme](img/ejinformesuccesfullycreated.png)
![Contenido](img/contenidoinforme.png)

## Pruebas respecto al Ranking 

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si un nuevo jugador alcanza el primer puesto del ranking | Se espera que la lista esté correctamente ordenada en todos los casos | La salida obtenida fue una lista correctamente ordenada |

![PruebaVerRankingAntes](/imgs/ejverrankingantes.jpg)
![PruebaVerRankingDespués](/imgs/ejverrankingdespues.jpg)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si se quiere consultar el ranking habiendo habido en total cero jugadores | Se espera que el programa no muestre un ranking en respuesta al array vacío devuelto por la API | La salida obtenida fue un mensaje explicando que no hay jugadores cargados en el ranking |

![PruebaRanking](/imgs/ejverrankingvacio.png)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si se quiere ingresar un nuevo jugador al ranking | Se espera que el programa actualice el ranking luego de la partida para que figure una entrada con el nuevo jugador | La salida obtenida fue el ranking con el nuevo jugador y el resultado de la partida que jugó |

![PruebaIngresar](/imgs/ejagregarantes.png)
![PruebaIngresar2](/imgs/ejagregardespues.png)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si se juega una partida con el nombre de un jugador que ya existe en el ranking | Se espera que el programa actualice el ranking luego de la partida, sumándole una victoria al jugador pertinente en el caso de que haya ganado | La salida obtenida fue el ranking con el puntaje del jugador actualizado |

![PruebaAcumular](/imgs/ejagregarantes.png)