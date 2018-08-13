#include <stdio.h>

// gcc -Wall -o 08_array_punteros 08_array_punteros.c

int main(void)
{
   int *vec[3];
   int x = 10, y = 20, z = 30;
   int i;

   vec[0] = &x;
   vec[1] = &y;
   vec[2] = &z;

   printf("dir(x) = %p, dir(y) = %p, dir(z) = %p, dir(vec) = %p\n", &x, &y, &z, vec);

   for (i=0; i< 3; i++)
      printf("El valor de *(vec[%d]) = %d, y su dirección es %p\n", i, *(vec[i]), vec[i]);

   return 0;
}

