from time import sleep

tiempo = 0.05 #segundos

# Observe como colocar varios comandos en una sola línea. Esto de todos
# modos no se recomienda en Python: 
# Ver: https://www.python.org/dev/peps/pep-0008/
# Aquí simplemente lo hago porque mejora la claridad del código

for i in range(101):
    print('%3d%% \\' % i, end = '', flush = True); sleep(tiempo)
    print('\b|',          end = '', flush = True); sleep(tiempo)
    print('\b/',          end = '', flush = True); sleep(tiempo)
    print('\b-',          end = '', flush = True); sleep(tiempo)
    print('\r',           end = '', flush = True)

# Aquí toca poner el "flush = True", porque normalmente el buffer
# de salida solo se imprime cuando aparece un \n

print('FIN!\a')

