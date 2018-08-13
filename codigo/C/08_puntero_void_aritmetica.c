#include <stdio.h>

// gcc -Wall -o 08_puntero_void_aritmetica 08_puntero_void_aritmetica.c

int main(void)
{
   int   a = 10;
   void *p; // Declarando un puntero void

   p = &a;
   printf("Direccion de a = %p\n", &a);
   
   printf("p = %p\n", p);
   p = p+2;
   printf("p = %p\n", p);  
  
   return 0;
}

