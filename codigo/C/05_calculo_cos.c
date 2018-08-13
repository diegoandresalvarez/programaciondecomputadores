#include <stdio.h>

// gcc -Wall -o 05_calculo_cos 05_calculo_cos.c

long long int factorial(int n);
double potencia(double x, int n);
double absoluto(double x);
double coseno(double x);

int main(void)
{
    double t = 3.14159265358979/2;        
    printf("cos(%f) = %g\n", t, coseno(t));
    return 0;   
}

long long int factorial(int n)
{
    if (n==1 || n==0) 
        return 1;
    else
        return n*factorial(n-1);
}

double potencia(double x, int n)
{
    int i;
    double tmp = 1;
    for (i=0; i<n; i++) tmp *= x;
    return tmp;
}

double absoluto(double x)
{
    return (x<0) ? -x : x;
}

double coseno(double x)
{
    int m = 1;
    double res = 1.0, res_old = 0.0;
  
    while(absoluto(res - res_old) > 1e-13)
    {
        res_old = res;
        res += potencia(-1.0, m)*potencia(x,2*m)/(double)factorial(2*m);
        printf("%g %g\n", res, res_old);
        m++;
    }
    return res;
 }