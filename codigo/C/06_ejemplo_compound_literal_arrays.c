#include<stdio.h>
#include<math.h>  // aquí esta definido isnan() y NAN

// Compile con:
// gcc -Wall -o 06_ejemplo_compound_literal_arrays 06_ejemplo_compound_literal_arrays.c -lm

double suma(double v[]);

int main(void)
{
   double p[] = {1.0, 2.0, 3.0, 4.0, 5.0, NAN};

   printf("suma = %f\n", suma(p));
   
   // Observe que usando un compound literal paso un array como un argumento a
   // una función. El final del array se indica con NAN
   printf("suma = %f\n", suma((double[]){1.0, 2.0 ,3.0, 4.0, 5.0, NAN}));

   return 0;
}

double suma(double v[])
{
   int i;
   double sum = 0.0;

   for (i=0; !isnan(v[i]); i++)
      sum += v[i];

   return sum;
}

