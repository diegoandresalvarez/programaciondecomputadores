#include<stdio.h>

// Compile con: gcc -Wall -o 05_global_vs_local 05_global_vs_local.c

int x; // x es una variable global
void fun1(int s);
void fun2(int s);

int main(void)
{
   x = 5;   printf("main: x = %d\n", x);
   fun1(4); printf("main: x = %d\n", x);
   fun2(2); printf("main: x = %d\n", x);
   return 0;
}

void fun1(int s)  // s es una variable local
{
   int y;         // y es una variable local
                  printf("fun1: x = %d, y = %d\n", x, y);
   x = 3; y = s;  printf("fun1: x = %d, y = %d\n", x, y);
   return;
}

void fun2(int s)  // s es una variable local
{
   int y;         // y es una variable local
                  printf("fun2: x = %d, y = %d\n", x, y);
   x = 1; y = s;  printf("fun2: x = %d, y = %d\n", x, y);
   return;
}

