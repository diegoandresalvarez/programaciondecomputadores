#include <stdlib.h>
#include <stdio.h>

#define N 2000

int main(void)
{
   int i;
   double *x;  // se separa memoria para una fila

   x = malloc(N * sizeof(double));
   if (x == NULL) {
      fputs("No hay memoria RAM disponible", stderr);
      return EXIT_FAILURE;
   }

   for (i = 0; i < N; i++) x[i] = i;

   free(x);

   return EXIT_SUCCESS;
}


