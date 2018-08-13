#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_fgetc.c -o 09_fgetc

int main(void)
{
   FILE* tmpf = tmpfile();     // se crea un archivo temporal
   fputs("abcde\n", tmpf);     // se guarda la cadena "abcde\n" en dicho archivo

   rewind(tmpf);               // nos desplazamos al inicio del archivo

   int ch;
   while ((ch=fgetc(tmpf)) != EOF)  // se leen los caracteres del archivo
      putchar(ch);                  // y se imprimen

   // Verificar las dos razones por las que se pudo alcanzar un EOF:
   if (feof(tmpf))             // se llegó al final del archivo
      puts("Hemos alcanzado el final del archivo (EOF)");
   else if (ferror(tmpf))      // el error lo produjo alguna otra condición
   {
      perror("fgetc()");
      exit(EXIT_FAILURE);
   }

   return EXIT_SUCCESS;
}
