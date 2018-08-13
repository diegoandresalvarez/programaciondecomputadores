x = int(input("Entre un número: "))

if x<0:
   print("El número es negativo")
   
   # Aquí cambio el número a cero
   x = 0
elif x == 0:
   print("El número es cero")      
elif 0 < x <= 10:
   print("El número está en el intervalo (0,10]")   
else:
   print("El número es mayor que 10")
      
         