#include<stdio.h>

// Compile con: gcc -Wall -o 02_increm 02_increm.c

int main(void)
{
   int x = 5;
   printf ("%d \n", x++); // imprima x y luego incremente
   printf ("%d \n", ++x); // incremente x y luego imprima

   return 0;
}
