#include <stdlib.h>
#include <stdio.h>

#define M 2000
#define N 2000

// Compile con: gcc -Wall -o 06_big_matrix_crash 06_big_matrix_crash.c

int main()
{
   int i, j, k=0;
   double A[M][N]; // esta matriz ocupa (2000^2*8)/(1024*1024) = 30.5 Mb
   for (i=0; i<M; i++)
      for (j=0; j<N; j++)
         A[i][j] = k++;

   return EXIT_SUCCESS;
}

