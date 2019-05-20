# Taller 1, Parte 1: 20 ejercicios
* No utilizar en la solución de estos problemas listas (pero si se pueden utilizar tuplas).
* No convertir los números a cadenas para poderlos descomponer.
* Cuando se pregunta por ejemplo un número entero de tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -101, -100, 100, 101, ..., 998 y 999.
* Cuando se pregunta por ejemplo un número entero de máximo tres dígitos, se está refiriendo a los números enteros -999, -998, ..., -2, -1, 0, 1, 2, ..., 998 y 999.
* Los números primos son los números naturales 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
* La serie de Fibonacci está dada por: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
* Tener en cuenta que muchos de los ejercicios solicitan cálculos sobre los números enteros; no sobre los números naturales; por lo tanto es necesario tener en cuenta los números enteros negativos, cuando sea del caso.
* Se dice que 3, 4, 5 y 6 son los números enteros comprendidos entre el 3 y el 6.
* Del número 349857 se puede decir que el 3 es su primer dígito, el 4 es su segundo dígito, el 5 es su penúltimo dígito y el 7 es su último dígito.
 
---

## Decisiones y ciclos

### `01.py`
Leer un número entero de 3 dígitos y determinar si contiene el dígito 1.

### `02.py`
Leer un número entero de seis dígitos y determinar si el segundo dígito es igual al penúltimo.

### `03.py`
Lea un número entero positivo y determine la suma de sus dígitos pares.

### `04.py`
Lea un número entero positivo de máximo 5 dígitos y determine cual de sus dígitos es el mayor.

### `05.py`
Leer tres números enteros y determinar si el penúltimo dígito de los tres números es igual.

### `06.py`
Leer dos números enteros y determinar si la magnitud de la diferencia entre los dos es un número primo.

### `07.py`
Lea un número entero positivo y determine si existen en el número dígitos repetidos. Reporte cuales son los dígitos repetidos.

### `08.py`
Leer un número entero y determinar si la suma de sus dígitos es un número de Fibonacci.

### `09.py`
Leer un número entero y determine el número de cincos que están consecutivos en un número. Por ejemplo, en `5512355551` hay 6 cincos consecutivos. Ahora, en `234555234512` solo hay 3 cincos consecutivos.

### `10.py`
Escriba un programa que lea un número natural *n* y calcule la suma de los números de múltiplos de 3 desde 0 hasta *n* utilizando: 
   * a) un ciclo **para**; 
   * b) un ciclo **mientras**; 
   * c) un ciclo **repita-hasta que**.

### `11.py`
Escriba un programa que lea un número de días (número entero no negativo) y lo convierta a días, semanas (7 días), meses (30 días) y años (365 días). Por ejemplo 1234 representa 3 años, 4 meses, 2 semanas y 5 días. Resuelva este ejercicio utilizando los operadores `//`, `%` y/o la función `divmod()`. Vuelva a resolver el ejercicio sin utilizar dichos comandos.

### `12.py`
Sin utilizar las funcionalidades de fechas de PYTHON, haga un programa que lea una fecha entre Enero 1 de 2000 y Mayo 7 de 2019 y determine el número de días desde ese día hasta Enero 1 de 2020. Tenga en cuenta los años bisiestos.

### `13.py`
Calcule la suma de todos los múltiplos de 3 y de 5 que hay entre 101 y 1001. Tenga en cuenta que los números naturales entre 1 y 15 que son múltiplos de 3 y de 5 son 3, 5, 6 y 9, 12 y 15. La suma de dichos dígitos es 50. Adicionalmente, note que aunque 15 es múltiplo tanto de 3 como de 5 se sumo una única vez.

### `14.py`
Haga un programa que lea las coordenadas *(x1,y1,r1)* y *(x2,y2,r2)* que corresponden al centro y al radio de dos círculos. Lea un punto de coordenadas *(a,b)*. Determina si *(a,b)* está contenido: a) dentro del círculo 1; b) dentro del círculo 2; c) dentro de ambos círculos; d) fuera de ambos círculos. Recordemos que el *círculo* es el lugar geométrico de los puntos del plano cuya distancia a otro punto fijo, llamado centro, es menor o igual que una cantidad constante, llamada radio.


### `15.py`
Lea una matriz cuadrada y determine su traza y el promedio de los números en ella contenida. Recuerde que no puede utilizar listas para la solución de este problema. Tampoco puede utilizar el módulo `numpy` o similares.

---

## Cadenas

### `16.py`
Haga un programa que lea una cadena de texto e informe al usuario cuales son las palabras más largas y mas cortas en dicho texto. NOTA: no se puede utilizar el comando `split()` ya que este utiliza listas y las listas no están permitidas para este taller.

### `17.py`
Sin utilizar el método `.upper()` para cadenas, escriba un programa que lea una cadena de texto y la imprima en mayúscula. Tenga en cuenta que el programa debe aceptar las letras con tilde, la ñ y la ü.

### `18.py`
Escriba un programa que reciba una cadena de texto y reporte: 
   * a) cuántas letras vocales en mayúscula se entraron;
   * b) cuántas letras con tilde se entraron (minúsculas y mayúsculas);
   * c) cuántos dígitos se entraron,
   * d) cuántos espacios se entraron;
   * e) cuántas palabras reservadas se entraron.

Utilice para ello los métodos de cadenas especializados como `.isupper()`, `.isdigit()`,  etc. y la palabra reservada `in`. Consulte [la ayuda de PYTHON](https://docs.python.org/3.7/library/stdtypes.html?highlight=islower#string-methods) para verificar que comandos especializados le pueden servir.

### `19.py`
Haga un programa que lea dos palabras (podrían estar en mayúscula o minúscula) y determine cual está primero en el diccionario. El programa debe soportar letras con tilde y la ü.

### `20.py`
Escriba un programa que lea una cadena de texto y la imprima como un triángulo. Por ejemplo, si la cadena entrada es: *"Es una locura odiar a todas las rosas porque una te pinchó: renunciar a todos tus sueños porque uno de ellos no se realizó - El Principito"*, el programa debe imprimir:
```
         E
        sun
       alocu
      raodiar
     atodaslas
    rosasporque
   unatepinchó:r
  enunciaratodost
 ussueñosporqueuno
deellosnoserealizó-
   ElPrincipito
```

Observe que la última cadena queda centrada con respecto a la base del triángulo.
