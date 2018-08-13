/*
 * Solucionador de SUDOKUS utilizando el algoritmo BACKTRACKING
 * 
 * La lógica detrás de este algoritmo es la misma que utilizamos para salir de un laberinto:
 * Intentamos una solución posible
 * Si dicha solución es mala, nos devolvemos, hasta el punto que podamos ensayar otra solución
 * ...
 * Repita hasta que salgamos del laberinto. Si regresamos a la salida, es porque no había solución
 * 
 * En nuestro caso:
 * The algorithm tries a value, then optimistically recurs on the next cell and
 * checks if the solution (as built up so far) is valid. If, at some later point
 * in execution, it is determined that what was built so far will not solve the
 * problem, the algorithm backs up the stack to a state in which there could be
 * another valid solution.
 * 
 * Tomado de:
 * http://spin.atomicobject.com/2012/06/18/solving-sudoku-in-c-with-recursive-backtracking/
 * http://en.wikipedia.org/wiki/Sudoku_solving_algorithms* 
 * http://en.wikipedia.org/wiki/Backtracking
 */

#include <stdio.h>
#include <stdbool.h>

// gcc -Wall -o 05_resolver_sudoku 05_resolver_sudoku.c

// Declaración de funciones
void imprimir_tablero();
bool usado_en_fila(int fil, int num);
bool usado_en_columna(int col, int num);
bool usado_en_caja(int x, int y, int num);
bool se_puede_colocar(int i, int j, int num);
bool sudoku(int i, int j);

// Declaración de variables globales

// SUDOKU super dificil: 
// http://en.wikipedia.org/wiki/User_talk:170.115.251.13/Su_Doku
int t[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},  // tablero a resolver (SUPER DURO)
               {0, 0, 0, 0, 0, 3, 0, 8, 5},  // en mi PC se demora 36s.
               {0, 0, 1, 0, 2, 0, 0, 0, 0},
               {0, 0, 0, 5, 0, 7, 0, 0, 0},
               {0, 0, 4, 0, 0, 0, 1, 0, 0},
               {0, 9, 0, 0, 0, 0, 0, 0, 0},
               {5, 0, 0, 0, 0, 0, 0, 7, 3},
               {0, 0, 2, 0, 1, 0, 0, 0, 0},
               {0, 0, 0, 0, 4, 0, 0, 0, 9}};
/*
int t[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  // tablero a resolver (FACIL)
               {5, 2, 0, 0, 0, 0, 0, 0, 0},
               {0, 8, 7, 0, 0, 0, 0, 3, 1},
               {0, 0, 3, 0, 1, 0, 0, 8, 0},
               {9, 0, 0, 8, 6, 3, 0, 0, 5},
               {0, 5, 0, 0, 9, 0, 6, 0, 0},
               {1, 3, 0, 0, 0, 0, 2, 5, 0},
               {0, 0, 0, 0, 0, 0, 0, 7, 4},
               {0, 0, 5, 2, 0, 6, 3, 0, 0}};
 */

// Procedimiento principal
int main()
{
   if (sudoku(0, 0))
      imprimir_tablero();
   else
      puts("El tablero no tiene solución");

   return 0;
}

// Imprimir el tablero del sudoku
void imprimir_tablero()
{
   int i, j;
   for (i=0; i<9; i++)
   {
      for (j=0; j<9; j++) printf("%2d", t[i][j]);
      printf("\n");
   }
}

// Retorna TRUE si el numero "num" ya se puso en la fila "fil"
bool usado_en_fila(int fil, int num)
{
   int j;
   for (j=0; j<9; j++)
      if (t[fil][j] == num) return true;
    
   return false;
}

// Retorna TRUE si el numero "num" ya se uso en la columna "col"
bool usado_en_columna(int col, int num)
{
   int i;
   for (i=0; i<9; i++)
      if (t[i][col] == num) return true;
    
   return false;
}

// Retorna TRUE si el numero "num" ya se uso en la caja con borde sup izq "x,y"
bool usado_en_caja(int x, int y, int num)
{
   int i,j;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
         if (t[i+x][j+y] == num) return true;
        
    return false;
}

// Retorna TRUE si se puede colocar num en la posición "i,j"
bool se_puede_colocar(int i, int j, int num)
{
    return !usado_en_fila(i, num)    && 
           !usado_en_columna(j, num) &&
           !usado_en_caja(i-i%3, j-j%3, num);
}

bool sudoku(int i, int j)
{
   int num;

   if (i == 9) return true; // lo resolvimos!!!, ya que i=0..8

   // si la casilla i,j está ocupada, intentar la siguiente casilla.
   if (t[i][j])
   {
      if (j == 8)
      {  // intentar la siguiente fila,    si se resuelve retornar TRUE 
         if (sudoku(i+1, 0)) return true; 
      }
      else
      {  // intentar la siguiente columna, si se resuelve retornar TRUE
         if (sudoku(i, j+1)) return true; 
      }

      return false; // como no se pudo resolver, retornar FALSE
   }

   // como la casilla está vacia, intente todos los números en esta celda
   for (num=1; num<=9; num++)
   {
      if (se_puede_colocar(i, j, num))
      {
         t[i][j] = num; // proponer una solución

         // Ensayar resolver el SUDOKU con la solución propuesta
         if (j == 8)    
         {  // intentar la siguiente fila,    si se resuelve retornar TRUE
            if (sudoku(i+1, 0)) return true; 
         }
         else
         {  // intentar la siguiente columna, si se resuelve retornar TRUE         
            if (sudoku(i, j+1)) return true;
         }
            
         // como la solución no funcionó, deshacer e intentar de nuevo         
         t[i][j] = 0;
      }
   }
   
   return false; // no se pudo resolver despues de intentar todos los números
}
