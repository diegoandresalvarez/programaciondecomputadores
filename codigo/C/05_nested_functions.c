#include <stdio.h>

// gcc -Wall -o 05_nested_functions 05_nested_functions.c

float fun1(float x);

int main(void)
{
   printf("El resultado es %f\n", fun1(10));
   return 0;
}

float fun1(float x)
{
   int z = 1;
   float fun2(float y)
   {
      return x + y + z;
   }
   float fun3(float y)
   {
      return x*y + z;
   }   
   return fun2(3) + fun3(4) + z;
}

