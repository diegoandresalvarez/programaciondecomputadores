import random

# Declaración de constantes
IMAX = 10  # Número máximo permisible de intentos
NDIG = 4   # Número de dígitos

# Declaración de variables
n = NDIG*[None]   # centenas, decenas, unidades de numero entrado por el teclado

# Generar el número secreto
s = [random.randint(0, 9) for i in range(NDIG)]

MAXDIG = 10**NDIG - 1

print(' MASTERMIND '.center(40, '*'))

# Bucle principal
for numero_intentos in range(1, IMAX+1):
    # Leer el número desde el teclado
    while True:
        try:
            num = int(input('Entre un número entero entre 0 y {} = '.format(MAXDIG)))
            if 0 <= num <= MAXDIG: break
        except ValueError:
            print('Por favor entre un entero. Intente de nuevo ...')

    # Se separan centenas, decenas y unidades del número entrado desde el teclado
    for i in range(NDIG):
        n[i] = num % 10
        num //= 10

    # Inicializar variables
    bu = cp = 0             # números buenos, números en correcta posición
    usada_s = NDIG*[False]  # ninguna cifra del núm. secreto no ha sido usada

    # Contabilizar buenos y en correcta posición
    for i in range(NDIG):
        # contabilizar las cifras de correcta posición
        if n[i] == s[i]: cp += 1

        # contabilizar las cifras que están buenas
        for j in range(NDIG):
            # si son iguales y ambas están disponibles, cuente el número bueno
            if (n[i] == s[j]) and not usada_s[j]:
                bu += 1            # contando los buenos
                usada_s[j] = True  # la cifra s[j] ya no está disponible
                break              # ya no vale la pena seguir variando s[j]
                                   # ya que n[i] se utilizó

    print("BUENAS = {0}, CORRECTA POSICIÓN = {1}".format(bu, cp).rjust(80))

    # Comparar
    if cp == NDIG:
        print('\nGANASTE!!! Utilizaste {0} intentos'.format(numero_intentos))
        break
else:
    # Se calcula en número secreto, a partir de sus dígitos
    ns = s[0]
    for i in range(1,NDIG):
        ns += s[i]*pow(10,i)

    print('\nPERDISTE :-( El número secreto era el {0}.'.format(ns))
    print('Inténtalo de nuevo')
