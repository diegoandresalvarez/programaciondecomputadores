#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   // escribir el array a un archivo
   FILE *f1 = fopen("file.bin", "wb");
   char buffer[] = { 'x' , 'y' , 'z' };
   int ret_code = fwrite(buffer, sizeof(char), sizeof(buffer), f1);
   if (ret_code < (int)sizeof(buffer))
      if (ferror(f1))
      {
         perror("fwrite()");
         fprintf(stderr,"fwrite() failed in file %s at line # %d\n", __FILE__,__LINE__-5);
         exit(EXIT_FAILURE);
      }
   fclose(f1);

   //leer el array desde el archivo e imprimirlo en pantalla
   FILE *f2 = fopen("file.bin", "rb");
   char rbuf[10];
   const char* res = fgets(rbuf, sizeof(rbuf), f2);
   fclose(f2);

   if (res)   // apunta a rbuf en caso de éxito y a NULL en caso de fracaso
      puts(res);

   return EXIT_SUCCESS;
}
