#include<stdio.h>

// gcc -Wall -std=c99 -o 06_matrices_par_func 06_matrices_par_func.c

void asigne(int m, int n, double a[m][n]);
void imprima(int n; double a[][n], int m, int n);

int main (void)
{
   double a1[5][6]; asigne(5, 6, a1); imprima(a1, 5, 6);
   putchar('\n');
   double a2[7][3]; asigne(7, 3, a2); imprima(a2, 7, 3);

   return 0;
}

void asigne(int m, int n, double a[m][n])
{
   int k=0;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         a[i][j] = k++;
}

void imprima(int n; double a[][n], int m, int n) 
// observe aquí la declaracion anticipada
{
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < n; j++)
         printf("%3.f, ",a[i][j]);
      printf("\b\b\n");
   }
}
