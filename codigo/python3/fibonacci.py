# Módulo para el cálculo de las series de Fibonacci

def fib(n):    
# escribe en pantalla la serie de Fibonacci hasta en número n
   a, b = 0, 1
   while b < n:
      print(b, end=' ')
      a, b = b, a+b
   print()

def fib2(n): # return Fibonacci series up to n
# retorna una lista con la serie de Fibonacci hasta en número n   
   result = []
   a, b = 0, 1
   while b < n:
      result.append(b)
      a, b = b, a+b
   return result

print("Inicializando Fibonacci ...")

