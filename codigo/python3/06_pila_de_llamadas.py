def fun1():
   a = 1; b = 2
   print('fun1a(): a = {0}, b = {1}'.format(a,b))
   fun2()
   print('fun1b(): a = {0}, b = {1}'.format(a,b))

def fun2():
   a = 3; b = 4
   print('fun2a(): a = {0}, b = {1}'.format(a,b))
   fun3()
   print('fun2b(): a = {0}, b = {1}'.format(a,b))

def fun3():
   a = 5; b = 6
   print('fun3():  a = {0}, b = {1}'.format(a,b))

# PROCEDIMIENTO PRINCIPAL
a = 7; b = 8
print('fun0a(): a = {0}, b = {1}'.format(a,b))
fun1()
print('fun0b(): a = {0}, b = {1}'.format(a,b))

