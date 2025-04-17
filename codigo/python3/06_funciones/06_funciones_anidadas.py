def fun1(x):
   z = 1
   
   def fun2(y):
      return x+y+z
   
   def fun3(y):
      return x*y + z
   
   return fun2(3) + fun3(4) + z

print(fun1(10))

