# Taller 1, Parte 1: 20 ejercicios
* No convertir los números a cadenas para poderlos descomponer.
* No utilizar la librerías *numpy*, *scipy* o similares que provean las funciones que se supone ustedes deben implementar.
* Cuando se pregunta por ejemplo un número entero de tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -2, -1, 0, 1, 2, ..., 998 y 999.
* Los números primos son los números naturales 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
* La serie de Fibonacci está dada por: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
* Tener en cuenta que muchos de los ejercicios solicitan cálculos sobre los números enteros; no sobre los números naturales; por lo tanto es necesario tener en cuenta los números enteros negativos, cuando sea del caso.
* Un *triángulo isósceles* es aquel que tiene únicamente dos lados de igual longitud.
* Se dice que 3, 4, 5 y 6 son los números enteros comprendidos entre el 2 y el 7.

## Del libro de Trejos

### Capítulo 7: Decisiones
*NOTA*: No utilizar en la solución de estos problemas ciclos o listas. Se exceptúa el `while True` que acompaña al `try-except` en la lectura de los datos de entrada.

* 18: Leer un número entero de tres dígitos y determinar si algún dígito es múltiplo de los otros. Por ejemplo, si el número ingresado es el `248`, el programa debería imprimir algo similar a:
```
El 4 es múltiplo del 2 
El 8 es múltiplo del 2 
El 8 es múltiplo del 4
```

* 23: Leer un número entero de tres dígitos y determinar cuántos dígitos primos tiene.
* 28: Leer un número entero menor que 50 y positivo y determinar si es un número primo.
* 38: Leer tres números enteros y determinar si el último dígito de los tres números es igual.
* 43: Leer dos números enteros y determinar si la diferencia entre los dos es un número divisor exacto de alguno de los dos números.

### Capítulo 8: Ciclos
*NOTA*: No utilizar en la solución de estos problemas listas.

* 3: Leer un número entero y mostrar todos los divisores exactos del número comprendidos entre 1 y el número leído.
* 18: Leer dos números entero y mostrar todos los múltiplos de 5 comprendidos entre el menor y el mayor.
* 23: Leer un número entero y determinar si la suma de sus dígitos es un número primo.
* 28: Leer dos números enteros y determinar cual de los dos tiene mayor cantidad de dígitos primos.
* 33: Leer un número entero. Hacer un programa que determine cuál es el número primo más grande menor que dicho número.
* 43: Leer dos números enteros. Determinar cuántos elementos de la serie de Fibonacci se encuentran entre ellos.

## Del libro de Oviedo

### Capítulo 4: Estructura decisión lógica
*NOTA*: No utilizar en la solución de estos problemas listas.
* 26: Hacer un algoritmo que solicite cuatro números; el algoritmo debe determinar la suma del valor menor y mayor de dichos datos.
* 28: Dados tres valores positivos determinar si éstos no forman triángulo o si forman triángulo, decir si éste es: equilátero, isósceles o escaleno y obtener el área del triángulo.
* 30: Elaborar un algoritmo que entre un punto (x, y); diga si está, o no, en el área determinada por la parábola Y = 4 - X^2 y la recta Y = X - 3. 

### Capítulo 5: Estructura repetitiva
* 42: Hacer un algoritmo que encuentre la suma de los valores mayor y menor entre un grupo de datos positivos. No utilizar las funciones `min()`, `max()`, `sorted()`, el método `sort()` o similares que provee Python.
* 44: Haga un programa que pregunte cuantos triángulos se desean analizar. Para cada triángulo ingrese tres números positivos que representan sus lados. Hacer un algoritmo que determine cuántos triángulos equiláteros, isósceles y escalenos hay.
* 47: Varias ambulancias recorren la ciudad y cuando se recibe en la CENTRAL una llamada se informa la ubicación de la emergencia mediante coordenadas, lo mismo que la ubicación de todas las ambulancias. La central es el punto (0,0) u origen de las coordenadas. Se sabe que existen N ambulancias en servicio. Realice un algoritmo que, pregunte para cada ambulancia sus coordenadas y las coordenadas del punto de la emergencia, e informe cual ambulancia está más cercana al punto de emergencia. Para el cálculo de la distancia, utilizar la distancia euclídea (sugerencia: utilizar la función `hypot()`).
* 52: Elaborar un algoritmo que muestre los enteros desde 1 hasta N y sus cuadrados, calculados solamente con sumas y utilizando el método propuesto. 
```
Número Cuadrado Método 
  1       1        1 
  2       4        1 + 3 
  3       9        1 + 3 + 5 
  4      16        1 + 3 + 5 + 7 
  5      25        1 + 3 + 5 + 7 + 9 
        ...
```     
*NOTA*: no es necesario imprimir la columna *Método*. Solo se coloca aquí para fines ilustrativos.

* 73: Escriba un algoritmo para leer e imprimir un texto de entrada y determinar el número de oraciones y palabras involucradas. Asuma que: 
  * a. Cada oración termina con un punto, y que el carácter punto no es utilizado para ningún otro propósito. 
  * b. Las palabras están conformadas por letras y separadas por uno o más espacios. El algoritmo debe verificar que la frase únicamente está compuesta por letras, espacios y puntos.
  * Para este ejercicio no utilizar los métodos que tiene el objeto str en python. Solo se puede utilizar indexación y slicing.
* 75: Elaborar un algoritmo que entre la hora de un día en horas, minutos y segundos; se desea obtener la hora a los 30 segundos siguientes. Imprimir la hora en el formato militar HH:MM:SS; por ejemplo: 08:55:03.