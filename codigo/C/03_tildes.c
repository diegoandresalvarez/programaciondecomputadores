 /*
   Para imprimir las tildes en WINDOWS se debe cambiar la fuente
   de la consola a "Lucida console fonts"
*/   

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   puts("áéíóúüñÑÁÉÍÓÚÜ€");
   
#if defined(__MINGW32__)
   puts("Corriendo bajo WINDOWS de 32/64 bits");
   system("chcp 65001 > nul");    // se debe activar la tabla de códigos para UTF-8
#elif defined(__GNUC__)
   puts("Corriendo bajo LINUX");  // no se debe hacer nada especial
#endif

   puts("áéíóúüñÑÁÉÍÓÚÜ€");
   
   return 0;
}
