#include <stdio.h>

// gcc -Wall 04_imprimir_binario.c -o 04_imprimir_binario

int main(void)
{
   unsigned int z;
   unsigned int x = 811232345;

   // 2^31=2147483648 = 10000000000000000000000000000000 (31 ceros)
   for (z = 2147483648u; z > 0; z >>= 1) 
      putchar(((x&z) == z) ? '1' : '0');

   putchar('\n');
   return 0;
}


