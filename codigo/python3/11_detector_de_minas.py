#   Detector de minas:
#
#   Tablero de juego:
#
#       | 0 1 2 3 4 5 6 7 8 9 |        intento   mina1   mina2   mina3
#    ---+---------------------+           1
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
#    ---+---------------------+

import random

def leer_radar(C, F, m):
   if m['c'] == C and m['f'] == F: m['detectada'] = True

   if m['detectada']:
      print('DETECTADA')
      return

   if m['f'] > F:
      print('S', end='')
   elif m['f'] < F:
      print('N', end='')

   if m['c'] > C:
      print('E', end='')
   elif m['c'] < C:
      print('W', end='')

   print('')
   return

# Declaración de constantes
N_MINAS =  3 # número de minas
IMAX    = 10 # número de iteraciones máximo

# Se define el vector (diccionario) que contendrá las minas
m = [{'c': None, 'f': None, 'detectada': False} for i in range(N_MINAS)]  

# Inicializar la posición de las minas aleatoriamente
for i in range(N_MINAS):
    m[i]['c'] = random.randint(0, 9)
    m[i]['f'] = random.randint(0, 9)

for i in range(IMAX):
    # Leer el fila y columna desde el teclado
    while True:
        num = input("Entre las coordenadas de la mina A..J, 0..9 = ")
        F = ord(num[0].upper()) - ord('A') # Fila: A=0, B=1, C=2, ... J=9
        C = int(num[1])                    # Columna
        if len(num)==2 and 0<=C<=9 and 0<=F<=9: break
    
    num_minas_detectadas = 0 # número de minas detectadas
    for j in range(N_MINAS):
        print(f'Mina {j+1}: ', end = '')
        leer_radar(C, F, m[j])
        if m[j]['detectada']: num_minas_detectadas += 1
  
    if num_minas_detectadas == N_MINAS:
        print(f'\nGANASTE!!! Utilizaste {i} intentos')
        break
else:
    print('\nPERDISTE :-( Las minas estaban localizadas en:')
    for j in range(N_MINAS):
        print('Mina {0}: {1}{2}'.format(j+1, chr(m[j]['f']+ord('A')), m[j]['c']))

    print('Inténtalo de nuevo')
