#include <stdio.h>

// gcc -Wall 09_fread.c -o 09_fread -std=c99

#define SIZE 5

int main(void)
{
   double a[SIZE] = {1., 2., 3., 4., 5.};
   FILE *fp = fopen("test.bin", "wb"); // debe ser modo binario
   fwrite(a, sizeof *a, SIZE, fp);     // escribe un array de doubles
   fclose(fp);

   double b[SIZE];
   fp = fopen("test.bin","rb");
   size_t ret_code = fread(b, sizeof *b, SIZE, fp); // lee un array de SIZE doubles
   if(ret_code == SIZE)
   {
      puts("El array se leyó correctamente: ");
      for(int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
      putchar('\n');
   }
   else // sucedió un error
   {
      if (feof(fp))
         puts("Error reading test.bin: unexpected end of file");
      else if (ferror(fp))
         perror("Error reading test.bin");
   }
}
