#include<stdio.h>

void min_max_array(const int *v, int n, int *min_v, int *max_v);

int main(void)
{
    int x[10] = {1, 2, 5, 2, -3, 4, 2, -54, 100, 4};
    int minimo_x, maximo_x;

    min_max_array(x, 10, &minimo_x, &maximo_x);
    printf("El minimo y maximo valor de x[] es %d y %d respectivamente\n",
           minimo_x, maximo_x);

    return 0;
}

void min_max_array(const int *v, int n, int *min_v, int *max_v)
{
    *min_v = *max_v = v[0];

    for(int i=0; i<n; i++)
    {
        if (*min_v > v[i]) *min_v = v[i];
        if (*max_v < v[i]) *max_v = v[i];
    }
    return;
}



