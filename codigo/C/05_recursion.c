#include<stdio.h>
#include<stdbool.h>

bool es_primo(int, int);

int main()
{
   int i;

   for (i=1; i<100; i++)
      if (es_primo(i, i/2)) printf("%d, ", i);
         
   printf("\b\b.\n");

   return 0;
}

bool es_primo(int n, int i)
{
   if (n == 1)   return false; // el número 1 no es primo
   if (i == 1)   return true;
   if (n%i == 0) return false; // es divisible entre i?
   return es_primo(n, i-1);
}
