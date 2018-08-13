#include <stdio.h>

// gcc -Wall 06_casting_array_a_matriz.c -o 06_casting_array_a_matriz

void imprimir_columna(int nfil, int ncol, int M[nfil][ncol], int j);

int main(void)
{
   int x[] = {1,  2,  3,
              4,  5,  6,
              7,  8,  9,
             10, 11, 12,
             13, 14, 15};

//   imprimir_columna(5, 3, x, 1);
   imprimir_columna(5, 3, (int (*)[3]) x, 1);             

   return 0;
}

void imprimir_columna(int nfil, int ncol, int M[nfil][ncol], int j)
{
   int i;
   for(i=0; i<nfil; i++)
      printf("M[%d][%d] = %d\n", i, j, M[i][j]);
}