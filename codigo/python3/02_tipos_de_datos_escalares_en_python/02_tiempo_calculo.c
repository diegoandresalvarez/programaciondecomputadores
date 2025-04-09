#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

double intervalo_tiempo_ms(struct timeval toc, struct timeval tic);

int main() {
   struct timeval tic, toc;
   double x, dif, suma = 0;

   gettimeofday(&tic, NULL);   
   for (int i=0; i < 10000000; i++)
      suma += 1.0/(2*i + 1) - 1.0/(2*i + 2);
   gettimeofday(&toc, NULL);

   dif = intervalo_tiempo_ms(toc, tic);

   printf("ln(2) = %g\n", suma);
   printf("El cálculo se realizó en %g segundos.\n", dif);

   return 0;
}

double intervalo_tiempo_ms(struct timeval toc, struct timeval tic)
{
   return (toc.tv_sec - tic.tv_sec) + (toc.tv_usec - tic.tv_usec)/1000000.0;
}
