#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   FILE* tmpf = tmpfile();
   fputs("abcde\n", tmpf);
   rewind(tmpf);

   int ch;
   while ((ch=fgetc(tmpf)) != EOF) // leer caracteres incluyendo en \n
      putchar(ch);

   // verificar las razones por las cuales se alcanzó el EOF
   if (feof(tmpf))         // se alcanzó el final del archivo
      puts("End of file reached successfully");
   else if (ferror(tmpf))  // falla causada por otro error
   {
      perror("fgetc()");
      fprintf(stderr,"fgetc() failed in file %s at line # %d\n", __FILE__,__LINE__-9);
      exit(EXIT_FAILURE);
   }

   return EXIT_SUCCESS;
}
