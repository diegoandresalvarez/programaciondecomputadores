def ordenar_lista_cadenas(L):
    """
    Organiza alfabéticamente una lista con cadenas de texto, teniendo en cuenta
    que dichas cadenas pueden tener tildes, diéresis o la letra ñ.
    :param   L: lista a ordenar
    :return: la lista ordenada
    """

    # Crea la tabla para las conversiones de caracteres
    tabla = str.maketrans("áéíóúüñÁÉÍÓÚÜÑ", "aeiouunAEIOUUN")

    # Se crea un iterador de 0 a len(L)-1
    range_num = range(len(L))

    # Se les quita la tilde a cada una de las palabras de la lista
    L_sin_tilde = [L[i].translate(tabla) for i in range_num]

    # Se ordena la lista y junto con sus índices de ordenamiento
    tmp = sorted(zip(L_sin_tilde, range_num))

    # se retorna la lista ordenada (L_ord) y los índices después del
    # ordenamiento (idx). Aquí se está desempacando el contenido de tmp
    # Ver: https://docs.python.org/3/library/functions.html#zip
    L_ord, idx = zip(*tmp)

    # Se retorna la lista ordenada
    return [L[idx[i]] for i in range_num]

lista_palabras = "murciélago árbol nunca otoño ñoño érase cigüeña".split()

# Lista de palabras mal ordenadas con sorted()
print(sorted(lista_palabras))

# Lista de palabras correctamente ordenadas
print(ordenar_lista_cadenas(lista_palabras))

