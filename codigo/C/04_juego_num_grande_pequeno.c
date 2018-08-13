#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// gcc -Wall -o 04_juego_num_grande_pequeno 04_juego_num_grande_pequeno.c

const int IMAX = 7; // Numero maximo permisible de intentos

void vaciar_buffer_del_teclado(void);

int main(void)
{
   int np;       // numero de parametros leidos en scanf
   int i;        // contador
   int n;        // numero entrado por teclado
   int nsecret;  // numero secreto

   // Inicializar el generador de números aleatorios
   srand(time(NULL));
   
   #ifdef _WIN32 // Windows (x64 and x86)   
   rand();       // Toca agregar esta línea para que el gcc "no moleste".
                 // en Windows. De todas formas recuerde que el numero 
                 // aleatorio generado con rand() es de pésima calidad.
   #endif

   // Generar el número secreto entre 0 y 100
   nsecret = (int)(101*((double)rand())/RAND_MAX);

   for(i=1 ;; i++)
   {
      // Entrar numero
      do
      {
         printf("Entre un número entre 0 y 100 = ");
         np = scanf("%d", &n);

         vaciar_buffer_del_teclado();

      // Se sale cuando efectivamente se entró un número
      } while((np != 1) || (n < 0) || (n > 100));

      // Comparar
      if (n == nsecret)
      {
         printf("\nGANASTE!!! Utilizaste %d intentos\n", i);
         break;
      }
      else if (i == IMAX)
      {
         printf("\nPERDISTE :-( El número secreto era el %d.\n", nsecret);
         puts("Intentalo de nuevo");
         break;
      }
      else if (n > nsecret)
         printf("%d es muy grande. Te quedan %d intentos\n",  n, IMAX-i);
      else if (n < nsecret)
         printf("%d es muy pequeño. Te quedan %d intentos\n", n, IMAX-i);
   }

   return(0);
}

void vaciar_buffer_del_teclado(void)
{
   int c;
   while((c = getchar()) != '\n' && c != EOF); // vaciamos el buffer del teclado
}
