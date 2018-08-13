#include <stdio.h>

// gcc -Wall -o 07_ej_uniones 07_ej_uniones.c

typedef enum { ENTERO, CADENA, REAL, PUNTERO, CARACTER } tipo;

typedef struct
{
   tipo tipodato;
   union {
      unsigned int entero;
      char *cadena;
      double real;
      void *puntero;
      char caracter;
   };
} valor;


// prototipos de funciones
valor funcion_entero(int r);
void funcion_real(double r, valor *v);


int main(void)
{
   valor v1;
   v1 = funcion_entero(1234567890); // = 0x499602d2 en base 16
   // hex2dec('49') == 73 == 'I'    hex2dec('96') == 150
   // hex2dec('02') ==  2           hex2dec('d2') == 210 == ''

   
   if (v1.tipodato == ENTERO)
      printf("v1.entero = %d\n"
             "v1.real = %f\n"
             "v1.caracter = %hhx\n"
             "v1.puntero = %p\n",
             v1.entero, 
             v1.real, 
             v1.caracter, 
             v1.puntero);

   return 0;
}

valor funcion_entero(int r)
{
   valor v;
   v.tipodato = ENTERO;
   v.entero = r;
   return v;
}

void funcion_real(double r, valor *v)
{
   v->tipodato = REAL;
   v->real = r;
}
