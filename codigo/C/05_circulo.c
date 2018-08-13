#include<stdio.h>

// gcc -Wall -o 05_circulo 05_circulo.c

// Definicion de constantes
const double PI = 3.141592;

// Prototipo de la funcion
void circulo(double, double *, double *);

int main(void)
{
   double r, p, A;
   
   printf("Entre el radio = ");
   scanf("%lf", &r);
   circulo(r,&p,&A);
   printf("Perimetro = %f\n", p);
   printf("Area      = %f\n", A);

   return 0;
}

void circulo(double radio, double *perim, double *area)
{
   *perim = 2*PI*radio;
   *area  = PI*radio*radio;
}

