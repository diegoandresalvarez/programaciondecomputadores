#include <stdio.h>

// gcc -Wall -o 05_agotando_memoria_pila 05_agotando_memoria_pila.c

int n;

void llamando_a_funcion();

int main(void)
{
	llamando_a_funcion();
   return 0;
}

void llamando_a_funcion()
{
   printf("%d\n", n++);
   llamando_a_funcion();
}

