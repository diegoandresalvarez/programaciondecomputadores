sufijos = { 1000: ['KB',  'MB',  'GB',  'TB'],
            1024: ['KiB', 'MiB', 'GiB', 'TiB']}

def tamaño_aproximado(tamaño, exacto=True):
   ''' Convierte un número de bytes a otras unidades.

       tamaño_aproximado(tamaño, exacto=True)

       Parámetros de entrada:
            tamaño: tamaño dado en bytes
            exacto: True  = división entre 1024 
                    False = división entre 1000

       Retorna una cadena de texto
   '''

   if tamaño < 0:
      raise ValueError('"tamaño" debe ser positivo')

   multiple = 1024 if exacto else 1000
   for s in sufijos[multiple]:
      tamaño /= multiple
      if tamaño < multiple:
         return '{0:.1f} {1}'.format(tamaño, s)

   raise ValueError('"tamaño" es demasiado grande')

if __name__ == '__main__':
      print(tamaño_aproximado(1000000000, False))
      print(tamaño_aproximado(1000000000))

