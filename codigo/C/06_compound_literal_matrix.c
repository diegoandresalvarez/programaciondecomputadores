#include<stdio.h>

// gcc -Wall -o 06_compound_literal_matrix 06_compound_literal_matrix.c

int main(void)
{
   int i, j, x=1;  
   int **p;
   p = (int *[]) { (int[]) {x, 2, 3},
                   (int[]) {4, 5, 6}, 
                   (int[]) {7, 8, 9} };
      
   for (i=0; i<3; i++)
      for (j=0; j<3; j++)      
         printf("p[%d][%d] = %d\n", i,j, p[i][j]);
   
   return 0;
}

