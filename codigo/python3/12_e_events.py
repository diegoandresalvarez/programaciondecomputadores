# -*- coding: utf-8 -*-

# Mueva la ficha del jugador con las flechas, o con asdw
# x mueve la ficha del jugador a una dirección aleatoria en la pantalla
# un click con el mouse pone una comida en la posición del mouse
# ESC se sale del juego

import sys
import random
import pygame
# from pygame.locals import *

# set up pygame
pygame.init()
mainClock = pygame.time.Clock()

# set up the window
WINDOWWIDTH = 400
WINDOWHEIGHT = 300
windowSurface = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT), 0, 32)
pygame.display.set_caption('Reconociendo el mouse y el teclado')

# set up the colors
BLACK = (  0,   0,   0)
GREEN = (  0, 255,   0)
WHITE = (255, 255, 255)

# set up the player and food data structure
foodCounter = 0
NEWFOOD = 40
FOODSIZE = 20
player = pygame.Rect(300, 100, 50, 50)
foods = []
for i in range(20):
    foods.append(pygame.Rect(random.randint(0, WINDOWWIDTH  - FOODSIZE), 
                             random.randint(0, WINDOWHEIGHT - FOODSIZE), 
                             FOODSIZE, FOODSIZE))

# set up movement variables
moveLeft = moveRight = moveUp = moveDown = False
MOVESPEED = 6

# run the game loop
while True:
    # check for events
    for event in pygame.event.get():
        print(event)
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            # change the keyboard variables
            # no importa si se presionó la minúscula o la mayúscula
            if event.key in (pygame.K_LEFT, ord('a')):
                moveLeft = True                
                moveRight = False
            if event.key in (pygame.K_RIGHT, ord('d')):
                moveLeft = False
                moveRight = True
            if event.key == pygame.K_UP or event.key == ord('w'):
                moveDown = False
                moveUp = True
            if event.key == pygame.K_DOWN or event.key == ord('s'):
                moveDown = True
                moveUp = False                
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_ESCAPE:
                pygame.quit()
                sys.exit()
            if event.key in (pygame.K_LEFT,  ord('a')): moveLeft  = False
            if event.key in (pygame.K_RIGHT, ord('d')): moveRight = False
            if event.key in (pygame.K_UP,    ord('w')): moveUp    = False
            if event.key in (pygame.K_DOWN,  ord('s')): moveDown  = False
            if event.key == ord('x'):
                player.top  = random.randint(0, WINDOWHEIGHT - player.height)
                player.left = random.randint(0, WINDOWWIDTH  - player.width)

        if event.type == pygame.MOUSEBUTTONUP:
            foods.append(pygame.Rect(event.pos[0], event.pos[1],
                                     FOODSIZE, FOODSIZE))

    foodCounter += 1
    if foodCounter >= NEWFOOD:
        # add new food
        foodCounter = 0
        foods.append(pygame.Rect(random.randint(0, WINDOWWIDTH  - FOODSIZE), 
                                 random.randint(0, WINDOWHEIGHT - FOODSIZE), 
                                 FOODSIZE, FOODSIZE))

    # draw the black background onto the surface
    windowSurface.fill(BLACK)

    # move the player
    if moveDown  and player.bottom < WINDOWHEIGHT: player.top   += MOVESPEED
    if moveUp    and player.top > 0:               player.top   -= MOVESPEED
    if moveLeft  and player.left > 0:              player.left  -= MOVESPEED
    if moveRight and player.right < WINDOWWIDTH:   player.right += MOVESPEED

    # draw the player onto the surface
    pygame.draw.rect(windowSurface, WHITE, player)

    # check if the player has intersected with any food squares.
    # In the previous Collision Detection program, the doRectsOverlap() 
    # function to check if one rectangle had collided with another. That 
    # function was included in this book so you could understand how the 
    # code behind collision detection works.

    # In this program, you can use the collision detection function that 
    # comes with Pygame. The colliderect() method for pygame.Rect objects 
    # is passed another pygame.Rect object as an argument and returns True 
    # if the two rectangles collide and False if they do not.
    for food in foods[:]:
        if player.colliderect(food):
            foods.remove(food)

    # draw the food
    for i in range(len(foods)):
        pygame.draw.rect(windowSurface, GREEN, foods[i])

    # draw the window onto the screen
    pygame.display.update()
    mainClock.tick(40)
