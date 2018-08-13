#include<stdio.h>

// gcc -Wall -o 06_filas_matriz 06_filas_matriz.c

void imprimir_vector1(int n, int *v);
void imprimir_vector2(int n, int v[]);

int main(void)
{
    int M[][5] = {{ 1,  2,  3,  4,  5},
                  { 6,  7,  8,  9, 10},
                  {11, 12, 13, 14, 15},
                  {16, 17, 18, 19, 20}};

    imprimir_vector1(5, M[2]);
    imprimir_vector2(5, M[2]);

    return 0;
}

void imprimir_vector1(int n, int *v)
{
    int i;
    for(i=0; i<n; i++) printf("%d, ", v[i]);
    printf("\b\b.\n");
}

void imprimir_vector2(int n, int v[])
{
    int i;
    for(i=0; i<n; i++) printf("%d, ", v[i]);
    printf("\b\b.\n");
}


