class Direccion():
    nombre = ""
    via1 = ""
    via2 = ""
    ciudad = ""
    provincia = ""
    cod_postal = ""

# Crea una dirección
mi_direccion = Direccion()

# Cuidado! Esto no establece el nombre para la dirección!
nombre = "Dr. Craven"

# Esto tampoco
Direccion.nombre = "Dr. Craven"

# Esto sí está bien:
mi_direccion.nombre = "Dr. Craven"