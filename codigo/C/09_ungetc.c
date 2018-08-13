#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_ungetc.c -o 09_ungetc

int main(void)
{
   FILE* fp = fopen("test.txt", "w");
   fputs("abc\n", fp);
   fclose(fp);
   
   fp = fopen("test.txt", "r");

   // leer "abc" y escribir "abbc"
   char ch;  
   ch = fgetc(fp); putchar(ch); // leer "a" y escribirlo
   ch = fgetc(fp); putchar(ch); // leer "b" y escribirlo   
   int ret_code = ungetc(ch, fp);   // retornar "b" al archivo
   
   // ungetc() retorna EOF si hubo errores
   if (ret_code == EOF)
      if (ferror(fp))
      {
         perror("ungetc()");
         fprintf(stderr,"ungetc() failed in file %s at line # %d\n", __FILE__,__LINE__-7);
         exit(EXIT_FAILURE);
      }

   ch = fgetc(fp); putchar(ch); // releer "b" y escribirlo
   ch = fgetc(fp); putchar(ch); // leer "c" y escribirlo   
   putchar('\n');

   fclose(fp);
   
   return EXIT_SUCCESS;
}
