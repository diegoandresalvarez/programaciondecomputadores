#include<stdio.h>
// gcc -Wall -o 06_array3d 06_array3d.c  
int main(void)
{
   int i, j, k;
   int x[3][3][3]=
         {
            {
               {11, 12, 13},
               {14, 15, 16},
               {17, 18, 19}
            },
            {
               {21, 22, 23},
               {24, 25, 26},
               {27, 28, 29}
            },
            {
               {31, 32, 33},
               {34, 35, 36},
               {37, 38, 39}
            },
         };

   for(i=0; i<3; i++)
   {
      for(j=0; j<3; j++)
      {
         for(k=0; k<3; k++) printf("%d\t", x[i][j][k]);
         printf("\n");
      }
      printf("\n");
   }

   return 0;
}
