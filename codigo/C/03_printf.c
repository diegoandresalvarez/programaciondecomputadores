#include <stdio.h>

// Compile con: gcc -Wall -o 03_printf 03_printf.c

int main()
{
   printf("Caracteres: %c %c\n", 'a', 65);
   printf("Enteros: %d %ld\n", 1977, 650000L);
   printf("Precedido de espacios: |%10d|\n", 1977);
   printf("Precedido de ceros:    |%010d|\n", 1977);
   printf("En otras bases: %d %X %o %#x %#o\n", 941, 941, 941, 941, 941);
   printf("Reales: |%4.2f| |%+.0e| %E\n", 3.1416, 3.1416, 3.1416);
   printf("Reales: |%.2f| |%+.0f|\n", 3.1416, 3.1416);
   printf("Truco con el ancho: |%*d|, |%*s|.\n", 5, 10, 10, "Hola");
   printf("Un texto: |%s|, |%-7s|, |%7s|.\n", "Hola", "Hola", "Hola");
   printf("Un texto: |%.3s|, |%.1s|.\n", "Hola", "Hola");
   printf("Los signos: %d, % d, %+d, %+d\n", 10, 10, 10, -10);
   printf("Un long double: %30.27Lf\n", 7.45705212176720177385406211643499538942L);
   printf("El porcentaje: %d%%\n", 10);
   return 0;
}
