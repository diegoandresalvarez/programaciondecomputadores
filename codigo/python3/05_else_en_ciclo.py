def encontrar_en_lista(lista, objetivo):
   for index, x in enumerate(lista):
      if x == objetivo:
         break
   else:
      index = None
   return index

def encontrar_en_lista2(lista, objetivo):
   index = 0
   while index < len(lista):
      if lista[index] == objetivo:
         break
      index += 1
   else:
      index = None
   return index

L = [1, 2, 'x', 4, 'yyy', [1, 4]]

print(encontrar_en_lista(L, 'yyy'))
print(encontrar_en_lista(L, 'zzz'))

print(encontrar_en_lista2(L, 'yyy'))
print(encontrar_en_lista2(L, 'zzz'))

