# Basado en el código: http://labix.org/snippets/labsolver

import copy

# Se definen las constantes y otros caracteres especiales
VACIO     = ' ' # nunca se ha visitado
PRINCIPIO = 'P'
FIN       = 'F'
VISITADO  = '.' # visitado pero no es el camino correcto
OK        = 'o' # camino correcto
COL       = 29  # número de columnas del laberinto
FIL       = 18  # número de filas del laberinto

# Se define el laberinto
L = ["#############################",
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
     "#############################"]


def imprimir_laberinto(r=None, s=None):
    # Se imprime el laberinto
    LAB = copy.deepcopy(L)

    if r is not None and s is not None:
        LAB[r][s] = 'x'

    for i in range(FIL):
        LAB[i] = ''.join(LAB[i])
        print(LAB[i].replace('#', chr(0x2588)))  # ponga el bloque en vez del #


def resolver():
    # Pararse en la posición (i,j) moverse desde esta posición hacia la
    # derecha, abajo, izquierda o arriba, en ese orden
    # Esta función devuelve TRUE si a partir de la posición "i,j" se pudo mover
    # y devuelve FALSE si se llegó al final de un camino y se tuvo que devolver
    def _resolver(i, j):
        # si se sale del laberinto, devuélvase una posición e intente de nuevo
        if not (0 <= j < COL) and (0 <= i < FIL):
            return False

        posactual = L[i][j]

        input()
        imprimir_laberinto(i,j)

        # si chocamos contra un muro o llegamos a una casilla ya visitada
        if posactual == '#' or posactual == VISITADO:
            return False

        if posactual == FIN:  # llegamos a la salida
            return True

        if posactual == VACIO or posactual == PRINCIPIO:
            if posactual == VACIO:
                L[i][j] = VISITADO    # señalar que aquí estuve

            # Mover en las direcciones
            #   derecha              abajo                izquierda            arriba
            if _resolver(i, j+1) or _resolver(i+1, j) or _resolver(i, j-1) or _resolver(i-1, j):
                # si en alguna de las posiciones circundantes hay salida, decir
                # que hubo exito y retornar un verdadero
                if posactual == VACIO:
                    L[i][j] = OK
                return True  # movimiento OK
            else:
                # en ninguna de las posiciones alrededor hay salida, por lo
                # que toca devolverse una posición e intentar de nuevo
                return False

    encontrado = False

    # Se buscan "los" principios del laberinto.
    for i in range(FIL):
        for j in range(COL):
            if L[i][j] == PRINCIPIO:
                # se parte de ese principio
                encontrado = encontrado or _resolver(i, j)

    return encontrado


########################### PROGRAMA PRINCIPAL ###########################

# Se convierte el laberinto a una lista
for i in range(FIL):
    L[i] = list(L[i])

if resolver():
    imprimir_laberinto()
else:
    print('El laberinto no tiene solución')
