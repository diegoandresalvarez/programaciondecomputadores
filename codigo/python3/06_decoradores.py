def mi_decorador(func):
    def envolver():
        print(">>> ", end="")
        func()
        print(" <<<")
    return envolver

@mi_decorador
def diga_hola1():
    print("Hola 1", end="")

def diga_hola2():
    print("Hola 2", end="")

diga_hola2 = mi_decorador(diga_hola2)

diga_hola1()
diga_hola2()