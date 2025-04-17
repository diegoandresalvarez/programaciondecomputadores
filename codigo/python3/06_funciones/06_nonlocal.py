def outer():
   # Se declaran las variables
   x = 1
   
   # Se declaran las subfunciones
   def inner():
      nonlocal x
      x += 2
      print("inner:", x)

   # código de outer()
   inner()
   print("outer:", x)
   
outer()

