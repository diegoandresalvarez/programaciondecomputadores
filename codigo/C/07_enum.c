#include<stdio.h>
// Ejemplo tomado de: http://maxus.fis.usal.es/FICHAS_C.WEB/02xx_PAGS/0201.html
#define NUM_OPCIONES 5

int main(void)
{
   enum opciones{ Nuevo, Abrir, Guardar, Cerrar, Salir };

   char menu[][10] = {"Nuevo", "Abrir", "Guardar", "Cerrar", "Salir"};
   char opcion; 
   int i,c;
   enum opciones caso;

   do
   {
      printf("Seleccione una opción:\n");
      for (i = 0; i < NUM_OPCIONES; i++) printf("%d: %s\n", i+1, menu[i]);

      printf("Número de la opción: ");
      scanf("%c", &opcion);  
      while((c = getchar()) != '\n' && c != EOF); // vaciar el buffer

      caso = opcion - '0' - 1;
      switch (caso)
      {
      case Nuevo:   printf("\nSe ha seleccionado la opción %s\n\n", menu[caso]);
         break;
      case Abrir:   printf("\nSe ha seleccionado la opción %s\n\n", menu[caso]);
         break;
      case Guardar: printf("\nSe ha seleccionado la opción %s\n\n", menu[caso]);
         break;
      case Cerrar:  printf("\nSe ha seleccionado la opción %s\n\n", menu[caso]);
         break;
      case Salir:   printf("\nSe ha seleccionado la opción %s\n\n", menu[caso]);
         break;
      default:      printf("\nOPCION INCORRECTA!!\n\n");
         break;
      }
   }
   while (caso != Salir);
   printf("\n\nFin del programa\n\n");

   return 0;
}

