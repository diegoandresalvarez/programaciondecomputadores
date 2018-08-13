# Programa adaptado de: http://inventwithpython.com/chapter17.html

import sys
import pygame
from math import pi
from pygame.locals import QUIT # aquí están definidas QUIT, K_ESCAPE


# %% Se definen los colores -- hay dos formas de hacerlo:
# a) con tuplas
NEGRO    = (0,     0,   0)    # R,G,B 0..255
BLANCO   = (0xFF, 0xFF, 0xFF)
ROJO     = (255,   0,   0)
VERDE    = (  0, 128,   0)
GRIS     = (128, 128, 128)
PURPURA  = (128,   0, 128)

# b) con el comando pygame.Color
AMARILLO = pygame.Color(255, 255,   0) # R,G,B
AZUL     = pygame.Color(  0,   0, 255)

# %%Se inicializa el modo pygame
pygame.init()


# %%Se crea el lienzo: (ancho, alto) = en pixeles
# ventana será un objeto de tipo pygame.Surface
ventana = pygame.display.set_mode((400, 300))

# %%Se coloca el título a la ventana
pygame.display.set_caption('Hola mundo')

# %%Se pone el color de fondo
ventana.fill(BLANCO)

# %% FORMAS

# Se dibujan unas línea (ventana, color, coord ini, coord fin, ancho en pixeles)
# Si no se especifica el ancho de la línea, será 1 pixel
for i in range(1, 90, 10):
    pygame.draw.line(ventana, ROJO, (60, i), (160, i), i//10)

# Se dibujan círculos, elipses rectángulos y polígonos
pygame.draw.circle(ventana, AZUL, (200, 230), 50, 0)    # centro, radio, ancho
pygame.draw.ellipse(ventana, VERDE, (250,200,80,40), 4) # top left, top right, width, height, ancho línea
pygame.draw.rect(ventana, NEGRO, (60, 210, 100, 50), 1)    # x0, y0, ancho, alto, (ancho_línea=0)
pygame.draw.polygon(ventana, PURPURA, ((300, 20), (200, 20), (220, 80), (250,100)))
# En las figuras anteriores un ancho de línea de 0, quiere decir que se rellena

# Dibuja una secuencia de líneas
pygame.draw.lines(ventana, NEGRO, False, [[0, 80], [50, 90], [200, 80], [220, 30]], 5)

# Lineas con y sin aliasing
# aaline(Surface, color, startpos, endpos, blend=1) -> Rect
# Draws an anti-aliased line on a surface. This will respect the clipping
# rectangle. A bounding box of the affected area is returned as a rectangle.
# If blend is true, the shades will be be blended with existing pixel shades
# instead of overwriting them.
pygame.draw.aaline(ventana, VERDE, [50, 50], [100, 80], True)
pygame.draw.aaline(ventana, VERDE, [50, 55], [100, 85], False)
pygame.draw.line  (ventana, VERDE, [50, 60], [100, 90], 1)


# Dibuje unos arcos
# arc(Surface, color, Rect, start_angle, stop_angle, width=1) -> Rect
pygame.draw.arc(ventana, NEGRO, [210, 75, 150, 125], 0,      pi/2,   2)
pygame.draw.arc(ventana, VERDE, [210, 75, 150, 125], pi/2,   pi,     2)
pygame.draw.arc(ventana, AZUL,  [210, 75, 150, 125], pi,     3*pi/2, 2)
pygame.draw.arc(ventana, ROJO,  [210, 75, 150, 125], 3*pi/2, 2*pi,   2)

# %% FUENTES

# Se configuran las fuentes
# El primer parámetro es la fuente (aquí se está usando la que está por defecto)
# El segundo parámetro es el tamaño de la fuente.
# fuente es un objeto "pygame.font.Font"
fuente = pygame.font.SysFont(None, 48)

# Se configura el texto
# Texto, AliasedText=True/False, ForegroundColor, BackgroundColor
# texto es un objeto "pygame.Surface"
texto = fuente.render('Hola a tod@s!', True, ROJO, AZUL)

# get_rect() es un método de las clases pygame.font.Font y pygame.Surface
# retornan objectos pygame.Rect, para representar el tamaño y la posición de
# la fuente o la superficie
textoRect = texto.get_rect()
textoRect.centerx = ventana.get_rect().centerx
textoRect.centery = ventana.get_rect().centery

# Se hace un rectángulo que contenga el texto
pygame.draw.rect(ventana, ROJO, (textoRect.left - 20, textoRect.top - 20,
                                textoRect.width + 40, textoRect.height + 40), 1)

# Se dibuja el texto en el lienzo
# El método blit() dibuja los contenidos de un objeto Surface en otro objeto
# Surface. El primer argumento dice que dibujar, el segundo argumento dice la
# ubicación
ventana.blit(texto,textoRect)

# %% MODIFICANDO PIXELES

ventana.set_at((380,280), ROJO)

# Obtener un pixel array de la ventana
# El objeto PixelArray es una lista de listas de tuplas de colores que
# representan al objeto ventana
pixArray = pygame.PixelArray(ventana)

# El pixel (380,280) se dibujará de color ROJO, etc...
#pixArray[380][280] = ROJO
pixArray[390][280] = VERDE
pixArray[380][290] = AZUL
pixArray[390][290] = NEGRO

# Creating a PixelArray object from a Surface object will lock that Surface
# object. Locked means that no blit() function calls (described next) can be
# made on that Surface object. To unlock the Surface object, you must delete
# the PixelArray object with the "del" operator. If you forget to delete the
# PixelArray object, you will get an error message that says pygame.error:
# "Surfaces must not be locked during blit."
del pixArray


# %% ACTUALIZACION DE PANTALLA
# Se vacía el lienzo a la pantalla. Esto es más rápido que escribir directamente
# a pantalla todos los comandos anteriores.
pygame.display.update()


# %% The game loop
while True:
    for evento in pygame.event.get():
        if evento.type == QUIT: # se genera al cerrar el programa con la X (mouse)
            # Si no se sale bien, el programa puede ocasionar un error
            pygame.quit()
            sys.exit()

