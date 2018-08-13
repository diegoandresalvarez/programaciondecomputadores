#include<stdio.h>

// gcc -Wall -o 08_puntero_constante 08_puntero_constante.c

int main(void)
{
   int var1 = 0, var2 = 0;
   int *const p = &var1;
//   p = &var2;
   *p = 10;
   printf("var1 = %d, var2 = %d, *p = %d\n", var1, var2, *p);

   return 0;
}

