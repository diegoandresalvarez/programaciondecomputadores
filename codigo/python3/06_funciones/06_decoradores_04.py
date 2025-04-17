def hacer_dos_veces(func):
    def envolver_hacer_dos_veces(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)
    return envolver_hacer_dos_veces

@hacer_dos_veces
def saludar(nombre):
    print("Creando un saludo ...")
    return f"Hola {nombre}"

saludo = saludar("Pepito")
print(saludo)


