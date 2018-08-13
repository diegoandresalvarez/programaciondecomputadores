#include<stdio.h>

int main(void)
{
   int x,y;
   for (x = 0; x < 10; x++)
      printf ("%d ", x);

   printf ("\n");

   x = 1;
   for (; x <= 10; x++)
      printf ("%d ", x);

   printf ("\n");

   for (x = 1, y = 10; x <= 10 && y >= 1; x+=2, y--)
      printf ("x = %d, y = %d\n", x, y);

/*
   for (x = 1; ; x++)      // ESTO ES UN CICLO
      printf ("%d ", x);   // INFINITO

   for (x = 1; x <= 10;)   // ESTO ES UN CICLO
      printf ("%d ", x);   // INFINITO
*/

   return 0;
}