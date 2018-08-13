#include <stdio.h>

// gcc -Wall 09_perror.c -o 09_perror

int main(void)
{
   FILE* f = fopen("archivo_que_no_existe.txt", "r");
   if (f == NULL)
   {
      perror("fopen()");
      fprintf(stderr,"fopen() falló en %s (línea %d)\n", __FILE__,__LINE__-4);
   }
   else
      fclose(f);
   
   return 0;
}
