# Taller 1, Parte 2: 20 ejercicios
* No convertir los números a cadenas para poderlos descomponer.
* No utilizar la librerías `numpy`, `scipy` o similares que provean las funciones que se supone ustedes deben implementar, a menos que se diga lo contrario.
* Cuando se pregunta por ejemplo un número entero de tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -2, -1, 0, 1, 2, ..., 998 y 999.
* Los números primos son los números naturales 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
* La serie de Fibonacci está dada por: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
* Tener en cuenta que muchos de los ejercicios solicitan cálculos sobre los números enteros; no sobre los números naturales; por lo tanto es necesario tener en cuenta los números enteros negativos, cuando sea del caso.
* Se dice que 3, 4, 5 y 6 son los números enteros comprendidos entre el 2 y el 7.
* No utilizar las funciones/métodos `min()`, `max()`, `sort()`, `sorted()` o similares provistas por Python.

## Del libro de Trejos

### Capítulo 9: vectores (3 ejercicios)
* 23: Leer 10 números enteros, almacenarlos en un vector y determinar si existe al menos un número repetido. Utilizar para tal fin el método `count()`.

* 38: Leer 10 números enteros, almacenarlos en un vector y determinar si la semisuma entre el valor mayor y el valor menor es un número primo.

* 48: Leer 10 números enteros, almacenarlos en un vector y determinar en qué posición se encuentra el número primo con mayor cantidad de dígitos pares. Utilizar el método `index()` de listas.

### Capítulo 10: Matrices (5 ejercicios)
*NOTA 1:* No utilizar el método `count()` de listas.

*NOTA 2:* Cuando se reporten posiciones dentro de una matriz, considere como si esta se encontrara dentro de una hoja de cálculo. Por ejemplo, si se tiene una matriz de 4x6, las filas se numerarían 1 a 4 y las columnas de A a F.

*NOTA 3:* En cada ejercicio se deben imprimir de forma "bonita" cada matriz una vez entrados los datos, utilizando las funcionalidades de impresión asociadas a la función `print()` que se encuentran en las diapositivas **9**. Por forma "bonita" me refiero que los números deben estar perfectamente alineados por sus unidades y la impresión debe ser agradable a la vista.

* 13: Leer una matriz 5x3 entera y determinar en qué columna está el mayor número que comienza con el dígito 4. Tenga en cuenta que el número 412378 comienza con el dígito 4. 

* 28: Leer una matriz 4x6 entera y determinar en qué posiciones se encuentran los números cuyo segundo dígito sea el 5. Tenga en cuenta que el segundo dígito del número 59352242 es el 9.

* 38: Leer dos matrices 4x6 enteras y determinar si el mayor número primo de una matriz aparece dos o más veces en la otra matriz. Reportar el número de repeticiones y las posiciones donde se encuentra dicho número repetido.

* 43: Leer dos matrices 5x5 enteras y determinar si el promedio entero de los números pares de una matriz es igual al promedio de los números pares de la otra matriz. Reportar dichos promedios.

* 48: Leer dos matrices 5x5 enteras y determinar si el promedio de los mayores elementos que pertenecen a la serie de Fibonacci de cada fila de una matriz es igual al promedio de los mayores elementos que pertenecen a la serie de Fibonacci de cada fila de la otra matriz. Reportar dichos promedios.

## Del libro de Oviedo

### Capítulo 6: Estructuras adicionales (2 ejercicios)
* 103:  Hacer un programa con el siguiente menú:
```  
  Menú principal
  ==============
  A. Entrada de datos
  B. Mostrar los datos
  C. Número de chilenos con estatura mayor a 160 cm.
  D. Número de colombianos con estatura en el intervalo [150 cm, 170 cm].
  E. Total de sudamericanos.
  F. Total de mexicanos menores de 30 años
  G. Total de colombianos menores de 40 años con estatura menor a 160 cm.

  Entre su opción: 
```  
La opción A permite preguntar el registro de información de personas. De cada persona se suministró la siguiente información:
* Estatura en centímetros.
* Nacionalidad (1: Colombiana, 2: Mexicana, 3: Chilena).
* Edad.

Las opciones B. a las G. deben funcionar según lo solicitado. Utilizar para la solución de este problema diccionarios y la estructura `if-elseif-else`.

* 121: Una estación climática proporciona un par de temperaturas diarias (máxima, mínima - no es posible que alguna o ambas temperaturas sean 0 grados). La pareja fin de temperaturas es 0, 0. Elabore un algoritmo para determinar el número de días, cuyas temperaturas se han proporcionado, las medidas máxima y mínima, el promedio de las temperaturas mínimas, el promedio de las temperaturas máximas, el número de errores (temperaturas de 0 grados) y el porcentaje que representan.

### Capítulo 8: vectores (7 ejercicios)
* 151: Hacer un algoritmo que forme una lista de números del que no se sabe su tamaño. El programa pregunta por números hasta que se ingrese la palabra *FIN*. Calcule el promedio de los elementos y forme dos nuevos vectores, uno con los elementos menores o iguales al promedio y otro con los superiores. Imprima los dos nuevos vectores.

* 152: Elaborar un algoritmo que lea dos vectores de igual tamaño y forme un tercer vector mediante el producto de los elementos de los dos vectores, tomados en orden inverso, es decir, productos del primer elemento del primer vector con el último del segundo; del segundo del primer vector con el penúltimo del segundo vector; hasta llegar
al último del primer vector con el primero del segundo vector. Imprimir el vector formado.

* 157: Elaborar un algoritmo que forme dos vectores. El primero contiene los M códigos de los estudiantes que perdieron CALCULO y el segundo los N códigos de los estudiantes que perdieron HUMANIDADES. Partiendo de los dos vectores formar uno nuevo con los códigos de los estudiantes que perdieron ambas materias.

* 164: Dados dos vectores A y B de N y M elementos respectivamente, elaborar un algoritmo que encuentre la unión, la intersección y las diferencias de conjuntos (es decir, A\B y B\A). Para recordar los conceptos anteriores, se recomienda este [enlace](https://edu.gcfglobal.org/es/los-conjuntos/operaciones-entre-conjuntos/1/). Elabore dicho programa inicialmente sin utilizar las funcionalidades de conjuntos que ofrece Python y a continuación resolverlo utilizando dichas funcionalidades.

* 167: Haga un programa que lea un conjunto N de números reales (x,y) que tienen la tendencia de una línea recta. Elaborar un algoritmo que utilice tres
funciones para obtener los parámetros m y b de la ecuación de la recta y = mx + b. Las fórmulas para calcular m y b se encuentran en el siguiente [enlace sobre mínimos cuadrados](https://miprofe.com/minimos-cuadrados/). Resolver a continuación dicho problema utilizando las funcionalidades que tiene `numpy`. Adicionalmente graficar con `matplotlib` los puntos y la línea calculada.

* 171: Escribir un algoritmo que dado un vector y su tamaño, elimine sus elementos repetidos, dejando un elemento en cada caso. No utilizar las funcionalidades de conjuntos que ofrece Python, ni el método `unique()` de `numpy`.

* 176: Elaborar un algoritmo que utilice un menú de entrada de datos. El algoritmo debe tener en cuenta dos vectores relacionados que almacenen los códigos de los N artículos que se venden en un almacén y la existencia (número de, unidades existentes) de cada uno de los artículos, así:
```
Código Existencia
  101     30
  200     40
```  
Del artículo 101 hay 30 unidades en existencia; del artículo 200, hay 40 unidades y así sucesivamente. Por cada proveedor o cliente que llega al almacén se genera un registro con los siguientes datos:
* Tipo de transacción [1 para proveedor (recibo); 2 para cliente (venta)].
* Código del artículo transado.
* Número de unidades transadas (recibidas o vendidas).

Se requiere calcular lo siguiente para cada transacción:
* Si es recibo, se suma a las existencias actuales de este artículo el número de unidades
transadas.
* Si es venta, se resta a las unidades en existencia de ese artículo las unidades vendidas. 

Al final se deben mostrar los códigos de los artículos y las existencias de cada uno de ellos, es decir, el vector de códigos y de existencias ya actualizado. 

Verifique que en ningún momento la cantidad vendida sea mayor que la cantidad en existencia.

* 182: Elaborar un algoritmo que lea una lista de números enteros positivos entre 0 y 100 y ejecute las siguientes operaciones:
  * Mostrar los números de la lista en orden creciente.
  * Calcular e imprimir la mediana.
  * Calcular e imprimir la moda.
  * Imprimir tres listas: una con los números menores que 30, otra con los números mayores que 70 y otra con los números entre 30 y 70.

* 201: Sin utilizar el método de listas`sort()` o la función `sorted()`, haga un programa que lea una matriz; luego pregunte que columna desea ordenar y ordene las filas de dicha matriz de acuerdo al orden ascendente de los elementos de la columna seleccionada.

* 202: Hacer un programa que pregunte las dimensiones MxN de una matriz. Adicionalmente ingrese un vector de números con un tamaño menor o igual a M*N. Haga un programa que imprima los elementos de dicho vector ordenados y escritos en forma de espiral en la matriz de tamaño MxN. Dicho espiral deberá empezar en la esquina superior izquierda de la matriz y se debe imprimir en sentido antihorario.