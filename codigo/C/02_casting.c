#include <stdio.h>

// Compile con:
// gcc -Wall -o 02_casting 02_casting.c

int main()
{
   double a=3.4, b=3.3, c=3.3;
   int    r1 = (int)a + (int)b + (int)b;
   int    r2 = a + b + c;
   double d1 = a + b + c;

   printf("a = %20.17f\n", a);
   printf("b = %20.17f\n", b);
   printf("c = %20.17f\n", c);
   printf("r1 = %d\n", r1);
   printf("r2 = %d\n", r2);
   printf("d1 = %20.17f\n", d1);
   
   return 0;
}
