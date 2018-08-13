#include <stdio.h>
#include <string.h>

// gcc -Wall -o 08_memmove 08_memmove.c

int main(void)
{
   char orig[50] = "Una cadena de texto";
   char *dest;
   
   dest = orig+5;

   printf("(antes de memmove)   orig = %s, dest = %s\n", orig, dest);
   memmove(dest, orig, 10);
   printf("(después de memmove) orig = %s, dest = %s\n", orig, dest);
   
   return(0);
}

