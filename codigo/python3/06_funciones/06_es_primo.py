def es_primo(num):
    '''Detemina si un número es primo o identifica los primos de una lista/tupla

    es_primo(num)
    
    Parametro de entrada:
    num: número entero, tupla o lista
    
    Retorna:
    Si num es un entero, retorna True o False dependiendo si num es primo
    Si num es una lista o tupla de enteros, retorna un vector con True o False 
    dependiendo si los elementos de num son primos o no.
    '''
    if isinstance(num, int):       # en caso que num sea un entero
        if num == 2:
            return True
        elif (num < 2) or(num%2 == 0):
            return False
        else:
            for i in range(3, num//2 + 1, 2):
                if num%i == 0:
                    return False
            return True
    elif type(num) in (tuple, list):  # en caso que num sea una tupla o lista
        vec_es_primo = [es_primo(numero) for numero in num]
        return vec_es_primo
    else:
        return False

print(es_primo(37))
print(es_primo([97,98,99,'Hola',101,102,103]))

