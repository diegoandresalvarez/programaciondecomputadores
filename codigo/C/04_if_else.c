#include <stdio.h>

int main(void)
{
   int r, a=3, b=-2, c=4;

   // determine el menor de a,b,c
   if (a < b)
   {
      if (a < c)
         r = a;
      else
         r = c;
   }
   else
   {
      if (b < c)
         r = b;
      else
         r = c;
   }
   printf("El menor vale %d\n", r);

   return 0;
}
