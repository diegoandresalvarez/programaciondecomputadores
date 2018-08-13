#include <stdio.h> 

struct mi_struct_A
{
   char a;
   int b;
   char c;
} x;

struct mi_struct_B
{
   int b;
   char c;
} y;

struct __attribute__((__packed__)) mi_struct_C
{
   int b;
   char c;
} z;


int main(void)
{
   printf("tamaño(x) = %d, tamaño(y) = %d, tamaño(z) = %d\n", sizeof(x), sizeof(y), sizeof(z));
   printf("dir x.a = %p, dir x.b = %p, dir x.c = %p\n",       &x.a, &x.b, &x.c);
   printf("                     dir y.b = %p, dir y.c = %p\n",      &y.b, &y.c);
   printf("                     dir z.b = %p, dir z.c = %p\n",      &z.b, &z.c);      
   
   return 0;
}

