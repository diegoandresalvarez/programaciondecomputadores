# -*- coding: utf-8 -*-
"""
    BUSCAMINAS
    Con espacio marca/desmarca la mina
    Con las flechas se mueve
    Con ENTER destapa
    Con ESCAPE se sale del juego

    Instale la librería curses en WINDOWS con:
    python -m pip install windows-curses
"""

import random
import curses
import numpy as np
import sys

# %% Constantes
ESCAPE = 27
ENTER  = 10

MAXFIL, MAXCOL = 12, 14
NMINAS = 20

# %% Variables globales
destapado = np.zeros((MAXFIL, MAXCOL), dtype=bool)  # = False
protegido = np.zeros((MAXFIL, MAXCOL), dtype=bool)  # = False
esmina    = np.zeros((MAXFIL, MAXCOL), dtype=bool)  # = False


# %%
def suma_alrededor(f, c):
    i = j = suma = 0

    # para evitar contar fuera de los bordes de la matriz esmina[][]
    fmin, fmax = max(f-1, 0), min(f+1, MAXFIL-1)
    cmin, cmax = max(c-1, 0), min(c+1, MAXCOL-1)

    for i in range(fmin, fmax+1):
        for j in range(cmin, cmax+1):
            suma += esmina[i, j]

    return suma


# %%
def destapar(f, c):
    if (f < 0) or (f > MAXFIL-1) or (c < 0) or (c > MAXCOL-1):
        return False

    if destapado[f, c] or protegido[f, c]:
        return False

    if esmina[f, c]:  # exploto la mina!!
        # mostrar todas las minas
        stdscr.attron(curses.A_BOLD | curses.A_REVERSE)  # activar negrilla
        for i in range(MAXFIL):
            for j in range(MAXCOL):
                if esmina[i, j]:
                    # extraer caracter de la posición
                    ch = stdscr.inch(i, j)

                    # solo obtener el caracter como tal, y vuelva a pintarlo
                    stdscr.addch(i, j, ch & curses.A_CHARTEXT)

        stdscr.attroff(curses.A_BOLD | curses.A_REVERSE)  # desactivar negrilla

        stdscr.attron(curses.color_pair(1))
        stdscr.addstr(MAXFIL, 0, "Perdiste :-(")
        stdscr.attroff(curses.color_pair(1))

        stdscr.refresh()                    # actualizar la pantalla
        stdscr.getch()                      # presione una tecla para salir
        curses.endwin()                     # terminar el modo ncurses
        quit()

    destapado[f, c] = True

    suma = suma_alrededor(f, c)
    if suma == 0:
        stdscr.addch(f, c, ' ')
        destapar(f-1, c-1);    destapar(f, c-1);    destapar(f+1, c-1)
        destapar(f-1, c);                           destapar(f+1, c)
        destapar(f-1, c+1);    destapar(f, c+1);    destapar(f+1, c+1)
    else:
        stdscr.addch(f, c, str(suma))  # imprima numero de minas alrededor

    stdscr.move(f, c)

    return True


# %% Programa principal
stdscr = curses.initscr()       # entrada al modo curses

if not curses.has_colors():
    curses.endwin()
    print("Este computador no puede mostrar colores", file=sys.stderr)
    quit()

curses.start_color()                # start color
curses.init_pair(1, curses.COLOR_RED, curses.COLOR_WHITE)

# permitir utilizar teclas especiales como las flechas
stdscr.keypad(True)

curses.noecho()        # no muestre el caracter en pantalla cuando use getch()
curses.curs_set(0)     # hacer el cursor invisible

# inicializar el tablero
for i in range(MAXFIL):
    for j in range(MAXCOL):
        stdscr.addch(i, j, '.')

f, c = MAXFIL//2, MAXCOL//2
stdscr.addch(f, c, '#')  # este es el cursor
stdscr.move(f, c)
stdscr.refresh()

random.seed()  # active la semilla del generador de números aleatorios

# Crear minas
for k in range(NMINAS):
    i, j = random.randrange(MAXFIL), random.randrange(MAXCOL)
    esmina[i, j] = True

# procesar entrada del teclado
while True:
    # se almacena al posición del cursor antes de moverlo
    fcur, ccur = f, c         # se guarda la posición actual del cursor
    ch = stdscr.getch()
    if ch == curses.KEY_LEFT:
        if (c > 0):        c -= 1
    elif ch == curses.KEY_RIGHT:
        if (c < MAXCOL-1): c += 1
    elif ch == curses.KEY_UP:
        if (f > 0):        f -= 1
    elif ch == curses.KEY_DOWN:
        if (f < MAXFIL-1): f += 1
    elif ch == ENTER:    # destapar
        destapar(f, c)
    elif ch == ord(' '):      # proteger (sino esta destapado)
        if not destapado[f, c]:
            protegido[f, c] = not protegido[f, c]
    elif ch == ESCAPE:
        curses.endwin()  # terminar el modo curses
        quit()

    # graficar de nuevo la casilla donde estaba el cursor después de moverlo
    if protegido[fcur, ccur]:
        stdscr.addch('*')
    else:  # no protegido
        if destapado[fcur, ccur]:
            suma = suma_alrededor(fcur, ccur)
            if suma == 0:
                stdscr.addch(' ')
            else:
                stdscr.addch(str(suma))
        else:
            stdscr.addch('.')

    stdscr.addch(f, c, '#')  # poner el cursor en la nueva posición
    stdscr.move(f, c)
    stdscr.refresh()        # actualizar la pantalla
    # verificar si todas las minas están marcadas y no hay casillas limpias
    # incorrectamente marcadas
    todas_minas_marcadas = True
    for i in range(MAXFIL):
        for j in range(MAXCOL):
            if esmina[i, j] != protegido[i, j]:
                todas_minas_marcadas = False
                break
        if not todas_minas_marcadas:
            break

    if todas_minas_marcadas:
        break

stdscr.attron(curses.A_BLINK)
stdscr.addstr(MAXFIL, 0, "Ganaste :-)")
stdscr.attroff(curses.A_BLINK)
stdscr.refresh()        # actualizar la pantalla
stdscr.getch()          # presione una tecla para salir
curses.endwin()         # terminar el modo curses
