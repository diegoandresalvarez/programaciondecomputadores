
=Los ejercicios a realizar=
**Parte 1: 18 ejercicios**
Del libro Marzal-Gracia-García:
Capítulo 4: Estructuras de Control
80
112
124

Del libro Trejos:
Capítulo 7: Decisiones
5
15
25
30
40: . Leer dos números enteros y si la diferencia entre los dos es menor o igual a 10 entonces mostrar en pantalla todos los enteros comprendidos entre el menor y el mayor de los números leídos. Incluir ambos números en la impresión
45: Leer un número natural de 3 dígitos y si es par mostrar en pantalla la suma de sus dígitos, si es primo y menor que 500 mostrar en pantalla su último dígito y si es múltiplo de 5 y menor que 300 mostrar en pantalla el primer dígito.
50: Leer un número entero y si es múltiplo de 4 mostrar en pantalla su mitad, si es múltiplo de 5 mostrar en pantalla su cuadrado y si es múltiplo e 6 mostrar en pantalla su primer dígito. Asumir que el número no es mayor que 100. Observe que en este caso si entramos por ejemplo el 20, al ser múltiplo de 4 y 5 tendrá que mostrarse en pantalla su mitad y su cuadrado.

Capítulo 8: Ciclos
15
20
25
30
35: Leer dos números naturales y determinar a cuánto es igual el producto del primer dígito de cada uno. Tengamos en cuenta que para el número 23 el primer dígito es el 2. Y para el número 543 es el 5.
40
45
50

**Parte 2: 21 ejercicios**
Del libro Marzal-Gracia-García:
Capítulo 5: Secuencias: Listas y cadenas
152   
160: Diseña un programa que lea una cadena y un número entero n y nos diga si todas sus palabras tienen una longitud de n caracteres. Aclaración: este programa por ejemplo diría que en la cadena "ábaco ratón cl123         +1231      éxito  horas" todas las cadenas tienen una longitud de 5 caracteres (observe que entre las palabras pueden existir uno o más espacios). Asuman que las palabras están separadas únicamente por espacios. Obviamente n debe ser un número positivo. Si se ingresa un número negativo, debe sacar una advertencia al usuario. Tenga en cuenta que pueden existir varios espacios entre las palabras; dichos espacios, no se deben tener en cuenta.
168   
180: Diseña un programa que lea una cadena que representa un número NATURAL codificado en base 8 y muestre por pantalla su representación en base 2.
188: Una de las técnicas de criptografía más rudimentarias consiste en sustituir cada uno de los caracteres por otro situado n posiciones más a la derecha en el abecedario. Si n = 2, por ejemplo, sustituiremos la «a» por la «c», la «b» por la «d», y así sucesivamente. El problema
que aparece en las últimas n letras del alfabeto tiene fácil solución: en el ejemplo, la letra «y» se sustituirá por la «a» y la letra «z» por la «b». La sustitución debe aplicarse a las letras minúsculas y mayúsculas y a los dígitos (el «0» se sustituye por el «2», el «1» por el «3» y así hasta llegar al «8», que se sustituye por el «0», y el «9», que se sustituye por el «1»). Diseña un programa que lea un texto y el valor de n y muestre su versión criptografiada.
NOTAS:
- El valor de n debe estar entre 1 y 10.
- A caracteres diferentes a letras y números no se les aplicaría el cambio (se dejan tal cual) ejemplo: ?^^¡![] se dejan así
- Los caracteres áéíóúüÁÉÍÓÚ no se cambiarán con dicha codificación. Si se debe tener en cuenta la ñÑ
- Este tipo de codificación se conoce como "el cifrado César": [[http://en.wikipedia.org/wiki/Caesar_cipher]] [[http://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar]]

200. Diseña un programa que lea dos cadenas y devuelva el prefijo común más largo de ambas. Por ejemplo: "¡¡¡Hoy, 14 de abril de 2015, es un día muy especial!!!" y "¡¡¡Hoy, 14 de agosto de 2015, es un día muy especial!!!". El programa retornaría "¡¡¡Hoy, 14 de a".
224   
240: Haz un de programa que pida un número natural n y almacene en una variable M la matríz identidad de n × n (la que tiene unos en la diagonal principal y ceros en el resto de celdas. Imprima dicha matriz.

Del libro Trejos:
Capítulo 9: Arreglos
10
20: Leer 10 números enteros, almacenarlos en un vector y determinar en qué posición está el menor número primo. Si el menor número primo está en varias posiciones, reportar todas aquellas posiciones donde este se encuentra.
35
40
45
50: Leer 10 números enteros, almacenarlos en un vector y determinar cuántos números de los almacenados en dicho vector comienzan en dígito primo. Tenga en cuenta por ejemplo que el número -79812 comienza en 7 (no en -7).

Capítulo 10: Matrices
10
20
30
35: Leer una matriz 4x6 entera y determinar cuál es el mayor dato almacenado en ella que pertenece a la serie de Fibonacci"
40
45
50: Leer una matriz entera 5x5 y determinar si el promedio ENTERO de los elementos que se encuentran en su diagonal PRINCIPAL está almacenado en ella. Mostrar en pantalla en qué posiciones exactas se encuentra dicho dato.



**Parte 3: 21 ejercicios**
* **En todos los programas se debe incluir un mecanismo para leer los datos requeridos por la función desde el teclado.**
* **Se puede utilizar la librería math para los cálculos requeridos en esta entrega del taller.**


Del libro Marzal-Gracia-García:
Capítulo 6: Funciones:
272
276   

280 Define una función, que dados dos parámetros b y x, devuelva el valor del logaritmo de x en base b. Para tal fin, tenga en cuenta que:
[[math]]
\log_b(x) = \frac{\ln(x)}{\ln(b)}
[[math]]
y que,
[[math]]
\ln(a) = \int_1^a \frac{1}{x} dx
[[math]]
<span style="color: #0000ff;">En este caso, se permite un error en el cálculo de la integral anterior de máximo 1e-3, asumiendo que a<5.</span>

284: Define una función llamada raiz_n_esima que devuelva el valor de x^{1/n}. Utilice series de Taylor. Recuerde que:
[[math]]
a^b = \exp(b \ln(a)) = \sum_{i=0}^\infty \frac{(b \ln(a))^i}{i!} = 1 + (b \ln(a)) + \frac{(b \ln(a))^2}{2!} + \frac{(b \ln(a))^3}{3!} + \frac{(b \ln(a))^4}{4!} + \cdots
[[math]]
288. Un ejemplo de programa podría ser el siguiente:

Por favor responda UNICAMENTE "sí" o "no" a cada una de las siguientes preguntas:

* ¿Has besado alguna vez alguien que no te gusta?
* ¿Te has dormido en clase de programación de computadores?
* ¿Cantas por la mañana en la ducha?
* ¿Has comido carne de cocodrilo?
* ¿Has olvidado el cumpleaños de tu mejor amig@?

etc. Simplemente usen su creatividad.

292: Diseña un programa que, dado un número n, muestre por pantalla todas las parejas de números amigos menores que n. La impresión de los resultados debe hacerse desde un procedimiento. NOTA: los números amigos se explican en [[http://es.wikipedia.org/wiki/N%C3%BAmeros_amigos]]   
296   
300: Diseña una función que reciba una lista de palabras (cadenas) y devuelva, simultáneamente, la primera y la última palabras según el orden alfabético. En este ejercicio no se deben tener en cuenta las tildes y la ñ. Sin embargo, no se puede utilizar el comando sorted() o el método sort() de Python. Deben crear sus propias funciones de ordenamiento de cadenas.
304   
308   
312   
316   
332   
336   
348   
352   
356   
364   

**En los siguientes programas se debe mejorar/implementar el módulo pedido, junto con las funciones que se solicitan:**
<span style="color: #0000ff;">La solución de los ejercicios MGG_380, MGG_384 y MGG_388 requiere la implementación de módulos. En este caso, se solicita que el nombre de los archivos asociados a ese módulo sean: vectores.py, estadisticas.py y matrices.py respectivamente.
</span>
380   
384   
388   

=Parte 4 -- opcional para los que quieran mejorar su nota y obligatorio para los que quieran volver a repetir la sustentación (12 ejercicios)=





MGG_310 No utilizar para ello las utilidades de conjuntos que suministra Python. 

EJE_2.py Dado una lista L, que contiene números enteros repetidos y en desorden, imprimir una lista en la cual aparezcan dichos valores ordenados y una sola vez; por ejemplo si L = [2,1,7,1,3,4,-1,7,9,5,2,5], entonces el programa imprime [-1,1,2,3,4,5,7,9]. No usar las utilidades de conjuntos ni las utilidades para ordernar listas que provee Python (ejemplo: sorted() o el método sort()). 

EJE_3.py Elaborar un algoritmo que pregunte al usuario vectores de n1 y n2 elementos, los cuales, se sabe, están ordenados ascendentemente cada uno. Forme un tercer arreglo que quede ordenado en la medida que pasan los elementos de los dos arreglos iniciales. Imprimir el nuevo arreglo. No usar las utilidades que provee Python para ordenar listas: ejemplo sorted() o el método sort(). 

EJE_4.py Sin utilizar las funcionalidades que provee Python para convertir un número de una base a otra, elabore un programa que lea un número de base 10 e imprima su equivalente en las bases 2 8 y 16. 
