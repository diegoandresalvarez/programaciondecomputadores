#include <curses.h>

/*
WINDOWS : gcc -Wall -o 03_init_func_example 03_init_func_example.c -lpdcurses
LINUX   : gcc -Wall -o 03_init_func_example 03_init_func_example.c -lncurses
*/

int main(void)
{
   int ch;

   initscr();            // comience modo ncurses
   raw();                // interprete los caracteres inmediatamente los reciba
                        // (line buffering disabled)

   keypad(stdscr, TRUE); // se puede recibir flechas, los F1, F2, ESC, etc
   noecho();             // no haga echo() cuando se hace getch()

   printw("Presione una tecla\n");
   ch = getch();         // Si no tuvieramos raw() se tendría que presionar ENTER
   // de modo que el programa procesara la tecla.
   // Además el noecho() hace que no se muestre los codigos
   // generados por las teclas presionadas

   if(ch == KEY_DOWN)    // se requiere keypad() para activar este comnado
      printw("Se presiono la flecha hacia abajo");
   else
   {
      printw("La tecla presionada fue ");
      // Nota en PDcurses el A_BLINK no funciona, parece ser un bug.
      // sin embargo en LINUX funciona perfectamente.
      attron(A_BOLD  | A_BLINK | A_UNDERLINE);    // activar negrilla + parpadeo + subrayado
      printw("%c", ch);             // imprimir la tecla

      // Estas dos lineas no funcionan en WINDOWS: al parecer un bug de la librería
      attroff(A_BLINK);   // desactivar parpadeo
      printw("%c", ch);             // imprimir la tecla
   }
   refresh();            // imprimir en pantalla
   getch();              // presione una tecla para salir
   endwin();             // terminar modo ncurses

   return 0;
}

/*
attrset() and its sister function attr_get() can be used to set and get attributes and produce a colorful display.

We can OR(|) any number of above attributes to get a combined effect. If you wanted reverse video with blinking characters you can use attron(A_REVERSE | A_BLINK);
*/
