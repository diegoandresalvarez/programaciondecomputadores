#include <stdlib.h>
#include <stdio.h>

/*
 * In the example below the stop_now() function is called, which causes
 * the program to immediately terminate. The code with the printf() and
 * the return EXIT_SUCCESS; after the call to stop_now() is never
 * executed and the execution never returns to the main() function,
 * where stop_now() was called from.
 * http://en.cppreference.com/w/c/language/function_specifiers
 */

// _Noreturn void stop_now() { abort(); }
void stop_now() { abort(); }

int main(void)
{
  printf("Preparing to stop...\n");
  stop_now();
  printf("This code is never executed.\n");
  return EXIT_SUCCESS;
}

/*
daa@heimdall ~ $ gcc 05_noreturn.c  -Wmissing-noreturn
05_noreturn.c: In function ‘stop_now’:
05_noreturn.c:17:6: warning: function might be candidate for attribute ‘noreturn’ [-Wsuggest-attribute=noreturn]
 void stop_now() { abort(); }
      ^
*/
