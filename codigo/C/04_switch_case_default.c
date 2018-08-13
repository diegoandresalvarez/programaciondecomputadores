#include <stdio.h>

// OJO esto solo compila con el gcc
// gcc -Wall -o 04_switch_case_default 04_switch_case_default.c

int main(void)
{
   char c;
   printf("Entre una letra = "); scanf("%c", &c);
   switch (c)
   {
      case 'A' ... 'Z':
         printf("%c es una letra mayúscula\n",c);
         break;
      case 'a' ... 'z':
         printf("%c es una letra minúscula\n",c);
         break;
      case '0' ... '9':
         printf("%c es un número\n",c);
         break;      
      default:
         printf("%c es un espacio o un símbolo\n",c);
         break;
   }

   return 0;
}


/*
#include <stdio.h>

int main(void)
{
   int x;
   printf("Entre x = "); scanf("%d", &x);
   switch (x)
   {
      case 0:
         puts ("x vale 0");
         break;
      case 1:
      case 2:      
         puts ("x vale 1 o 2");
         break;
      default:
         puts ("x tiene otro valor");
         break;
   }

   return 0;
}
*/

