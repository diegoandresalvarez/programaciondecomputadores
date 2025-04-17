def fun1(x):
   return x+1, x**2, 3*x

def fun2(x):
   return [x+1, [1,2,3], 'Hola']

def fun3(x):
   return (x+1, [1,2,3], 'Hola')

a,b,c = fun1(10);    print(a,b,c)
[a,b,c] = fun1(10);  print(a,b,c)
(a,b,c) = fun1(10);  print(a,b,c)
a,b,c = fun2(10);    print(a,b,c)
a,b,c = fun3(10);    print(a,b,c)

a,b = fun3(10) # se están recibiendo dos parámetros y se están entregando 3
print(a,b,c)

