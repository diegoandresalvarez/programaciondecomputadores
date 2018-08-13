#include <stdio.h>
#include <float.h>

// gcc 02_evite_usar_float.c -o 02_evite_usar_float

int main(void)
{
   printf("FLT_DIG     = %d\n", FLT_DIG);   
   // FLT_DIG es el número máximo de dígitos decimales (en base 10) que se 
   // pueden representar sin perder precisión por un float
   
   printf("DBL_DIG     = %d\n\n", DBL_DIG);   
   // DBL_DIG es el número máximo de dígitos decimales (en base 10) que se 
   // pueden representar sin perder precisión por un double   
   
   printf("%16.4f %16.4f\n", (float)         6.98, (float)         5.31);   
   printf("%16.4f %16.4f\n", (float)        26.98, (float)        25.31);   
   printf("%16.4f %16.4f\n", (float)       126.98, (float)       125.31);

   // De aquí en adelante tenemos más de 6 dígitos decimales (FLT_DIG), por lo 
   // tanto se esperan aproximaciones, no el resultado correcto
   printf("%16.4f %16.4f\n", (float)      4126.98, (float)      4125.31);
   printf("%16.4f %16.4f\n", (float)     34126.98, (float)     34125.31);
   printf("%16.4f %16.4f\n", (float)    334126.98, (float)    334125.31);
   printf("%16.4f %16.4f\n", (float)   3334126.98, (float)   3334125.31);
   printf("%16.4f %16.4f\n", (float)  33334126.98, (float)  33334125.31);
   printf("%16.4f %16.4f\n", (float) 333334126.98, (float) 333334125.31);
   
   // ahora imprimiendo dos doubles
   printf("%16.4f %16.4f\n",         333334126.98,         333334125.31);   
   return 0;  
}

