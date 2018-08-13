#include<stdio.h>

typedef enum { Nuevo, Abrir, Guardar, Cerrar, Salir } opciones;

int main(void)
{
   opciones caso;

   caso = Guardar;
   switch (caso)
   {
   case Nuevo:   printf("\nSe ha seleccionado la opción Nuevo\n\n");
      break;
   case Abrir:   printf("\nSe ha seleccionado la opción Abrir\n\n");
      break;
   case Salir:   printf("\nSe ha seleccionado la opción Salir\n\n");
      break;
   }

   return 0;
}

