#include<stdio.h>
#include<math.h>

// gcc -Wall -o 08_punteros_a_funciones 08_punteros_a_funciones.c -lm

double integral(double (*f)(double), double a, double b);
inline double mifun(double x);

int main(void)
{
   double (*ff)(double (*)(double ), double, double);

   ff = integral;
   printf("int_0^{pi/2} sin(x) dx = %f\n", ff(mifun,0,M_PI_2));

   return 0;
}

// Calcule int_a^b f(x) dx
double integral(double (*f)(double), double a, double b)
{
   double  suma = 0.0, dt = (b-a)/10000000.0;
   int i;

   // Integración por sumas de Riemann
   for (i=0;  i<10000000;  i++)
      suma += f(i*dt + a);  // es equivalente a: suma += (*f)(i*dt + a);
   return suma*dt;
}

inline double mifun(double x)
{
   return sin(x);
}

