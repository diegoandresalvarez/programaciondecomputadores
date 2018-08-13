#include <stdio.h>
#include <string.h>

// gcc -Wall -o 03_sol_problem_scanf 03_sol_problem_scanf.c

void vaciar_buffer_del_teclado(void);

int main()
{
   int edad;
   char nombre[80], *p;
	
   printf("Entre su edad: "); scanf("%d", &edad);
	vaciar_buffer_del_teclado();
	
   printf("Entre su nombre: ");
   if (fgets(nombre, sizeof(nombre), stdin) == NULL) return 1;
	
   if ((p = strchr(nombre, '\n')) != NULL) *p = '\0'; // remueva el \n
   
   printf("%s tiene %d años\n", nombre, edad);
	
   return 0;
}

void vaciar_buffer_del_teclado(void)
{
	int c;
   while((c = getchar()) != '\n' && c != EOF); // vaciamos el buffer del teclado
}
	
	