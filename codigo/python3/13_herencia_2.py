class Persona:
    nombre = ''
    def __init__(self, nompers):
        self.nombre = nompers
        print('Persona creada')

    def __str__(self):
        return self.nombre

class Empleado(Persona):
    nombre_del_cargo = ''
    def __init__(self, nompers='',nomcargo=''):
        self.nombre_del_cargo = nomcargo
        # Persona.__init__(nompers) -> PRODUCE ERROR
        Persona.__init__(self, nompers)
        print('Empleado creado')

    def __str__(self):
        return Persona.__str__(self) + ' ' + self.nombre_del_cargo


johnSmith = Persona('John Smith')
print(johnSmith)

janeEmpleado = Empleado('Jane Empleado','Abogada')
print(janeEmpleado)

