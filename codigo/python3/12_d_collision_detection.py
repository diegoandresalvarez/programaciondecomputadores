# Adaptado de:
# http://inventwithpython.com/chapter18.html

import random
import sys
import pygame

def doRectsOverlap(rect1, rect2):
    # Se determina si los rectangulos se intersectan (o colisionan). Se miran
    # los cuatro bordes de ambos rectángulos. Si al menos uno de estos ocho
    # bordes está dentro del otro rectángulo, entonces se dice que ambos
    # rectángulos colisionaron.
    def isPointInsideRect(x, y, rect):
        return (rect.left < x < rect.right) and (rect.top < y < rect.bottom)

    for a, b in [(rect1, rect2), (rect2, rect1)]:
        # Check if a's corners are inside b
        if ((isPointInsideRect(a.left, a.top, b)) or
            (isPointInsideRect(a.left, a.bottom, b)) or
            (isPointInsideRect(a.right, a.top, b)) or
            (isPointInsideRect(a.right, a.bottom, b))):
            return True

    return False

# PROGRAMA PRINCIPAL
# set up pygame
pygame.init()

# In the previous Animation program, a call to time.sleep(0.02) would slow
# down the program so that the program doesn’t run too fast. The problem with
# time.sleep() is that might be too much of a pause on slow computers and not
# enough of a pause on fast computers.

# Se prepara el objeto mainClock, el cual será usado más adelante
mainClock = pygame.time.Clock()

# set up the window
WINDOWWIDTH = 500
WINDOWHEIGHT = 400
windowSurface = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT))
pygame.display.set_caption('Collision Detection')

# set up direction variables
DOWNLEFT = 1
DOWNRIGHT = 3
UPLEFT = 7
UPRIGHT = 9

MOVESPEED = 4 #pixeles/frame

# set up the colors
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
WHITE = (255, 255, 255)

# set up the bouncer and food data structures
foodCounter = 0
NEWFOOD = 40
FOODSIZE = 20
bouncer = {'rect':pygame.Rect(300, 100, 50, 50), 'dir':UPLEFT}
foods = []
for i in range(20):
    foods.append(pygame.Rect(random.randint(0, WINDOWWIDTH - FOODSIZE),
                             random.randint(0, WINDOWHEIGHT - FOODSIZE),
                             FOODSIZE, FOODSIZE))

# run the game loop
while True:
    # check for the QUIT event
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    foodCounter += 1
    if foodCounter >= NEWFOOD:
        # add new food
        foodCounter = 0
        foods.append(pygame.Rect(random.randint(0, WINDOWWIDTH - FOODSIZE),
                                 random.randint(0, WINDOWHEIGHT - FOODSIZE),
                                 FOODSIZE, FOODSIZE))

    # draw the black background onto the surface
    windowSurface.fill(BLACK)

    # move the bouncer data structure
    if bouncer['dir'] == DOWNLEFT:
        bouncer['rect'].left -= MOVESPEED
        bouncer['rect'].top += MOVESPEED
    if bouncer['dir'] == DOWNRIGHT:
        bouncer['rect'].left += MOVESPEED
        bouncer['rect'].top += MOVESPEED
    if bouncer['dir'] == UPLEFT:
        bouncer['rect'].left -= MOVESPEED
        bouncer['rect'].top -= MOVESPEED
    if bouncer['dir'] == UPRIGHT:
        bouncer['rect'].left += MOVESPEED
        bouncer['rect'].top -= MOVESPEED

    # check if the bouncer has move out of the window
    if bouncer['rect'].top < 0:
        # bouncer has moved past the top
        if bouncer['dir'] == UPLEFT:       bouncer['dir'] = DOWNLEFT
        if bouncer['dir'] == UPRIGHT:      bouncer['dir'] = DOWNRIGHT
    if bouncer['rect'].bottom > WINDOWHEIGHT:
        # bouncer has moved past the bottom
        if bouncer['dir'] == DOWNLEFT:     bouncer['dir'] = UPLEFT
        if bouncer['dir'] == DOWNRIGHT:    bouncer['dir'] = UPRIGHT
    if bouncer['rect'].left < 0:
        # bouncer has moved past the left side
        if bouncer['dir'] == DOWNLEFT:     bouncer['dir'] = DOWNRIGHT
        if bouncer['dir'] == UPLEFT:       bouncer['dir'] = UPRIGHT
    if bouncer['rect'].right > WINDOWWIDTH:
        # bouncer has moved past the right side
        if bouncer['dir'] == DOWNRIGHT:    bouncer['dir'] = DOWNLEFT
        if bouncer['dir'] == UPRIGHT:      bouncer['dir'] = UPLEFT

    # draw the bouncer onto the surface
    pygame.draw.rect(windowSurface, WHITE, bouncer['rect'])

    # check if the bouncer has intersected with any food squares.
    # if you iterate over a copy of the list (and the copy never changes),
    # adding or removing items from the original list won’t be a problem.
    for food in foods[:]:
        if doRectsOverlap(bouncer['rect'], food):
            foods.remove(food)
            # "del foods[food]" no funciona, ya que el argumento debe ser el
            # número indice dentro de foods.

    # draw the food
    for i in range(len(foods)):
        pygame.draw.rect(windowSurface, GREEN, foods[i])

    # draw the window onto the screen
    pygame.display.update()

    # A pygame.time.Clock object can pause an appropriate amount of time on any
    # computer. mainClock.tick(40) waits enough time so that the main loop it
    # runs at bout 40 iterations a second, no matter what the computer’s speed
    # is. This ensures that the game never runs faster than you expect. A call
    # to tick() should only appear once in the game loop.
    mainClock.tick(40)
