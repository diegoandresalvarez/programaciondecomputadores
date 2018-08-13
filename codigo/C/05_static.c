#include<stdio.h>

// Compile con: gcc -Wall -o 05_static 05_static.c

void fun1(int s);
void fun2(int s);

int main(void)
{
   fun1(2); fun1(2); fun1(2); 
   fun2(2); fun2(2); fun2(2);
   return 0;
}

void fun1(int s)     // s es una variable local
{
   static int x = 3; // x es una variable estatica
   x += s;
   printf("fun1: x = %d\n", x);
   return;
}

void fun2(int s)  // s es una variable local
{
   int x = 3;     // x es una variable local
   x += s;
   printf("fun2: x = %d\n", x);
   return;
}

