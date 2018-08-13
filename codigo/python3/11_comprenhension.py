## El siguiente procedimiento:
#squares = []
#for x in range(10):
   #squares.append(x**2)
#print(squares)

## Se puede escribir como:
#squares = list(map(lambda x: x**2, range(10)))
#print(squares)

## O como:
#squares = [x**2 for x in range(10)]  # list comprenhension
#print(squares)

## El siguiente procedimiento:
#combinaciones = []
#for x in [1,2,3]:
   #for y in [3,1,4]:
      #if x != y:
         #combinaciones.append((x, y))         
#print(combinaciones)         

## Se puede escribir utilizando una "list comprenhension":
#combinaciones = [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
#print(combinaciones)         

# Nested list comprenhensions
matriz = [
   [1, 2, 3, 4],
   [5, 6, 7, 8],
   [9, 10, 11, 12],
]

# El siguiente código transpone la matriz
transpuesta = [[fila[i] for fila in matriz] for i in range(4)]
print(transpuesta)

# El siguiente código es equivalente:
transpuesta = []
for i in range(4):
   transpuesta.append([fila[i] for fila in matriz])
print(transpuesta)   
   
# Y este también:
transpuesta = []
for i in range(4):
   fila_transpuesta = []
   for fila in matriz:
      fila_transpuesta.append(fila[i])
   transpuesta.append(fila_transpuesta)
print(transpuesta)
