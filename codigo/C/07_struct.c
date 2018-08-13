#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

// gcc -Wall -o 07_struct 07_struct.c

typedef struct
{
   int cod;
   char nombre[100];
   char sexo;
} persona;

void vaciar_buffer_teclado(void);
void leer_cadena(int n, char cad[n]);

int main()
{
   int i, n;
   char tmp[100];

   printf("Numero de personas = ");
   scanf("%d", &n); vaciar_buffer_teclado();

   persona p[n];
   for (i=0; i<n; i++)
   {
      printf("PERSONA %d:\n", i+1);
      printf("Codigo   = ");
      scanf("%d", &(p[i].cod)); vaciar_buffer_teclado();

      printf("Nombre   = ");
      leer_cadena(sizeof(p[i].nombre), p[i].nombre);

      printf("Sexo M/F = ");
      scanf("%s", tmp); vaciar_buffer_teclado();
      p[i].sexo = toupper(tmp[0]);

      printf("\n");
   }

   puts("\n----------------------------------------------------------------\n");

   for (i=0; i<n; i++)
   {
      printf("PERSONA %2d:\n",    i+1);
      printf("Codigo   = %d\n",   p[i].cod);
      printf("Nombre   = %s\n",   p[i].nombre);
      printf("Sexo M/F = %c\n\n", p[i].sexo);
   }

   return 0;
}
 
void vaciar_buffer_teclado(void)
{
   int c;
   while((c = getchar()) != '\n' && c != EOF);
   return;
}

void leer_cadena(int n, char cad[n])
{
   char *p;
   if (fgets(cad, n, stdin) == NULL) exit(EXIT_FAILURE);
   if ((p = strchr(cad, '\n')) != NULL) *p = '\0'; // remueva el \n
   return;
}
