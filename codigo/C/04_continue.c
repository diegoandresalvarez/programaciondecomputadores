#include<stdio.h>

// Compile con: gcc -Wall -o 04_continue 04_continue.c

int main(void)
{
   int n;
   for (n=10; n>0; n--)
   {
      if (n==5) continue;
      printf("%d, ", n);
   }

   puts("Bye, bye!");

   return 0;
}

