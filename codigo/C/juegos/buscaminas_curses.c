/*
   BUSCAMINAS

   Con espacio marca/desmarca la mina
   Con las flechas se mueve
   Con ENTER destapa
   Con ESCAPE se sale del juego

   Compile con:
   gcc -Wall -o buscaminas_curses buscaminas_curses.c -lcurses
*/

// en stdlib.h esta rand() y srand() y en en time.h esta time()
#include<stdlib.h>
#include<time.h>
#include<curses.h>
#include<stdbool.h>

// Constantes
#define ESCAPE   27
#define ENTER    10

#define MAXFIL    8
#define MAXCOL   10
#define NMINAS   13

// Macros (de todos modos es preferible hacerlos como funciones inline)
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))

// Variables globales
bool destapado[MAXFIL][MAXCOL];
bool protegido[MAXFIL][MAXCOL];
bool esmina[MAXFIL][MAXCOL];

// Prototipos de funciones
bool destapar(int f, int c);
int suma_alrededor(int f, int c);

int main(void)
{
   int suma, i, j, k, f, c;
   bool todas_minas_marcadas;

   initscr();            // entrada al modo ncurses
   keypad(stdscr, true); // permitir utilizar teclas especiales como las flechas
   noecho();             // no muestre el caracter en pantalla cuando use getch()
   curs_set(0);          // hacer el cursor invisible

   // inicializar el tablero
   for(i=0; i<MAXFIL; i++)   
      for(j=0; j<MAXCOL; j++)
      {
         destapado[i][j] = protegido[i][j] = esmina[i][j] = false;
         mvaddch(i,j,'.');
      }

   f = MAXFIL/2;
   c = MAXCOL/2;
   mvaddch(f, c, '#'); // este es el cursor
   move(f, c);
   refresh();

   srand(time(NULL)); // active la semilla del generador de numeros aleatorios

   // Crear minas
   for(k=0; k<NMINAS; k++)
   {
      i = (int) MAXFIL*(double)rand()/RAND_MAX;
      j = (int) MAXCOL*(double)rand()/RAND_MAX;
      esmina[i][j] = true;
   }
      
   // procesar entrada del teclado
   do
   {     
      // se almacena al posicion del cursor antes de moverlo
      int fcur=f, ccur=c;  // se guarda la posicion actual del cursor    
      switch(getch())
      {
         case KEY_LEFT:  if (c > 0)        c--; break;
         case KEY_RIGHT: if (c < MAXCOL-1) c++; break;
         case KEY_UP:    if (f > 0)        f--; break;
         case KEY_DOWN:  if (f < MAXFIL-1) f++; break;
         case ENTER:     // destapar
            destapar(f,c);
            break;
         case ' ': // proteger (sino esta destapado)
            if (!destapado[f][c]) protegido[f][c] = !protegido[f][c];
            break;
         case ESCAPE:
            endwin();           // terminar el modo ncurses
            exit(EXIT_SUCCESS);
      }

      // graficar de nuevo la casilla donde estaba el cursor despues de moverlo
      if (protegido[fcur][ccur])
         addch('*');
      else
      { // no protegido
         if (destapado[fcur][ccur])
         {
            suma = suma_alrededor(fcur,ccur);
            if (suma == 0)
               addch(' ');
            else 
               addch((char)(suma+(int)'0'));
         }
         else
            addch('.');
      }
      mvaddch(f,c,'#'); // poner el cursor en la nueva posicion
      move(f,c);
      refresh();        // actualizar la pantalla

      // verificar si todas las minas estan marcadas y no hay casillas limpias
      // incorrectamente marcadas
      todas_minas_marcadas = true;
      for(i=0; todas_minas_marcadas == true && i<MAXFIL; i++)
         for(j=0; j<MAXCOL; j++)
         {
            if ((esmina[i][j] != protegido[i][j]))
            { 
               todas_minas_marcadas = false;
               break;
            }
         }         
      
   } while(!todas_minas_marcadas);

   attron(A_BLINK); 
   mvprintw(MAXFIL,0,"Ganaste :-)");
   attroff(A_BLINK); 
   refresh();      // actualizar la pantalla
   getch();        // presione una tecla para salir
   endwin();       // terminar el modo ncurses

   return 0;
}

// Declaracion de las funciones
bool destapar(int f, int c)
{
   int i, j, suma;
   chtype ch;

   if (f < 0) return false;      if (f > MAXFIL-1) return false;
   if (c < 0) return false;      if (c > MAXCOL-1) return false;

   if (destapado[f][c] || protegido[f][c]) return false;
   
   if (esmina[f][c]) // exploto la mina!!
   {
      // mostrar todas las minas
      attron(A_BOLD | A_REVERSE);    // activar negrilla      
      for(i=0; i<MAXFIL; i++)
         for(j=0; j<MAXCOL; j++)
            if (esmina[i][j])
            {
               refresh();
               ch = mvinch(i,j);              // extraer caracter de la posicion
               mvaddch(i,j, ch & A_CHARTEXT); // solo obtener el caracter como tal
      
            }
      attroff(A_BOLD | A_REVERSE);   // desactivar negrilla            

      if(has_colors() == FALSE)
      {
         endwin();
         fprintf(stderr, "Este computador no puede mostrar colores\n");
         exit(EXIT_FAILURE);
      }

      start_color();          // start color
      init_pair(1, COLOR_RED, COLOR_WHITE);
      attron(COLOR_PAIR(1));
      mvprintw(MAXFIL,0, "Perdiste :-(");
      attroff(COLOR_PAIR(1));

      refresh();              // actualizar la pantalla
      getch();                // presione una tecla para salir
      endwin();               // terminar el modo ncurses
      exit(EXIT_SUCCESS);
   }

   destapado[f][c] = true;

   suma = suma_alrededor(f,c);
   if (suma==0)
   {
      mvaddch(f,c,' ');
      destapar(f-1,c-1);   destapar(f,c-1);       destapar(f+1,c-1);
      destapar(f-1,c);                            destapar(f+1,c);
      destapar(f-1,c+1);   destapar(f,c+1);       destapar(f+1,c+1);
   }
   else
      mvaddch(f,c,(char)(suma+(int)'0')); // imprima numero de minas alrededor

   move(f,c);

   return true;
}

int suma_alrededor(int f, int c)
{
   int i, j, suma = 0;

   // para evitar contar fuera de los bordes de la matriz esmina[][]
   int fmin = max(f-1,0);
   int fmax = min(f+1,MAXFIL-1);   
   int cmin = max(c-1,0);
   int cmax = min(c+1,MAXCOL-1);

   for(i=fmin; i<=fmax; i++)
      for(j=cmin; j<=cmax; j++)
         suma += (int)esmina[i][j];

   return suma;
}
