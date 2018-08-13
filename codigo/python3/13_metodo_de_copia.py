class Persona():
    def __init__(self, nombre, telefonos, edad):
        self.nombre = nombre
        self.telefonos =  telefonos
        self.edad = edad
        
    def copia1(self):
        return Persona(self.nombre, \
                       self.telefonos, \
                       self.edad)
    
    def copia2(self):
        return Persona(self.nombre[:], \
                       self.telefonos[:], \
                       self.edad)
    
              
p1 = Persona('Pepito Pérez', [8722821, 8848421], 20)
p2 = p1
p3 = p1.copia1()
p4 = p1.copia2()


