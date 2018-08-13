#include <stdio.h>

// gcc -Wall -o 08_puntero_a_puntero2 08_puntero_a_puntero2.c

int main(void)
{
   int a    = 3; 
   int *b   = &a;
   int **c  = &b;
   int ***d = &c;

   printf("dir(a) = %p, dir(b) = %p, dir(c) = %p, dir(b) = %p\n", &a, &b, &c, &d);
   printf("a = %d, b = %p, c = %p, d = %p\n", a, b, c, d);
   printf("a = %d = %d = %d = %d\n", a, *b, **c, ***d);
   
   return 0;
}

