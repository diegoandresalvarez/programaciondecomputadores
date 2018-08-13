#include<stdio.h>

// Compile con: gcc -Wall -o 05_par_ref_valor 05_par_ref_valor.c

int func(int, int*);

int main(void)
{
   int x = 2, y = 3, z = 0;
   printf("x = %d, y = %d, z = %d\n", x, y, z);
   z = func(x,&y);
   printf("x = %d, y = %d, z = %d\n", x, y, z);

   return 0;
}

int func(int a, int *b)
{
   a = 2 * a;
   *b = *b + 5;
   return a;
}

