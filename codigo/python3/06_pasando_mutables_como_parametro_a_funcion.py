def intentemos_cambiar_el_contenido_de_la_lista(L):
    '''
    Esta función modifica la lista que se pasa a la función
    '''
    print ('recibió', L)
    L.append('four')
    print ('cambió a', L)

def intentemos_cambiar_la_referencia_a_la_lista(L):
    '''
    Esta función modifica la referencia a la lista que se pasó como parámetro 
    a la función
    '''
    print ('recibió', L)
    L = ['cambiamos', 'la', 'referencia', 'L']
    print ('cambió a', L)    
 
lista_exterior = ['one', 'two', 'three']
print ('antes, lista_exterior =', lista_exterior)
intentemos_cambiar_el_contenido_de_la_lista(lista_exterior)
print ('después, lista_exterior =', lista_exterior)

print(80*'-')

lista_exterior = ['one', 'two', 'three']
print ('antes, lista_exterior =', lista_exterior)
intentemos_cambiar_la_referencia_a_la_lista(lista_exterior)
print ('después, lista_exterior =', lista_exterior)

