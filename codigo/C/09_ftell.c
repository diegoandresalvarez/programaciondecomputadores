#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_ftell.c -o 09_ftell

#define SIZE 5

int main(void)
{
   double A[SIZE] = {1.,2.,3.,4.,5.};
   
   FILE * fp = fopen("test.bin", "wb");
   fwrite(A, sizeof(double), SIZE, fp); // escriba el array A a un archivo
   fclose (fp);

   double B[SIZE];
   fp = fopen("test.bin","rb");
   long int pos = ftell(fp);   // indicador de posición al principio del archivo   
   if (pos == EOF)
   {
      perror("ftell()");
      fprintf(stderr,"ftell() failed in file %s at line # %d\n", __FILE__,__LINE__-4);
      exit(EXIT_FAILURE);
   }
   printf("Posición antes de lectura = %ld\n", pos); 

   fread(B, sizeof(double), 1, fp); // lea un double
   pos = ftell(fp); // indicador de posición después de la lectura
   if (pos == EOF)
   {
      perror("ftell()");
      fprintf(stderr,"ftell() failed in file %s at line # %d\n", __FILE__,__LINE__-4);
      exit(EXIT_FAILURE);
   }
   printf("Posición después de lectura = %ld\n", pos);
   printf("%.1f\n", B[0]); // imprima el double leído

   return EXIT_SUCCESS;
}
