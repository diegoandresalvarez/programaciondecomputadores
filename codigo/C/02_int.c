#include<stdio.h>
#include<limits.h>

// Compile con: gcc -std=c99  -Wall -o 02_int 02_int.c

int c;

int main(void)
{
   printf("int:\n");
   printf("sizeof   = %d\n", sizeof(int));
   printf("INT_MIN  = %d\n", INT_MIN);
   printf("INT_MAX  = %d\n", INT_MAX);

   c =  214848;         printf("c = %d\n", c);
   c =  2147483648;     printf("c = %d\n", c);
   c = -3333333333;     printf("c = %d\n", c);
   c =  32.9231;        printf("c = %f\n", c);

   return 0;
}

