#include <stdio.h>
#include <string.h>

// gcc -Wall -o 03_problem_scanf 03_problem_scanf.c

int main()
{
   int edad;
   char nombre[80];
   char *p;
      
   printf("Entre su edad: ");
   scanf("%d", &edad);

   printf("Entre su nombre: ");
   if (fgets(nombre, sizeof(nombre), stdin) == NULL) return 1;
   if ((p = strchr(nombre, '\n')) != NULL) *p = '\0'; // remueva el \n
   // NOTA: este mismo problema hubiera sucedido con
   // gets(nombre) o con scanf("%[^\n]s",nombre)
   
   printf("%s tiene %d años\n", nombre, edad);
   
   return 0;
}
