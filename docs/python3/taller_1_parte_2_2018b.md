# Taller 1, Parte 2: 20 ejercicios
* No convertir los números a cadenas para poderlos descomponer.
* No utilizar la librerías *numpy*, *scipy* o similares que provean las funciones que se supone ustedes deben implementar.
* Cuando se pregunta por ejemplo un número entero de tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -2, -1, 0, 1, 2, ..., 998 y 999.
* Los números primos son los números naturales 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
* La serie de Fibonacci está dada por: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
* Tener en cuenta que muchos de los ejercicios solicitan cálculos sobre los números enteros; no sobre los números naturales; por lo tanto es necesario tener en cuenta los números enteros negativos, cuando sea del caso.
* Se dice que 3, 4, 5 y 6 son los números enteros comprendidos entre el 2 y el 7.
* No utilizar las funciones/métodos `min()`, `max()`, `sort()`, `sorted()` o similares provistas por Python.

## Del libro de Trejos

### Capítulo 9: Arreglos (3 ejercicios)
* 23. Leer 10 números enteros, almacenarlos en un vector y determinar si existe al menos un número repetido. Utilizar para tal fin el método `count()`.

* 38. Leer 10 números enteros, almacenarlos en un vector y determinar si la semisuma entre el valor mayor y el valor menor es un número primo.

* 48. Leer 10 números enteros, almacenarlos en un vector y determinar en qué posición se encuentra el número primo con mayor cantidad de dígitos pares. Utilizar el método `find()` de listas.

### Capítulo 10: Matrices (5 ejercicios)
* No utilizar los métodos `count()` y `find()` de listas.
* Cuando se reporten posiciones dentro de una matriz, considere como si esta se encontrara dentro de una hoja de cálculo. Por ejemplo, si se tiene una matriz de 4x6, las filas se numerarían 1 a 4 y las columnas de A a F.
* En cada ejercicio se deben imprimir de forma "bonita" cada matriz una vez entrados los datos, utilizando las funcionalidades de impresión asociadas a la función `print()` que se encuentran en las diapositivas ***9***. Por forma "bonita" me refiero que los números deben estar perfectamente alineados por sus unidades y la impresión debe ser agradable a la vista.

* 13. Leer una matriz 5x3 entera y determinar en qué columna está el mayor número que comienza con el dígito 4. Tenga en cuenta que el número 412378 comienza con el dígito 4.

* 28. Leer una matriz 4x6 entera y determinar en qué posiciones se encuentran los números cuyo penúltimo dígito sea el 5. Tenga en cuenta que el penúltimo dígito del número 52352242 es el 4.

* 38. Leer dos matrices 4x6 enteras y determinar si el mayor número primo de una matriz está aparece dos o más veces en la otra matriz. Reportar el número de repeticiones y las posiciones donde se encuentra dicho número repetido.

* 43. Leer dos matrices 5x5 enteras y determinar si el promedio entero de los números pares de una matriz es igual al promedio de los números pares de la otra matriz. Reportar dichos promedios.

* 48. Leer dos matrices 5x5 enteras y determinar si el promedio de los mayores elementos que pertenecen a la serie de Fibonacci de cada fila de una matriz es igual al promedio de los mayores elementos que pertenecen a la serie de Fibonacci de cada fila de la otra matriz. Reportar dichos promedios.

## Del libro de Oviedo

### Capítulo 6: Estructuras adicionales (2 ejercicios)
* 103. Se preguntan 20 registros de personas. De cada persona se suministró la siguiente información:
  ** Estatura en centímetros.
  ** Nacionalidad (1: Colombiana, 2: Mexicana, 3: Chilena).
  ** Edad.

  Hacer un programa con el siguiente menú:
```  
  Menú principal
  A. Número de chilenos con estatura mayor a 160 cm.
  B. Número de colombianos con estatura en el intervalo [150 cm, 170 cm].
  C. Total de sudamericanos.
  D. Total de mexicanos menores de 30 años
  E. Total de colombianos menores de 40 años con estatura menor a 160 cm.

  Entre su opción: 
```  
El programa debe imprimir la información solicitada. Utilizar para la solución de este problema diccionarios y la estructura `if-elseif-else`.

* 121. Una estación climática proporciona un par de temperaturas diarias (máxima, mínima - no es posible que alguna o ambas temperaturas sea 0 grados). La pareja fin de temperaturas es 0, 0. Elabore un algoritmo para determinar el número de días, cuyas temperaturas se han proporcionado, las medidas máxima y mínima, el número de errores (temperaturas de 0 grados) y el porcentaje que representan.

### Capítulo 8: Arreglos (7 ejercicios)
* 151. Hacer un algoritmo que forme un vector del que no se sabe el número de elementos. Calcule el promedio de los elementos y forme dos nuevos arreglos, uno con los elementos menores o iguales al promedio y otro con los superiores. Imprima los dos nuevos arreglos.

* 152. Elaborar un algoritmo que lea dos arreglos unidimensionales de igual tamaño y forme un tercer arreglo mediante el producto de los elementos de los dos arreglos, tomados en orden inverso, es decir, productos del primer elemento del primer arreglo con el último del segundo; del segundo del primer arreglo con el penúltimo del segundo arreglo; hasta llegar
al último del primer arreglo con el primero del segundo arreglo. Imprimir el arreglo formado.

* 157. Elaborar un algoritmo que forme dos arreglos. El primero contiene los M códigos de los estudiantes que perdieron CALCULO y el segundo los N códigos de los estudiantes que perdieron HUMANIDADES. Partiendo de los dos arreglos formar uno nuevo con los códigos de los estudiantes que perdieron ambas materias.

* 164. Elaborar un algoritmo que encuentre la intersección de dos vectores A y B, de N y M elementos respectivamente. Elabore dicho programa inicialmente sin utilizar las funcionalidades de conjuntos que ofrece Python y resolverlo utilizando dichas funcionalidades.

* 167. Haga un programa que lea un conjunto N de números reales (x,y) que tienen la tendencia de una línea recta. Elaborar un algoritmo que utilice tres
funciones para obtener los parámetros m y b de la ecuación de la recta y = mx + b. Las fórmulas para calcular m y b se encuentran en [https://miprofe.com/minimos-cuadrados/]. Resolver a continuación dicho problema utilizando las funcionalidades que tiene numpy. Adicionalmente graficar con matplotlib los puntos y la línea calculada.

* 171. Escribir un algoritmo que dado un arreglo unidimensional y su tamaño, elimine sus elementos repetidos, dejando un elemento en cada caso. No utilizar las funcionalidades de conjuntos que ofrece Python.

* 176. Elaborar un algoritmo que forme dos arreglos relacionados que almacenen los códigos de los N artículos que se venden en un almacén y la existencia (número de, unidades existentes) de cada uno de los artículos, así:
```
Código Existencia
  101     30
  200     40
```  
Del artículo 101 hay 30 unidades en existencia; del artículo 200, hay 40 unidades y así sucesivamente. Por cada proveedor o cliente que llega al almacén se genera un registro con los siguientes datos:
** Tipo de transacción [1 para proveedor (recibo); 2 para cliente (venta)].
** Código del artículo transado.
** Número de unidades transadas (recibidas o vendidas).

Se requiere calcular lo siguiente para cada transacción:
** Si es recibo, se suma a las existencias actuales de este artículo el número de unidades
transadas.
** Si es venta, se resta a las unidades en existencia de ese artículo las unidades vendidas. 

Al final se deben mostrar los códigos de los artículos y las existencias de cada uno de ellos, es decir, el arreglo de códigos y de existencias ya actualizado. Asuma que en ningún momento la cantidad vendida es mayor que la cantidad, en existencia,
y por lo tanto no le presentan inconsistencias.
