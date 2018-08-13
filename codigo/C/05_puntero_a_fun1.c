#include <stdio.h>

void fun1(int i);
void fun2(int i);
void mensaje(void (*f)(int), int n);
void ejemplo(int w);
     
int main(void)
{
   printf("Llamo a ejemplo con 1\n");
   ejemplo(1);

   printf("Llamo a ejemplo con 0\n");
   ejemplo(0);

   return 0;
}

void fun1(int i)
{
   printf ("fun1 dice %d\n", i);
}
     
void fun2(int i)
{
   printf ("fun2 dice %d\n", i);
}
     
void mensaje(void (*f)(int), int n)
{
   int i;
   for (i=1; i<=n; i++)
      f(i);  // es equivalente a (*f)(i)
}
     
void ejemplo(int w)
{
   void (*pf)(int) = &fun2; // el & es opcional
   if (w)
      pf = fun1;
   mensaje(pf, 3);
}













