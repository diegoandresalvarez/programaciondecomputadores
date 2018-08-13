#include<stdio.h>

// gcc -Wall -o 08_puntero_a_constante 08_puntero_a_constante.c

int main(void)
{
   int var1 = 5, var2 = 10;
   const int *p;
   p = &var1;
   *p = 1;
   p = &var2;
   printf("var1 = %d, var2 = %d, *p = %d\n", var1, var2, *p);

   return 0;
}


