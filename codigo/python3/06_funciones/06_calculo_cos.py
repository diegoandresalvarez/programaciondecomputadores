import math

def factorial(n):
    # Recuerde que math.factorial() existe
    if (n == 1) or (n == 0):
        return 1
    else:
        return n*factorial(n-1)

def potencia(x, n):
    # Recuerde que pow() existe
    tmp = 1.0
    for i in range(n): tmp *= x
    return tmp


def absoluto(x):
    # Recuerde que abs() existe
    return -x if (x<0) else x

def coseno(x):
    m = 1
    res = 1.0
    res_old = 0.0
    while absoluto(res - res_old) > 1e-15:
        res_old = res
        res += potencia(-1.0, m)*potencia(x,2*m)/factorial(2*m)
        print("m: {0:2d} -> {1: .13e}".format(m, res))
        m += 1
    return res

t = math.pi/2
print("\ncos({0}) = {1}".format(t, coseno(t)))


