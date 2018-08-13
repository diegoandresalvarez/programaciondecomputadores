/*
   Detector de minas:

       | 0 1 2 3 4 5 6 7 8 9 |        intento   mina1   mina2   mina3
    ---x---------------------x           1
     A |                     |           2
     B |                     |           3
     C |                     |           4
     D |                     |           5
     E |                     |           6
     F |                     |           7
     G |                     |           8
     H |                     |           9
     I |                     |          10
     J |                     |
    ---x---------------------x
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// gcc -Wall -o 05_detector_de_minas 05_detector_de_minas.c

/// Declaración de tipos de datos
typedef struct
{
   int x, y;
   bool detectada;
} mina;

/// Declaración de funciones
void vaciar_buffer_del_teclado(void);
void leer_radar(int X, int Y, mina *m);

/// Declaración de constantes globales
const int N_MINAS =  3; // numero de minas
const int IMAX    = 10; // numero de iteraciones maximo

int main(void)
{
   int i,j;         // contador
   char fil;        // columna (letra)
   int X;           // columna (numero)
   int Y;           // fila (numero)
   int np;          // numero de parametros leidos en scanf
   mina m[N_MINAS]; // vector de minas
   int n_minas;     // numero de minas detectadas

   /// Inicializar el generador de números aleatorios
   srand(time(NULL));

   /// Inicializar la posición de las minas
   for (i=0; i<N_MINAS; i++)
   {
      m[i].x         = 10*(double)rand()/RAND_MAX;
      m[i].y         = 10*(double)rand()/RAND_MAX;
      m[i].detectada = false;
   }

   for (i=1 ; ; i++)
   {
      /// Entrar letra y numero
      do
      {
         printf("Entre las coordenadas de la mina A..J, 0..9 = ");
         scanf("%c%d", &fil, &X);
         vaciar_buffer_del_teclado();
      } // Se sale cuando efectivamente se entró una letra y un número
      while (fil<'A'|| fil>'J' || X<0 || X>9);

      /// Se deja la fila A=0, B=1, C=2, ... J=9,
      Y = fil-'A';

      n_minas = 0;
      for (j=0; j<N_MINAS; j++)
      {
         printf("Mina %d: ", j+1);
         leer_radar(X, Y, &m[j]);
         if (m[j].detectada) n_minas++;
      }

      if (n_minas==N_MINAS)
      {
         printf("\nGANASTE!!! Utilizaste %d intentos\n", i);
         break;
      }
      else if (i==IMAX)
      {
         puts("\nPERDISTE :-("
              "\nLas minas estaban localizadas en:");
         for (j=0; j<N_MINAS; j++)
            printf("Mina %d: %c%d\n", j+1, m[j].y+'A', m[j].x);

         puts("\nIntentalo de nuevo");
         break;
      }
   }

   return 0;
}

void vaciar_buffer_del_teclado(void)
{
   int c;
   while((c = getchar()) != '\n' && c != EOF); // vaciamos el buffer del teclado
}

void leer_radar(int X, int Y, mina *m)
{
   if (m->x==X && m->y==Y) m->detectada = true;

   if (m->detectada)
   {
      puts("DETECTADA");
      return;
   }

   if (m->y > Y)
      putchar('S');
   else if (m->y < Y)
      putchar('N');

   if (m->x > X)
      putchar('E');
   else if (m->x < X)
      putchar('W');

   putchar('\n');
}
