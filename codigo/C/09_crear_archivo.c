#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 09_crear_archivo.c -o 09_crear_archivo

int main()
{
   int codigo;
   char nombre[30];
   double nota;

   FILE *f = fopen("estudiantes.dat", "w"); // abra el archivo
   if (f == NULL)
   {
      perror("fopen()");
      fprintf(stderr, "No se pudo abrir el archivo\n");
      exit(EXIT_FAILURE);
   }

   puts("Entre el código, nombre y nota.\n");
   puts("Entre EOF para terminar la entrada.\n");
   printf("> ");
   scanf("%d%s%lf", &codigo, nombre, &nota);

   // escriba lo leido a un archivo
   while (!feof(stdin))
   {
      fprintf(f, "%d %s %.2f\n", codigo, nombre, nota);
      printf("> ");
      scanf("%d%s%lf", &codigo, nombre, &nota);
   }

   puts("\nGrabando la información a estudiantes.dat\n\n");
   fclose(f); // cierre el archivo

   return EXIT_SUCCESS;
}

