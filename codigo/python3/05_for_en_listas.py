# enumerate retorna el índice y el valor
for i, v in enumerate(['tic', 'tac', 'toe']):
   print(i, v)

# zip() acopla dos secuencias al mismo tiempo
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
   print('What is your {0}?  It is {1}.'.format(q, a))

# reversed() permite iterar sobre una secuencia en orden inverso
for i in reversed(range(1, 10, 2)):
   print(i)

# sorted() permite iterar sobre una secuencia en forma ordenada, 
# sin cambiar los contenidos de la lista
basket = ['aa', 'cc', 'bb', 'rr', 'aa']
for f in sorted(basket):
   print(f)

# antes de alterar una lista con un for haga una copia de esta, 
# ya que el for no hace una copia de esta:
print('Con copia = ')
palabras = ['gato', 'ventana', 'arrojar']
for w in palabras[:]:  # [:] hace la copia
   if len(w) > 6:
      palabras.insert(0, w)

print(palabras)

print('Sin copia = ')
palabras = ['gato', 'ventana', 'arrojar']
for w in palabras:
   if len(w) > 6:
      palabras.insert(0, w)
   if len(palabras) > 10:  # sin esta condición el ciclo hubiera sido infinito
      break

print(palabras)





