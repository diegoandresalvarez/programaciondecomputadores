#include<stdio.h>

// gcc -Wall 02_complemento_a_2.c -o 02_complemento_a_2

int main(void)
{
   int x;
   x =  31333; printf("%8d\n", ~x+1);
   x = -65445; printf("%8d\n", ~x+1);
   return 0;
}

 
