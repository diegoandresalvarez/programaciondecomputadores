#include <stdlib.h>
#include <stdio.h>

#define M 3   // Numero de filas
#define N 4   // Numero de columnas

int main(void)
{
   int i, j, k=0;
    
   int (*A)[N];  // se separa memoria para una FILA con N elementos
    
   A = malloc(M * sizeof(*A)); // se separa memoria para M FILAS
   if (A == NULL)
   { 
      fputs("No hay memoria RAM disponible\n", stderr);
      return EXIT_FAILURE;
   }

   for (i = 0; i < M*N; i++) *((int *)A + i) = k++;
      
   for (i = 0; i < M; i++)
   {
      printf("Fila %d: %p\n", i, A[i]);
      for (j = 0; j < N; j++)
         printf("%p[%2d]  ", &A[i][j], A[i][j]);
      printf("\n");
   }
  
   free(A);
   
   return EXIT_SUCCESS;
}


