#include <stdio.h>

// gcc -Wall 02_operador_or.c -o 02_operador_or

int main(void)
{
   int x = 10, y = 0;

   if((x>15) || (++y)) puts("Hola");
   printf("x = %d; y = %d\n", x, y);

   return 0;
} 
