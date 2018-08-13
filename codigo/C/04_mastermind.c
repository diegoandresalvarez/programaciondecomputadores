#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

// gcc -Wall -o 04_mastermind 04_mastermind.c

const int IMAX = 10;  // Numero maximo permisible de intentos
const int NDIG = 3;   // Numero de dígitos

void vaciar_buffer_del_teclado(void);

int main(void)
{
   // Declaración de variables
   int intentos;       // número de intentos
   int i,j;            // contador
   unsigned int num;   // numero entrado por teclado
   int n[NDIG];        // centenas, decenas, unidades de numero entrado por teclado
   int s[NDIG];        // centenas, decenas, unidades de numero secreto
   bool disp_s[NDIG];  // disponible cifra del número secreto

   int bu,cp;          // Números buenos, números en correcta posición

   // Inicializar el generador de números aleatorios
   srand(time(NULL));
   #ifdef _WIN32 // Windows (x64 and x86)   
   rand();       // Toca agregar esta línea para que el gcc "no moleste".
                 // en Windows. De todas formas recuerde que el numero 
                 // aleatorio generado con rand() es de pésima calidad.
   #endif   
   

   // Generar el número secreto
   for (i=0; i<NDIG; i++)
      s[i] = (int)(10*((double)rand())/RAND_MAX);

   puts("*** MASTERMIND ***\n");

   // Bucle principal
   for(intentos=1 ;; intentos++)
   {
      // Entrar numero
      do
      {
         printf("Entre un numero entre 0 y 999 = ");
         scanf("%3u", &num);

         vaciar_buffer_del_teclado();

      // Se sale cuando efectivamente se entró un número
      } while((num < 0) || (num > 999));

      // Se separan centenas, decenas y unidades
      // n[2] = num/100;                  // centenas
      // n[1] = (num - 100*n[2])/10;      // decenas
      // n[0] = num - 100*n[2] - 10*n[1]; // unidades
      for (i=0; i<NDIG; i++)
      {
         n[i] = num%10;
         num /= 10;
      }

      // Inicializar variables
      bu = cp = 0;
      for (i=0; i<NDIG; i++) disp_s[i] = true; // todas estan disponibles

      // Contabilizar buenos y en correcta posición
      for (i=0; i<NDIG; i++)
      {
         // contabilizar los de correcta posición
         if (n[i] == s[i]) cp++;

         // contabilizar los que están buenos
         for (j=0; j<NDIG; j++)
         {
            // si son iguales y ambas estan disponibles, cuente el número bueno
            if ((n[i] == s[j]) && disp_s[j])
            {
               bu++;              // contando los buenos
               disp_s[j] = false; // s[j] ya no están disponible
               break;             // ya no vale la pena seguir variando s[j] ya que n[i] se utilizó
            }
         }
      }

      printf("\t\t\t\t\tBUENOS = %d, CORRECTA POSICION = %d\n", bu, cp);

      // Comparar
      if (cp == NDIG)
      {
         printf("\nGANASTE!!! Utilizaste %d intentos\n", intentos);
         break;
      }
      else if (intentos == IMAX)
      {
         printf("\nPERDISTE :-( El numero secreto era el %0*d.\n",
                                             NDIG, 100*s[2] + 10*s[1] + s[0]);
         puts("Intentalo de nuevo");
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
