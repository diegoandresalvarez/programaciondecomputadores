class Perro():
    def __init__(self,nombre,color_perro='Negro'):
        self.nombre = nombre
        self.color = color_perro

    def ladrar(self, num=1):
        print(num * "Guau!! ")
        
    def imprimir(self):
        print('Nombre =', self.nombre)
        print('Color =',  self.color)                
        
p1 = Perro('Guardián','Blanco')
p1.ladrar(3)
p1.imprimir()
print(p1.nombre, p1.color)

p2 = Perro('Kaiser')
p2.imprimir()
print(p2.nombre, p2.color)

