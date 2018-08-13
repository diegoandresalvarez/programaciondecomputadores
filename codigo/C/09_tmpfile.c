#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_tmpfile.c -o 09_tmpfile

int main(void)
{
   FILE* tmpf = tmpfile(); // abre el archivo temporal como "wb+"
   if (tmpf == NULL)
   {
      perror("tmpfile()");
      fprintf(stderr,"tmpfile() failed in file %s at line # %d", __FILE__,__LINE__-4);
      exit(EXIT_FAILURE);
   }

   fputs("Hello, world", tmpf);   // escribe en el archivo temporal
   rewind(tmpf);                  // "rebobina" al principio del mismo
   char buf[6];
   fgets(buf, sizeof(buf), tmpf); // lee una cadena del archivo de 5 chars y el \0
   printf("%s\n", buf);           // y la imprime

   return EXIT_SUCCESS;
}
