#include<stdio.h>
#include<limits.h>

int n          = INT_MAX;
unsigned int u = UINT_MAX;
short int s    = SHRT_MAX;

int main(void)
{
   printf("n = %d\n", n); n++;
   printf("n = %d\n", n);

   printf("u = %u\n", u); u++;
   printf("u = %u\n", u);

   printf("s = %d\n", s); s++;
   printf("s = %d\n", s);
   
   return 0;
}

