#include <curses.h>
#include <string.h>

/*
WINDOWS : gcc -Wall -o 03_scanw_example 03_scanw_example.c -lpdcurses
LINUX   : gcc -Wall -o 03_scanw_example 03_scanw_example.c -lncurses
*/

int main()
{
   char mesg[]="Entre una cadena: "; // mensaje que aparecera en pantalla
   char str[80];

   initscr();

   // imprima el mensaje en el centro de la pantalla
   mvprintw(LINES/2,(COLS-strlen(mesg))/2,"%s",mesg);

   getstr(str);                      // leer la cadena
   mvprintw(LINES - 2, 0, "Usted escribio: %s", str);
   refresh();
   getch();
   endwin();

   return 0;
}

