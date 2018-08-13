#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
   double A[SIZE] = {1.,2.,3.,4.,5.};
   
   FILE * fp = fopen("test.bin", "wb");
   fwrite(A, sizeof(double), SIZE, fp); // escriba el array A a un archivo
   fclose (fp);

   double B[SIZE];
   fp = fopen("test.bin","rb");
   if (fseek(fp, sizeof(double)*2L, SEEK_SET) != 0) // salte dos doubles
   {
      if (ferror(fp))
      {
         perror("fseek()");
         fprintf(stderr,"fseek() failed in file %s at line # %d\n", __FILE__,__LINE__-5);
         exit(EXIT_FAILURE);
      }
   }

   fread(B, sizeof(double), 1, fp); // lea un double e imprímalo
   printf("%.1f\n", B[0]);                       

   fclose(fp);
   return EXIT_SUCCESS;
}
