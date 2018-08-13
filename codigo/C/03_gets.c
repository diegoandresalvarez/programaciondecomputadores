#include <stdio.h> 

//compile con: gcc -Wall -fpack-struct -o 03_gets 03_gets.c

typedef struct
{
  char buf[5];
  int  i;
} mi_estructura;

int main(void)
{
   mi_estructura m;

   m.i = 10;
   printf ("m.i es %d\n", m.i);

   printf ("Entre una cadena de 8 letras: ");
   gets(m.buf);

   printf ("En %p = m.buf se almacena >%s<\n", m.buf, m.buf);
   printf ("En %p = m.i se almacena %d = %#x\n", &m.i, m.i, m.i);

  return(0);
}

/*
#include <stdio.h>

int main()
{
  char nombre [256];
  printf ("Entre su nombre completo: ");
  gets(nombre);
  printf ("Su nombre es: %s\n", nombre);
  return 0;
}
*/