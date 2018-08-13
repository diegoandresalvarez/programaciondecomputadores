#include<stdio.h>

// Compile con: gcc -Wall -o 06_array_cadenas 06_array_cadenas.c

int main(void)
{
   int i;

   char cad1[][10] = {"Saludos", "a", "todos"};
   for(i=0; i<3; i++) printf("%2d:\t%s\n",i,cad1[i]);
   printf("sizeof(cad1) = %d\n\n", sizeof(cad1));

   char *cad2[3];       // array de tres punteros
   cad2[0] = "x";       // el primer  puntero apunta a "x"
   cad2[1] = "y";       // el segundo puntero apunta a "y"
   cad2[2] = "abcdefghijklmnopqrstuvwxyz"; // 26 letras
   for(i=0; i<3; i++) printf("%2d:\t%s\n",i,cad2[i]);

   printf("sizeof(cad2) = %d\n\n", sizeof(cad2));

   return 0;
}

