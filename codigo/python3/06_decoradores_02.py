def hacer_dos_veces(func):
    def envolver_hacer_dos_veces():
        func()
        func()
    return envolver_hacer_dos_veces

@hacer_dos_veces
def saludar(nombre):
    print(f"Hola {nombre}")

saludar("Pepito")

