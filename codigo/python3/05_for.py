for letra in "ABCDEF":
   if letra in "AEIOU":
      print(letra, "es una vocal")
   else:
      print(letra, "es una consonante")   

print()

for pais in ["Perú", "Panamá", "Chile"]:
   print(pais)
   
print()

# Usualmente la lista se asigna
# primero a una variable:
paises = ["Perú", "Panamá", "Chile"]   
for pais in paises:
   if len(pais) == 6:
      paises.append("Colombia")
   print(pais)

print()

for pais in paises[:]:
   if len(pais) == 6:
      paises.append("México")
   print(pais)


   
