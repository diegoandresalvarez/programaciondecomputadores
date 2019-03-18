# -*- coding: utf-8 -*-
'''
S N A K E
Por:
Diego Andrés Álvarez Marín (daalvarez@unal.edu.co)
Ver el juego en el que se inspira:
https://www.dosgamesarchive.com/play/nibbles/

INSTRUCCIONES:
Flechas (y las teclas A,S,D,W) mueven la serpiente
ESPACIO pausa
ESCAPE  se sale del juego
'''

# %% se cargan las librerías
import time, sys, pygame
import numpy as np
from random import randrange
from collections import deque

# %% se definen las constantes globales
CABEZA         =      -1    # índice posición de la cabeza en el cuerpo
F,C            =     0,1    # constantes para mejorar legibilidad del código
NUM_CELDAS_A_ALARGAR = 5    # número de celdas a alargar con la cápsula
ANCHO_CASILLA  =      15    # pixeles
COLISION       =    True

# colores del tablero
COLOR_SNAKE1               = (255,   0,   0)
COLOR_SNAKE2               = (  0, 255,   0)
COLOR_MURO                 = (255, 255, 255)
COLOR_FONDO                = ( 80,  80,  80)
COLOR_CAPSULA_ALARGAMIENTO = (  0,   0, 255)

# caracteres utilizados en el mapa para identificar los objetos
CAPSULA_ALARGAMIENTO = '*'
#TUNEL                = 'T'

# se definen las constantes de los movimientos
(QUIETO, DERECHA, ARRIBA, IZQUIERDA, ABAJO) = range(5)

# %% se define el diccionario "serpiente"
serpiente = {
    'alargar'  :    0,          # número de casillas que faltan por alargar
    'nombre'   : None,          # letra que la identifica en el mapa
    'color'    : None,          # color de la serpiente
    'cuerpo'   : None,          # cola (donde se almacena la serpiente)
    'dir'      : None,          # dirección hacia la que avanza
    'marcador' : None,          # puntaje
    'tiempo_entre_mov' : 1/8,   # muévase 8 cuadros por segundo
    'tic'      : time.time(),   # para el cronómetro
    'toc'      : 0,
    'vidas'    : None,          # vidas de la serpiente
}
sammy0 = serpiente.copy()
sammy1 = serpiente.copy()

# %% se define el tablero de juego y otras variables globales relacionadas
mapa = [
"+----------------------------------------------------------------+",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"|                                                                |",
"+----------------------------------------------------------------+"
]
# se convierte el mapa a un array de caracteres de NumPy
try:
    mapa = np.array([list(mapa[i]) for i in range(len(mapa))])
    NFIL, NCOL = mapa.shape  # filas mapa, columnas mapa
except:
    print("Error en la definición del mapa")
    sys.exit(-1)

copia_mapa = mapa.copy() # crear una copia para cuando toque reiniciar

# %% se definen las funciones
def imprimir_casilla(pos, color):
    ''' imprima en la posición "pos" un recuadro de color "color"
    '''
    f,c = pos
    casilla = pygame.Rect(c*ANCHO_CASILLA, f*ANCHO_CASILLA,
                          ANCHO_CASILLA, ANCHO_CASILLA)
    pygame.draw.rect(ventana, color, casilla)


def imprimir_mapa(m):
    ''' imprime el mapa "m", para propósitos de depuración del código
    '''
    for f in m[:]:
        print (''.join(f))


def reiniciar_nivel():
    ''' pone el mapa original (borrar el tablero)
    '''
    global mapa, sammy0, sammy1

    mapa = copia_mapa.copy()

    # se crean/inicializan de nuevo las serpientes
    sammy0['nombre'] = '0'
    sammy0['color']  = COLOR_SNAKE1
    sammy0['cuerpo'] = deque([( 8,9),( 8,10),( 8,11)]) # cola, cuerpo, cabeza
    sammy0['dir']    = QUIETO
    sammy0['tiempo_entre_mov'] = 1/8  # muévase 8 cuadros por segundo
    idx = np.array(sammy0['cuerpo'])
    mapa[idx[:,0], idx[:,1]] = sammy0['nombre']

    sammy1['nombre'] = '1'
    sammy1['color']  = COLOR_SNAKE2
    sammy1['cuerpo'] = deque([(16,9),(16,10),(16,11)]) # cola, cuerpo, cabeza
    sammy1['dir']    = DERECHA
    sammy1['tiempo_entre_mov'] = 1/8  # muévase 8 cuadros por segundo
    idx = np.array(sammy1['cuerpo'])
    mapa[idx[:,0], idx[:,1]] = sammy1['nombre']


def inicializar_serpientes_y_tablero():
    ''' inicializa de nuevo las serpientes y el tablero
    '''
    global sammy0, sammy1

    reiniciar_nivel()

    # inicializar vidas y marcador de serpientes
    sammy0['marcador'] = sammy1['marcador'] = 0
    sammy0['vidas']    = sammy1['vidas']    = 3


def pintar_tablero():
    ''' borra la pantalla y pinta los muros, las serpientes y la cápsula
    '''
    ventana.fill(COLOR_FONDO)

    for f in range(NFIL):
        for c in range(NCOL):
            pos = f,c
            if mapa[pos] == ' ':
                # si hay un espacio vacío no haga nada
                pass
            elif mapa[pos] in ['-', '|', '+']:
                imprimir_casilla(pos, COLOR_MURO)
            elif mapa[pos] == sammy0['nombre']:
                imprimir_casilla(pos, sammy0['color'])
            elif mapa[pos] == sammy1['nombre']:
                imprimir_casilla(pos, sammy1['color'])
            elif mapa[pos] == CAPSULA_ALARGAMIENTO:
                imprimir_casilla(pos, COLOR_CAPSULA_ALARGAMIENTO)
            else:
                pygame.quit()    # finalice el modo PYGAME
                print("Error en la especificación del laberinto")
                print("El mapa de juego es:\n")
                imprimir_mapa(mapa)
                sys.exit(-1)

    # Actualizar la pantalla
    pygame.display.update()


def mover_serpiente(s, dir_sgte):
    ''' mueve la serpiente "s" en la dirección "dir_sgte"
    '''
    global capsula_alargamiento

    colision = False  # hubo colisión contra una serpiente, o contra un muro

    # coordenadas de la cabeza de la serpiente
    f,c = s['cuerpo'][CABEZA]

    # actualizar direcciones (teniendo en cuenta que no se puede retroceder)
    if dir_sgte == QUIETO:
        return # detener la serpiente
    elif ((dir_sgte == DERECHA   and s['dir'] != IZQUIERDA) or
          (dir_sgte == ARRIBA    and s['dir'] != ABAJO)     or
          (dir_sgte == IZQUIERDA and s['dir'] != DERECHA)   or
          (dir_sgte == ABAJO     and s['dir'] != ARRIBA)):
            s['dir'] = dir_sgte

    # actualizar los movimientos
    if    s['dir'] == QUIETO:                       pass # no hacer nada
    elif (s['dir'] == DERECHA)   and (c < NCOL-1):  c += 1
    elif (s['dir'] == ARRIBA)    and (f>0):         f -= 1
    elif (s['dir'] == IZQUIERDA) and (c>0):         c -= 1
    elif (s['dir'] == ABAJO)     and (f<NFIL-1):    f += 1

    if mapa[f,c] in [ sammy0['nombre'], sammy1['nombre'], '-', '|', '+' ]:
        colision = True
        # se chocó contra otra serpiente, contra sí misma o contra un muro
        if   mapa[f,c] == sammy0['nombre']:
            print(f"Perdió sammy{s['nombre']}: se chocó contra sammy0")
        elif mapa[f,c] == sammy1['nombre']:
            print(f"Perdió sammy{s['nombre']}: se chocó contra sammy1")
        elif mapa[f,c] in [ '-', '|', '+' ]:
            print(f"Perdió sammy{s['nombre']}: se chocó contra un muro")
        print("Presiona espacio para continuar ... ")

        # Actualizar la pantalla
        pygame.display.update()

        salirse_ciclo = False
        while not salirse_ciclo:
            for event in pygame.event.get():
                # si se presiona una tecla:
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_SPACE:
                        salirse_ciclo = True

        # perdió una vida
        s['vidas'] -= 1

        if s['vidas'] != 0:
            reiniciar_nivel()
            capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO)
            pintar_tablero()
    elif mapa[f,c] == ' ' or mapa[f,c] == CAPSULA_ALARGAMIENTO:
        if mapa[f,c] == CAPSULA_ALARGAMIENTO:
            capsula_alargamiento['comida'] = True
            s['alargar'] = NUM_CELDAS_A_ALARGAR
            s['marcador'] += 1

        # poner la cabeza
        poner_cabeza_serpiente(s, celda=(f,c))

        # quitar la cola (o alargar si es necesario)
        if s['alargar'] > 0:
            s['alargar'] -= 1
        else:
            quitar_cola_serpiente(s)

    # Actualizar vidas y marcadores
    print(f"SAMMY{s['nombre']}: {s['vidas']} vidas, {s['marcador']} puntos")
    return colision


def poner_cabeza_serpiente(s, celda):
    ''' coloca la cabeza de la serpiente "s" en la celda "celda" e imprimirla
    '''
    s['cuerpo'].append(celda)
    mapa[celda] = s['nombre']
    imprimir_casilla(celda, s['color'])


def quitar_cola_serpiente(s):
    ''' remuever la cola de la serpiente "s" e imprimir la casilla vacía
    '''
    celda = s['cuerpo'].popleft()
    mapa[celda] = ' '
    imprimir_casilla(celda, COLOR_FONDO)


def poner_capsula(tipo_capsula):
    ''' pone la capsula aleatoriamente en el tablero
    '''
    # busque una posición vacía y al azar para la cápsula
    while True:
        pos = randrange(NFIL), randrange(NCOL) # números aleat. entre 0 y NFIL-1
        if mapa[pos] == ' ':
            break

    # se pone el caracter en el tablero
    mapa[pos] = tipo_capsula

    # se retorna la capsula generada
    return {'comida': False, 'pos': pos}


def mover_automaticamente(s):
    ''' mueve la serpiente "s" utilizando una búsqueda inteligente.

    Aquí se esta implementando el algoritmo *Breadth-first search*, para
    encontrar el camino mas corto entre la cápsula y la cabeza de la serpiente,
    la cual se ubica en "pos_ini".

    Ver: http://en.wikipedia.org/wiki/Breadth-first_search
    '''
    f_ini, c_ini = pos_ini = s['cuerpo'][CABEZA]

    # se crea una copia del tablero
    L = mapa.copy()

    # cree una array entero de NFIL x NCOL x 2 lleno de -100s
    referente = np.full((NFIL,NCOL,2), -100, dtype=int)

    # si esta a una casilla de distancia ...
    if capsula_alargamiento['pos'][F] == f_ini:
       if (capsula_alargamiento['pos'][C] - c_ini ==  1): return DERECHA
       if (capsula_alargamiento['pos'][C] - c_ini == -1): return IZQUIERDA

    if capsula_alargamiento['pos'][C] == c_ini:
       if (capsula_alargamiento['pos'][F] - f_ini ==  1): return ABAJO
       if (capsula_alargamiento['pos'][F] - f_ini == -1): return ARRIBA

    # El nodo "pos_ini" es el principio, no tiene un anterior
    referente[pos_ini] = (-1, -1)

    # crear cola y agregarle el nodo inicial
    qq = deque([pos_ini])

    # hacer el ciclo hasta que no hayan más nodos vecinos que revisar
    while len(qq) != 0:
        # se saca el elemento de la cola
        f_actual, c_actual = actual = qq.popleft()

        # revisar los vecinos del nodo_actual
        for dir in [DERECHA, ARRIBA, IZQUIERDA, ABAJO]:
            if   dir == DERECHA:    sgte = (f_actual,     c_actual + 1)
            elif dir == ARRIBA:     sgte = (f_actual - 1, c_actual    )
            elif dir == IZQUIERDA:  sgte = (f_actual,     c_actual - 1)
            elif dir == ABAJO:      sgte = (f_actual + 1, c_actual    )

            # si se salió del laberinto, siga con el siguiente ciclo
            if not ((0 <= sgte[F] < NFIL) and (0 <= sgte[C] < NCOL)):
                continue

            # si el nodo sgte no ha sido visitado:
            if L[sgte] == ' ':
                # la referente de la celda sgte es la celda actual
                referente[sgte] = actual
                L[sgte] = '.'
                #imprimir_mapa(L)
                #pygame.time.wait(10)
                qq.append(sgte)

            # si encontramos la cápsula de alargamiento, retornar la dirección
            elif L[sgte] == CAPSULA_ALARGAMIENTO:
                referente[sgte] = actual
                while True:
                    #L[tuple(actual)] = '#' # para propósitos de depuración
                    #imprimir_mapa(L)
                    #print(actual)
                    #pygame.time.wait(10)
                    oldactual = actual
                    actual = referente[tuple(oldactual)]
                    if np.all(referente[tuple(actual)] == (-1,-1)):
                        break

                if actual[F] < oldactual[F]: return ABAJO
                if actual[F] > oldactual[F]: return ARRIBA
                if actual[C] < oldactual[C]: return DERECHA
                if actual[C] > oldactual[C]: return IZQUIERDA

    # se exploro todo el laberinto pero no se encontró la salida, por lo tanto
    # quedese quieto (esto quiere decir que no hay una salida)
    return QUIETO

# %%###### ########## ######## PROGRAMA PRINCIPAL ######## ########## #########
# %% Se inicializa el modo PYGAME
pygame.init()
ventana = pygame.display.set_mode((NCOL*ANCHO_CASILLA,
                                   NFIL*ANCHO_CASILLA)) # ventana de juego
pygame.display.set_caption('S N A K E')       # título de la ventana
reloj = pygame.time.Clock()                   # reloj

# %% se inicializan las serpientes y el tablero de juego
inicializar_serpientes_y_tablero()
capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO)
pintar_tablero()

proxima_dir = [sammy0['dir'], sammy1['dir']] # direcciones del próx. movimiento
dir_mov0 = dir_mov1 = QUIETO

# Inicializar el cronometro de las serpientes
for s in [sammy0, sammy1]:
    s['tic'] = time.time()

salirse_del_juego = False

while (sammy0['vidas']>0) and (sammy1['vidas']>0) and (not salirse_del_juego):
    # mover las serpientes
    for i,s in enumerate([sammy0, sammy1]):
        s['toc'] = time.time()
        tiempo = s['toc'] - s['tic']
        if tiempo > s['tiempo_entre_mov']:
            if mover_serpiente(s, proxima_dir[i]) == COLISION:
                break # ya que si fue sammy0, no tiene sentido mover sammy1
            s['tic'] = time.time()

    # si se comieron la capsula de alargamiento, generar una nueva
    if capsula_alargamiento['comida']:
        capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO)
        imprimir_casilla(capsula_alargamiento['pos'], COLOR_CAPSULA_ALARGAMIENTO)

    # Actualizar la pantalla
    pygame.display.update()

    # leer el teclado
    for event in pygame.event.get():
        # si se presiona con el mouse la X de la ventana:
        if event.type == pygame.QUIT:
            salirse_del_juego = True

        # si se presiona una tecla:
        if event.type == pygame.KEYDOWN:
            if event.key in [pygame.K_ESCAPE, pygame.K_q]:
                salirse_del_juego = True
            if event.key in [pygame.K_UP,     pygame.K_w]: # HACIA ARRIBA
                dir_mov0 = ARRIBA
            if event.key in [pygame.K_DOWN,   pygame.K_s]: # HACIA ABAJO
                dir_mov0 = ABAJO
            if event.key in [pygame.K_LEFT,   pygame.K_a]: # HACIA LA IZQUIERDA
                dir_mov0 = IZQUIERDA
            if event.key in [pygame.K_RIGHT,  pygame.K_d]: # HACIA LA DERECHA
                dir_mov0 = DERECHA
            if event.key == pygame.K_SPACE:                # HACER UNA PAUSA
                # FALTA IMPLEMENTAR
                pass

    # si la dirección tentativa de movimiento no es quieto, seguirla,
    # de lo contrario, seguir la inercia
    #dir_mov0 = mover_automaticamente(sammy0)
    dir_mov1 = mover_automaticamente(sammy1)
    #dir_mov1 = QUIETO

    if (dir_mov0 != QUIETO): proxima_dir[0] = dir_mov0
    if (dir_mov1 != QUIETO): proxima_dir[1] = dir_mov1

    # número de cuadros/segundo en la animación
    tiempo_entre_ciclos = reloj.tick_busy_loop(30)

# %% BYE, BYE!
pygame.quit()    # finalice el modo PYGAME

