#include<stdio.h>
#include<limits.h>
/*
Compile con:
gcc -std=c99 -Wall -o limites_para_enteros limites_para_enteros.c
*/
int main(void)
{
   printf("char:\n");
   printf("sizeof     = %d\n", (int) sizeof(char));
   printf("CHAR_BIT   = %d\n", CHAR_BIT);
   printf("SCHAR_MIN  = %d\n", SCHAR_MIN);
   printf("SCHAR_MAX  = %d\n", SCHAR_MAX);
   printf("UCHAR_MAX  = %d\n", UCHAR_MAX);
   printf("CHAR_MIN   = %d\n", CHAR_MIN);
   printf("CHAR_MAX   = %d\n", CHAR_MAX);
   printf("\n");
   printf("long long:\n");
   printf("sizeof     = %d\n",  (int) sizeof(long long));
   printf("LLONG_MIN  = %lld\n", LLONG_MIN);
   printf("LLONG_MAX  = %lld\n", LLONG_MAX);
   printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
   printf("\n");

   return 0;
}

