#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000
#define DATO_NO_ENCONTRADO -1

// gcc -Wall -o 06_alg_busqueda 06_alg_busqueda.c

int i, x[N];

inline int comparar(const void *arg1, const void *arg2);
inline void intercambiar(int *a, int *b);
int busqueda_binaria(int v[], int buscado, int imin, int imax);

int main(void)
{
   int dato_buscado, pos;
   int *puntero_a_dato;

   // Inicializar el generador de numeros aleatorios
   srand(time(NULL));

   // Inicializar el vector x
   for (i=0; i<N; i++) x[i] = N*(double) rand()/RAND_MAX;

   // Ordenar el vector x
   qsort(x, N, sizeof(x[0]), comparar);

   // Imprimir el vector x ordenado
   // for (i=0; i<N; i++) printf("x[%d] = %5d\n", i, x[i]);

   // Se define el dato a buscar
   dato_buscado = 90;
   
   // Algoritmo 1:
   puts("\nFuncion busqueda_binaria()");
   pos = busqueda_binaria(x, dato_buscado, 0, N-1);
   if (pos == DATO_NO_ENCONTRADO)
      printf("El numero %d no se encuentra en el array x\n", dato_buscado);
   else
      printf("El numero %d se encuentra en la posicion %d\n", dato_buscado, pos);	

   // Algoritmo 2:
   puts("\nFuncion bsearch() (stdlib.h)");
   puntero_a_dato = (int*)bsearch(&dato_buscado, x, N, sizeof(x[0]), comparar);   
   if (puntero_a_dato == NULL)
      printf("El numero %d no se encuentra en el array x\n", dato_buscado);
   else
      printf("El numero %d se encuentra en la direccion de memoria %d\n", *puntero_a_dato, puntero_a_dato-x);

   return 0;
}

inline void intercambiar(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

/* Prototipo de la función comparar(), utilizada en qsort() */
inline int comparar(const void *a, const void *b)
{
   return (*(int*)a - *(int*)b);
}

int busqueda_binaria(int v[], int buscado, int imin, int imax)
{
  // busque mientras [imin, imax] no sea vacio
   while (imax >= imin)
   {
      // calcule el punto medio
      int imitad = imin + (imax-imin)/2;
		printf("imin = %d, imax = %d, imitad = %d\n", imin, imax, imitad);
	
      // determine en que subarray buscar
      if (v[imitad] < buscado)
         // cambien el indice min de modo que busque en el array derecho
         imin = imitad + 1;
      else if (v[imitad] > buscado)
         // cambien el indice max de modo que busque en el array izquierdo
         imax = imitad - 1;
      else
		   // se encontro el dato buscado en la posición imitad
         return imitad;
		
   }
    
   // no se encontró nada
   return DATO_NO_ENCONTRADO;
}
