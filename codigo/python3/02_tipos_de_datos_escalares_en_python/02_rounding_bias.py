from math import copysign, floor
from statistics import mean
from random import randint

# Generar una lista de 1000 números aleatorios entre 0 y 1000.
numeros = [randint(0, 10000)/10 for _ in range(100)]

# Definir funciones para los métodos de redondeo
def round_half_to_even(y):
    return round(y)

def round_half_away_from_zero(y):
    return copysign(floor(abs(y) + 0.5), y)

# Aplicar dichos métodos de redondeo
redondeo_hte  = [round_half_to_even(num)        for num in numeros]
redondeo_hafz = [round_half_away_from_zero(num) for num in numeros]

# Calcular los promedios
promedio_original = mean(numeros)
promedio_hte      = mean(redondeo_hte)
promedio_hafz     = mean(redondeo_hafz)

# Imprimir resultados
print("Promedio original:", promedio_original)
print("Promedio hte:     ", promedio_hte)
print("Promedio hafz:    ", promedio_hafz)
