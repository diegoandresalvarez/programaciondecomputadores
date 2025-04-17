def mifuncion1():
   x = 99                       # este "x" es una variable local a mifuncion1()
   print("x (mifuncion1) =", x)
   
def mifuncion2():
   global x                     # se declara "x" como global para poder modificarla
   x = -21                      # este "x" es la variable global
   print("x (mifuncion2) =" ,x)   

def mifuncion3():
   print("x (mifuncion3) =", x) # este "x" hace referencia a la variable global   
   
x = 42                          # este "x" es una variable global
print("x =", x)

mifuncion1()
print("x =", x)                 # mifuncion1() no cambió el contenido de "x"

mifuncion2()
print("x =", x)                 # mifuncion2() cambió el contenido de "x"

mifuncion3()                   
