#include <stdlib.h>
#include <stdio.h>

#define M 2000

int main()
{
   int i;
   double *A;  // se separa memoria para una fila

   A = malloc(M * sizeof(double));
   if (A == NULL) {
      fputs("No hay memoria disponible", stderr);
      return EXIT_FAILURE;
   }

   for (i = 0; i < M; i++) A[i] = i;

   free(A);

   return EXIT_SUCCESS;
}
