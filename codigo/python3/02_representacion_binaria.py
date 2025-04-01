import numpy as np

def double_to_bin(d):
    b = int(np.float64(d).view(np.int64))
    return f'{b:64b}'.lstrip()

# se almacena la representación binaria como cadena de texto
s1 = double_to_bin(0.2)
s2 = double_to_bin(0.3-0.1)

# y la imprime
print(s1)
print(s2)

# se muestra la diferencia entre las representaciones
print(''.join('1' if s1[i] == s2[i] else '0' for i in range(len(s1))))

print("\nSe imprimen todos los decimales:")
print(f'{0.2    :.25f}')
print(f'{0.3-0.1:.25f}')
