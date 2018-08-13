#include <stdio.h>
#include <string.h>

// gcc -Wall -o 08_memcpy 08_memcpy.c

int main(void)
{
   const char orig[50] = "Una cadena de texto";
   char dest[50] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

   printf("dest (antes de memcpy) = %s\n", dest);
   memcpy(dest, orig, strlen(orig)+1);
   printf("dest (después de memcpy) = %s\n", dest);
   
   return(0);
}

