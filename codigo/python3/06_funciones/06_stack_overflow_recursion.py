n = 0

def llamando_a_funcion():
   global n
   n += 1
   print(n)
   llamando_a_funcion()
   
llamando_a_funcion()

