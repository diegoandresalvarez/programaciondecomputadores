#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_fgets_fputs.c -o 09_fgets_fputs


int main(void)
{
   char buf[8];   
   FILE* f = fopen("mi_archivo","wb+");
   fputs("Alan Turing\n", f);      // guarda cadenas en el archivo
   fputs("John von Neumann\n", f);
   fputs("Alonzo Church\n", f);
      
   // imprime el contenido del archivo 
   rewind(f);                      // regresa al inicio del archivo
   while (fgets(buf,sizeof(buf),f) != NULL) printf("\"%s\"\n", buf);
   rewind(f);                      // regresa al inicio del archivo  
   while (fgets(buf,sizeof(buf),f) != NULL) fputs(buf, stdout);   

   // razones del por qué se obtuvo el NULL
   if (feof(f))                    // llegamos al final del archivo
      puts("*** EOF ***");
   else if (ferror(f))             // algún otro error
   {
      perror("fgets()");
      exit(EXIT_FAILURE);
   }
   fclose(f);

   return EXIT_SUCCESS;
}
