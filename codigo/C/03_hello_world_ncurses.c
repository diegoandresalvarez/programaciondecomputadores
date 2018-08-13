#include <curses.h>

/*
WINDOWS : gcc -Wall -o 03_hello_world_ncurses 03_hello_world_ncurses.c -lpdcurses
LINUX   : gcc -Wall -o 03_hello_world_ncurses 03_hello_world_ncurses.c -lncurses
*/

int main(void)
{
	initscr();		            	// Empiece el modo CURSES
	printw("Hola a todos !!!");
	refresh();                    // Imprima la cadena en pantalla
	getch();                      // Presione una tecla
	endwin();                     // Termine el modo CURSES

	return 0;
}

