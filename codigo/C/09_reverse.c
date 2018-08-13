// Muestra un archivo en orden reverso.
#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_reverse.c -o 09_reverse -std=c99

// marcador de EOF en archivos de texto de MS-DOS
#define CTRL_Z 0x1A

int main(void)

{
   char file[] = "09_reverse.c";
   
   // abra archivo para lectura en modo binario
   FILE *fp = fopen(file,"rb"); 
   if (fp == NULL)
   {
      printf("No se pudo abrir el archivo %s\n", file);
      exit(EXIT_FAILURE);
   }
   fseek(fp, 0L, SEEK_END); // vaya al final del archivo
   long int last = ftell(fp);

   for (long int count = last-1; count >= 0; count--)
   {
      fseek(fp, count, SEEK_SET); // avance
      int ch = getc(fp);

      #if defined _WIN32 || defined _WIN64 || defined __linux__
      // para MS-DOS (funciona con UNIX)
      if ((ch != '\r') && (ch != CTRL_Z))
         putchar(ch);
      #elif defined __APPLE__
      // Para MAC
      if (ch == '\r')
         putchar('\n');
      else
         putchar(ch);
      #endif
   }
   putchar('\n');
   fclose(fp);
   return 0;
}


