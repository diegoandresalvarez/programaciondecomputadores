#include <stdio.h>

// gcc -Wall -o 08_aritmetica_punteros1 08_aritmetica_punteros1.c

int main(void)
{
   char cadena[] = "Pepito Perez";
   char *p;
   int num_vocales = 0;

   p = cadena;

   do
   {
      switch (*p)
      {
         case 'A':      case 'a':
         case 'E':      case 'e':
         case 'I':      case 'i':
         case 'O':      case 'o':
         case 'U':      case 'u':
            num_vocales++;
            break;
      }
      p++;
   } while (*p);

   printf("\"%s\" tiene %d vocales\n", cadena, num_vocales);
   return 0;
}

