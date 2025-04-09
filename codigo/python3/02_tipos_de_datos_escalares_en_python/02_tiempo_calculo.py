import time
import fractions
from math import log

suma = 0
tic = time.time()
for i in range(0, 10000): 
   suma += fractions.Fraction(1,2*i + 1) - fractions.Fraction(1,2*i + 2)
toc = time.time()
print('ln(2) = ', float(suma))
print ('El cálculo se realizó en ', toc-tic, 'segundos')

suma = 0
tic = time.time()
for i in range(0,10000000):
   suma += 1/(2*i + 1) - 1/(2*i + 2);
toc = time.time()
print('ln(2) = ', suma)
print('El cálculo se realizó en ', toc-tic, 'segundos')

print('ln(2) = ', log(2))
