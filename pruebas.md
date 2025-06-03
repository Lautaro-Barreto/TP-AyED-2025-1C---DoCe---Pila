## Pruebas de comportamiento de la IA en dificultad "Difícil"

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre cuando la IA tiene más de 8 puntos| Se espera que la IA priorice cartas que suman puntos | La IA se centra en jugar cartas que la acerquen a los 12 puntos | 

![Prueba1](/imgs/ejiaporganar1.jpg)
![Prueba2](/imgs/ejiaporganar2.jpg)
![Prueba3](/imgs/ejiaporganar3.jpg)
![Prueba4](/imgs/ejiaporganar4.jpg)

## Pruebas de generación de informes

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que ocurre con el informe al finalizar la partida | Se espera que se genere un archivo de texto con la fecha y hora actual, quién jugó cuál carta en cada turno y cuál fue el ganador de la partida | Se obtuvo un archivo de texto con el formato de nombre informe-juego_YYYY-MM-DD-HH-mm.txt |


## Pruebas de Ver Ranking 

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si un nuevo jugador alcanza el primer puesto del ranking | Se espera que la lista esté correctamente ordenada en todos los casos | La salida obtenida fue una lista correctamente ordenada |

![Prueba5](/imgs/ejverrankingantes.jpg)
![Prueba6](/imgs/ejverrankingdespues.jpg)

| Descripción | Salida esperada | Salida obtenida
| --- | --- | --- |
| Se quiere probar qué es lo que pasaría si se quiere consultar el ranking habiendo habido en total cero jugadores | Se espera que el programa no muestre un ranking en respuesta al array vacío devuelto por la API | La salida obtenida fue un mensaje explicando que no hay jugadores cargados en el ranking |

![Prueba7](/imgs/ejverrankingvacio.jpg)
