#include <stdio.h>

// Compile con: gcc -Wall -o 03_putchar 03_putchar.c

int main ()
{
   char c;
   for (c = 'A'; c <= 'Z'; c++) putchar(c);
   putchar('\n');

   return 0;
}
