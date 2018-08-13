#include <stdio.h>

// gcc -Wall 08_truco_arrays_cadenas.c

int main()
{
   char *lista[] = {"uno", "dos", "tres", NULL};
   char **p;
   for(p=lista; *p!=NULL; p++)
      printf("%s\n", p[0]);
   return 0;
}

