#include <stdio.h>

// Compile con gcc 07_for_enum.c -o 07_for_enum

int main (void)
{
   enum dias {domingo,lunes,martes,miercoles,jueves,viernes,sabado};

   enum dias i, d = martes;

   for(i=lunes; i<jueves; i++)
      if (d == i) printf("%d\n",i);

   return 0;
}

