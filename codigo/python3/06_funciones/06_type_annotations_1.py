def funcion(a: str, b: str, times: int) -> str:
    return (a + b) * times

print(funcion("¡Buenos ", "días! ", 3))

# Observe que lastimosamente el intérprete de Python 
# no le hace caso a las type annotations.
print(funcion(1, 2, 3))

edad: int = 20
print(edad)  # 20
edad = 'Veinte'
print(edad)

