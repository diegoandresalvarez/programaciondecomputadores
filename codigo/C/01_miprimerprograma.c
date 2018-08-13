/*
   Este programa sirve para calcular el perimetro y el area
   de una circunferencia, dado el radio del mismo.
*/
#include <stdio.h> 

// Se ponen los encabezados de las funciones
double perimetro(double r);

// Se definen las constantes
const double PI = 3.14159265358979;

// Se definen las variables
double r, A, p;

int main(void)
{
   // Entramos los datos
   printf("Entre el radio (en m) = ");
   scanf("%lf",&r);   // el %lf quiere decir que esperamos un double

   // Ahora realizamos los calculos
   p = perimetro(r);  // se llama a la función perimetro()
   A = PI*r*r;        // Se calcula el área

   // Finalmente se imprimen los resultados
   printf("El perimetro del circulo es %f m y su area es %f m^2\n", p, A);

   // Codigo de salida exitoso es 0
   return 0;
}

// Definicion de funciones
double perimetro(double r)
{
   return (2*PI*r);
}

