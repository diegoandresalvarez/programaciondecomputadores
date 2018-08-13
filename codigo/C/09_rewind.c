#include <stdio.h>

// gcc -Wall 09_rewind.c -o 09_rewind -std=c99

char str[20];

int main(void)
{
   FILE *f = fopen("file.txt", "w");
   for (char ch = '0'; ch <= '9'; ch++) fputc(ch, f);
   fclose(f);

   f = fopen("file.txt", "r"); fread(str, 1, 10, f); puts(str);
   rewind(f);                  fread(str, 1, 10, f); puts(str);
   fclose(f);

   return 0;
}
