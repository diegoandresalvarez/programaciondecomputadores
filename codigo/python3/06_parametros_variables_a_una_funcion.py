def mi_fun(aa1, aa2, *bbb, **ccc):
   print('El argumento aa1 es', aa1)
   print('El argumento aa2 es', aa2)   
   print('-'*70)
   print('El argumento bbb es', bbb)
   for i,b in enumerate(bbb):
      print('bbb[', i, '] =', b)
   print('-'*70)
   print('El argumento ccc es', ccc)
   keys = sorted(ccc.keys())
   for kw in keys:
      print('ccc[', kw, '] =', ccc[kw])

mi_fun('Arg 1', 'Arg 2', 'Arg 3', 'Arg 4', a2 = 'Arg 5', a3 = 123, a1 = [1,2,3])

