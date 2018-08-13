# No compare floats con ==

x = 0.1 - 0.3
y = -0.2

# Forma incorrecta de comparar:
if (x == y):
   print('x es igual a ', y)
else:
   print('x es diferente de ', y)
   
print('x - y = ', x-y)

# Forma correcta de comparar:
if abs(x-y) < 1e-10:
   print('x es igual a ', y)
else:
   print('x es diferente de ', y)
   
