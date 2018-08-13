#include<stdio.h>

int main()
{
   int x = 10, y;
 
   //ciclo hecho con un goto (NO LO HAGA!)
label:
   printf("%d ", x);
   x -= 2;
 
   if (x != 0) goto label;
   printf("\n");

   // salirse de un for anidado con un goto
   for (x = 0; x < 4; x++)
   {
      for (y = 0; y < 4; y++)
      {
         printf("(%d;%d) ", x, y);
         if (x + y >= 4) goto endloop;
      }
    }
    
endloop:
   printf("\n");
 
   return 0;
}

// compile con: gcc -Wall -o 04_goto 04_goto.c