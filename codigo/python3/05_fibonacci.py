
def fib(n):  
   """Escriba la serie de Fibonacci hasta el número n."""
   a, b = 0, 1
   while a < n:
      print(a, end=' ')
      a, b = b, a+b
   print()



def fib2(n):  
   """Retorna la serie de Fibonacci hasta el número n."""
   resultado = []
   a, b = 0, 1
   while a < n:
      resultado.append(a)
      a, b = b, a+b
   return resultado

