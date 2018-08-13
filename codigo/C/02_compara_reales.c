#include<stdio.h>
#include<math.h>

// Compile con: gcc -Wall -o 02_compara_reales 02_compara_reales.c -lm

int main(void)
{
   // (x-sqrt(5))^2 = x^2 - 2*sqrt(5) x + 5
   double x1, x2, a, b, c, d, d2;
   a = 1.0; b = -2.0*sqrt(5.0); c = 5.0;
   
   d2 = b*b - 4.0*a*c;     printf("d2 = %.25g\n",d2); // debe dar 0
   d  = sqrt(d2);          printf("d  = %.25g\n", d); // debe dar 0
   x1 = (-b + d)/(2.0*a);  printf("x1 = %.25g\n",x1);
   x2 = (-b - d)/(2.0*a);  printf("x2 = %.25g\n",x2);

   if (x1 == x2)
      printf("x1 == x2\n");
   else
      printf("x1 != x2\n");

   if (fabs(x1-x2) < 1e-6)
      printf("x1 == x2\n");
   else
      printf("x1 != x2\n");

   return 0;
}

