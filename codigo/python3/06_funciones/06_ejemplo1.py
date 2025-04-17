def fun(a,b):
   b = b[:]
   for i in b:
      a.append(i)
        
   b += [4]
   a[-1] = 100
   del b[0]
   return b[:]
    
L1 = [1,2,3]
L2 = [1,2,3]
L3 = fun(L1,L2)

print('L1 = ', L1)
print('L2 = ', L2)
print('L3 = ', L3)

