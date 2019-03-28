# Taller de programación 2: (20% de la nota final)

Se requiere elaborar una versión del legendario juego [SNAKE](http://es.wikipedia.org/wiki/Snake_(videojuego))  (también conocido como NIBBLES), utilizando como base el archivo [snake.py](../../codigo/python3/juegos/snake.py) y la librería [`pygame`](https://www.pygame.org/).

![Caricatura](http://i1.ytimg.com/vi/UmeKHtei0qo/maxresdefault.jpg)

# Forma de presentación
* Individual

# Fecha y hora límite de entrega: 
* Marzo 29 de 2019; enviar a <daalvarez@unal.edu.co>. Sin excepción, por cada **HORA** de retraso en la entrega se rebajará **1.0 unidad** de la nota. 

# Fecha y hora de la sustentación
* Marzo 29 de 2019, a partir de las 7:00 am, de acuerdo con el horario acordado con el profesor.

# Forma de calificación
El programa se calificará por objetivos de la siguiente forma:

## Puntos obligatorios
Los puntos obligatorios no otorgan unidades, solo las quitan, es decir un programa que solo tiene los puntos obligatorios tiene una nota de 0.0):

* La serpiente debe conservar su inercia (no se puede detener su movimiento), la serpiente se mueve horizontal/verticalmente utilizando las flechas o las teclas ASDW (**si no se realiza -5.0 unidades**).

* La serpiente que se mueve en modo automático debe moverse de modo tal que se coma la cápsula más cercana; en caso que su movimiento esté dañado se obtendrán **-5.0 unidades**.

* Debe demostrar durante la sustentación que se sabe manejar el depurador (**si no se realiza -5.0 unidades**). En YouTube encontrarán cientos de tutoriales al respecto. Busquen con las palabras clave  `buscando errores python`, `debugger python` y `depurador python`.
  * Para el SPYDER sugiero, adicionalmente, los siguientes tutoriales:
    - https://docs.spyder-ide.org/debugging.html
    - https://docs.spyder-ide.org/variableexplorer.html
    - https://realpython.com/python-debugging-pdb/

* En el diálogo "Perdiste" debe identificarse claramente que serpiente/jugador perdió los puntos (**si no se realiza -1.0 unidad**).

* El juego debe tener la opción "Persona vs Computador" (**si no se realiza -1.0 unidad**).

* Debe existir en el tablero una cápsula que incrementa la longitud de la serpiente que se come dicha cápsula (**si no se realiza -1.0 unidad**).

* Hacer un START, un PAUSE, un PERDISTE y un FELICITACIONES, COMPLETASTE EL NIVEL (encima del tablero tal y como aparece en el juego original (**si no se realiza -1.0 unidad**).

* En la parte superior del tablero debe haber un panel donde se muestren las vidas, el puntaje, un cronómetro que indique el tiempo de juego y cualquier otra información de relevancia para el juego (**si no se realiza -1.0 unidad**).

## Puntos opcionales
* Al principio del juego, el programa pregunta el nombre de los jugadores y utiliza este nombre para referirse al jugador que ganó o perdió (**0.5 unidades**).
* Implementar un menú previo al juego que permite las siguientes opciones (**0.5 unidades** cada una):
  * Persona sola (maneja con las flechas y con las teclas ASDW o asdw).
  * Persona (flechas) vs Persona (maneja con las teclas ASDW o asdw).
  * Persona (flechas y teclas ASDW o asdw) vs computador.
  
* Incluir en el menú anterior la opción:  
  * Persona vs 2 Serpientes manejadas por el computador (**1.0 unidad**).

* Implementar las siguientes cápsulas de poder (las cuales deben aparecer aleatoriamente en el tablero, en las posiciones libres):
  * Capsula que da una vida extra (**0.5 unidades**).
  * Cápsulas que incrementa la velocidad de la serpiente que se la come (**0.25 unidades**).
  * Cápsulas que reduce la velocidad de la serpiente que se la come (**0.25 unidades**).
  * Cápsula que invierte la serpiente, es decir, la cabeza se vuelve la cola y la cola se vuelve la cabeza (**1.5 unidades**).
  * Etiquetar las cápsulas que alargan con los números 1, 2, 3, ..., 9. Al comer la cápsula número 9  termina el nivel y continua al siguiente. Deben haber al menos 4 niveles de juego (cada tablero es más complejo) y 3 de velocidad (**1.0 unidad**)
  * Cápsula que acorta la serpiente en cinco cuadros, siendo la longitud mínima de un cuadrito (**0.5 unidades**).
  * Cápsula que congela a las otras serpientes por cinco segundos (**1.5 unidades**). Escribir en pantalla el tiempo que dura el efecto de esta cápsula de poder (**0.5 unidades**).
  * Cápsula de poder que se guarda en una bodega y que posteriormente se activa al presionar la tecla "INSERT". Dicha cápsula permitiría a la serpiente atravesar muros durante los 5 segundos siguientes (**1.0 unidad**). Escribir en pantalla el tiempo que dura el efecto de esta cápsula de poder (**0.5 unidades**).

* Pueden estar simultáneamente en el tablero hasta dos cápsulas, ambas de diferente clase. Estas cápsulas sólo pueden aparecer una vez por nivel (**1.0 unidad**).
* Si se come la cápsula debe aparecer en pantalla, cerca al lugar en el que se comió la cápsula, el número de puntos obtenidos: (**1.0 unidad**)
* El jugador solo tiene como tiempo máximo dos minutos para completar el tablero. En el tablero deben aparecer los segundos faltantes (**1.0 unidad**).
* Implementar el juego de modo que funcione con joysticks (**1.0 unidad**).
* Implementación de túneles de modo que la serpiente pase por el borde izquierdo de la pantalla y salga por el derecho y viceversa y que se desplace entre los bordes superior e inferior: (**0.5 unidades**).
* Teclas especiales:
  * Al presionar 'H' o 'h' aparece el manual de instrucciones del juego: (**0.5 unidades**).
  * Implementar el TOP 10 de los mejores jugadores del juego, guardarlo a disco y recuperarlo al iniciar el programa; Al presionar 'T' o 't' se hace una pausa y aparece el top 10 de los mejores jugadores del juego. Obviamente, el programa debe utilizar el nombre real del jugador. (**2.0 unidad**)
  * Implementar una pausa al presionar la tecla espacio. En este caso, detener el cronómetro de juego y reanudarlo una vez se vuelva a presionar la tecla espacio (**0.5 unidades**).
  * Incluirle al juego sonidos: una pista musical al fondo del nivel y efectos especiales cuando la serpiente muere o se come una cápsula (**1.0 unidad**). Cuando se presiona `M` se activa/desactiva la música y los sonidos (**0.5 unidades**).
  * Crear una tecla para la serpiente de cada jugador humano que genere un modo turbo que triplique la velocidad de la serpiente. Dicho modo tendrá una duración máxima de 5 segundos. Y se recargará a una velocidad de 0.1 segundos por cada segundo de juego. Mostrar una barra con un porcentaje que muestre como se carga/descarga dicho modo a medida que se juega (**2.0 unidad**).
* Hacer introducción ANIMADA del juego: (**1.0 unidad**)
* A una entrega que incluya sonidos, imágenes y fuentes especiales en: los menús, el tablero, el  marcador de juego, del top de los mejores jugadores, sonidos, etc., que hagan que la presentación sea muy profesional se le dará **+1.0 unidad** extra. Les recomiendo que descarguen a su celular programas similares al pedido para que encuentren inspiración en la presentación del programa.
* Hacer uno de los siguientes dos puntos:
  * O dibujarle a la serpiente una carita y una colita que se modifiquen de acuerdo con su dirección (**1.0 punto**).
  * O hacer el juego en modo gŕafico utilizando alguno de los "sprites" mostrados en (**5.0 unidades**).:
    * http://www.html5gamedevs.com/topic/25589-general-data-structure-for-phaser-snake-game/
    * http://rembound.com/articles/creating-a-snake-game-tutorial-with-html5
  

# Notas adicionales
* En caso que se detecte que hay copia en alguno de los puntos presentados se tendrá como nota un **0.0** en todo el taller (usted y su compañero).
* Habrá sustentación del programa. La sustentación se hará frente al PC y se pedirá modificar algún punto en particular del programa o explicar que hace un código. Si se hizo el programa, pero no se aprobó la sustentación, se tendrá una nota en el taller de **0.0**. La nota de la sustentación será **APROBADO/NO APROBADO**.
* El programa deberá estar **muy bien comentado**. La falta de comentarios explicativos le rebajará el 50% de la nota en ese punto.
* Si el programa está feo o desordenado en su presentación, se rebajará 50% de la nota en ese punto.
* Si el programa no corre o funciona incorrectamente, se tendrá como nota 0.0 en ese punto.
* Si se utilizan innecesariamente variables globales: se rebajará 50% de la nota para ese programa (esto pasa por ejemplo si la variable global se puede reemplazar por una estática).
* Utilización de nombres de variables sin mucho sentido para quien lo lee (a excepción del programador) y sin comentarios apropiados (**-1.0 punto**).
* Si el programa excede en más del 10% del código las 80 columnas se rebajará el 50% de la nota (se sugiere activar la opción que muestra la columna # 80 en su ambiente de desarrollo).
* Por cada error de ortografía se rebajará 1 décimas de la nota final (para evitar esto se sugiere activar el corrector de ortografía de su ambiente de desarrollo).


# Consejos
* Si quieren aprender en verdad a programar intenten ustedes mismos hacer los ejercicios de forma autónoma (sin ayuda de los compañeros de clase o de alguien más). Por lo tanto **eviten en lo posible los grupos de trabajo**. Se prohíbe cualquier tipo de "colaboración" entre compañeros. Aprender a programar es como aprender a nadar. Uno no aprende a nadar viendo los campeonatos de natación en la TV. Hay que tirarse al agua para en verdad dominar la natación.
* No esperen hasta el último minuto para empezar a trabajar en el proyecto; como ya probablemente se han dado cuenta, el desarrollo de software es una actividad que requiere tiempo. La mejor forma de asegurar un buen trabajo es repasar los conceptos vistos en clase, dar un vistazo general a las diferentes librerías con las que cuenta el lenguaje python.
* Aprendan a manejar el debugger, ya que es una herramienta bastante eficiente para la captura de errores. En YouTube hay cientos de tutoriales de ello.
* En internet se encuentre el código solicitado, sin embargo, no lo copien (fraude), sino que utilícenlo para adquirir ideas de cómo mejorar el suyo.
