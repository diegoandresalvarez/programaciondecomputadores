#include<stdio.h>

// Compile con: gcc -Wall -o 02_char 02_char.c

char c;

int main(void)
{
   c = 109;
   printf("decimal = %d\n"
          "hexadecimal = %x\n"
          "caracter = %c\n\n", c,c,c);

   c = 0x6D;
   printf("decimal = %d\n"
          "hexadecimal = %x\n"
          "caracter = %c\n\n", c,c,c);

   c = 'm';
   printf("decimal = %d\n"
          "hexadecimal = %x\n"
          "caracter = %c\n\n", c,c,c);

   return 0;
}

