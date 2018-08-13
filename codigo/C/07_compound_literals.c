#include<stdio.h> 

// gcc -Wall -o 07_compound_literals 07_compound_literals.c

typedef struct
{
    int   x;
    float y;
    char  *z;
} mystruct;

int main()
{
   mystruct p1, p2, p3;
   p1 = (mystruct){ 3, 3.1415, "Pi" };
   p2 = (mystruct){ .z = "Euler", .x = 2, .y = 2.7183 };
   p3 = (mystruct){ .z = "Euler", .y = 2.7183 };   

   printf("x = %d, y = %f, z = %s\n", p1.x, p1.y, p1.z);
   printf("x = %d, y = %f, z = %s\n", p2.x, p2.y, p2.z);
   printf("x = %d, y = %f, z = %s\n", p3.x, p3.y, p3.z);   

   return 0;
}

