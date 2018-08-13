#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_leer_archivo.c -o 09_leer_archivo

int main()
{
   int codigo;
   char nombre[30];
   double nota;

   FILE *f = fopen("estudiantes.dat", "r"); // abra el archivo para lectura
   if (f == NULL)
   {
      perror("fopen()");
      fprintf(stderr, "No se pudo abrir el archivo\n");
      exit(EXIT_FAILURE);
   }

   printf("%-10s%-13s%s\n", "Codigo", "Nombre", "Nota" );

   // lea el contenido del archivo
   while (fscanf(f, "%d%s%lf", &codigo, nombre, &nota) != EOF)
   {
      printf("%-10d%-13s%4.2f\n", codigo, nombre, nota);
   }

   fclose(f); // cierre el archivo

   return EXIT_SUCCESS;
}
