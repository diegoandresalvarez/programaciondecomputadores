#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 100000000

// gcc -Wall -o 06_memcpy_vs_for 06_memcpy_vs_for.c

int i, x[N], v1[N], v2[N];

int main(void)
{
   clock_t start, stop;

   printf("Asignando %d elementos en x[]\n", N);
   for (i=0; i<N; i++) x[i] = i;

   start = clock();
   memcpy(v1, x, N*sizeof(int));         // copiar el vector x a v1
   stop = clock(); 
   printf("Tiempo empleado memcpy()       = %8.4f s.\n", (double) (stop-start)/CLOCKS_PER_SEC);

   start = clock();
   for (i=0; i<N; i++) v2[i] = x[i];     // copiar el vector x a v2
   stop = clock();
   printf("Tiempo empleado usando for(;;) = %8.4f s.\n", (double) (stop-start)/CLOCKS_PER_SEC);

/*
   for (i=0; i<N; i++)
      printf("x[%d] = %5d, \t v1[%d] = %5d, \t v2[%d] = %5d\n", i, x[i], i, v1[i], i, v2[i]);
*/

   return 0;
}

