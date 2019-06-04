# Taller 1, Parte 2: 17 ejercicios

* No convertir los números a cadenas para poderlos descomponer.
* No utilizar la librerías `numpy`, `scipy` o similares que provean las funciones que se supone ustedes deben implementar, a menos que se diga lo contrario.
* Cuando se pregunta por ejemplo un número entero de tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -101, -100, 100, 101, ..., 998 y 999.
* Cuando se pregunta por ejemplo un número entero de máximo tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -2, -1, 0, 1, 2, ..., 998 y 999.
* Los números primos son los números naturales 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
* La serie de Fibonacci está dada por: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
* Tener en cuenta que muchos de los ejercicios solicitan cálculos sobre los números enteros; no sobre los números naturales; por lo tanto es necesario tener en cuenta los números enteros negativos, cuando sea del caso.
* Se dice que 3, 4, 5 y 6 son los números enteros comprendidos entre el 3 y el 6.
* No utilizar las funciones/métodos `min()`, `max()`, `sort()`, `sorted()` o similares provistas por Python.

## Listas
*NOTA 1:* No utilizar el método `count()` de listas, a menos que se diga lo contrario.

*NOTA 2:* Cuando se reporten posiciones dentro de una matriz, considere como si esta se encontrara dentro de una hoja de cálculo. Por ejemplo, si se tiene una matriz de 4x6, las filas se numerarían 1 a 4 y las columnas de A a F. Asuma que máximo se tendrán 26 columnas, que comprenden las letras de la A a la Z sin contar la Ñ.

*NOTA 3:* En cada ejercicio se deben imprimir de forma "bonita" cada matriz una vez entrados los datos, utilizando las funcionalidades de impresión asociadas a la función `print()` que se encuentran en las diapositivas [09_-_Entrada_y_salida_en_Python_3.pdf](../../diapositivas/python3/09_-_Entrada_y_salida_en_Python_3.pdf). Por forma "bonita" me refiero que los números deben estar perfectamente alineados por sus unidades y la impresión debe ser agradable a la vista.

*NOTA 4:* Cuando no se especifique el tipo de número a leer asuma que se deben leer números enteros.

### `01.py`
Lea una lista de números enteros y enumere cuantos elementos se repiten exactamente dos veces. Utilizar para tal fin el método `count()` de listas.

### `02.py`

Sin utilizar las funcionalidades de conjuntos de python, lea dos matrices de números enteros A y B, las cuales tienen el mismo tamaño, y determine los elementos que:
   * son comunes a A y B.
   * están en A pero no están en B (esto se escribe en matemáticas como A\B); en este caso, imprima unas matrices que identifiquen los elementos solicitados; por ejemplo, dadas las matrices:
```
A =
   19    2    2   13    3
    7   17   14   19    5
   19   12   17   13    7
    8   12    2    6   13
```
y
```
B =
    3    1    8    3   20
    9    9   17    8    9
   14    8    5   20   18
   12    7   14   18   13
```
el programa debe imprimir en este segundo caso:
```
A\B =
   19    2    2    *    *
    *    *    *   19    *
   19    *    *    *    *
    *    *    2    6    *
```
Repita el mismo ejercicio utilizando las funcionalidades de conjuntos de python.

### `03.py`
Lea una lista de números ya ordenados de forma ascendente y verifique que dicha lista está ordenada. Luego, lea un número e insértelo en la lista en la posición que le corresponde a dicho número.

### `04.py`
Lea una lista de números enteros y determine cual es el segundo elemento mayor de dicha lista. No utilice ningún tipo de algoritmo de ordenamiento para realizar este ejercicio. Por ejemplo, en la lista `[11, 22, 3, 4, 22]`, el segundo número mayor sería el 11; de otro lado, en la lista `[1, 1, 1, 1, 1]` no existe un segundo elemento mayor.

### `05.py`
Lea dos matrices A y B. Determine la suma de cada una de las filas de la matriz A. Determine si alguna de dichas sumas tiene un valor igual a la multiplicación de los elementos de alguna de las columnas de la matriz B. Imprima el número de las filas de A y de las columnas B que cumplen dicha igualdad. Imprima también el valor de la suma referida.

### `06.py`
Lea una matriz e imprima el vector que aparece cuando la matriz se desenreda en forma de espiral que gira en el sentido horario a partir de la esquina inferior derecha. Por ejemplo, dada la matriz, 
```
   59   99   95   12   88
   63   32   49    4   73
   40   28   62   78    6
   45   63   51   85   26
```
el vector solicitado es el `[26, 85, 51, 63, 45, 40, 63, 59, 99, 95, 12, 88, 73, 6, 78, 62, 28, 32, 49, 4]`.

### `07.py`
Lea una matriz cuadrada A, obtenga su [matriz triangular superior](https://es.wikipedia.org/wiki/Matriz_triangular) asociada U y determine qué fila de U contiene la mayor cantidad de unos. La función debe funcionar de forma similar al comando [numpy.triu](https://docs.scipy.org/doc/numpy/reference/generated/numpy.triu.html) para `k=0`.

### `08.py`
Lea una matriz y determine cual es el número que más se repite en ella. Identifique las posiciones en las cuales se encuentra dicho número. Para tal fin utilice el método `index()` de listas.

### `09.py`
Lea una lista e identifique la primera sublista más larga dentro de dicha lista que se encuentra ordenada ascendentemente. Por ejemplo en la lista `[5, 6, 5, 1, 2, 6, 9, 2, 4, 1, 3, 4, 5]` la mayor sublista ordenada es la `[1, 2, 6, 9]`.

### `10.py`
Haga un programa que lea una matriz y la rote 90 grados en sentido antihorario. Imprima la matriz resultante. Por ejemplo, dada la matriz
```
    62    42    70    66    10
    35    10     4    92    94
    33    37     5   100    19
    79    44    72    53    91
```
la matriz solicitada es la:
```
    10    94    19    91
    66    92   100    53
    70     4     5    72
    42    10    37    44
    62    35    33    79
```
Repita el mismo ejercicio utilizando el módulo `numpy`.

### `11.py` (tiene una probabilidad dos veces más alta de salir)
Haga un programa que lea n parejas de coordenadas (x_i, y_i) y calcule el correspondiente [polinomio de Lagrange](https://en.wikipedia.org/wiki/Lagrange_polynomial) que pasa por dichos puntos. Grafique dicho polinomio y los puntos leídos utilizando el módulo `matplotlib`. Investigue que funciones de interpolación tiene python en sus módulos `numpy` y `scipy` y utilice el comando `legend()` de `matplotlib` para comparar gráficamente las diferentes interpolaciones con dichos puntos. ¿Cuál de todos esos algoritmos, cree usted, que provee la mejor interpolación de los datos? Aprenda a utilizar dichas funciones leyendo la documentación.


## Funciones

### `12.py`
Haga un programa que lea dos cadenas de texto y determine cual es la subcadena más larga común a ambas cadenas de texto.

### `13.py`
Cree una función que haga **exactamente** lo mismo que el [método `list.index(x[, start[, end]])`](https://docs.python.org/3/tutorial/datastructures.html?highlight=index#more-on-lists). La función incluso debe fallar igual que la función original, debe mostrar una ayuda similar, pero en español, y debe implementar los parámetros opcionales `start` y `end`. ¿Qué pasa por ejemplo cuando le pasa parámetros negativos?

### `14.py`
Haga un programa que contenga una función que tome como argumento un número entero y lo convierta a una cadena de texto. No puede para ello utilizar la función `str()` o similar de python para convertir dicho número a cadena.

### `15.py`
Lea una cadena de texto que contenga paréntesis, corchetes y llaves. Verifique que los paréntesis estén perfectamente balanceados. Por ejemplo, en la cadena `[(xyz)ee]{rr}ww{ff[(123)()](abc)}` los paréntesis, corchetes y llaves están bien balanceados, pero en la cadena `[aa(123]6)` no lo están. PISTA: para ello se podría emplear el concepto de pilas visto en clase.

### `16.py`
Cree un programa que mediante una función recursiva invierta una cadena de texto entrada por el usuario.

### `17.py` (tiene una probabilidad tres veces más alta de salir)
Cree una función que retorne listas con las coordenadas (x_i, y_i) de los nodos del polígono mostrado teniendo como base las variables dimensiones de la figura:

<img src="https://www.engineeringtoolbox.com/docs/documents/1328/geometric_sections_nonsymmetrical_shape-Model.png" width="500">

dichas coordenadas deben estar especificadas en sentido antihorario. Uno de los parámetros de la figura son las coordenadas (x0,y0) del origen de coordenadas.

Adicionalmente, implemente funciones que calculen:
* el perímetro
* el área A
* la posición del centro de gravedad: (Cx, Cy)
* los primeros momentos de área: Qx, Qy
* los segundos momentos de área (o inercia): Ix, Iy, Ixy

de un polígono; para tal fin utilice las ecuaciones especificadas en los siguientes enlaces:
* Hally, David (1987). [Calculation of the Moments of Polygons](https://apps.dtic.mil/dtic/tr/fulltext/u2/a183444.pdf). Canadian National Defense. Technical Memorandum 87/209.
* https://en.wikipedia.org/wiki/Polygon#Area
* https://en.wikipedia.org/wiki/Polygon#Centroid
* https://en.wikipedia.org/wiki/Second_moment_of_area#Any_polygon

Haga un programa que le pregunte al usuario las dimensiones asociadas a la figura anterior y las coordenadas (x0,y0) correpondientes a la esquina inferior izquierda de la figura; todas esas dimensiones estarán especificadas en centímetros. Finalmente, grafíque el polígono utilizando `matplotlib`. Ubique en ella la posición del centro de gravedad, los ejes y las medidas mostradas en la figura (junto con las correspondientes flechitas). Imprima en la misma figura el perímetro, área, las coordenadas del centro de gravedad y los momentos de área estimados con respecto a las coordenadas (x0,y0) y con respecto al centro de gravedad.

Si lo desea, para el cálculo anterior puede utilizar el módulo `numpy`.
