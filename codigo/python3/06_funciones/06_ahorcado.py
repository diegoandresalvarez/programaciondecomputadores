# A H O R C A D O
# http://es.wikipedia.org/wiki/Ahorcado_(juego)
# Basado en el código: http://inventwithpython.com/hangman.py

import random

# Se definen las constantes
FIGURAS = ['''

  +---+
  |   |
      |
      |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

PALABRAS = 'Abeja Águila Anguila Antílope Araña Ardilla Atún Avestruz Avispa \
Babosa Ballena Buey Búfalo Búho Buitre Burro Caballo Cabra Caimán Calamar \
Camaleón Camarón Camello Canario Cangrejo Canguro Caracol Castor Cebra Cerdo \
Chimpancé Ciempiés Ciervo Cigarra Cigüeña Cisne Cocodrilo Codorniz Colibrí \
Comadreja Cóndor Conejo Cucaracha Cuervo Delfín Elefante Erizo Escarabajo \
Escorpión Faisán Foca Gallina Gallo Ganso Garrapata Gato Gavilán Gaviota \
Golondrina Gorila Gorrión Grillo Grulla Gusano Halcón Hiena Hipopótamo Hormiga \
Iguana Jabalí Jaguar Jirafa Koala Lagartija León Leopardo Libélula Liebre \
Llama Lobo Lombriz Loro Luciérnaga Mamut Mandril Mariposa Mariquita Morsa \
Mosca Mula Murciélago Nutria Orca Oruga Oso Ostra Oveja Pájaro Paloma Pantera \
Pato Pavo Pelícano Perro Pingüino Polilla Pollo Polluelo Puercoespín Pulga \
Pulpo Puma Rana Rata Ratón Raya Reno Rinoceronte Ruiseñor Salamandra Salmón \
Sapo Sardina Serpiente Ternero Tiburón Tigre Topo Toro Tortuga Trucha Vaca \
Yegua Zorro'.lower().split()

def generar_palabra_al_azar(lista_de_palabras):
    # Esta función retorna una cadena aleatoria a partir de lista_de_palabras
    idx = random.randint(0, len(lista_de_palabras) - 1)
    return lista_de_palabras[idx]


def mostrar_tablero(letras_malas, letras_correctas, palabra_secreta):
    # Muestra el tablero con el ahorcado, las letras correctas y las incorrectas

    # muestra el ahorcado
    print(FIGURAS[len(letras_malas)])
    print()

    # muestra las letras equivocadas
    print('Letras equivocadas:', end=' ')
    for letra in letras_malas:
        print(letra, end=' ')
    print()

    # genere los espacios apropiados para la palabra secreta
    espacios = '_' * len(palabra_secreta)
        
    # reemplace los espacios con las letras correctamente identificadas
    for i in range(len(palabra_secreta)): 
        if palabra_secreta[i] in letras_correctas:
            espacios = espacios[:i] + palabra_secreta[i] + espacios[i+1:]
   
    # muestre los caracteres identificados y los espacios no identificados
    # de la palabra secreta
    for letra in espacios:
        print(letra, end=' ')
    print()


def leer_intento(letras_ya_adivinadas):
    # Lee una letra del teclado. Esta función se asegura que el jugador entro
    # únicamente una letra, no otra tecla como números o símbolos
    while True:
        intento = input('Adivine una letra: ').lower()
        if len(intento) != 1:
            print('Por favor ingrese únicamente UNA letra')
        elif (not intento.isalpha()) and (intento not in 'áéíóúüñ'):
            print('Por favor ingrese únicamente una LETRA')
        elif intento in letras_ya_adivinadas:
            print('Usted ya había ingresado la letra "{0}". '.format(intento) +
                  'Por favor intente de nuevo.')
        else:
            return intento


def jugar_de_nuevo():
    # Esta función le pregunta a jugador si quiere jugar de nuevo. Si es así
    # retorna True, de lo contrario retorna False.
    print('¿Quiere jugar de nuevo? (si o no)')
    return input().lower().startswith('s')


# Aquí empieza el procedimiento principal
print()
print(' A H O R C A D O '.center(29, '*'))
letras_malas = ''
letras_correctas = ''
palabra_secreta = generar_palabra_al_azar(PALABRAS)
Game_Over = False

while True:
    # se muestra el tablero de juego
    mostrar_tablero(letras_malas, letras_correctas, palabra_secreta)

    # se le solicita al jugador que ingrese una letra
    intento = leer_intento(letras_malas + letras_correctas)

    # si la letra se encuentra en la palabra secreta ...
    encontro_letra = False
    if intento == 'a' and 'á' in palabra_secreta:
        letras_correctas += 'aá'
        encontro_letra = True
    elif intento == 'e' and 'é' in palabra_secreta:
        letras_correctas += 'eé'
        encontro_letra = True
    elif intento == 'i' and 'í' in palabra_secreta:
        letras_correctas += 'ií'
        encontro_letra = True
    elif intento == 'o' and 'ó' in palabra_secreta:
        letras_correctas += 'oó'
        encontro_letra = True
    elif intento == 'u' and ('ú' in palabra_secreta or 'ü' in palabra_secreta):
        letras_correctas += 'uúü'
        encontro_letra = True
    elif intento in palabra_secreta:
        letras_correctas += intento
        encontro_letra = True

    # verificar si el jugador ganó con este último intento
    if encontro_letra:
        se_encontraron_todas_las_letras = True
        for i in range(len(palabra_secreta)):
            if palabra_secreta[i] not in letras_correctas:
                se_encontraron_todas_las_letras = False
                break
        
        # si efectivamente el jugador adivinó todas las letras
        if se_encontraron_todas_las_letras:
            print('YES!!! Adivinaste todas las letras!!!\n'
                  'La palabra secreta era "' + palabra_secreta + '".')
            Game_Over = True
    else: # si la letra no se encuentra en la palabra secreta
        letras_malas += intento

        # si el jugador ha adivinado más veces de las permitidas, perdió ...
        if len(letras_malas) == len(FIGURAS) - 1:
            mostrar_tablero(letras_malas, letras_correctas, palabra_secreta)
            print('Se te acabaron las oportunidades :-(\n'
                  'Tuviste {0} intentos fallidos y {1} intentos correctos.\n' 
                  'La palabra secreta era "{2}".'.format(
                     len(letras_malas), len(letras_correctas), palabra_secreta))
            Game_Over = True

    # preguntarle al jugador si quiere jugar de nuevo (se hace únicamente si el 
    # juego ha terminado)
    if Game_Over:
        if jugar_de_nuevo():
            letras_malas = ''
            letras_correctas = ''
            palabra_secreta = generar_palabra_al_azar(PALABRAS)
            Game_Over = False
        else:
            break
