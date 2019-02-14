# Taller 1, Parte 3: 11 ejercicios

Esta parte del taller, a diferencia de las partes anteriores requerirá de ustedes la habilidad de buscar en intenet información sobre librerías, funciones y métodos para realizar las tareas encomendadas y obviamente, aprenderlas a usar. Muchas de las funciones que requerirán para hacer el taller no se verán en clase, por lo que es necesario que complementen su conocimiento en foros, YouTube y tutoriales.

Cada uno de los siguientes ejercicios debe realizarse utilizando las librerías `NumPy`, `SciPy`, `pandas` y/o `matplotlib`, a menos que se diga lo contrario. Únicamente el ejercicio 11 deberá realizarse utilizando `Jupyter`.

No use las listas de Python en caso que la librería NumPy permita hacer la misma operación con mayor claridad.

En estos ejercicios no se deben utilizar listas de diccionarios, sino las utilidades provistas por las librerías `NumPy` (ver arrays estructurados) y `pandas`.

Cuando el nombre del ejercicio termina con `_pd` quiere decir que se debe realizar utilizando `pandas`; si termina con `_np`, quiere decir que se debe realizar utilizando los arrays estructurados de `NumPy`.

No olvide adjuntar los archivos de MS EXCEL (`.xlsx`), en formato CSV (`.csv`) o cualquier otro archivo que contienen datos de entrada del ejercicio referido. El programa debe advertir en caso dado que esos archivos no existan. Tenga en cuenta que MS EXCEL también puede abrir los archivos CSV, en caso que necesite visualizarlos.

Si los datos vienen de un archivo, el programa debe leer dichos datos del archivo. No se puede copiar y pegar el contenido de los archivos en el archivo `.py`. No se deben modificar los archivos descargados de internet, sino que se debe hacer el tratamiento del mismo desde Python. Si se modifican los archivos descargados desde internet, se tendrá un **cero** en ese ejercicio. En caso extremo que lo tenga que modificar, pida primero permiso al profesor, de modo que el pueda poner dicha excepción por escrito en las condiciones del problema.

Cuando se solicite un gráfico, este debe hacerse con la mayor información posible. Si está incompleto se quitará una unidad; esto sucede por ejemplo si olvida el nombre de un eje, de un título, colocar una leyenda, o cualquier otra información necesaria para entender un gráfico. Explore todas posibilidades para que sus gráficos queden bien bonitos.

---

## `1_pd.py` (se sugiere hacerlo en `pandas`)
Se tiene la siguiente información de un grupo de personas: 
   * cédula
   * apellidos
   * nombres
   * dirección
   * teléfono
   * sexo
   * estado laboral (empleado formar, empleado informal, desempleado)

Dicha información se encuentra escrita en la hoja de EXCEL `01.xlsx` (para cuando use pandas) y/o en el archivo CSV `02.csv` (para cuando use NumPy). En caso que los archivos `01.xlsx` o `02.csv` no existan, se deben crear.

Hacer un programa que funcione de acuerdo con el siguiente menú:
```
  Menú principal
  ==============
  A. Adicionar nueva persona
  B. Editar persona
  C. Remover persona
  D. Buscar persona por cédula o nombre y apellidos
  E. Listar personas que trabajan y que no trabajan, clasificadas por sexo.
  F. Salir

  Entre su opción: 
```
Las opciones A., B. y C. deben actualizar/crear los archivos `01.xlsx` o `02.csv` con la información, guardando las personas ordenadamente de acuerdo con el número de cédula.

Las opciones B. y C. preguntan el número de cédula de la persona a editar/remover, muestran la persona con toda su información y solicitan una confirmación antes de hacer el cambio final.

La opción E lista las personas ordenadas por cédula de forma ascendente. Aquí deben mostrarse cuatro listados: hombres que trabajan, mujeres que trabajan, hombres desempleados, mujeres desempleadas. Guarde dichas listas en un archivo e infórmele al usuario que así lo hizo.

La opción E debe advertir que no existen personas en caso que no existan los archivos `01.xlsx` o `02.csv`.

La primera fila de los archivos debe tener el título de la columna. Las columnas de los archivos deben contener la información en el mismo orden que se presenta arriba de modo tal que la columna A contiene la cédula y la columna G contiene el estado laboral.

## `2.py`
Calcule e imprima las coordenadas en 2D de los vértices de un polígono regular de _n_ lados, de modo que el lado inferior siempre sea paralelo al eje _x_ y que cada lado tenga una longitud unitaria. Grafique dicho polígono usando `matplotlib` utilizando el color azul. El programa debe tener una opción para rotar el polígono un ángulo dado (la dirección antihoraria es la positiva). Grafique el polígono rotado en color rojo y en negro con una línea punteada más delgada la circunferencia más pequeña que contiene dicho polígono. Utilice un `.legend()` para identificar el polígono original, el polígono rotado y la circunferencia. Los vértices del polígono deben tener unos puntos de adorno. Póngale nombre a los ejes _x_ y _y_.

---

Los siguientes ejercicios están basados en unos que aparecen en http://disi.unitn.it/~teso/courses/sciprog/index.html

## `3.py`
Guarde el archivo https://drive.google.com/open?id=0B0wILN942aEVVlk4TS1WaDItVU0 y léalo desde su programa. La primera columna contiene el número de identificación de un experimento, la segunda columna, contiene el caudal medido en m³/s. El intervalo de tiempo entre mediciones es de 1 hora. Se hicieron 10 experimentos en total. Para cada experimento, grafique los valores como una serie de tiempo. Para las 10 series de tiempo, grafique la serie de tiempo media, y una área que indique una desviación estándar (algo similar a lo mostrado [aquí](https://www.arcus.org/files/resize/sio/25738/figure6b-700x555.png)). Muestre el gráfico en pantalla y adicionalmente guárdelo como un archivo `.pdf`.


## `4.py`
Utilizando la base de datos IRIS:
* https://en.wikipedia.org/wiki/Iris_flower_data_set
* https://www.kaggle.com/jchen2186/machine-learning-with-iris-dataset (descárguela de aquí)
cree un gráfico similar a [este](https://imdevsoftware.files.wordpress.com/2012/08/clipboard04.jpg).

Finalmente, el programa debe imprimir una tabla en la que muestre para cada clase la siguiente información:
* Media
* Desviación estándar
* Valor mínimo y máximo
* Correlación de Pearson entre el ancho y largo del pétalo.

---

## `5.py` (se sugiere hacerlo en `pandas`)
Utilizando la base de datos de todos los pasajeros del Titanic (https://www.kaggle.com/c/titanic -> usar únicamente `train.csv`) hacer lo siguiente:
* Cree una torta que muestre la proporción de hombres y mujeres y justo al lado otro  que indique la clase (primera, segunda o tercera clase).
* Cree un diagrama de dispersión que muestre la tarifa pagada vs. la edad. Distinga el sexo mediante un color. Ver por ejemplo [este](https://support.minitab.com/en-us/minitab-express/1/scatterplot_pulse_rates_1_y_with_groups_3col.xml_Graph_cmd2o1.png) gráfico.
* Cree un histograma con la tarifa pagada.

---

Los siguientes dos ejercicios son se inspiran de:
https://www.physik.uzh.ch/~python/python_2018-06/lecture_analysis/Analytics_ex.pdf

Los archivos requeridos para esta tarea se encuentran en los archivos `.tar.gz` (descomprímalos) que están en:
https://www.physik.uzh.ch/~python/python_2018-06/lecture_analysis/

## `6.py`
Hacer el ejercicio 4 de https://www.physik.uzh.ch/~python/python_2018-06/lecture_analysis/Analytics_ex.pdf

## `7.py`
El archivo `routes.txt` contiene una lista de casi todos las conexiones aéreas comerciales conocidas. Esta lista incluye información sobre la aerolínea, el punto de partida y el destino.

Determine e imprima cuales son las cuatro aerolíneas con más conexiones aéreas en Colombia. Haga para cada una de esas aerolíneas un mapa similar a http://www.paisatours.com/images/avianca_route_map_l.jpg con las conexiones que cubren.

Ver los archivos `airports.txt`, `airlines.txt` y `planes.txt` y la página https://openflights.org/data.html podría ayudarle a entender los datos.

---

# Ejercicios eliminados
No hacer los siguientes ejercicios:

<strike>

## `02_np.py`

## `07_np.py`

## `08.py`
Descargar el archivo de MS EXCEL de los índices de precios de vivienda nueva del Banco de la República:
* https://en.wikipedia.org/wiki/House_price_index
* http://www.banrep.gov.co/es/indice-precios-vivienda-nueva-ipvnbr
Sin alterar el archivo de MS EXCEL original, haga un gráfico que ilustre la serie de tiempo contenida en dicha tabla. El eje de las abscisas debe mostrar la fecha cada 4 meses de modo similar a como se muestra [aquí](https://i.stack.imgur.com/MUXMz.png), pero solo colocando el mes y el año.

## `11.ipynb`
Crear un notebook de `jupyter` que ilustre paso a paso el diseño de una viga de concreto reforzado a flexión y cortante, haciendo las referencias respectivas a la norma NSR-10, colocando ecuaciones, figuras ilustrando la teoría, gráficos y por supuesto, el código de Python que ayude en el diseño mismo.
</strike>