class Persona:
    nombre = ""   
    def __init__(self, nompers):
        self.nombre = nompers
        print("Persona creada")                
    def imprimir(self):
        print(self.nombre)        
    
class Empleado(Persona):
    nombre_del_puesto = ""    
    def imprimir(self):
        print(self.nombre, self.nombre_del_puesto)
        
class Cliente(Persona):
    email = ""
    def imprimir(self):
        print(self.nombre, self.email)
            
johnSmith = Persona("John Smith")
johnSmith.imprimir()
janeEmpleado = Empleado("Jane Empleado")
janeEmpleado.nombre_del_puesto = "Desarrollador Web"
janeEmpleado.imprimir()
bobCliente = Cliente("Bob Cliente")
bobCliente.email = "enviame@spam.com"
bobCliente.imprimir()

