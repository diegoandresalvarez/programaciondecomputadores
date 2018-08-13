class Perro():
    def __init__(self): # el constructor
        self.edad = 0
        self.nombre = ""
        self.peso = 0
        self.color = 'Negro'

    def ladrar(self, num=1):
        print(num * "Guau!! ")
        
    def imprimir(self):
        print('Nombre =', self.nombre)
        print('Edad =',   self.edad, 'años')
        print('Peso =',   self.peso, 'kg')
        print('Color =',  self.color)                
        
p = Perro()
p.edad = 10 # años
p.nombre = 'Guardián'
p.peso = 50 # kg
p.raza = 'Criollo'

p.ladrar(3)
p.imprimir()

