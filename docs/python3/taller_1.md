# Taller de programación 1: (20% de la nota final)

![Caricatura](http://imgs.xkcd.com/comics/ballmer_peak.png)

Fuente: <http://xkcd.com/323/>

# Fecha y hora límite de entrega:
* **Parte 1**: Septiembre 23, 2018 a las 11:59pm 
* **Parte 2**: ~~Octubre 21, 2018~~ Febrero 3, 2019 a las 11:59pm
* **Parte 3**: ~~Noviembre 11, 2018~~ Marzo 1, 2019 a las 11:59pm
* **Parte 4 (opcional)**: ~~Noviembre 18, 2018~~ Marzo 13, 2019 a las 11:59pm. La parte 4 de este taller es opcional y reemplaza la nota más baja de las entregas 1, 2 y 3. Es requisito presentar este taller para poder realizar de nuevo la sustentación.

Cada entrega del taller debe enviarse a <daalvarez@unal.edu.co>. Sin excepción, por cada día de retraso en la entrega, se rebajarán 3 décimas de la nota de esa entrega del Taller 1. 

# Los ejercicios a realizar
- [Taller 1, Parte 1](taller_1_parte_1_2018b.md)
- [Taller 1, Parte 2](taller_1_parte_2_2018b.md)
- [Taller 1, Parte 3](taller_1_parte_3_2018b.md)
- [Taller 1, Parte 4](taller_1_parte_4_2018b.md)

<!---
## Parte 4
<details><summary>Haga click para ver la parte 4</summary>
<p>
 
#### yes, even hidden code blocks!

```python
print("hello world!")
```

</p>
</details>
-->

# Forma de presentación
* Individual

# Forma de calificación
* Una vez entregados los ejercicios por todos los estudiantes, en clase se seleccionarán de la parte 1 tres ejercicios al azar, de la parte 2 tres ejercicios y de la parte 3 cuatro ejercicios al azar, los cuales serán los únicos calificados. Se calificarán por lo tanto solo 10 ejercicios de los presentados.
* Cada ejercicio se califica entre 0.0 y 5.0. La nota final de cada entrega es el promedio de las notas obtenidas en los ejercicios seleccionados.
* En caso que no se haya presentado dicho ejercicio, tendrá una nota de 0 en dicho ejercicio (no importa si se olvidó incluirlo en el correo).
* En caso que se detecte que hay copia o fraude en alguno de los ejercicios presentados (seleccionado o no en clase para calificación) se tendrá como nota un CERO en *todo el Taller 1* (usted y su compañero).
* Sin excepción alguna, por cada día de retraso en la entrega se rebajarán 3 décimas de la nota de dicha entrega.

# Forma de presentación 
Si lo escrito a continuación no se cumple EXACTAMENTE se rebajará una unidad en la entrega. Seré estricto con respecto a esto.

* Se deben entregar archivos `.py` empaquetados en un solo archivo `.zip` (no `.rar` u otro formato) y en una única carpeta.
* La forma de nombrar los archivos será por ejemplo `09_03.py`, lo cual quiere decir que se está entregando el ejercicio 3 del capítulo 9 (observe los ceros). Todos los archivos deben ir en una carpeta cuyo nombre es su código+nombre; algo así como:
```
107011_Pepito_Perez (nombre de la carpeta con guión bajo en vez de espacio)
 |
 |- 07_01.py        (Nombrar de esta forma los archivos del libro de Trejos)
 |- 07_03.py        (OJO al 0 que antecede al 1)
 |- 07_05.py        (observe que son dos dígitos no tres)
 |- 07_07.py
 |- 07_09.py
 |- ...
 |- OVI_011.py      (Nombrar de esta forma los archivos del libro de Oviedo)
 |- OVI_013.py
 |- ...
 |- MGG_090.py      (Nombrar de esta forma los archivos del libro de Marzal-Gracia-García)
 |- MGG_091.py      (OJO al 0 que antecede al 9)
 \- MGG_130.py      (observe que son tres dígitos)
```

# Criterios de calificación
**CONSEJO:** Revisar las notas de como se debe escribir un buen código de programación (ver las diapositivas `07_-_Consejos_de_programacion_y_normas_de_estilo_con_Python_3.pdf`)

* Si el programa no corre o si funciona incorrectamente, se tendrán en cuenta los siguientes criterios de calificación:

  * Si es un **error grave** en la concepción del algoritmo: Nota 0.0.
  * Si es un **error menor** en la concepción del algoritmo (por ejemplo, faltó un espacio de sangrado, se esperaba un número y el usuario entró una cadena, etc), se rebajará la nota de la siguiente forma:
    * Por un error menor: se rebaja la nota en 20%.
    * Por dos errores menores: se rebaja la nota en 40%.
    * Por tres errores menores: se rebaja la nota en 70%.
    * Por cuatro o más menores: NOTA 0.0.
  * El decidir si un programa se encuentra en una categoría o en otra se deja a total criterio del profesor y de los monitores.

* Ortografía:
  * Por cada error de ortografía se rebajará 1 décima en ese ejercicio (para evitar esto se sugiere activar el corrector de ortografía de su ambiente de desarrollo). Se exceptúa escribir en mayúscula la primera letra de cada comentario y poner el punto final a las líneas de los comentarios.
  * No tildar el nombre de las variables o funciones. Tampoco utilizar la ñ mayúscula o minúscula o las diéresis. La violación de esta norma rebaja -0.5 en el ejercicio propuesto. Los comentarios si deben ir con toda la ortografía del caso, es decir, en los comentarios si se puede utilizar la eñe, las tildes y las diéresis.

* Cualquier violación a las siguientes reglas o si el programa hace una de las cosas nombradas a continuación se descontarán **10%** en la nota obtenida del ejercicio:
  * Se debe utilizar un sangrado de 4 espacios (ajustar la configuración en el IDE utilizado).
  * Se debe utilizar codificación UTF-8.
  * Se deben alinear los comentarios, cuando estos se encuentren en filas consecutivas.  

* Cualquier violación a las siguientes reglas o si el programa hace una de las cosas nombradas a continuación se descontarán **20%** en la nota obtenida del ejercicio:
  * Independientemente del libro y del capítulo del libro, utilizar siempre funciones para realizar actividades como detectar el primer dígito, verificar si un número entero es primo, verificar si un número entero es Fibonacci, etc.
  * Cuando utilice funciones, estas deben retornar algún valor; el único lugar donde está permitido imprimir los resultados es en el bloque principal del programa. Se exceptúa el caso que se hace una función que explícitamente está diseñada para imprimir resultados o datos, algo así como `imprimir_matriz(M)`.
  * No se deben utilizar de nombres de identificadores (variables, funciones, listas, etc) inapropiados o sin mucho sentido para quien lo lee (a excepción del programador) y sin comentarios apropiados.  
  * El programa no debe imprimir información sin contexto alguno.
  * El programa no debe estar feo o desordenado en su presentación.
  * El programa no puede exceder en más del 10% del código las 80 columnas (se sugiere activar la opción que muestra la columna 80 en su ambiente de desarrollo)
  * Se debe colocar un comentario informativo al principio de cada programa que indique la misión que debe realizar el programa que se muestra a continuación.
  * En los bloques `try-except` o se debe solicitar de nuevo una entrada o se debe corregir el error hecho por el usuario.
  * Se deben utilizar estructuras `try-except` para evitar que el programa falle debido a entradas no esperadas por parte del usuario.
  * No se deben utilizar comparaciones de variables booleanas contra `True` o `False`, es decir, no se deben hacer comparaciones como `if es_primo == True` (asumiendo que `es_primo` es una variable booleana) ya que son confusas e innecesarias.
  * No se deben utilizar comparaciones contra funciones que retornan `True` o `False`, es decir, no se deben hacer comparaciones como `if es_primo(n) == True` (asumiendo  que `es_primo(n)` es una función que retorna `True` si `n` es primo, de lo contrario retorna `False`) ya que son confusas e innecesarias.
  * No se deben crear funciones que lean la información directamente desde el teclado o que la imprima a la pantalla, excepto si la función se crea explícitamente con el objetivo de leer/imprimir dicha información. Por ejemplo es válido crear funciones como `leer_matriz()` o `imprimir_matriz()`, pero no es válido crear funciones como `es_primo()` la cual imprima desde la misma si un valor dado es primo o no.
  * No se pueden utilizar estructuras `if` similares a:
      ```python
      if num%2 == 0:
          return True
      else:
          return False
      ```
      lo correcto sería:
      ```python
      return num%2 == 0
      ```
      o a
      ```python
      if num%2 == 0:
          es_divisible_2 = True
      else:
          es_divisible_2 = False
      ```
      lo correcto sería:
      ```python
      es_divisible_2 = (num%2 == 0)
      ```
  * No se debe cambiar la variable índice de un ciclo for dentro del mismo ciclo for: ejemplo 
    ```python
    for i in range(5):
       i += 2
    ```  
    o
    ```python
    for i in range(5):
       for i in range(3):
          print(i)
    ```   
      son ciclos for que incumplen la norma anterior.
  
  * No usar variables con asignaciones enteras (como ```es_primo = 1``` o   ```es_primo = 0```) que podrían perfectamente reemplazarse con variables   booleanas (en tal caso la forma correcta sería ```es_primo = True``` o   ```es_primo = False```).    
  
  * REGLAS VALIDAS A PARTIR DE LA *SEGUNDA ENTREGA*:
    * Todas las funciones deben tener un docstring asociado. Estas deben estar contenidas entre `'''` y `'''`. Las `'''` deben ir en reglones separados y estar perfectamente lineadas.  
    * No se debe mezclar o alternar las definiciones de función, importación de módulos y sentencias del programa principal.
    * El programa se debe escribir con secciones perfectamente definidas. Por ejemplo, una sección de entrada de datos, otra de procesamiento de datos y otra de presentación de resultados. Estas secciones se pueden mezclar únicamente cuando la legibilidad del programa se mejore.  
    * No se debe usar la palabra reservada `pass` "indiscriminadamente". Si se utiliza en ciertas construcciones con el objeto de mejorar la claridad del código, esa bien.      

  * REGLAS VALIDAS A PARTIR DE LA *TERCERA ENTREGA*:
    * No escribir código innecesario.
    * No escribir código ineficiente.

* Cualquier violación a las siguientes reglas o si el programa hace una de las cosas nombradas a continuación se descontarán **50%** en la nota obtenida del ejercicio:
  * El programa deberá estar **super comentado**, explicando las razones del porqué de su código, no las implementaciones de su código. Se recomienda leer: 
    * <http://www.variablenotfound.com/2007/12/13-consejos-para-comentar-tu-cdigo.html> 
    *   <https://www.genbeta.com/desarrollo/diez-consejos-para-mejorar-tus-comentarios-de-codigo-fuente>

  * Por favor evite comentarios del tipo:
    ```python
    printf("Hola")   # imprime Hola
    x += 1           # incrementa la variable x en 1
    ```
    ya que son obvios!!. 
  
  * No se deben utilizar variables globales (a menos que sea estrictamente necesario -- se deja a criterio del monitor/profesor).
  * Se prohíbe expresamente cualquier manipulación de un número convirtiéndolo previamente a una cadena de texto. Todas las operaciones con números deben realizarse utilizando operaciones aritméticas. 
  * Cuando una función que retorna el resultado de un cálculo numérico, dicha función no puede retornar cadenas para indicar que hubo un error. Si la función falla, debe fallar con una excepción que usted lance.
  * Se debe informar al usuario sobre todas las situaciones anómalas posibles. El programa no debe quedarse callado frente a ciertas entradas incorrectas o que no producen los resultados esperados.
  * Un bloque `try-except` debe estar únicamente protegiendo la línea susceptible al error.

# Consejo
Si quieren aprender en verdad a programar intenten ustedes mismos hacer los ejercicios de forma autónoma (sin ayuda de los compañeros de clase o de alguien más). Por lo tanto <span style="color: #ff0000;">eviten en lo posible los grupos de trabajo</span>. Se prohíbe cualquier tipo de "colaboración" externa. Aprender a programar es como aprender a nadar. Uno no aprende a nadar viendo los campeonatos de natación en la TV. Hay que tirarse al agua para en verdad volverse un nadador. De alguna forma la sustentación es tan estricta porque solo le otorga los puntos obtenidos si usted le muestra al profesor que adquirió la habilidad para programar.

# Sustentación
* Habrá sustentación de los ejercicios. La sustentación será un examen basado en los ejercicios presentados (no necesariamente los seleccionados anteriormente). La nota de la sustentación básicamente un coeficiente de ponderación de la nota del trabajo, dado por la siguiente figura:

![Imagen](../imagenes/ponderacion_taller1.svg)

```python
import matplotlib.pyplot as plt
plt.figure()
plt.plot([0, 160], [1.5, 1.2], linewidth=3, label='Intento 1')
plt.plot([0, 160], [1.3, 1.0], linewidth=3, label='Intento 2')
plt.plot([0, 160], [1.1, 0.8], linewidth=3, label='Intento 3')
plt.plot([0, 160], [0.9, 0.6], linewidth=3, label='Intento 4')
plt.axis([0, 160, -0.05, 1.55])
plt.title('Factor de ponderación obtenido en la sustentación', fontsize=16)
plt.xlabel('Tiempo utilizado para resolver la sustentación (minutos)', fontsize=12)
plt.ylabel('Factor de ponderación', fontsize=12)
plt.legend()
plt.grid()
plt.savefig("ponderacion_taller1.svg")
plt.show()
```
Habrán 4 intentos para la sustentación. Cada una de ellas durará 160 minutos. En cada intento, el profesor propondrá 3 ejercicios diferentes. La sustentación se considerará aprobada cuando el estudiante resuelva tres de los ejercicios propuestos entre todas las sustentaciones. Por ejemplo usted en el primer intento pudo hacer un ejercicio y en el segundo intento no fue capaz de hacer ningún ejercicio; en el tercer intento hizo dos ejercicios en 80 minutos. Su coeficiente de ponderación será por lo tanto 0.75 ya que así completa los tres ejercicios solicitados.

Si en el caso de terminar los 4 intentos, el estudiante solo hizo dos ejercicios, obtendrá un coeficiente de ponderación de 0.4, si hizo un solo ejercicio, obtendrá un coeficiente de ponderación de 0.2 y si no hizo ninguno, obtendrá un coeficiente de ponderación de CERO. En estos tres casos, no podrá presentar el Taller 2 y obtendrá como nota del Taller 2, la misma nota que obtuvo en el Taller 1.

* La nota del taller estará dada por la siguiente ecuación: 
![Imagen](https://i.imgur.com/6O1iVTE.png)

Asumiendo que Nota 1, Nota 2 y Nota 3 se evalúan sobre 5.0. Con el factor de ponderación de la sustentación, podría obtenerse una nota mayor.

## Fecha y hora de la sustentación
* Oportunidad 1: Marzo 1 de 2019, 6:00am.
* Oportunidad 2: Marzo 8 de 2019, 6:00am (fecha y hora tentativa).

# Nota con respecto al Taller 2
Para poder presentar el Taller 2 se deberán cumplir el siguiente requisito:
* Obtener en la sustentación un factor de ponderación por tiempo mayor o igual a 0.8
En caso que lo anterior no se cumpla se le asignarán 12 nuevos ejercicios; de dicha entrega extra se seleccionarán al azar 3 ejercicios que se computarán con las entregas ya presentados. Adicionalmente, se repetirá la sustentación, previa entrega de los ejercicios adicionales. Esta acción se repetirá hasta que aprueben ambas condiciones. Si al finalizar el semestre no han aprobado dichas condiciones, no podrá presentar el Taller 2 y en ese caso, la nota recibida en el Taller 2 será la misma nota del Taller 1.

# Nota (para Diego)
Imprimir el taller con el comando de consola de Linux:
```bash
for f in MGG_240.py 09_20.py 10_50.py; do
    echo " "
    echo "---------------------------------------------------------------------"
    echo "$f"
    echo "---------------------------------------------------------------------"    
    for dir in *; do
        if test -d "$dir"; then
            cd "$dir"        
            if [ -f $f ]; then
                #echo ">>>> $dir <<<<"
                iconv -c -f utf-8 -t ISO-8859-1 "$f" > "_$f"
                #a2ps "_$f" --silent --prologue=fixed --highlight-level=normal --landscape --tabsize=4 --file-align=fill --header=%c --output="${f%.*}.pdf"
                a2ps "_$f" --silent --prologue=fixed --highlight-level=normal --landscape --tabsize=4 --file-align=fill --header=%c --sides=duplex
                rm "_$f"
            else
                echo "ERROR: El archivo $dir/$f no existe"
            fi
            cd ..
        fi        
    done
done
```
