# Programa para adivinar un número secreto entre 1 y 20

import random

num_secreto = random.randint(1, 20)

for intentos in range(1,7):
    # Leer el número desde el teclado
    while True:
        num = int(input("Entre un número entre 1 y 20 = "))
        if 1 <= num <= 20: break

    if num < num_secreto:
        print('El número entrado es muy pequeño.')
    elif num > num_secreto:
        print('El número entrado es muy grande.')
    else: # if num == num_secreto:
        print('Adivinaste el número secreto en', intentos, 'intentos!')
        break
else:
    print('Perdiste. El número secreto era el', num_secreto)

print('*** FIN DEL JUEGO ***')

