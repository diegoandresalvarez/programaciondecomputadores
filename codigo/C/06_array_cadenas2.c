#include<stdio.h>
#include<string.h>

// Compile con: gcc -Wall -o 06_array_cadenas2 06_array_cadenas2.c

int main(void)
{
   int i;
   
   char cad[][10] = {"Saludos", "a", "todos"};
   for(i=0; i<3; i++) printf("%2d:\t%s\n",i,cad[i]);

   char nombre[] = "Pepito";
   strcpy(cad[2], nombre);
   for(i=0; i<3; i++) printf("%2d:\t%s\n",i,cad[i]);
   
   return 0;
}







