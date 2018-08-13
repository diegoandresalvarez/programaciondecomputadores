// Codigo tomado de:
// Matthew Neil and Stones, Richard. Beginning Linux Programming. 4th Edition. Wrox.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int arg;

   for(arg = 0; arg < argc; arg++)
   {
      if(argv[arg][0] == '-')
         printf("opción: %s\n", argv[arg]+1);
      else
         printf("argumento %d: %s\n", arg, argv[arg]);
   }
   exit(EXIT_SUCCESS);
}
