import math

# (x - sqrt(5))^2 = x^2 - 2*sqrt(5) x + 5
a = 1
b = -2*math.sqrt(5)       # a*x^2 + b*x + c = 0
c = 5;                    # x^2 - 2*sqrt(5) + 5 = 0
   
d2 = b**2 - 4.0*a*c;  print("d2 = ", d2) # debe dar 0
d  = math.sqrt(d2);   print("d  = ", d)  # debe dar 0
x1 = (-b + d)/(2*a);  print("x1 = ", x1)
x2 = (-b - d)/(2*a);  print("x2 = ", x2)

if (x1 == x2):
   print('x1 == x2')
else:
   print('x1 != x2')

if (abs(x1-x2) < 1e-6):
   print('x1 == x2')
else:
   print('x1 != x2');

