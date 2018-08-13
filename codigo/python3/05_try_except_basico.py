while True:
   try:
      num = int(input('Entre un número entero entre 0 y 100 = '))
      if 0 <= num <= 100: break
   except ValueError:
      print('Por favor entre un entero. Intente de nuevo ...')

print('El número entrado es el', num)

