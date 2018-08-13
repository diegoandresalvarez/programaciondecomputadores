#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7000
#define M 7000

double A[N][M], B[N][M], C[N][M];

int main(void)
{
   int i, j;
   clock_t tic, toc;
   srand(time(NULL));

   printf("Tamano de A = %d Mb\n", sizeof(A)/1024/1024);
   
   // Inicializa las matrices B y C
   for(i=0;i<N;i++)
      for(j=0;j<M;j++)
      {
         B[i][j] = (double)rand()/(double)RAND_MAX;
         C[i][j] = (double)rand()/(double)RAND_MAX;
      }

   tic = clock();
   for(i=0;i<N;i++)
      for(j=0;j<M;j++)
         A[i][j] = B[i][j] + C[i][j];
   toc = clock();
   printf("Tiempo loop i,j = %lf seg\n", (double)(toc-tic)/CLOCKS_PER_SEC);

   tic = clock();
   for(j=0;j<M;j++)
      for(i=0;i<N;i++)   
         A[i][j] = B[i][j] + C[i][j];
   toc = clock();
   printf("Tiempo loop j,i = %lf seg\n", (double)(toc-tic)/CLOCKS_PER_SEC);
       
   return 0;
}


