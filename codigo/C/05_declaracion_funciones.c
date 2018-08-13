#include <stdio.h>

// gcc -Wall -o 05_declaracion_funciones 05_declaracion_funciones.c

// double fun(double x);

int main(void)
{
    double d = fun(1.0);
    printf("fun(1.0) = %f\n", d);
    return 0;
}

double fun(double x) { return 2.8; };

