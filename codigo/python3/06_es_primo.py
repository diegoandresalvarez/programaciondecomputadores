def es_primo(num):
    '''
    es_primo(num)

    Función que detemina si num es primo o no
    
    Parametro de entrada:
    num: número entero o lista de números enteros
    
    Retorna:
    Si num es un entero, retorna True o False dependiendo si num es primo
    Si num es una lista de enteros, retorna un vector con True o False 
    dependiendo si num los elementos de num son primos o no.         
    '''
    try:
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
        elif isinstance(num, list):    # en caso que num sea una lista
            vec_es_primo = [es_primo(num[i]) for i in range(len(num))]
            return vec_es_primo
    except:
        return False

print(es_primo(37))
print(es_primo([97,98,99,100,101,102,103]))

