#include <complex.h>
#include <stdio.h>

// Compile con: gcc -std=c99 -Wall -o 02_complex 02_complex.c -lm

int main(void)
{
   complex y, z = 1.0 + 3.0*I;

   printf("Parte real       = %f\n", creal(z));
   printf("Parte imaginaria = %f\n", cimag(z));
   printf("Fase             = %f\n", carg(z));
   printf("Modulo           = %f\n", cabs(z));
   y = conj(z);
   printf("Conjugado        = %.2f %+.2f i\n", creal(y), cimag(y));

   return 0;
}
