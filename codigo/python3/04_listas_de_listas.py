# Para crear una matriz, primero se debe inicializar esta
 
# Crea una matriz de 4 filas y 6 columnas
Matriz = [[0 for c in range(6)] for f in range(4)] 

for fila in Matriz:
   print(fila)

print()
Matriz[0][0] = 1
Matriz[3][0] = 5
Matriz[2][4] = -8

for fila in Matriz:
   print(fila)

Matriz[4][6] = 15

