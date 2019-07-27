# Taller 1, Parte 4: 6 ejercicios

Cuando se solicite un gráfico, este debe hacerse con la mayor información posible. Si está incompleto se quitará una unidad; esto sucede por ejemplo si olvida el nombre de un eje, de un título, colocar una leyenda, o cualquier otra información necesaria para entender un gráfico. Explore todas posibilidades para que sus gráficos queden bien bonitos.

## `1.py`
Haga un programa que reciba una cadena que codifica un número en base 8 o en base 16 y muestre el valor de dicho número en base 10.
   * Si la cadena empieza por `0X` o por `0x` se interpretará como un número hexadecimal (ejemplo: `0xFF` es 255).
   * Si la cadena empieza por `0O` o por `0o` se interpretará como un número octal (ejemplo: `0o2342` es 1250).

Para la solución de este problema no se puede utilizar los comandos `int()` y `eval()`.

## `2.py`
Diseñe un programa que lea una cadena y muestre por pantalla una listas con todas sus letras en minúsculas. Una de las listas debe contener todas las palabras no repetidas, mientras que la otra debe mostrar las palabras repetidas. Por ejemplo, dada la cadena de texto: `"La perfección se logra no cuando no hay nada más que añadir, sino cuando no hay nada más que quitar. Antoine de Saint-Exupéri"`, el programa retornará la lista de palabras no repetidas: `["la", "perfección", "se", "logra", "no", cuando", "hay", "nada", "más", "que", "añadir", "sino", "quitar.", "antoine", "de", "saint-exupéri"]` y la lista de palabras repetidas `["no", "cuando", "hay", "nada," "más"]`. Dichas listas deberán contener las palabras en el orden de aparición. No utilizar los métodos de cadenas `lower()` o `split()`, o las utilidades de conjuntos para realizar este ejercicio.

## `3.py`
Haga un programa que ilustre una función llamada `es_repetición()`; dicha función deberá recibir una cadena de texto y debe retornar `True` en caso que la cadena esté formada mediante la concatenación de una cadena consigo misma. Por ejemplo, `es_repetición("abcabcabc")` devolverá `True`, ya que pues la cadena `abcabcabc` está formada con la cadena `abc` repetida y `es_repetición("abcabcd")` devolverá `False` ya que la cadena no se forma por repetición de otra. Otro ejemplo sería: `es_repetición("123 123 123 123 "`) retorna `True` (observe el espacio final), ya que la cadena es repetición de `"123 "`; sin embargo, pero `es_repetición("123 123 123 123")` retorna `False`.

## `4.py`
Haga un programa ilustre una función llamada `prefijo_comun()`. Dicha función recibirá como parámetro de entrada una lista de cadenas. La función retornará la prefijo común más largo de las palabras de la lista escrito en minúscula y sin tildes. Por ejemplo: `prefijo_comun(["aerosol", "Aerodinámico", "aeródromo", "aeropuerto"])` retorna `aero`. Observe que la tilde o las mayúsculas no afectan la extracción del prefijo común.

## `5.py`
Utilizando `numpy`, haga una simulación de Monte Carlo para estimar el número pi. No utilizar para ello las funciones suministradas por el módulo `random` o por `numpy.random`, sino que debe implementar el algoritmo [Linear Congruential Generator](https://en.wikipedia.org/wiki/Linear_congruential_generator) utilizando las constantes `a`, `c` y `m` del `glibc`. Grafique el error en la convergencia de la estimación de pi para máximo 1_000_000 simulaciones de Monte Carlo. Haga la misma estimación con 10_000_000 simulaciones utilizando `numpy.random.rand()`. En ambos casos no puede utilizar ciclos. Pistas: https://www.youtube.com/watch?v=VJTFfIqO4TU https://www.youtube.com/watch?v=9aJADZgNl18. El gráfico solicitado debe estar en escala logarítmica en ambos ejes.

## `6.py`
Dados dos vectores `x` y `y` de `n` elementos cada uno, calcular la ecuación de regresión lineal. Es decir, estimar las constantes `m` y `b` de `y = m*x+b`. Resuelva este problema a) sin utilizar `numpy` o `scipy` b) utilizando `numpy` y la función [`scipy.stats.linregress()`](https://docs.scipy.org/doc/scipy-0.14.0/reference/generated/scipy.stats.linregress.html). Grafique los puntos entrados y la línea de regresión. Pista: https://towardsdatascience.com/linear-regression-detailed-view-ea73175f6e86




