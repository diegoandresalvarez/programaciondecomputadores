#include<stdio.h>

// gcc 08_puntero_a_constante2.c -o 08_puntero_a_constante2

int suma(int n, const int *v);

int main(void)
{
   int i;
   int r[5] = {10, 20, 30, 40, 50};
   int s = suma(5,r);
   printf("r = ");
   for(i=0; i<5; i++)
      printf("%d ",r[i]);
   printf("\n");
   return 0;
}

int suma(int n, const int *v) //El parámetro es puntero a constante entera
{
   int i, suma=0;
   for(i=0; i<n; i++) suma += v[i];
   v[2] = 1000; // ERROR!!!
   return suma;
}


/*
#include<stdio.h>

// gcc 08_puntero_a_constante2.c -o 08_puntero_a_constante2

int suma(int n, int *v);

int main(void)
{
   int i;
   int r[5] = {10, 20, 30, 40, 50};
   int s = suma(5,r);
   printf("r = ");
   for(i=0; i<5; i++)
      printf("%d ",r[i]);
   printf("\n");
   return 0;
}

int suma(int n, int *v) //El parámetro es puntero a entero
{
   int i, suma=0;
   for(i=0; i<n; i++) suma += v[i];
   v[2] = 1000; // Paso por referencia
   return suma;
}

*/

