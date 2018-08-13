#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#define N 100000
#define N 50

// gcc -Wall -o 06_alg_ordenamiento 06_alg_ordenamiento.c

int i, x[N], v1[N], v2[N], v3[N];
unsigned int intercambios;
unsigned int comparaciones;

inline int comparar(const void *arg1, const void *arg2);
inline void intercambiar(int *a, int *b);
int colocar(int *v, int ini, int fin);
void Quicksort(int *v, int ini, int fin);
void Burbuja(int *v, int fin);

int main(void)
{
   clock_t start, stop;

   // Inicializar el generador de numeros aleatorios
   srand(time(NULL));

   // Inicializar el vector x
   for (i=0; i<N; i++)
      x[i] = 100000*(double) rand()/RAND_MAX;

   memcpy(v1, x, N*sizeof(int)); // copiar el vector x a v1
   memcpy(v2, x, N*sizeof(int)); // copiar el vector x a v2
   memcpy(v3, x, N*sizeof(int)); // copiar el vector x a v3

   puts("\nFuncion Quicksort()");
   intercambios = comparaciones = 0;
   start = clock();
   Quicksort(v1, 0, N-1);
   stop = clock(); 
   printf("Tiempo empleado = %8.4f s.\n", (double) (stop-start)/CLOCKS_PER_SEC);
   printf("intercambios = %d, comparaciones = %d\n", intercambios, comparaciones);

   puts("\nFuncion qsort() (stdlib.h)");
   intercambios = comparaciones = 0;
   start = clock();   
   qsort(v2, N, sizeof(v2[0]), comparar);
   stop = clock(); 
   printf("Tiempo empleado = %8.4f s.\n", (double) (stop-start)/CLOCKS_PER_SEC); 
   printf("comparaciones = %d\n", comparaciones);

   puts("\nFuncion Burbuja()");
   intercambios = comparaciones = 0;
   start = clock();
   Burbuja(v3, N-1);
   stop = clock();
   printf("Tiempo empleado = %8.4f s.\n", (double) (stop-start)/CLOCKS_PER_SEC);
   printf("intercambios = %d, comparaciones = %d\n\n", intercambios, comparaciones);

   if (N<100) // no es práctico imprimir más de 100 elementos
      for (i=0; i<N; i++)
         printf("x[%d] = %5d, \t v1[%d] = %5d, \t v2[%d] = %5d, \t v3[%d] = %5d\n",
               i, x[i], i, v1[i], i, v2[i], i, v3[i]);
   

   return 0;
}

inline void intercambiar(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
   intercambios++;
}

int colocar(int *v, int ini, int fin)
{
   int i;

   // Selección del pivote. Aqui se selecciono el primer elemento de v[]
   int pos_pivote       = ini;
   int valor_pivote = v[pos_pivote];

   for (i=ini+1; i<=fin; i++)
   {
      comparaciones++;
      if (v[i]<valor_pivote)  // poner a la izquierda del pivote los elementos
      {                       // menores que el pivote
         pos_pivote++;
         intercambiar(&v[i], &v[pos_pivote]);
      }
   }
   intercambiar(&v[ini], &v[pos_pivote]);
   return pos_pivote;
}

void Quicksort(int *v, int ini, int fin)
{
   // v vector a ordenar
   // ini primer elemento
   // fin ultimo elemento

   if (ini >= fin) return;

   int pos_pivote = colocar(v, ini, fin);
   Quicksort(v, ini, pos_pivote-1);
   Quicksort(v, pos_pivote+1, fin);
}

void Burbuja(int *v, int fin)
{
   int i, j;

   for (i = 0; i<fin; i++)
      for (j = i+1; j<=fin; j++)
      {
         comparaciones++;
         if (v[i]>v[j]) intercambiar(&v[i], &v[j]);
      }
}

/* Prototipo de la función comparar(), utilizada en qsort() */
inline int comparar(const void *a, const void *b)
{
   comparaciones++;
   return (*(int*)a - *(int*)b);
}