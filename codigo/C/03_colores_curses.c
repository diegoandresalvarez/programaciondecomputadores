#include <curses.h>

/*
WINDOWS : gcc -Wall -o 03_colores_curses 03_colores_curses.c -lpdcurses
LINUX   : gcc -Wall -o 03_colores_curses 03_colores_curses.c -lncurses
*/

int main(void)
{
   initscr();
   if(has_colors() == FALSE)
   {
      endwin();
      puts("Su monitor no soporta colores");
      return 1;
   }

   start_color(); // activar modo colores
   init_pair(1, COLOR_CYAN,  COLOR_MAGENTA); // letras/fondo
   init_pair(2, COLOR_GREEN, COLOR_RED);     // letras/fondo
   /*
      COLOR_BLACK   0        COLOR_BLUE    4
      COLOR_RED     1        COLOR_MAGENTA 5
      COLOR_GREEN   2        COLOR_CYAN    6
      COLOR_YELLOW  3        COLOR_WHITE   7
   */
   attron(COLOR_PAIR(1)); printw("En ");      attroff(COLOR_PAIR(1));
   attron(COLOR_PAIR(2)); printw("colores!"); attroff(COLOR_PAIR(2));
   refresh();
   getch();
   endwin();
   return 0;
}

/*
cambia el RGB del color
RET = init_color(COLOR_RED, 700, 0, 0); //color name, R,G, B : rgb content min = 0, max = 1000
If your terminal cannot change the color definitions, the function returns ERR.
The function can_change_color() can be used to find out whether the terminal has the capability of changing color content or not.

The functions color_content() and pair_content() can be used to find the color content and foreground, background combination for the pair.
*/

/*
mvchgat(0, 0, -1, A_BLINK, 1, NULL);
* First two parameters specify the position at which to start
* Third parameter number of characters to update. -1 means till
* end of line
* Forth parameter is the normal attribute you wanted to give
* to the charcter
* Fifth is the color index. It is the index given during init_pair()
* use 0 if you didn't want color
* Sixth one is always NULL
*/
