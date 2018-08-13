#include<stdio.h>
#include<unistd.h>
// compile con: gcc -Wall -o 03_ejemplo_contador 03_ejemplo_contador.c
int main(void)
{
   int i;
   unsigned int usecs = 50000; // en micro (10^-6) segundos = 0.05 segundos
   
   for(i=0; i<=100; i++)
   {
      printf("%3d%% \\",i);                    fflush(stdout);
      usleep(usecs); printf("\b|");            fflush(stdout);
      usleep(usecs); printf("\b/");            fflush(stdout);
      usleep(usecs); printf("\b-");            fflush(stdout);
      usleep(usecs); printf("\r");             fflush(stdout);
   }

// Aquí toca poner el fflush(), porque normalmente el buffer
// de salida solo se imprime cuando aparece un \n
   
   printf("FIN!\a\n");
  
   return 0;
}
