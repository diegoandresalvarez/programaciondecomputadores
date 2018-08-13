import sys

try:
    f = open('miarchivo.txt')
    den = int(f.readline())       # lee el primer reglón de miarchivo.txt
    x = 1/den
except OSError as err:
    print("Error OS: {0}".format(err))
except ValueError:
    print("No pude convertir el dato a un entero.")
except:
    print("Error inesperado:", sys.exc_info()[0])
    raise
else:
    print('1/{0} = {1}'.format(den,x))

f.close()
