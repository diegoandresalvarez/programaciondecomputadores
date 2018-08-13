#include <stdio.h>
#include <string.h>

// gcc -Wall -o 08_memmove2 08_memmove2.c

int main(void)
{
   const char orig[50] = "Una cadena de texto";
   char dest[50] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

   printf("(antes de memmove)   orig = %s, dest = %s\n", orig, dest);
   memmove(dest, orig, strlen(orig)+1);
   printf("(después de memmove) orig = %s, dest = %s\n", orig, dest);
   
   return(0);
}
