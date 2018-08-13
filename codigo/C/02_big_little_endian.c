#include <stdio.h>

// Compile con:
// gcc -Wall -o 02_big_little_endian 02_big_little_endian.c

int main(void)
{
   int i = 0x4A3B2C1D;
   char *p = (char *) &i;
   if (*p == 0x1D)
      printf("Little Endian\n");
   else
      printf("Big Endian\n");
   return 0;
}
