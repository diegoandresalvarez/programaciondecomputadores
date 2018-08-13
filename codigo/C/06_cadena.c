#include<stdio.h>
#include<string.h>

// Compile con: gcc -Wall -o 06_cadena 06_cadena.c

int main(void)
{
   char fruta1[20];
   char fruta2[120] = "naranja";

   strcpy(fruta1, fruta2);

   printf("%s, "
          "sizeof(fruta1) = %d, "
          "strlen(fruta1) = %d\n",
          fruta1, sizeof(fruta1), strlen(fruta1));
   
   return 0;
}




