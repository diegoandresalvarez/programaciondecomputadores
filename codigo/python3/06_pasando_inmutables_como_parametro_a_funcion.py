def intentemos_cambiar_los_contenidos_de_los_parametros(num, boo, cad, tupla):
    print('recibió', num, boo, cad, tupla)
    print('ids = ', hex(id(num)), hex(id(boo)), hex(id(cad)), hex(id(tupla)))
    num += 10
    boo = not boo    
    cad += 'xxx'
    tupla = (10,20,30)
    print('cambió a', num, boo, cad, tupla)
    print('ids = ', hex(id(num)), hex(id(boo)), hex(id(cad)), hex(id(tupla)))

a = 1
b = True
c = 'Hola'
d = ('a','b','c')

print('antes de llamar función:  ', a, b, c, d)
print('ids = ', hex(id(a)), hex(id(b)), hex(id(c)), hex(id(d)))
intentemos_cambiar_los_contenidos_de_los_parametros(a, b, c, d)
print('ids = ', hex(id(a)), hex(id(b)), hex(id(c)), hex(id(d)))

