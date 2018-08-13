#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_fprintf_fscanf.c -o 09_fprintf_fscanf -std=c99

int main(void)
{
   // Cree un archivo con números, cuadrados y factoriales
   FILE *fp = fopen("results.dat", "w");
   if (fp == NULL)
   {
      perror("No se pudo abrir results.dat para escritura");
      return EXIT_FAILURE;
   }
   int product = 1;
   for (int i=1; i<=3; ++i)
      fprintf(fp, "i=%d, i^2=%d, factorial(%d)=%d\n", i, i*i, i, product*=i);
   fclose(fp);

   // Procese el archivo con fscanf()
   fp = fopen("results.dat", "r");
   if (fp == NULL)
   {
      perror("No se pudo abrir results.dat para lectura");
      return EXIT_FAILURE;
   }

   int n, sq, fact;
   while (fscanf(fp, "i=%d, i^2=%d, factorial(%*d)=%d ", &n, &sq, &fact) == 3)
      printf("factorial(%d) = %d\n", n, fact);
   fclose(fp);

   return EXIT_SUCCESS;
}

