def fun1(val1, val2, val3, calc_suma=True):    
    if calc_suma:  # Calcule la suma
        return val1 + val2 + val3
    else:          # Calcule mejor el promedio
        return (val1 + val2 + val3)/3

def fun2(val1=0, val2=0):
    return val1 - val2

print(fun1(1, 2, 3))
print(fun1(1, 2, 3, False))
print(fun1(1, 2, 3, calc_suma=False))
print('-----------------------------------------------------------------------')
print(fun2(10, 3))
print(fun2(val1=10, val2=3))
print(fun2(val2=3, val1=10)) # aquí los parámetros están en diferente orden
print(fun2(val1=10))
print(fun2(val2=3))


# print(fun2(val1=10,3)) # después de nombrar un parámetro, los sgtes deben nombrarse

