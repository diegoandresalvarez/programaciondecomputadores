#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_fclose.c -o 09_fclose

int main(void)
{
   FILE *fp = fopen("data.txt","w");
   
   // Se abrirá el archivo
   if (fp == NULL)
   {
      perror("fopen()");
      fprintf(stderr,"fopen() failed in file %s at line # %d\n", __FILE__,__LINE__-6);
      exit(EXIT_FAILURE);
   }

   // Aquí se procesa el archivo
   
   // Se cerrará el archivo
   int ret_code = fclose(fp);
   if (ret_code == EOF)
   {
      perror("fclose()");
      fprintf(stderr,"fclose() failed in file %s at line # %d\n", __FILE__,__LINE__-4);
      exit(EXIT_FAILURE);
   }

   return EXIT_SUCCESS;
}
