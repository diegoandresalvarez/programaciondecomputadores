#include<stdarg.h>
#include<stdio.h>

int sumar_varios_numeros(int n, ...);

int main(void)
{
   printf("La suma es %d\n", sumar_varios_numeros(5, 10, 20, 30, 40, 50));
   return 0;
}

int sumar_varios_numeros(int n, ...)
{
   int i, suma = 0;
   
   va_list par;                   // Declare una variable de tipo "va_list"    
   va_start (par, n);             // Llame a la función "va_start"
     
   for (i=0; i<n; i++)
      suma += va_arg(par, int);   // obtener valores de parametros adicionales

   va_end (par);                  // terminar el uso de parametros adicionales
     
   return suma;
}
