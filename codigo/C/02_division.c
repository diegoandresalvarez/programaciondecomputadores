#include<stdio.h>

int main(void)
{
   int a = 5, b = 3;
   printf("%f\n", (float)(a/b));    // convierte el entero (a/b) a float
   printf("%f\n", (float)((-a)/b)); // convierte el entero (-a/b) a float
   printf("%f\n", (float)a/b);      // convierte a a float
   printf("%f\n", a/(float)b);      // convierte b a float
 
   return 0;
}

