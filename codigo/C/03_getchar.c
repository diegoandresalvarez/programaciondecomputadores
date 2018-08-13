#include <stdio.h>

// compile con: gcc -Wall -o 03_getchar 03_getchar.c

int main ()
{
   int c; // OJO no se debería poner char porque las letras especiales
          // F1, F2, flechas, Ctrl+letra, etc pueden ocupar 2 o más bytes
   printf("Escriba un texto. Si presiona un punto el programa termina:\n");
   do
   {
      c = getchar();
		putchar(c);
   } while (c != '.');

   return 0;
}
