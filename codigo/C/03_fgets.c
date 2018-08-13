#include <stdio.h>
#include <string.h>

//compile con: gcc -Wall -o 03_fgets 03_fgets.c

int main()
{
   char buf[256];
   char *p;

   // sizeof(buf)-2 porque el ENTER (\n) y el \0 final ocupan 2 bytes
   printf ("Entre texto (maximo %d letras):\n", sizeof(buf)-2);

   if (fgets(buf, sizeof(buf), stdin) != NULL)
   {
      printf ("Usted escribio >%s<\n", buf);

      // Ahora remueva el \n
       if ((p = strchr(buf, '\n')) != NULL) *p = '\0';
       printf ("Ahora la cadena sin el \\n >%s<\n", buf);
   }

  return 0;
}
