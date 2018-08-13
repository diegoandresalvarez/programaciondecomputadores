i = 5

def fun1(arg=i): 
    print(arg)

def fun2(val, arr=[]):
    arr.append(val)
    return arr
   
# Solución al problema con fun2()   
def sol_fun2(val, arr=None):
    if arr is None:
        arr = []
    arr.append(val)
 
    return arr   
   
def fun3(a, b=5):
   b = b+a
   return b
 
i = 6; fun1()
print(fun2(1)); print(fun2(2)); print(fun2(3))
print(sol_fun2(1)); print(sol_fun2(2)); print(sol_fun2(3))
print(fun3(1), fun3(2), fun3(3))

