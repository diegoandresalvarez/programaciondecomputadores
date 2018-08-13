#include<stdio.h>
#include<stdlib.h>

// gcc -std=c99 -O3 -Wall -D USE_RESTRICT -o 08_restrict 08_restrict.c 
// gcc -std=c99 -O3 -S                08_restrict.c -o v1
// gcc -std=c99 -O3 -S -DUSE_RESTRICT 08_restrict.c -o v2

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
   for (int i=0; i<n; i++)
   {
      // The compiler has to read c in the second line because 
      // it may happen that either b points to a or c. 
      b[i] = b[i] + c[i];
      a[i] = a[i] + b[i]*c[i];
   }
   
   return;
}

/*

$ gcc -std=c99 -pedantic -Wall -Wextra -O3 -S restrict.c -o v1.s
$ gcc -std=c99 -pedantic -Wall -Wextra -O3 -S -DUSE_RESTRICT restrict.c -o v2.s

Without restrict:
  movl        12(%esp), %eax        ; eax <- c
  movl        4(%esp), %edx        ; edx <- a
  movl        (%eax), %ecx    ; ecx <- *c
  movl        %ecx, (%edx)    ; *a = *c
  movl        (%eax), %edx    ; edx <- *c
  movl        8(%esp), %eax   ; eax <- b
  movl        %edx, (%eax)        ; *b = *c
  ret

NB: *c is loaded twice.

With restrict:
  movl        12(%esp), %eax        ; eax <- c
  movl        4(%esp), %edx        ; edx <- a
  movl        (%eax), %eax        ; eax <- *c
  movl        %eax, (%edx)        ; *a = *c
  movl        8(%esp), %edx        ; edx <- b
  movl        %eax, (%edx)        ; *b = *c
  ret

NB: *c is loaded only once.

*/
