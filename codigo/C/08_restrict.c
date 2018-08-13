#include<stdio.h>
#include<stdlib.h>

// gcc -std=c99 -O3 -Wall -D USE_RESTRICT -o 08_restrict 08_restrict.c

#ifdef USE_RESTRICT
#else
#define restrict
#endif

const int N = 100000;

int *restrict x, *restrict y, *restrict z;

void fun(int *restrict a, int *restrict b, int *restrict c, int n);

int main()
{
   x = malloc(N * sizeof(int));
   y = malloc(N * sizeof(int));
   z = malloc(N * sizeof(int));
   if (x==NULL || y==NULL || z==NULL)
   {
      fprintf(stderr, "Error con malloc()!\n"); //imprimir mensaje de error
      return EXIT_FAILURE; //return with failure
   }

   // efectuar esta operacion mucha veces para medir el tiempo
   for (int i=0; i<10000; i++)
   {
      for (int j=0; j<N; j++) x[j] = y[j] = z[j] = j;
      fun(x, y, z, N);
      //fun(x, x, x, N);
   }

   free(x); free(y); free(z);

   return EXIT_SUCCESS;
}

void fun(int *restrict a, int *restrict b, int *restrict c, int n)
{
   for (int i=n; i<n; i++)
   {
      b[i] = b[i] + c[i];
      a[i] = a[i] + b[i]*c[i];
   }

   return;
}
/*
Restrict is a "no data hazards will be generated" contract between the programmer
and the compiler. The compiler relies on this information to make optimizations.
If the data is, in fact, aliased, the results are undefined and a programmer
should not expect the compiler to output a warning. The compiler assumes the
programmer is not lying.

Observe que el compilador tiene que recargar c en la segunda expresión, porque
tal vez b y c apuntan a la misma memoria. Por lo tanto, debe esperar a que se
guarde b, antes de recargar de nuevo a y c. Luego al principio del siguiente
ciclo debe recargar b y c.

Este aliasing se notará fuertemente si se ejecuta

fun(a, a, a, N);

Utilizar la palabra restrict le PROMETE al compilador que usted no hará
aliasing, de modo que no se tengan que recargar a, b y c continuamente.

nils@doofnase:~$ gcc -O3 test.c
nils@doofnase:~$ time ./a.out

The point is, that because 'restrict' makes that promise, it enables a
compiler to optimize the code on the assumption that the promise will
not be broken. This only matters if there is such an optimization
possible. In this case, there is. If c[i] will never refer to the same
object as b[i], then it's value need only be retrieved once per pass
through the loop; without 'restrict', it would have to be retrieved twice.
Note, however, that 'restrict' doesn't mandate performance of such
optimizations, it only allows them.
*/
