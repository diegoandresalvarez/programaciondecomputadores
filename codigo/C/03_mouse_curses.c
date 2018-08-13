// En WINDOWS: para que pdcurses.h funcione como ncurses.h, cargue antes de cargar curses.h
#define NCURSES_MOUSE_VERSION

#include <curses.h>
#include <stdio.h>

/*
WINDOWS : gcc -Wall -o 03_mouse_curses 03_mouse_curses.c -lpdcurses
LINUX   : gcc -Wall -o 03_mouse_curses 03_mouse_curses.c -lncurses
*/

void int_to_binary(unsigned int x);

int main(void)
{
   MEVENT event;
   int c, m;

   initscr();             // Empezar el modo ncurses
   cbreak();              // Desactivar el buffer del teclado
   keypad(stdscr, TRUE);  // Se recibiran caracteres como F1, F2 etc..
   noecho();              // No mostrar lo que se teclea

   mousemask(ALL_MOUSE_EVENTS, NULL);  // Obtener todos los eventos del mouse
//   mousemask(  mmask_t newmask,  The events you want to listen to
//               mmask_t *oldmask) The old events mask
// setting mousemask to 0 turns off the mouse

   scrollok(stdscr,TRUE); // permitir lineas despues de la ultima

   printw("ALL_MOUSE_EVENTS = ");
   int_to_binary(ALL_MOUSE_EVENTS);
   printw("\n\n");

   while(1)
   {
      c = getch();

      if (c == KEY_MOUSE)
      {
         m = getmouse(&event);
         printw("Mouse event: m=%d, id=%d, x=%3d, y=%3d, z=%3d, bstate=", m, event.id, event.x, event.y, event.z);
         // las coordenadas son relativas a la pantalla.

         int_to_binary(event.bstate);
         printw(" ");

         if(m == OK)
         {
            if(event.bstate & BUTTON1_RELEASED      ) printw("BUTTON1_RELEASED      ");
            if(event.bstate & BUTTON1_PRESSED       ) printw("BUTTON1_PRESSED       ");
            if(event.bstate & BUTTON1_CLICKED       ) printw("BUTTON1_CLICKED       ");
            if(event.bstate & BUTTON1_DOUBLE_CLICKED) printw("BUTTON1_DOUBLE_CLICKED");
            if(event.bstate & BUTTON1_TRIPLE_CLICKED) printw("BUTTON1_TRIPLE_CLICKED");

            if(event.bstate & BUTTON2_RELEASED      ) printw("BUTTON2_RELEASED      ");
            if(event.bstate & BUTTON2_PRESSED       ) printw("BUTTON2_PRESSED       ");
            if(event.bstate & BUTTON2_CLICKED       ) printw("BUTTON2_CLICKED       ");
            if(event.bstate & BUTTON2_DOUBLE_CLICKED) printw("BUTTON2_DOUBLE_CLICKED");
            if(event.bstate & BUTTON2_TRIPLE_CLICKED) printw("BUTTON2_TRIPLE_CLICKED");

            if(event.bstate & BUTTON3_RELEASED      ) printw("BUTTON3_RELEASED      ");
            if(event.bstate & BUTTON3_PRESSED       ) printw("BUTTON3_PRESSED       ");
            if(event.bstate & BUTTON3_CLICKED       ) printw("BUTTON3_CLICKED       ");
            if(event.bstate & BUTTON3_DOUBLE_CLICKED) printw("BUTTON3_DOUBLE_CLICKED");
            if(event.bstate & BUTTON3_TRIPLE_CLICKED) printw("BUTTON3_TRIPLE_CLICKED");

            if(event.bstate & BUTTON4_RELEASED      ) printw("BUTTON4_RELEASED      ");
            if(event.bstate & BUTTON4_PRESSED       ) printw("BUTTON4_PRESSED       ");
            if(event.bstate & BUTTON4_CLICKED       ) printw("BUTTON4_CLICKED       ");
            if(event.bstate & BUTTON4_DOUBLE_CLICKED) printw("BUTTON4_DOUBLE_CLICKED");
            if(event.bstate & BUTTON4_TRIPLE_CLICKED) printw("BUTTON4_TRIPLE_CLICKED");

            if(event.bstate & BUTTON_CTRL           ) printw("BUTTON_CTRL");
            if(event.bstate & BUTTON_SHIFT          ) printw("BUTTON_SHIFT");
            if(event.bstate & BUTTON_ALT            ) printw("BUTTON_ALT");
            printw("\n");
         }
      }
      else
         printw("Se presiono la tecla %3d: %c\n", c, c);

      refresh();

      if (c == 27) break; // se presionó ESCAPE
   }

   endwin();
   return 0;
}

void int_to_binary(unsigned int x)
{
   unsigned int z;
   for (z = 2147483648u; z > 0; z >>= 1)  // 2^31=2147483648
      printw("%c", ((x&z) == z) ? '1' : '0');

   return;
}

/*
The wmouse_trafo function transforms a given pair of coordinates from stdscr-relative coordinates to coordinates relative to the given  window  or  viceversa.   Please remember, that stdscr-relative coordinates are not always identical to window-relative coordinates due to the mechanism to reserve lines on top or bottom of the screen for other purposes (see the ripoffline() and slk_init calls, for example).  If  the  parameter  to_screen  is  TRUE,  the pointers  pY,  pX  must  reference  the coordinates of a location inside the window win.  They are converted to window-relative coordinates and returned through the pointers.  If the conversion was successful, the function returns TRUE.  If one of the parameters was NULL or the location is not inside the window,  FALSE  is returned.  If to_screen is FALSE, the pointers pY, pX must reference window-relative coordinates.  They are converted to stdscr-relaâ tive coordinates if the window win encloses this point.  In this case the function returns TRUE.  If one of the parameters is NULL or the point  is  not inside  the window, FALSE is returned.  Please notice, that the referenced coordinates are only replaced by the converted coordinates if the transformaâ tion was successful.

// Convert to mouse co-ordinates to screen relative co-ordinates with:
bool wmouse_trafo (const WINDOW*, int*, int*, bool);

The mouse_trafo function performs the same translation as wmouse_trafo, using stdscr for win.
bool mouse_trafo (int*, int*, bool);

// Sets the maximum time (in thousands of a second) that can elapse between press and release events in order for them to be recognized as a click. This function returns the previous interval value. Use mouseinterval(-1) to obtain the interval without altering it.  The default is one sixth of a second.
int mouseinterval (int);

// The ungetmouse function behaves analogously to ungetch.  It pushes a KEY_MOUSE event onto the input queue, and associates  with  that  event  the  given state data and screen-relative character-cell coordinates.
extern NCURSES_EXPORT(int) ungetmouse (MEVENT *);

// The  wenclose  function  tests whether a given pair of screen-relative character-cell coordinates is enclosed by a given window, returning TRUE if it is and FALSE otherwise.  It is useful for determining what subset of the screen windows enclose the location of a mouse event.
extern NCURSES_EXPORT(bool) wenclose (const WINDOW *, int, int);
*/
