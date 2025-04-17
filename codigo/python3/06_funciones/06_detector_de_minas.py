#   Detector de minas:
#
#   Tablero de juego:
#
#       | 0 1 2 3 4 5 6 7 8 9 |        intento   mina1   mina2   mina3
#    ---x---------------------x           1
#     A |                     |           2
#     B |                     |           3
#     C |                     |           4
#     D |                     |           5
#     E |                     |           6
#     F |                     |           7
#     G |                     |           8
#     H |                     |           9
#     I |                     |          10
#     J |                     |
#    ---x---------------------x

import random

def leer_radar(X, Y, m):
   if m['x'] == X and m['y'] == Y: m['detectada'] = True

   if m['detectada']:
      print('DETECTADA')
      return

   if m['y'] > Y:
      print('S', end='')
   elif m['y'] < Y:
      print('N', end='')

   if m['x'] > X:
      print('E', end='')
   elif m['x'] < X:
      print('W', end='')

   print('')
   return

# Declaración de constantes
N_MINAS =  3 # número de minas
IMAX    = 10 # número de iteraciones máximo

# Se define el vector (diccionario) que contendrá las minas
m = [{'x': None, 'y': None, 'detectada': False} for i in range(N_MINAS)]  

# Generar el número secreto
s = [random.randint(0, 9) for i in range(N_MINAS)]

# Inicializar la posición de las minas
for i in range(N_MINAS):
    m[i]['x']         = random.randint(0, 9)
    m[i]['y']         = random.randint(0, 9)
    m[i]['detectada'] = False

for i in range(IMAX):
    # Leer el fila y columna desde el teclado
    while True:
        num = input("Entre las coordenadas de la mina A..J, 0..9 = ")
        Y = ord(num[0].upper()) - ord('A') # Fila: A=0, B=1, C=2, ... J=9
        X = int(num[1])                   # Columna
        if len(num) == 2 and 0 <= X <= 9 and 0 <= Y <= 9: break
    
    num_minas_detectadas = 0 # número de minas detectadas
    for j in range(N_MINAS):
        print('Mina {0}: '.format(j+1), end = '')
        leer_radar(X, Y, m[j])
        if m[j]['detectada']: num_minas_detectadas += 1
  
    if num_minas_detectadas == N_MINAS:
        print('\nGANASTE!!! Utilizaste {0} intentos'.format(i))
        break
else:
    print('\nPERDISTE :-( Las minas estaban localizadas en:')
    for j in range(N_MINAS):
        print('Mina {0}: {1}{2}'.format(j+1, chr(m[j]['y']+ord('A')), m[j]['x']))

    print('Inténtalo de nuevo')
