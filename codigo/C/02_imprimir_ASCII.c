#include<stdio.h>

int i, j;

int main(void)
{
   for(i=0;i<256;i+=10)
   {
      for(j=0;j<10;j++)
         printf("%3d = %c   ", i+j, (char)(i+j));
      printf("\n");
   }
   return 0;
}