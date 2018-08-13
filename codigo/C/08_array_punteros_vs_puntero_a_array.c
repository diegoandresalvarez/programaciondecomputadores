#include <stdio.h>

// gcc -Wall -o 08_array_punteros_vs_puntero_a_array 08_array_punteros_vs_puntero_a_array.c

int main(void)
{
   double *vec1[3];     // array de tres punteros "double *"
   double (*vec2)[3];   // puntero a un array de 3 doubles

   printf("sizeof(vec1) = %d\n", sizeof(vec1));
   printf("sizeof(vec2) = %d, sizeof(*vec2) = %d\n", sizeof(vec2), sizeof(*vec2));

   return 0;
}

