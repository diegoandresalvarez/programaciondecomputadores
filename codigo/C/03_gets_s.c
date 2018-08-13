#include <stdio.h>

//compile con: gcc -Wall -o 03_gets_s 03_gets_s.c

int main()
{
  char string [256];
  printf ("Entre su nombre completo: ");
  gets_s(string, 256);
  printf ("Su nombre es: %s\n",string);
  return 0;
}


