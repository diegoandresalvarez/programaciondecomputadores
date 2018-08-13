#include<stdio.h>

// gcc -Wall -o 05_ambito 05_ambito.c

int main(void)
{
   int x = 10;
   {
      int x = 20;
      printf("x = %d\n", x);
   }
   printf("x = %d\n", x);

   return 0;
}

