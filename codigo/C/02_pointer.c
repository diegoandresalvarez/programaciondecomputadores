#include<stdio.h>

int main(void)
{
   int x, y, *px;

   x = 5;
   px = &x; // se le asigna la dirección de x;

   x = x + 1;
   
   printf("x   = %d\n", x);
   printf("px  = %p\n",px);  // la direccion de memoria de x
   printf("&px = %p\n",&px); // la direccion de memoria de px
   printf("*px = %d\n",*px); // el contenido de lo que apunta px

   y = 9;
   *px = y;

   printf("x   = %d\n", x);
   printf("*px = %d\n",*px); // el contenido de lo que apunta px;
   
   return 0;
}
