cadena = input('Entre una cadena = ')
i = int(input('Entre un número = '))
j = int(input('Entre otro número = '))

subcadena = ''
for k in range(i,j):
   subcadena += cadena[k]
   
print('La subcadena entre {0} y {1} es "{2}"'.format(i, j, subcadena))
print('La subcadena entre {0} y {1} es "{2}"'.format(i, j, cadena[i:j]))



