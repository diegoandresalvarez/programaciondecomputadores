def es_verdadero(x):
   if x:
      print(x, "es verdadero")
   else:
      print(x, "es falso")

# con números
es_verdadero(1)
es_verdadero(-1)
es_verdadero(1.1)
es_verdadero(0)
es_verdadero(0.0)

print()

# con fracciones
import fractions
es_verdadero(fractions.Fraction(1, 2))
es_verdadero(fractions.Fraction(0, 2))

print()

# con tuplas
es_verdadero((1, 2, 'x', []))
es_verdadero(())
es_verdadero((False))
print(type((False)))

# Observe como se crea una tupla con un solo elemento
es_verdadero((False, )) 
print(type((False, )))

print()

# con listas
es_verdadero([1, 2, 'x', []])
es_verdadero([])
es_verdadero([False])

print()

# con conjuntos
es_verdadero({1, 2, 'x'})
es_verdadero(set())
es_verdadero({False})

print()

# con diccionarios
es_verdadero({'a':1, 'b':[1, 3], 'c':'c'})
es_verdadero({})

print()

# con None
es_verdadero(None)
es_verdadero(not None)
