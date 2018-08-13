#include <stdio.h>

int x = 100; int y = 100; int z = 100; // Variables globales

int suma(int x, int y)
{
   z = 300;                            // z es la variable global
   return x + y;                       // x, y son variables locales    
}

int multiplicacion(int x, int y)
{
   y = x * y;                          // x, y son variables locales
   z += 10;                            // z es la variable global
   return y;
}

int agrega_50(int x)
{
   int z = 50;                         // x, z son variables locales
   y = x + z;                          // y es la variable global
   return y;
}

int main(void)
{
   printf("result = %d\n", suma(2,3) + multiplicacion(3,4) + agrega_50(1) + z);
   for(int i = 0; i<5; i+=1) printf("3x4 = %d\n", multiplicacion(3,4));
   printf("x = %d, y = %d, z = %d\n", x, y, z);
   return 0;
}

