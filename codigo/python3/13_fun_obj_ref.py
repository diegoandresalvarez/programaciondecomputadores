class Persona:
    def __init__(self):
        self.nombre = ""
        self.dinero = 0

def consignar_dinero_1(dinero):
    dinero += 100

def consignar_dinero_2(p):
    p.dinero += 100

juan = Persona()
juan.nombre = "Juan"
juan.dinero = 100

print(juan.dinero)

consignar_dinero_1(juan.dinero)
print(juan.dinero)

consignar_dinero_2(juan)
print(juan.dinero)

