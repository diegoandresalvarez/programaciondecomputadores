#include<stdio.h>

// Compile con: gcc -Wall -o 04_do_while 04_do_while.c

int main(void)
{
   int n;
   do
   {
      printf("Entre un número (0 para terminar): ");
      scanf("%d", &n);
      printf("Usted escribió: %d\n", n);
   } while(n != 0);

   return 0;
}
