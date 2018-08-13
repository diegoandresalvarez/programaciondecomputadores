#include <stdio.h>

int ncounter;

void stack ()
{
   printf("%d\n", ++ncounter);
   stack();
}

int main (void)
{
   stack();
   
   return 0;
}