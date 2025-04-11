import time
import fractions
from math import log

print('ln(2) [exacto] = ', log(2))

# cálculo con fractions (truncado a 200.000 términos)
suma = 0
tic = time.time()
for i in range(0, 100_000):
   suma += fractions.Fraction(1, 2*i + 1) - fractions.Fraction(1, 2*i + 2)
toc = time.time()
print('ln(2) = ', float(suma))
print (f'El cálculo se realizó en {toc-tic} segundos')

# cálculo con floats (truncado a 200.000 términos)
suma = 0
tic = time.time()
for i in range(0, 100_000):
   suma += 1/(2*i + 1) - 1/(2*i + 2);
toc = time.time()
print('ln(2) = ', suma)
print (f'El cálculo se realizó en {toc-tic} segundos')


