def suma(a,b):           return a+b
def resta(a,b):          return a-b
def multiplicacion(a,b): return a*b
def division(a,b):       return a/b

def aritmetica_con_if_elif(a,b,opcion):
   if   opcion == '+': return suma(a,b)
   elif opcion == '-': return resta(a,b)
   elif opcion == '*': return multiplicacion(a,b)
   elif opcion == '/': return division(a,b)

def aritmetica_con_funciones_como_parametros(a,b,fun):
   return fun(a,b)

print('La suma de 2 y 5 es', aritmetica_con_if_elif(2,5,'+'))
print('La suma de 2 y 5 es', aritmetica_con_funciones_como_parametros(2,5,suma))

