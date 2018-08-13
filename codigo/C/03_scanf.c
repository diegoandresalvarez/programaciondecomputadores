#include <stdio.h>

// Compile con: gcc -Wall -o 03_scanf 03_scanf.c

int main ()
{
   char s[80]; float f; char c; int items_leidos, n;

   printf ("Escriba 'Hola, 123, 3.141592, X, una cadena'\n");
   items_leidos = scanf ("Hola,%d,%g, %c,%[^\n]s", &n, &f, &c, s);
   printf("n = %d\n"
          "f = %g\n"
          "c = %c\n"
          "s = %s\n"
          "items_leidos = %d\n", n, f, c, s, items_leidos);

  return 0;
}

/*
#include <stdio.h>

// Compile con: gcc -Wall -o 03_scanf 03_scanf.c

int main ()
{
  char str [80];
  int i;

  printf ("Entre su nombre: ");
  scanf ("%s",str);
  printf ("Entre su edad: ");
  scanf ("%d",&i);
  printf ("El señor %s tiene %d años.\n",str,i);
  printf ("Entre un número hexadecimal: ");
  scanf ("%x",&i);
  printf ("Usted ha entrado %#x (%d).\n",i,i);

  return 0;
}
*/