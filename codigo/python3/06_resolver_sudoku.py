# Solucionador de SUDOKUS utilizando el algoritmo BACKTRACKING
#
# La lógica detrás de este algoritmo es la misma que utilizamos para salir de un
# laberinto:
# * Intentamos una solución posible
# * Si dicha solución es mala, nos devolvemos, hasta el punto que podamos
#   ensayar otra solución
# * Repita hasta que salgamos del laberinto. Si regresamos a la salida, es
#   porque no había solución
#
# En nuestro caso:
# The algorithm tries a value, then optimistically recurs on the next cell and
# checks if the solution (as built up so far) is valid. If, at some later point
# in execution, it is determined that what was built so far will not solve the
# problem, the algorithm backs up the stack to a state in which there could be
# another valid solution.
#
# Tomado de:
# http://spin.atomicobject.com/2012/06/18/solving-sudoku-in-c-with-recursive-backtracking/
# http://en.wikipedia.org/wiki/Sudoku_solving_algorithms*
# http://en.wikipedia.org/wiki/Backtracking

import time

# Declaración de variables globales
# SUDOKU super difícil:
# http://en.wikipedia.org/wiki/User_talk:170.115.251.13/Su_Doku
#t = [[0, 0, 0, 0, 0, 0, 0, 0, 0],  # tablero a resolver (SUPER DURO)
#     [0, 0, 0, 0, 0, 3, 0, 8, 5],  # en mi PC se demora:
#     [0, 0, 1, 0, 2, 0, 0, 0, 0],  # Lenguaje C: 3.1 seg (compilado con -O3)
#     [0, 0, 0, 5, 0, 7, 0, 0, 0],  # Python 3:   868.27 seg (14.5 min)
#     [0, 0, 4, 0, 0, 0, 1, 0, 0],  # Python 3 es 280 veces más lento que C
#     [0, 9, 0, 0, 0, 0, 0, 0, 0],
#     [5, 0, 0, 0, 0, 0, 0, 7, 3],
#     [0, 0, 2, 0, 1, 0, 0, 0, 0],
#     [0, 0, 0, 0, 4, 0, 0, 0, 9]]

t = [[3, 0, 6, 5, 0, 8, 4, 0, 0],  # tablero a resolver (FÁCIL)
     [5, 2, 0, 0, 0, 0, 0, 0, 0],  # Python 3 = 0.01 segundos
     [0, 8, 7, 0, 0, 0, 0, 3, 1],
     [0, 0, 3, 0, 1, 0, 0, 8, 0],
     [9, 0, 0, 8, 6, 3, 0, 0, 5],
     [0, 5, 0, 0, 9, 0, 6, 0, 0],
     [1, 3, 0, 0, 0, 0, 2, 5, 0],
     [0, 0, 0, 0, 0, 0, 0, 7, 4],
     [0, 0, 5, 2, 0, 6, 3, 0, 0]]


# Declaración de funciones
def imprimir_tablero():
    '''
    Imprime el tablero del sudoku
    '''
    for i in range(9):
        print(t[i])


def usado_en_fila(fil, num):
    '''
    Retorna True si el numero "num" ya se puso en la fila "fil"
    '''
    for j in range(9):
        if t[fil][j] == num: return True

    return False


def usado_en_columna(col, num):
    '''
    Retorna True si el numero "num" ya se uso en la columna "col"
    '''
    for i in range(9):
        if t[i][col] == num: return True

    return False

def usado_en_caja(x, y, num):
    '''
    Retorna True si el numero "num" ya se uso en la caja con borde sup izq "x,y"
    '''
    for i in range(3):
        for j in range(3):
            if t[i+x][j+y] == num: return True

    return False


def se_puede_colocar(i, j, num):
    '''
    Retorna True si se puede colocar num en la posición "i,j"
    '''
    return not usado_en_fila(i, num) and not usado_en_columna(j, num) and not usado_en_caja(i-i%3, j-j%3, num)


def sudoku(i, j):
    if i == 9: return True  # lo resolvimos!!!, ya que i = 0..8

    # si la casilla i,j está ocupada, intentar la siguiente casilla.
    if t[i][j]:
        if j == 8:
            # intentar la siguiente fila,    si se resuelve retornar TRUE
            if sudoku(i+1, 0): return True
        else:
            # intentar la siguiente columna, si se resuelve retornar TRUE
            if sudoku(i, j+1): return True

        return False  # como no se pudo resolver, retornar FALSE

    # como la casilla está vacía, intente todos los números en esta celda
    for num in range(1,10):  # 1 .. 9
        if se_puede_colocar(i, j, num):
            t[i][j] = num # proponer una solución

            # Ensayar resolver el SUDOKU con la solución propuesta
            if (j == 8):
                # intentar la siguiente fila,    si se resuelve retornar TRUE
                if sudoku(i+1, 0): return True
            else:
                # intentar la siguiente columna, si se resuelve retornar TRUE
                if sudoku(i, j+1): return True

            # como la solución no funcionó, deshacer e intentar de nuevo
            t[i][j] = 0

    return False # no se pudo resolver después de intentar todos los números


# Procedimiento principal
tic = time.time()
if sudoku(0, 0):
    imprimir_tablero()
else:
    print('El tablero no tiene solución')
toc = time.time()

print('Tiempo de cálculo empleado (segundos) = ', toc - tic)
