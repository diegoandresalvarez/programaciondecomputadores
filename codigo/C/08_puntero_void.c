#include <stdio.h>

// gcc -Wall -o 08_puntero_void 08_puntero_void.c

int main(void)
{
   int   a = 10;
   double b = 35.75;
   void *p; // Declarando un puntero void

   p = &a;
   printf("a = %d\n", *((int *)p));

   p = &b;
   printf("b = %f\n", *((double *)p));   

   return 0;
}

