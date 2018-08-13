#include <stdio.h>

// gcc 08_typedef_con_punteros.c -o 08_typedef_con_punteros

typedef char* cadena;

int main(void)
{
   cadena lista[] = {"uno", "dos", "tres", "cuatro", NULL};
   cadena *p;
   for (p = lista; *p != NULL; p++)
      puts(*p);

   return 0;
}

