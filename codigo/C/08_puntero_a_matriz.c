#include <stdio.h>

// gcc -Wall -o 08_puntero_a_matriz 08_puntero_a_matriz.c

int main(void)
{
   // "nombre" es un puntero a una cadena definida en el segmento de datos
   int i,j;
   int matriz[3][4] = {{ 1,  2,  3,  4},
                       { 5,  6,  7,  8},
                       { 9, 10, 11, 12}};
   
   int (*p)[3][4]; // puntero a una matriz [3][4]
   p = &matriz;
   
   for(i=0; i<3; i++) 
   {
      for(j=0; j<4; j++) 
         printf("%2d ", (*p)[i][j]);
      printf("\n");
   }
   
   return 0;
}

