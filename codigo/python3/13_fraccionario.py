class fraccionario:

    def __init__(self, n, d):
        self.numerador, self.denominador = fraccionario.simplificar(n, d)

    @staticmethod
    def maximo_comun_divisor(a, b):
        while b != 0:
            a, b = b, a%b
        return a

    @classmethod
    def simplificar(cls, n1, n2):
        g = cls.maximo_comun_divisor(n1, n2)
        return (n1 // g, n2 // g)

    def __str__(self):
        return str(self.numerador)+'/'+str(self.denominador)

x = fraccionario(8,24)
print(x)
