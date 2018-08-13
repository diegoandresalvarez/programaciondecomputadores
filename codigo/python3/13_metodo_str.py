class Persona():
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
       
    def imprimir(self):
        print('Llamando al método imprimir()')
        print('Nombre =', self.nombre)
        print('Edad =',   self.edad, 'años')

    def __str__(self):
        cadena = 'Llamando al método __str__()\n' + \
                 'Nombre = {0}\n'.format(self.nombre) + \
                 'Edad = {0} años'.format(self.edad)
        return cadena
        
p = Persona('Pepito Pérez', 20)
p.imprimir()
print()
print(p)



