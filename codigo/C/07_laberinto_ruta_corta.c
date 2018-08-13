// Programa para encontrar la salida de laberintos. Encuentra la ruta más corta
// utilizando para ello el algoritmo "breadth-first search"
// http://en.wikipedia.org/wiki/Breadth-first_search
//
// Compile con:
// gcc -Wall 07_laberinto_ruta_corta.c -o 07_laberinto_ruta_corta

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Se definen las constantes
const char VACIO     = ' '; // nunca se ha visitado
const char PRINCIPIO = 'P';
const char FIN       = 'F';
const char VISITADO  = '.'; // visitado pero no es el camino correcto
const char OK        = 'o'; // camino correcto

#define COL 29
#define FIL 18
char L[FIL][COL] =
{
   "#############################",
   "P #     #   #   #     #   # #",
   "# # ### ### # # # ### ### # #",
   "# # #       # # # #       # #",
   "# #   ### # # # #   ### # # #",
   "# # # #   # # # # # #   # # F",
   "#   # # # # # #   # # # # # #",
   "##### # # # # ##### # # # # #",
   "#     # # #   #     # # #   #",
   "# #     #   # # #     #   # #",
   "# # ### ### # # # ### ### # #",
   "# # #       # # # #       # #",
   "# #   ### # # # #   ### # # #",
   "# # # #   # # # # # #   # # #",
   "#   # # # # # #   # # # # # #",
   "##### # # # # ##### # # # # #",
   "#     # # #   #     # # #   #",
   "#############################"
};

// Se definen los tipos de datos
typedef struct
{
   int f, c;
} celda;

typedef struct
{
   celda nodo[FIL*COL];
   int ini, fin, nelem;
} cola;

// Se definen los prototipos de las funciones
bool cola_vacia(cola q);
bool entrar_cola(cola *q, celda item);
bool salir_cola(cola *q, celda *item);
// void imprimir_cola(cola q);
void imprimir_laberinto(void);
bool resolver(void);

// La cola está vacia?
bool cola_vacia(cola q)
{
   return (q.fin == q.ini);
}

// Meter un elemento a la cola
bool entrar_cola(cola *q, celda item)
{
   if (q->nelem == FIL*COL) return false;

   if(q->fin == (FIL*COL - 1))
      q->fin = 0;
   else
      q->fin++;

   q->nodo[q->fin] = item;
   q->nelem++;

   //  printf("pos= %d, item.f = %d, item.c = %d\n",q->fin, item.f,item.c);
   return true;
}

// Sacar un elemento de la cola
bool salir_cola(cola *q, celda *item)
{
   if(cola_vacia(*q)) return false;

   if(q->ini == (FIL*COL - 1))
      q->ini = 0;
   else
      q->ini++;

   *item = q->nodo[q->ini];
   q->nelem--;

   return true;
}

/*
void imprimir_cola(cola q)
{
   printf(".ini = %d, .fin = %d\n", q.ini, q.fin);

   int i;
   for (i=q.ini+1; i!=q.fin+1;  i++)
   {
      if (i == q.FIL*COL) i = 0;
      printf("i = %d, f = %d, c = %d\n", i, q.nodo[i].f, q.nodo[i].c);
   }
   printf("\n");

   return;
}
*/

// Algoritmo http://en.wikipedia.org/wiki/Breadth-first_search
bool resolver(void)
{
   celda actual;
   celda referente[FIL][COL];
   int i, j, dir;

   // crear cola e inicializarla a una cola vacia
   cola q = {.ini = 0, .fin = 0, .nelem = 0};

   // Encuentra el comienzo del laberinto y desde allí comienza la búsqueda
   for (i=0; i<FIL; i++)
      for (j=0; j<COL; j++)
         if (L[i][j] == PRINCIPIO)
            goto encontre_principio;

   puts("El laberinto no tiene un principio");
   return EXIT_FAILURE;

encontre_principio:
   // El nodo [i][j] es el principio, no tiene una celda referente
   referente[i][j] = (celda){.f = -1, .c = -1};

   // agregar el principio a la cola
   entrar_cola(&q, (celda){.f = i, .c = j});

   // hacer el ciclo hasta que no haya más nodos vecinos que revisar
   while(!cola_vacia(q))
   {
      // Se saca el elemento de la cola; este comando siempre retornara true
      // (ya que la cola no esta vacia)
      salir_cola(&q, &actual);

      //revisar los vecinos del actual
      for (dir=1; dir<=4; dir++)
      {
         celda sgte;
         switch(dir)
         {
            case 1: sgte.f = actual.f;   sgte.c = actual.c+1; break; //derecha
            case 2: sgte.f = actual.f-1; sgte.c = actual.c;   break; //arriba
            case 3: sgte.f = actual.f;   sgte.c = actual.c-1; break; //izquierda
            case 4: sgte.f = actual.f+1; sgte.c = actual.c;   break; //abajo
         }

         // si sgte se salio del laberinto, continue con el siguiente ciclo
         if (sgte.f<0 || sgte.f==FIL) continue; // (por arriba o por abajo)
         if (sgte.c<0 || sgte.c==COL) continue; // (por la izquierda o derecha)

         // si el sgte no ha sido visitado, o encontramos la salida:
         if (L[sgte.f][sgte.c] == VACIO || L[sgte.f][sgte.c] == FIN)
         {
            // la referente de la celda siguiente es la celda actual
            referente[sgte.f][sgte.c] = actual;

            // si encontramos el final, salirse y pintar el camino
            if (L[sgte.f][sgte.c] == FIN)
            {
               celda pos = referente[sgte.f][sgte.c];
               int pasos = 0;
               do
               {
                  pasos++;
                  L[pos.f][pos.c] = OK;
                  pos = referente[pos.f][pos.c];
               } while (referente[pos.f][pos.c].f != -1 &&
                        referente[pos.f][pos.c].c != -1);
               printf("Solución encontrada en %d pasos\n\n", pasos);
               return true;
            }
            else // si es una celda vacia
            {
               L[sgte.f][sgte.c] = VISITADO;
               entrar_cola(&q, sgte);
            }
         }
      }
   }

   // se exploró todo el laberinto pero no se encontró la salida
   return false;
}

// Imprime el laberinto
void imprimir_laberinto()
{
   int i, j;
   for (i=0; i<FIL; i++)
   {
      for (j=0; j<COL; j++)
         putchar(L[i][j]);
      putchar('\n');
   }
}

int main(void)
{
   if (resolver())
      imprimir_laberinto();
   else
      puts("El laberinto no tiene solución");

   return 0;
}
