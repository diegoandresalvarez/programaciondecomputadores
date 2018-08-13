class Persona:
    def __init__(self):
        self.nombre = ""
        self.codigo = 0

p1 = Persona()
p1.nombre = "Juan"
p1.codigo = 100

p2 = p1
p2.nombre = "Ana"

print(p1.nombre, "tiene el código", p1.codigo)
print(p2.nombre, "tiene el código", p2.codigo)

print(p1)
print(p2)
print(p1 is p2)
print(type(p1))
print(type(p2))

