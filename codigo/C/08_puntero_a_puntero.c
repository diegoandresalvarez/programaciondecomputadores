#include <stdio.h>

// gcc -Wall -o 08_puntero_a_puntero 08_puntero_a_puntero.c

int main(void)
{
   // "nombre" es un puntero a una cadena definida en el segmento de código
   char *nombre = "Pepito Perez";

   char **p1; // puntero a un puntero (char *)
   p1 = &nombre;

   char ***p2; // puntero a puntero que apunta a un puntero (char *)
   p2 = &p1;

   printf("El nombre es %s\n", nombre);
   printf("El nombre es %s\n", *p1);
   printf("El nombre es %s\n", **p2);

   return 0;
}

