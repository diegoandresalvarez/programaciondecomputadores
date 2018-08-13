#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_imprimir_archivo.c -o 09_imprimir_archivo

int main(void)
{
   int ch;   
   unsigned long conteo = 0;
   char nombre_archivo[] = "09_imprimir_archivo.c";
   
   FILE *fp = fopen(nombre_archivo, "r");
   if (fp == NULL)
   {
      fprintf(stderr, "Error abriendo el archivo \"%s\".", nombre_archivo);
      exit(EXIT_FAILURE);
   }
   
   while((ch = getc(fp)) != EOF)
   {
      putc(ch, stdout); // es lo mismo que putchar(c);
      conteo++;      
   }
   
   fclose(fp);
   
   fprintf(stdout, "El archivo \"%s\", tiene %ld caracteres\n", nombre_archivo, conteo);
   
   return EXIT_SUCCESS;
}

