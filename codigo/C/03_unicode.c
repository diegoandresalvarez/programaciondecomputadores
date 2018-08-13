#include <stdio.h>
#include <locale.h>

// gcc -Wall 03_unicode.c -o unicode

int main()
{
   setlocale(LC_CTYPE, "");
   printf("áÁ éÉ íÍ óÓ úÚ üÜ ñÑ\n");
   printf("مرحبا\n");       // Hola en árabe
   printf("Բարեւ Ձեզ\n");   // Hola en armenio
   printf("こんにちは\n");    // Hola en japonés
   printf("\u2602 \u265A \u263A\n");

   return 0;
}
