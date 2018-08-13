#include <stdio.h>

// gcc -Wall -o 08_comparacion_punteros 08_comparacion_punteros.c

int main(void)
{
   int x[] = {1, 2, 3, 4, 5};
   int *p1, *p2, *p3;
   double y=3, *p4;
   p1 = x;
   p2 = x+2;
   p3 = &x[2];
   p4 = &y;
   printf("x[0] = %d, dir(x[0]) = %p\n", *p1, p1);
   printf("x[2] = %d, dir(x[2]) = %p\n", *p2, p2);
   printf("dir(y) = %p\n", p4);      
   if (p1<p2)  puts("p1 apunta a menor memoria que p2");
   if (p2==p3) puts("p2 y p3 apuntan a la misma memoria");
   if (p1!=p3) puts("p1 y p3 apuntan diferente memoria");
      
   // WARNING: Punteros de diferente tipo
   if (p3>p4)  puts("p3 apunta a mayor memoria que p4");      

   return 0;
}

