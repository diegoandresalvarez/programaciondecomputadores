#include <stdio.h>
#include <stdlib.h>
#define LONG_MAX_VECTOR 100

typedef struct
{
  int n;
  int x[LONG_MAX_VECTOR];
} vector;

vector mi_fun(int n);

int main(void)
{
   vector v = mi_fun(20);
   for (int i=0; i<v.n; i++) printf("%d, ", v.x[i]);
   printf("\b\b.\n");   
   return 0;
}

vector mi_fun(int n)
{
   if (n > LONG_MAX_VECTOR)
   {  
      fprintf(stderr, "Error en la longitud del vector\n");
      exit(EXIT_FAILURE);
   }
   vector x;   
   for (int i=0; i<n; i++) x.x[i] = 2*(i+1);
   x.n = n;   
   return x;   
}

