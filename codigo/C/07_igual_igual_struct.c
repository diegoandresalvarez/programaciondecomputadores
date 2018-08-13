#include<stdio.h> 

// gcc -Wall -o 07_igual_igual_struct 07_igual_igual_struct.c

typedef struct
{
    int   x;
    float y;
    char  *z;
} mystruct;

int main()
{
   mystruct p1, p2;
   p1 = (mystruct){ 3, 3.1415, "Pi" };
   p2 = (mystruct){ 3, 3.1415, "Pi" };

   if (p1 == p2)
      puts("Las estructuras son iguales"); // error: el operador == no funciona con estructuras
   else
      puts("Las estructuras son diferentes");

   return 0;
}

