#include<stdio.h>
#include<stdbool.h>

// Compile con: gcc -Wall -o 04_while 04_while.c

int main(void)
{
   char c = 'A';   
   while(true)
   {
      putchar(c);
      if (c == 'Z')
         break;
      c++;         
   }
   putchar('\n');
   
   return 0;
}



/*

#include <stdio.h>

// Compile con: gcc -Wall -o 04_while 04_while.c

int main(void)
{
   char c = 'A';   
   while(c <= 'Z')
   {
      putchar(c);
      c++;
   }
   putchar('\n');
   
   return 0;
}

*/