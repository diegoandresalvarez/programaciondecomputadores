def fun1(s):
   x = 3; y = s  # x, y y s son variables locales
   print('fun1: x = {0}, y = {1}'.format(x,y))
   
def fun2(s):
   x = 1; y = s  # x, y y s son variables locales
   print('fun2: x = {0}, y = {1}'.format(x,y))

def fun3(s):
   global x      # x es la variable global
   x = 1; y = s  # y y s son variables locales
   print('fun3: x = {0}, y = {1}'.format(x,y))


x = 5;   # este x es una variable global
print('x = {0}'.format(x))
fun1(4); print('x = {0}'.format(x))
fun2(2); print('x = {0}'.format(x))
fun3(2); print('x = {0}'.format(x))

