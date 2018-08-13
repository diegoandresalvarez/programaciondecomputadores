from time import sleep
import sys

tiempo = 0.05 #segundos

# Observe como colocar varios comandos en una sola línea. Esto de todos
# modos no se recomienda en Python: 
# Ver: https://www.python.org/dev/peps/pep-0008/
# Aquí simplemente lo hago porque mejora la claridad del código

for i in range(101):
    print('%3d%% \\' % i, end = '');  sys.stdout.flush(); sleep(tiempo)
    print('\b|',          end = '');  sys.stdout.flush(); sleep(tiempo)
    print('\b/',          end = '');  sys.stdout.flush(); sleep(tiempo)
    print('\b-',          end = '');  sys.stdout.flush(); sleep(tiempo)
    print('\r',           end = '');

# Aquí toca poner el sys.stdout.flush(), porque normalmente el buffer
# de salida solo se imprime cuando aparece un \n

print('FIN!\a')

# bye bye!



