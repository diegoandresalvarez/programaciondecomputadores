#include <curses.h>
#include <stdio.h>

/*
WINDOWS : gcc -Wall -o 03_keys_curses 03_keys_curses.c -lpdcurses
LINUX   : gcc -Wall -o 03_keys_curses 03_keys_curses.c -lncurses
*/

int main(void)
{
   int c;
   initscr();             // Start curses mode
   raw();                 // Line buffering disabled
   keypad(stdscr, TRUE);  // We get F1, F2 etc..
   noecho();              // Don't echo() while we do getch

   scrollok(stdscr,TRUE); // permitir lineas despues de la ultima

   while (1)
   {
      c = getch();
      printw("%3d  %c  ", c, c);
      switch(c)
      {
      case KEY_DOWN     : printw("KEY_DOWN     \n"); break; // down-arrow key
      case KEY_UP       : printw("KEY_UP       \n"); break; // up-arrow key
      case KEY_LEFT     : printw("KEY_LEFT     \n"); break; // left-arrow key
      case KEY_RIGHT    : printw("KEY_RIGHT    \n"); break; // right-arrow key
      case KEY_HOME     : printw("KEY_HOME     \n"); break; // home key
      case KEY_BACKSPACE: printw("KEY_BACKSPACE\n"); break; // backspace key
      case KEY_F( 1)    : printw("KEY_F(1)     \n"); break; // Value of function key n
      case KEY_F( 2)    : printw("KEY_F(2)     \n"); break; // Value of function key n
      case KEY_F( 3)    : printw("KEY_F(3)     \n"); break; // Value of function key n
      case KEY_F( 4)    : printw("KEY_F(4)     \n"); break; // Value of function key n
      case KEY_F( 5)    : printw("KEY_F(5)     \n"); break; // Value of function key n
      case KEY_F( 6)    : printw("KEY_F(6)     \n"); break; // Value of function key n
      case KEY_F( 7)    : printw("KEY_F(7)     \n"); break; // Value of function key n
      case KEY_F( 8)    : printw("KEY_F(8)     \n"); break; // Value of function key n
      case KEY_F( 9)    : printw("KEY_F(9)     \n"); break; // Value of function key n
      case KEY_F(10)    : printw("KEY_F(10)    \n"); break; // Value of function key n
      case KEY_F(11)    : printw("KEY_F(11)    \n"); break; // Value of function key n
      case KEY_F(12)    : printw("KEY_F(12)    \n"); break; // Value of function key n
      case KEY_DL       : printw("KEY_DL       \n"); break; // delete-line key
      case KEY_IL       : printw("KEY_IL       \n"); break; // insert-line key
      case KEY_DC       : printw("KEY_DC       \n"); break; // delete-character key
      case KEY_IC       : printw("KEY_IC       \n"); break; // insert-character key
      case KEY_EIC      : printw("KEY_EIC      \n"); break; // sent by rmir or smir in insert mode
      case KEY_CLEAR    : printw("KEY_CLEAR    \n"); break; // clear-screen or erase key
      case KEY_EOS      : printw("KEY_EOS      \n"); break; // clear-to-end-of-screen key
      case KEY_EOL      : printw("KEY_EOL      \n"); break; // clear-to-end-of-line key
      case KEY_SF       : printw("KEY_SF       \n"); break; // scroll-forward key
      case KEY_SR       : printw("KEY_SR       \n"); break; // scroll-backward key
      case KEY_NPAGE    : printw("KEY_NPAGE    \n"); break; // next-page key
      case KEY_PPAGE    : printw("KEY_PPAGE    \n"); break; // previous-page key
      case KEY_STAB     : printw("KEY_STAB     \n"); break; // set-tab key
      case KEY_CTAB     : printw("KEY_CTAB     \n"); break; // clear-tab key
      case KEY_CATAB    : printw("KEY_CATAB    \n"); break; // clear-all-tabs key
      case KEY_ENTER    : printw("KEY_ENTER    \n"); break; // enter/send key
      case KEY_PRINT    : printw("KEY_PRINT    \n"); break; // print key
      case KEY_LL       : printw("KEY_LL       \n"); break; // lower-left key (home down)
      case KEY_A1       : printw("KEY_A1       \n"); break; // upper left of keypad
      case KEY_A3       : printw("KEY_A3       \n"); break; // upper right of keypad
      case KEY_B2       : printw("KEY_B2       \n"); break; // center of keypad
      case KEY_C1       : printw("KEY_C1       \n"); break; // lower left of keypad
      case KEY_C3       : printw("KEY_C3       \n"); break; // lower right of keypad
      case KEY_BTAB     : printw("KEY_BTAB     \n"); break; // back-tab key
      case KEY_BEG      : printw("KEY_BEG      \n"); break; // begin key
      case KEY_CANCEL   : printw("KEY_CANCEL   \n"); break; // cancel key
      case KEY_CLOSE    : printw("KEY_CLOSE    \n"); break; // close key
      case KEY_COMMAND  : printw("KEY_COMMAND  \n"); break; // command key
      case KEY_COPY     : printw("KEY_COPY     \n"); break; // copy key
      case KEY_CREATE   : printw("KEY_CREATE   \n"); break; // create key
      case KEY_END      : printw("KEY_END      \n"); break; // end key
      case KEY_EXIT     : printw("KEY_EXIT     \n"); break; // exit key
      case KEY_FIND     : printw("KEY_FIND     \n"); break; // find key
      case KEY_HELP     : printw("KEY_HELP     \n"); break; // help key
      case KEY_MARK     : printw("KEY_MARK     \n"); break; // mark key
      case KEY_MESSAGE  : printw("KEY_MESSAGE  \n"); break; // message key
      case KEY_MOVE     : printw("KEY_MOVE     \n"); break; // move key
      case KEY_NEXT     : printw("KEY_NEXT     \n"); break; // next key
      case KEY_OPEN     : printw("KEY_OPEN     \n"); break; // open key
      case KEY_OPTIONS  : printw("KEY_OPTIONS  \n"); break; // options key
      case KEY_PREVIOUS : printw("KEY_PREVIOUS \n"); break; // previous key
      case KEY_REDO     : printw("KEY_REDO     \n"); break; // redo key
      case KEY_REFERENCE: printw("KEY_REFERENCE\n"); break; // reference key
      case KEY_REFRESH  : printw("KEY_REFRESH  \n"); break; // refresh key
      case KEY_REPLACE  : printw("KEY_REPLACE  \n"); break; // replace key
      case KEY_RESTART  : printw("KEY_RESTART  \n"); break; // restart key
      case KEY_RESUME   : printw("KEY_RESUME   \n"); break; // resume key
      case KEY_SAVE     : printw("KEY_SAVE     \n"); break; // save key
      case KEY_SBEG     : printw("KEY_SBEG     \n"); break; // shifted begin key
      case KEY_SCANCEL  : printw("KEY_SCANCEL  \n"); break; // shifted cancel key
      case KEY_SCOMMAND : printw("KEY_SCOMMAND \n"); break; // shifted command key
      case KEY_SCOPY    : printw("KEY_SCOPY    \n"); break; // shifted copy key
      case KEY_SCREATE  : printw("KEY_SCREATE  \n"); break; // shifted create key
      case KEY_SDC      : printw("KEY_SDC      \n"); break; // shifted delete-character key
      case KEY_SDL      : printw("KEY_SDL      \n"); break; // shifted delete-line key
      case KEY_SELECT   : printw("KEY_SELECT   \n"); break; // select key
      case KEY_SEND     : printw("KEY_SEND     \n"); break; // shifted end key
      case KEY_SEOL     : printw("KEY_SEOL     \n"); break; // shifted clear-to-end-of-line key
      case KEY_SEXIT    : printw("KEY_SEXIT    \n"); break; // shifted exit key
      case KEY_SFIND    : printw("KEY_SFIND    \n"); break; // shifted find key
      case KEY_SHELP    : printw("KEY_SHELP    \n"); break; // shifted help key
      case KEY_SHOME    : printw("KEY_SHOME    \n"); break; // shifted home key
      case KEY_SIC      : printw("KEY_SIC      \n"); break; // shifted insert-character key
      case KEY_SLEFT    : printw("KEY_SLEFT    \n"); break; // shifted left-arrow key
      case KEY_SMESSAGE : printw("KEY_SMESSAGE \n"); break; // shifted message key
      case KEY_SMOVE    : printw("KEY_SMOVE    \n"); break; // shifted move key
      case KEY_SNEXT    : printw("KEY_SNEXT    \n"); break; // shifted next key
      case KEY_SOPTIONS : printw("KEY_SOPTIONS \n"); break; // shifted options key
      case KEY_SPREVIOUS: printw("KEY_SPREVIOUS\n"); break; // shifted previous key
      case KEY_SPRINT   : printw("KEY_SPRINT   \n"); break; // shifted print key
      case KEY_SREDO    : printw("KEY_SREDO    \n"); break; // shifted redo key
      case KEY_SREPLACE : printw("KEY_SREPLACE \n"); break; // shifted replace key
      case KEY_SRIGHT   : printw("KEY_SRIGHT   \n"); break; // shifted right-arrow key
      case KEY_SRSUME   : printw("KEY_SRSUME   \n"); break; // shifted resume key
      case KEY_SSAVE    : printw("KEY_SSAVE    \n"); break; // shifted save key
      case KEY_SSUSPEND : printw("KEY_SSUSPEND \n"); break; // shifted suspend key
      case KEY_SUNDO    : printw("KEY_SUNDO    \n"); break; // shifted undo key
      case KEY_SUSPEND  : printw("KEY_SUSPEND  \n"); break; // suspend key
      case KEY_UNDO     : printw("KEY_UNDO     \n"); break; // undo key
      case KEY_MOUSE    : printw("KEY_MOUSE    \n"); break; // Mouse event has occurred
      case KEY_RESIZE   : printw("KEY_RESIZE   \n"); break; // Terminal resize event
      case KEY_MAX      : printw("KEY_MAX      \n"); break; // Maximum key value is 0633
      default           : printw("Tecla sin codigo especial\n");
      }
      refresh();        /* Print it on to the real screen */
      if (c==27) break; // Se sale con ESCAPE
   }
   endwin();
   return 0;
}
