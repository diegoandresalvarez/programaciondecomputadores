# Taller 1, Parte 3: 6 ejercicios

Esta parte del taller, a diferencia de las partes anteriores, requerirá de ustedes la habilidad de buscar en intenet información sobre librerías, funciones y métodos para realizar las tareas encomendadas y obviamente, aprenderlas a usar. Muchas de las funciones que requerirán para hacer el taller no se verán en clase, por lo que es necesario que complementen su conocimiento en foros, YouTube y tutoriales.

Cada uno de los siguientes ejercicios debe realizarse utilizando las librerías `NumPy`, `SciPy`, `pandas` y/o `matplotlib`, a menos que se diga lo contrario.

No use las listas de Python en caso que la librería `NumPy` permita hacer la misma operación con mayor claridad.

En estos ejercicios no se deben utilizar listas de diccionarios, sino las utilidades provistas por las librerías `NumPy` (ver arrays estructurados) y `pandas`.

No incluir olvide adjuntar los archivos de MS EXCEL (`.xlsx`), en formato CSV (`.csv`) o cualquier otro archivo que contienen datos de entrada del ejercicio referido (excepto si tienen un tamaño mayor a 1 Mb; en este último caso, incluir dentro del programa algún comentario que diga de donde descargar el archivo en mención). El programa debe advertir en caso dado que esos archivos no existan y mostrar al usuario el enlace de donde lo puede descargar. Tenga en cuenta que MS EXCEL también puede abrir los archivos CSV, en caso que necesite visualizarlos.

Si los datos vienen de un archivo, el programa debe leer dichos datos del archivo. No se puede copiar y pegar el contenido de los archivos en el archivo `.py`. No se deben modificar los archivos descargados de internet, sino que se debe hacer el tratamiento del mismo desde Python. Si se modifican los archivos descargados desde internet, se tendrá un **cero** en ese ejercicio. En caso extremo que lo tenga que modificar, pida primero permiso al profesor, de modo que el pueda poner dicha excepción por escrito en las condiciones del problema. Finalmente, no cambie el nombre del archivo descargado desde internet. 

Cuando se solicite un gráfico, este debe hacerse con la mayor información posible. Si está incompleto se quitará una unidad; esto sucede por ejemplo si olvida el nombre de un eje, de un título, colocar una leyenda, o cualquier otra información necesaria para entender un gráfico. Explore todas posibilidades para que sus gráficos queden bien bonitos.

## `01.ipynb` (utilizar `NumPy` - tiene el doble de probabilidades de salir)
Estudiar a fondo el programa [12_rotar3d_pygame.zip](https://github.com/diegoandresalvarez/programaciondecomputadores/raw/master/codigo/python3/12_rotar3d_pygame.zip) y modificarlo de modo que no utilice listas sino arrays de `NumPy`. Todas las operaciones matemáticas deben hacerse también con `NumPy`.

El archivo principal de este programa es `rotar3d.py`. Para ejecutar dicho programa, primero debe instalar el módulo `pygame`, lo cual puede hacerse con el comando de consola:
```
python -m pip install pygame
```

## `02.py` (se recomienda utilizar `NumPy`)
Haga una hoja de Jupyter que grafique [polinomios de Legendre](https://en.wikipedia.org/wiki/Legendre_polynomials).

De forma similar a las siguientes figuras:

<img src="https://ipython-books.github.io/pages/chapter03_notebook/03_widgets_files/03_widgets_11_0.png" width="600">

<img src="https://blog.dominodatalab.com/wp-content/uploads/2016/05/sliderplot.gif" width="600">

utilice widgets para especificar:
* El orden del polinomio (entre 0 y 20).
* El color de la línea.
* El ancho de la línea.

El polinomio debe ser calculado utilizando `NumPy`. No se puede especificar directamente el polinomio o sus coeficientes en el programa. No utilizar la librería `SymPy`.

## `03.py` (se recomienda utilizar `NumPy`)
Descargar el archivo de MS EXCEL [Índice de precios de la vivienda nueva (IPVN) - Indices, según municipios y estratos 2010 - 2019 (datos trimestrales)](https://www.dane.gov.co/files/investigaciones/ipvn/IPVN_ind_mpi_estr_Itrim19_indice.xls) de la página del DANE.

Sin alterar el archivo de MS EXCEL original, haga una figura que ilustre en el mismo gráfico la serie de tiempo *anual* contenida en dicha tabla para Manizales, Pereira y Armenia. Tenga en cuenta que los datos provistos en el archivo de MS EXCEL son trimestrales.

Se recomienda al lector mirar la página https://en.wikipedia.org/wiki/House_price_index para entender qué es el *índice de precios de la vivienda*.

No se puede utilizar para la realización de este ejercicio el módulo `pandas`.

## `04.py` (se recomienda utilizar `pandas`)
Repetir el ejercicio anterior utilizando esta vez el módulo `pandas`.

No se puede utilizar para la realización de este ejercicio el módulo `Numpy`.

## `05.py` (se recomienda utilizar `pandas`)
Descargue de la página del DANE la base de datos del [Censo de Habitantes de Calle - CHC- 2017 - Bogotá, D.C.](http://microdatos.dane.gov.co/index.php/catalog/548)

Utilizando esta base de datos:
* Cree una [pirámide poblacional](https://en.wikipedia.org/wiki/Population_pyramid) que muestre la distribución de edades de los encuestados por sexo. Ver por ejemplo:
<img src="https://www.indexmundi.com/graphs/population-pyramids/colombia-population-pyramid-2016.gif" width="600">

en este caso, el eje horizontal debe mostrar el porcentaje de personas entrevistadas.

* Cree una torta que indique el nivel educativo más alto alcanzado.

## `06.py` (se recomienda utilizar `pandas` - tiene el doble de probabilidades de salir)
Descargar de la Registraduría los datos de los [resultados para la primera vuelta de las elecciones presidenciales para el 2014](https://www.registraduria.gov.co/-Historico-de-Resultados,3635-.html). Archivo: https://www.registraduria.gov.co/IMG/xlsx/PRE_1ERA_VUELTA_MMV_2014.xlsx

Procesar los datos mostrados y generar:
* Un gráfico similar al mostrado a continuación:
<img src="https://saintbrendansisland.files.wordpress.com/2014/05/colombia-20143.png" width="600">

Este gráfico muestra para cada departamento, el porcentaje de votos obtenidos por candidato. El gráfico superior izquierdo es un gráfico general en el que se muestran los porcentajes asociados a los ganadores.

* Un mapa del departamento de Caldas que indique cual fue el candidato ganador por municipio (similar al mapa anterior superior izquierdo).

En un comentario, indicar cuales comandos tuvo que ejecutar en la consola para instalar la(s) librería(s) para dibujar los mapas y también los links de los archivos necesarios para tal final (shapefiles, etc.)

Ver: https://www.semana.com/nacion/elecciones-2014/articulo/resultados-de-la-primera-vuelta-de-las-elecciones-presidenciales-2014/389356-3
