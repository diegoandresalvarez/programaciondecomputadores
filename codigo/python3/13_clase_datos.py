class Persona():
    nombre = "Aquí va el nombre"
    direccion = "Aquí va la dirección"
    edad = -1
    ciudad = "Aquí va la ciudad"

def imprimir_Persona(p):
    print('Nombre y dirección =', p.nombre, p.direccion)
    # Si existe una edad, imprimirla
    if p.edad >= 0:
        print('Edad =', p.edad)
    # Si existe una ciudad, imprimirla
    if p.ciudad != '':
        print('Ciudad =', p.ciudad)

P1 = Persona()
P1.nombre = "Pepito Pérez"
P1.direccion = "Carrera 2 # 3 - 42"
P1.ciudad = "Neira"
P1.edad = 25

P2 = Persona()
P2.nombre = "María Martínez"
P2.ciudad = "Manizales"

imprimir_Persona(P1)
imprimir_Persona(P2)

print("El nombre P1 es", P1.nombre)
print("La dirección de P2 es", P2.direccion)

