#include <stdio.h>
#include <float.h>

// Compile con: gcc -Wall -o 02_DBL_EPSILON 02_DBL_EPSILON.c

int main(void)
{
   if ((1.0 + DBL_EPSILON)   > 1.0) printf("(1.0 + DBL_EPSILON) > 1.0\n");
   if ((1.0 + DBL_EPSILON/2) > 1.0) printf("(1.0 + DBL_EPSILON/2) > 1.0\n");

   return 0;
}

/*
#include <stdio.h>

typedef union {
  long long int i64;
  double d64;
} dbl_64;

int main(void)
{
    dbl_64 s;
    s.d64 = 1;
    s.i64++;
    printf("DBL_EPSILON = %.20g\n", s.d64 - 1);

    return 0;
}
*/

/*
// NO SE PORQUE NO FUNCIONA
#include <stdio.h>

int main(void)
{
   double EPS = 1;

   printf( "EPS                             1 + EPS\n" );
    do
    {
       printf("%25.25g\t%25.25f\n", EPS, (1 + EPS));
       EPS /= 2;
    }
    while ((1 + (EPS/2)) > 1);
 
    printf( "\nCalculated Machine epsilon: %.25g\n", EPS);
    return 0;
}
*/