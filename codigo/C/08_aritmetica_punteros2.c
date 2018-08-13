#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -o 08_aritmetica_punteros2 08_aritmetica_punteros2.c

int main(void)
{
   char *x   = NULL;
   double *y = NULL;
   int d = 10;
   int *z    = &d;

   printf("x   = %p, \ty   = %p, \tz-2 = %p\n", x,   y,   z-2);
   printf("x+1 = %p, \ty+1 = %p, \tz-1 = %p\n", x+1, y+1, z-1);
   printf("x+2 = %p, \ty+2 = %p, \tz   = %p\n", x+2, y+2, z);
   printf("x+3 = %p, \ty+3 = %p, \tz+1 = %p\n", x+3, y+3, z+1);
   printf("x+4 = %p, \ty+4 = %p, \tz+2 = %p\n", x+4, y+4, z+2);

   return 0;
}

