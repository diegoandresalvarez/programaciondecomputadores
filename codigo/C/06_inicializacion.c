#include <stdio.h>

// gcc -Wall -o 06_inicializacion 06_inicializacion.c

int a[5] = {3};

int main(void)
{
   int i;
   int b[5] = {3,4};
   static int c[5] = {};
   int d[5];

   for(i=0; i<5; i++) printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);

   return 0;
}