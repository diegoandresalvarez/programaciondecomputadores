from math import copysign, floor

def mi_round(y):
    '''
    Implementa el método de redondeo
    "Round half away from zero"
    Ver:
    https://en.wikipedia.org/wiki/Rounding
    '''
    return copysign(floor(abs(y)+0.5), y)
    
for i in range(-6,6):
    x = i + 0.5
    print('% 3.1f ---> % 4.1f' % (x, mi_round(x)))

