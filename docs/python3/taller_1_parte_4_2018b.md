# Taller 1, Parte 4: 7 ejercicios

### ```1.py```
Lea dos polinomios de grado entre 0 y 9 con respecto a la variable *x*; imprima su suma y multiplicación. No usar las funcionalidades de `NumPy` o `SymPy` para realizar este ejercicio. Utilice como exponentes los superíndices ⁰¹²³⁴⁵⁶⁷⁸⁹. Adicionalmente, no deben existir espacios entre el coeficiente y la variable *x*, pero si pueden existir varios espacios entre el signo y los números o la *x* (en caso que dicha *x* represente *x*¹). Finalmente los exponentes 1 y 0 son opcionales y los coeficientes del polinomio son números enteros. Por ejemplo:
```
Entre el polinomio 1: 3x² +10x- 1
Entre el polinomio 2: 125x⁹+10x² -   1x¹     +32x⁰
La suma de los dos polinomios es: 125x⁹ + 13x²  + 9x + 31
La multiplicación de los dos polinomios es: 375x¹¹ + 1250x¹⁰ - 125x⁹ + 30x⁴ + 97x³ + 76x² + 321x - 32 
```
* NOTA: no se debe solicitar al usuario una a una las constantes asociadas al polinomio. Aquí el reto es interpretar las cadenas de texto para extraer la información de ellas.
* PISTA 1: se recomienda utilizar **expresiones regulares** para realizar este ejercicio. De este modo, es super fácil. Aprendan ese tema con YouTube (librería python: `import re`)
* PISTA 2: la multiplicación se hace fácilmente con una operación vectorial llamada la [convolución discreta](https://en.wikipedia.org/wiki/Convolution).


### ```2.py```
Repita el ejercicio ```1.py```, pero esta vez utilizando la librería `SymPy` y las funcionalidades de dicha librería para el manejo de polinomios. Haga que `SymPy` muestre los polinomios entrados y los resultados utilizando `LaTeX`. Ejecute por ejemplo en el spyder:
```python
import sympy as sp
sp.init_printing()

x = sp.symbols('x')
display(sp.Poly([3, 2, 1],x).as_expr())
```


### ```3.py```
Considere un triángulo rectángulo de lados *a*, *b*, *c* (tres números enteros) cuyo perímetro es *p*=*a+b+c*. Por ejemplo, si el perímetro *p* vale 120, los lados que satisfacen dicha igualdad son: {20,48,52}, {24,45,51}, {30,40,50}. ¿Para qué valor de *p* ≤ 1000 tenemos que el número de lados que cumplen el postulado se maximiza? 
* PISTA: Use las ecuaciones *a*² + *b*² = *c*²  y *p* = *a+b+c*, redúzcalas a una sola ecuación y trabaje con esta:
```python
from sympy import init_printing
init_printing(use_latex=True)
from sympy import symbols, Eq, solve

a, b, c, p = symbols('a b c p')
c = p - a - b
solve(Eq(a**2 + b**2, c**2), b)
```


### ```4.py```
Haga un programa que tome una matriz de tamaño *m*x*n* y la rote implementando su propia versión de la función `numpy.rot90()`; dicha función debe función igual que `rot90()` para matrices. Utilice para ello la librería `numpy`, pero obviamente, no se debe usar la función referida.


### ```5.py```
Haga un algoritmo que lea dos números, los almacene dígito a dígito en dos listas y los resta tal y como a usted le enseñaron en segundo de primaria (tomando prestado, etc). Imprima la resta en pantalla tal y como lo hacía usted en primaria, indicando con un alguna marca la columna donde le tocaba tomar prestado. Recuerde que en primaria le usted siempre ponía el número mayor en la fila de arriba. Además en primaria usted solo conocía los números naturales.
* PISTA: este ejercicio se resuelve fácilmente utilizando funciones recursivas.

### ```6.py```
**Utilizando colas**, elaborar un algoritmo que pregunte al usuario vectores de `n1` y `n2` elementos, los cuales, se sabe, están ordenados ascendentemente cada uno. Forme un tercer arreglo que quede ordenado en la medida que pasan los elementos de los dos arreglos iniciales. Imprimir el nuevo arreglo. No usar las utilidades que provee Python para ordenar listas: ejemplo `sorted()` o el método `sort()`, ni ninguna otra función de ordenamiento bajada de internet.
* PISTA: ver en el PDF 4 la diapositiva **Usando una lista como una cola** y la ayuda sobre el comando [`collections.deque`](https://docs.python.org/2/library/collections.html#collections.deque).
* EJEMPLO: suponga que los vectores leídos son: `n1 = [150, 160, 170, 180, 181, 187]` y `n2 = [155, 156, 160, 165, 168]`. Lo primero que debe hacer el código es verificar que los vectores estén ordenados. Luego se pasan a las colas y después de ejecutar el procedimiento pedido, el programa debería retornar el vector `[150, 155, 156, 160, 160, 165, 168, 170, 180, 181, 187]`.
NOTA: para simplificar la programación, considere que los vectores leídos están formados únicamente por números enteros.

### ```7.py```
Haga una simulación de Monte Carlo para estimar el número pi. Utilice `Numpy`. Para la generación de los números aleatorios implemente el algoritmo [Linear Congruential Generator](https://en.wikipedia.org/wiki/Linear_congruential_generator) (recuerde inicializar la semilla con el utilizando la función `time.time()`). Haga en `matplotlib` un gráfico que muestre como disminuye el error de estimación de pi a medida que usted aumenta las muestras desde 1000 hasta 100_000_000 simulaciones de Monte Carlo. El eje *x* de dicho gráfico se podría hacer con un `np.logspace(3,8,20)` y debe estar en escala logarítmica.
* NOTA: Utilice las constantes *a*, *c* y *m* del `glibc` (ver [Wikipedia](https://en.wikipedia.org/wiki/Linear_congruential_generator))
* NOTA: En la misma página de [Wikipedia](https://en.wikipedia.org/wiki/Linear_congruential_generator) está el código del LCG en Python. Si va a copiar dicho código, por favor explique en un bloque comentario como funciona la palabra reservada `yield`.
* NOTA: En [Wikipedia](https://en.wikipedia.org/wiki/Linear_congruential_generator) dice: "*LCGs should be chosen very carefully for applications where high-quality randomness is critical. Any Monte Carlo simulation should use an LCG with a modulus greater and preferably much greater than the cube root of the number of random samples which are required. This means, for example, that a (good) 32-bit LCG can be used to obtain about a thousand random numbers; a 64-bit LCG is good for about 2^21 random samples which is a little over two million, etc. For this reason, LCGs are in practice not suitable for large scale Monte Carlo simulations".* Por dicha razón, en los cálculos científicos usualmente se utiliza el generador de números aleatorios [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) por sus múltiples ventajas estadísticas y por su gran periodo de 2¹⁹⁹³⁷ − 1. Sin embargo, en este ejemplo continuaremos usando el generador LCG dada su simplicidad.
* PISTA 1: https://www.youtube.com/watch?v=VJTFfIqO4TU https://www.youtube.com/watch?v=9aJADZgNl18
* PISTA 2: por favor utilizar las propiedades de vectorización del código en Python. Si uno utiliza un ciclo for para hacer cada una de las simulaciones de Monte Carlo, la evaluación del taller demorará horas, mientras que si se vectoriza el código, se resolverá en segundos. Ver, por ejemplo: https://realpython.com/numpy-array-programming/#what-is-vectorization


