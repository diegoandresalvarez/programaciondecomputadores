def foo():
    foo.contador += 1
    print("El contador va en %d" % foo.contador)
foo.contador = 0  # inicialización de la variable estática

foo()
foo()
foo()
foo()
