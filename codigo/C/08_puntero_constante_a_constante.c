#include<stdio.h>
// gcc -Wall -o 08_puntero_constante_a_constante 08_puntero_constante_a_constante.c

int main(void)
{
   int var1 = 0,var2 = 0;
   const int* const p = &var1;
   *p = 1;
   p = &var2;
   printf("%d\n", *p);

   return 0;
}

