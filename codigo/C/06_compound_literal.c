#include<stdio.h>

// Compile con: gcc -Wall -o 06_compound_literal 06_compound_literal.c

int main(void)
{
   int i, x=10;
   int p1[] = {1, 2 ,3, 4, 5};
   int *p2;
   p2 = (int[]){x, 20 ,30, 40, 50};

   printf("sizeof(p1) = %d\n", sizeof(p1));
   printf("sizeof(p2) = %d\n", sizeof(p2));
   for(i=0; i<5; i++)
      printf("p2[%d] = %d\n", i,p2[i]);
   
   return 0;
}
