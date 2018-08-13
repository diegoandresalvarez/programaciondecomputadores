#include <stdio.h>
#include <string.h>

// gcc -Wall -o 08_memset 08_memset.c

int main ()
{
   char cad[50];

   strcpy(cad,"Esta es una cadena");
   puts(cad);

   memset(cad,'$',7);
   puts(cad);
   
   return(0);
}

