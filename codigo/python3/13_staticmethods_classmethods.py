class Mascotas1:
    nombre = "mascoticas"

    @staticmethod
    def acerca_de():
        print("Esta clase es sobre {}.".\
            format(Mascotas1.nombre))   
    

class Perros1(Mascotas1):
    nombre = "perritos"

class Gatos1(Mascotas1):
    nombre = "gaticos"

p = Mascotas1()
p.acerca_de()
d = Perros1()
d.acerca_de()
c = Gatos1()
c.acerca_de()

print(80*'-')

class Mascotas2:
    nombre = "mascoticas"

    @classmethod
    def acerca_de(cls):
        print("Esta clase es sobre {}.".\
            format(cls.nombre))   
    

class Perros2(Mascotas2):
    nombre = "perritos"

class Gatos2(Mascotas2):
    nombre = "gaticos"

p = Mascotas2()
p.acerca_de()
d = Perros2()
d.acerca_de()
c = Gatos2()
c.acerca_de()
