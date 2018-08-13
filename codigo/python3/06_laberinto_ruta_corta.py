# -*- coding: utf-8 -*-

# Programa para encontrar la salida de laberintos. Encuentra la ruta más corta
# utilizando para ello el algoritmo "breadth-first search"
# http://en.wikipedia.org/wiki/Breadth-first_search

from collections import deque

# Se definen las constantes y otros caracteres especiales
VACIO     = ' ' # nunca se ha visitado
PRINCIPIO = 'P'
FIN       = 'F'
VISITADO  = '.' # visitado pero no es el camino correcto
OK        = 'o' # camino correcto
COL       = 29  # número de columnas del laberinto
FIL       = 18  # número de filas del laberinto

# Se define el laberinto
L = [ "#############################",
      "P #     #   #   #     #   # #",
      "# # ### ### # # # ### ### # #",
      "# # #       # # # #       # #",
      "# #   ### # # # #   ### # # #",
      "# # # #   # # # # # #   # # F",
      "#   # # # # # #   # # # # # #",
      "##### # # # # ##### # # # # #",
      "#     # # #   #     # # #   #",
      "# #     #   # # #     #   # #",
      "# # ### ### # # # ### ### # #",
      "# # #       # # # #       # #",
      "# #   ### # # # #   ### # # #",
      "# # # #   # # # # # #   # # #",
      "#   # # # # # #   # # # # # #",
      "##### # # # # ##### # # # # #",
      "#     # # #   #     # # #   #",
      "#############################" ]

def resolver():
    # Encuentra el comienzo del laberinto y desde allí comienza la búsqueda
    try:
        for i in range(FIL):
            for j in range(COL):
                if L[i][j] == PRINCIPIO:
                    raise #Encontre_el_Principio
        else:
            print('El laberinto no tiene un principio')
            return False
    except: #Encontre_el_Principio:
       pass

    # crear la matriz referente
    referente = [[None for j in range(COL)] for i in range(FIL)]

    # El nodo [i][j] es el principio, no tiene una celda referente
    referente[i][j] = (-1, -1)

    # crear cola e inicializarla al principio, el cual está en (i,j)
    q = deque([(i,j)])

    # hacer el ciclo hasta que no haya más nodos vecinos que revisar
    while len(q) != 0:
        # Se saca el elemento de la cola
        actual = q.popleft()

        #revisar los vecinos del actual (fila, col)
        for sgte in [ (actual[0],   actual[1]+1),   # derecha
                      (actual[0]-1, actual[1]),     # arriba
                      (actual[0],   actual[1]-1),   # izquierda
                      (actual[0]+1, actual[1])   ]: # abajo

            # si sgte se salió del laberinto, continue con el siguiente ciclo
            if not (0 <= sgte[0] < FIL and 0 <= sgte[1] < COL):
                continue

            # si el sgte no ha sido visitado
            if L[sgte[0]][sgte[1]] == VACIO:
                # la referente de la celda siguiente es la celda actual
                referente[sgte[0]][sgte[1]] = actual
                L[sgte[0]][sgte[1]] = VISITADO
                q.append(sgte)
            # si encontramos el final, salirse y pintar el camino
            elif L[sgte[0]][sgte[1]] == FIN:
                pasos = 0
                while True:
                    pasos += 1
                    L[actual[0]][actual[1]] = OK
                    actual = referente[actual[0]][actual[1]]
                    if referente[actual[0]][actual[1]] == (-1,-1):
                        break
                print('Solución encontrada en %d pasos\n\n' % pasos)
                return True

    # se exploró todo el laberinto pero no se encontró la salida
    return False

########################### PROGRAMA PRINCIPAL ###########################

# Se convierte el laberinto a una lista
for i in range(FIL):
    L[i] = list(L[i])

if resolver():
    # Se imprime el laberinto
    for i in range(FIL):
        L[i] = ''.join(L[i])
        #print(L[i])
        print(L[i].replace('#', chr(0x2588)))  # ponga el bloque en vez del #
else:
    print('El laberinto no tiene solución')
