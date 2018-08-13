#include <stdio.h>
// Compile con: gcc -Wall -o 05_puntero_a_fun2 05_puntero_a_fun2.c
double suma          (double a, double b);
double resta         (double a, double b);
double multiplicacion(double a, double b);
double division      (double a, double b);
double aritmetica_con_switch(double a, double b, char opcion);
double aritmetica_con_puntero(double a, double b, double (*op)(double, double));

int main(void)
{
   printf("La suma de 2 y 5 es = %f\n", aritmetica_con_switch (2, 5, '+'));
   printf("La suma de 2 y 5 es = %f\n", aritmetica_con_puntero(2, 5, suma));
   return 0;
}

double suma          (double a, double b) { return a+b; }
double resta         (double a, double b) { return a-b; }
double multiplicacion(double a, double b) { return a*b; }
double division      (double a, double b) { return a/b; }

double aritmetica_con_switch(double a, double b, char opcion)
{
   double r;
   switch(opcion)
   {
      case '+' : r = suma          (a, b); break;
      case '-' : r = resta         (a, b); break;
      case '*' : r = multiplicacion(a, b); break;
      case '/' : r = division      (a, b); break;
   }
   return r;
}

double aritmetica_con_puntero(double a, double b, double (*op)(double, double))
{
   return op(a, b);    // llamado del puntero a funcion
}


