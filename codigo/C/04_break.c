#include<stdio.h>

// Compile con: gcc -Wall -o 04_break 04_break.c

int main(void)
{
   int n;
   for (n=10; n>0; n--)
   {
      printf("%d, ",n);
      if (n==3)
      {
         puts("conteo abortado!");
         break;
      }
   }
   
   return 0;
}
