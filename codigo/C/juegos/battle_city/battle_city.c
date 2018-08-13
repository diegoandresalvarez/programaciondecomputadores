/*      ____        _   _   _         _____ _ _
 *     |  _ \      | | | | | |       / ____(_) |
 *     | |_) | __ _| |_| |_| | ___  | |     _| |_ _   _
 *     |  _ < / _` | __| __| |/ _ \ | |    | | __| | | |
 *     | |_) | (_| | |_| |_| |  __/ | |____| | |_| |_| |
 *     |____/ \__,_|\__|\__|_|\___|  \_____|_|\__|\__, |
 *                                                 __/ |
 *                                                |___/
 * Por:
 * Diego Andrés Alvarez Marín (daalvarez@unal.edu.co)
 * Ver el Battle City original en:
 * http://nintendo8.com/game/245/battle_city/
 * https://www.youtube.com/watch?v=MPsA5PtfdL0
 * http://strategywiki.org/wiki/Battle_City
 *
 * INSTRUCCIONES:
 * Flechas mueven el tanque
 * ESPACIO dispara
 * P       pausa
 * ESCAPE  se sale del juego
 *
 * COMPILE CON:
 * WINDOWS:
 * gcc -Wall -O3 -o battle_city.exe battle_city.c -std=c99 -lpdcurses -lm
 *
 * LINUX/MAC:
 * gcc -Wall -O3 -o battle_city     battle_city.c -std=c99 -lncurses  -lm
 */

#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

/// se definen las constantes
#define KEY_ESCAPE           27    // código ASCII de la tecla ESCAPE
#define NFIL                 15    // filas mapa
#define NCOL                 28    // columnas mapa
#define N_MAX_TANQUES        18    // número máximo de tanques por nivel

// colores
#define COL_MURO_ACERO        1    // muro de acero
#define COL_MURO              2    // muro normal
#define COL_PASILLO           3
#define COL_BOSQUE            4
#define COL_AGUA              5

#define COL_TANQUE_AMIGO      6
#define COL_TANQUE_1          7
#define COL_TANQUE_2          8
#define COL_TANQUE_3          9
#define COL_TANQUE_4         10

#define COL_CAPSULA          11
#define COL_AGUILA           12
#define COL_BALA_AMIGA       13
#define COL_BALA_ENEMIGA     14

const chtype CHAR_MURO_ACERO = '*' | COLOR_PAIR(COL_MURO_ACERO) | A_BOLD;
const chtype CHAR_MURO       = ' ' | COLOR_PAIR(COL_MURO)       | A_BOLD;
const chtype CHAR_PASILLO    = ' ' | COLOR_PAIR(COL_PASILLO);
const chtype CHAR_BOSQUE     = ' ' | COLOR_PAIR(COL_BOSQUE)     | A_BOLD;
const chtype CHAR_AGUA       = ' ' | COLOR_PAIR(COL_AGUA)       | A_BOLD;

const char flecha_dir[5] = {'x', '>', '^', '<', 'v'};

/// se definen las enumeraciones
typedef enum {quieto, derecha, arriba, izquierda, abajo} direccion;

/// se definen las estructuras
typedef struct
{
   enum {amigo, enemigo} tipo; // tanque amigo o enemigo
   int fil, col;               // posición actual (fila, columna)
   direccion dir;              // dirección hacia la que avanza
   int vidas;                  // vidas del tanque
   int potencia_disparo;       // potencia del disparo
   struct timeval tic, toc;    // para el cronometro
   double tiempo_entre_mov;    // tiempo entre movimientos
   int id;                     // identificación del tanque (-1 tanque amigo)

   /// estas son características solo del tanque amigo:
   direccion proxima_dir;    // próxima dirección hacia la que avanza el tanque

   /// estas son características solo del tanque enemigo:
   chtype simbolo;           // representación gráfica del tanque
   double dps;               // número promedio de disparos por segundo
   double ted;               // tiempo entre disparos
   struct timeval ticd, tocd;// para el cronometro del disparo
   int caminados_misma_dir;  // número casillas avanzadas en la misma dirección
   int activo;               // si ya apareció o no el tanque en el tablero
} tanque;

typedef struct
{
   int fil, col;             // fila y columna de la bala
   direccion dir;            // dirección en la que avanza la bala
   int origen;               // quien disparó la bala?
   int poder_destructivo;    // de la bala
   struct timeval tic, toc;  // para el cronometro
   double tiempo_entre_mov;  // tiempo entre movimientos
}
tipo_nodo;

struct struct_nodo
{
   tipo_nodo dato;
   struct struct_nodo *sgte;
};
typedef struct struct_nodo nodo;

typedef struct
{
   nodo *cabeza;
} lista;

/// se definen las variables globales
lista lista_balas;          // lista simplemente enlazada que contiene las balas
int marcador = 0;           // marcador del juego
WINDOW *tablero_juego;      // tableros NCURSES
WINDOW *tablero_info;
tanque tanque_amigo;
tanque tanque_enemigo[N_MAX_TANQUES];
int idx_tanque = 0;         // índice del último tanque enemigo que apareció

char mapa[NFIL][NCOL] =     // tablero de juego
{
   "A--------------------------B",
   "|                          |",
   "|  ##  ##  ##  ##  ##  ##  |",
   "|  ##  ##  ##  ##  ##  ##  |",
   "|  ##  ##  ##**##  ##  ##  |",
   "|  ##  ##          ##  ##  |",
   "|          ##  ##          |",
   "|**  ####          ####  **|",
   "|          ##  ##          |",
   "|  ##  ##  ######  ##  ##  |",
   "|  ##  ##  ##  ##  ##  ##  |",
   "|  ##  ##          ##  ##  |",
   "|  ##  ##   ####   ##  ##  |",
   "|           #@@#           |",
   "D--------------------------C"
};

/// prototipos de funciones
void inicializaciones(void);
void inicializar_tanque_amigo(void);
void inicializar_tanques_enemigos(void);
void pintar_el_laberinto(void);
void actualizar_el_tablero_de_informacion(void);
void mover_tanque_amigo(direccion dir);
void mover_tanque_enemigo(tanque *T);
bool puede_moverse_tanque(tanque T, direccion dir);
nodo* crear_lista_enlazada(lista *L, tipo_nodo dato);
nodo* agregar_a_la_lista(lista *L, tipo_nodo dato);
void destruir_lista(lista *L);
void disparar_bala(tanque T);
bool mover_y_graficar_bala(nodo *ptr);
int muestrea_de_FMP(const int n, const double w[n]);
inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic);
void presionar_pausa(void);
bool hay_tanque_enemigo_en(int fil, int col);
void aparecen_los_tanques_al_azar(void);

/// procedimiento principal
int main(void)
{
   initscr();                     // empiece el modo NCURSES
   inicializaciones();            // inicializaciones de ncurses y de la semilla
   pintar_el_laberinto();
   inicializar_tanque_amigo();
   inicializar_tanques_enemigos();

   // Inicialmente se activan tres tanques
   tanque_enemigo[idx_tanque].activo = true; idx_tanque++;
   tanque_enemigo[idx_tanque].activo = true; idx_tanque++;
   tanque_enemigo[idx_tanque].activo = true; idx_tanque++;

   bool salirse = false;              // ¿ salirse del juego ?
   while ((tanque_amigo.vidas > 0) && (!salirse))
   {
      actualizar_el_tablero_de_informacion();

      aparecen_los_tanques_al_azar();

      /// mover y graficar las balas en el tablero (y hacer que destruyan cosas)
      // este ciclo for recorre la lista simplemente enlazada
      for(nodo *ptr = lista_balas.cabeza; ptr != NULL; ptr = ptr->sgte)
      {
         tipo_nodo *B = &(ptr->dato); // asigne la bala a la variable B

         gettimeofday(&(B->toc), NULL);
         double tiempo = intervalo_tiempo_seg(B->toc, B->tic);
         if (tiempo > B->tiempo_entre_mov)
            if (mover_y_graficar_bala(ptr)) salirse = true;
            // NOTA: recuerde que mover_y_graficar_bala() retorna true si
            // murió el tanque amigo o el águila
      }

      /// los tanques enemigos disparan balas
      for (int i=0; i<N_MAX_TANQUES; i++)
      {
         bool disparar = true;

         // si el tanque esta muerto o si no ha aparecido en el tablero continúe
         // con el siguiente
         if (tanque_enemigo[i].vidas <= 0 || !tanque_enemigo[i].activo) continue;

         int fil = tanque_enemigo[i].fil;
         int col = tanque_enemigo[i].col;
         do
         {
            switch(tanque_enemigo[i].dir)
            {
            case quieto:     break; // para hacer feliz al compilador
            case derecha:    if (col<NCOL-1) col++; break;
            case arriba:     if (fil>0)      fil--; break;
            case izquierda:  if (col>0)      col--; break;
            case abajo:      if (fil<NFIL-1) fil++;
            }

            // Si el disparo llegaría a un tanque enemigo
            if (hay_tanque_enemigo_en(fil, col))
            {
               disparar = false;
               break; // no dispare, los tanques enemigos no se atacan entre si
            }

            // si el disparo mata el tanque amigo o al águila
            if (((tanque_amigo.fil == fil) && (tanque_amigo.col == col)) ||
                (mapa[fil][col] == '@'))
            {
               /// ATAQUE !!!
               tanque_enemigo[i].ted = 0.5;
               break;
            }
         } while (mapa[fil][col] == ' '); // o agua o bosque

         gettimeofday(&(tanque_enemigo[i].tocd), NULL);
         double tiempo = intervalo_tiempo_seg(tanque_enemigo[i].tocd, tanque_enemigo[i].ticd);
         if ((tiempo > tanque_enemigo[i].ted) && (disparar == true))
         {
            // verificar que la bala no mate un tanque enemigo. Ellos no se
            // matan entre si.
            disparar_bala(tanque_enemigo[i]);

            // Si se modelan los disparos de balas como un proceso de Poisson,
            // entonces, los tiempos de espera entre disparos siguen una FMP
            // exponencial. Según
            // http://en.wikipedia.org/wiki/Exponential_distribution#Generating_exponential_variates
            // uno puede simular de una FDP exponencial usando la fórmula:
            // T = -ln(U)/lambda, donde U ~ Unif(0,1)
            // donde lambda es el número promedio de disparos por segundo

            // calculo del tiempo para que se efectúe el sgte disparo
            tanque_enemigo[i].ted = -log(((double)rand())/RAND_MAX)/tanque_enemigo[i].dps;

            // active de nuevo el cronometro preparándose para el sgte disparo
            gettimeofday(&(tanque_enemigo[i].ticd), NULL);
         }
      }

      /// mover los tanques enemigos
      for (int i=0; i<N_MAX_TANQUES; i++)
      {
         // si el tanque esta muerto o si no ha aparecido en el tablero continúe
         // con el siguiente
         if (tanque_enemigo[i].vidas <= 0 || !tanque_enemigo[i].activo) continue;

         gettimeofday(&(tanque_enemigo[i].toc), NULL);
         double tiempo = intervalo_tiempo_seg(tanque_enemigo[i].toc, tanque_enemigo[i].tic);
         if (tiempo > tanque_enemigo[i].tiempo_entre_mov)
         {
            mover_tanque_enemigo(&tanque_enemigo[i]);

            // active de nuevo el cronometro preparándose para el sgte movimiento
            gettimeofday(&(tanque_enemigo[i].tic), NULL);
         }
      }

      /// mover el tanque_amigo
      gettimeofday(&tanque_amigo.toc, NULL);
      double tiempo = intervalo_tiempo_seg(tanque_amigo.toc, tanque_amigo.tic);
      if (tiempo > tanque_amigo.tiempo_entre_mov)
      {
         // si se puede mover en la próxima dirección hágalo, de lo contrario
         // siga la inercia
         if(puede_moverse_tanque(tanque_amigo, tanque_amigo.proxima_dir))
            mover_tanque_amigo(tanque_amigo.proxima_dir);
         else
            mover_tanque_amigo(tanque_amigo.dir);

         // active de nuevo el cronometro preparándose para el sgte movimiento
         gettimeofday(&tanque_amigo.tic, NULL);
      }

      /// contar el número de tanques enemigos activos
      int numero_tanques_activos = 0;
      for (int i=0; i<N_MAX_TANQUES; i++)
         numero_tanques_activos += tanque_enemigo[i].activo;

      /// Si se eliminaron todos los tanques enemigos, ganaste el juego
      if (idx_tanque == 18 && numero_tanques_activos == 0)
      {
         WINDOW *ventana;
         char mensaje[] = "Presione 'C' para continuar";
         // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
         ventana = newwin(9, strlen(mensaje)+4, 1+NFIL/2, NCOL+3);
         box(ventana, 0, 0);	 // 0, 0 pone los caracteres estándar del borde
         wattron(ventana, A_BOLD);
         mvwprintw(ventana, 2, 2, "     FELICITACIONES!!!     ");
         mvwprintw(ventana, 4, 2, "***  Gastaste el juego  ***");
         wattroff(ventana, A_BOLD);
         mvwprintw(ventana, 6, 2, mensaje);
         wrefresh(ventana);
         flushinp();              // borre el buffer del teclado
         wtimeout(ventana, 1);    // wgetch() espera 1 milisegundo
         do {} while (toupper(wgetch(ventana)) != 'C'); // 'C' para continuar
         werase(ventana);         // borre los caracteres de la ventana
         wrefresh(ventana);
         delwin(ventana);
         touchwin(tablero_juego); // redibujar la ventana tablero_juego

         salirse = true;
      }

      /// vaciamos el buffer del teclado
      // para que lea solo lo último especificado: esto se hace porque si se
      // presione siempre las flechas no se reaccionaría inmediatamente a la
      // última flecha
      flushinp();

      /// leer el teclado
      int ch = wgetch(tablero_juego); // contiene la letra leída desde el teclado
      switch(ch)
      {
      case KEY_RIGHT: // flecha derecha
         tanque_amigo.proxima_dir = derecha;
         break;
      case KEY_UP:    // flecha arriba
         tanque_amigo.proxima_dir = arriba;
         break;
      case KEY_LEFT:  // flecha izquierda
         tanque_amigo.proxima_dir = izquierda;
         break;
      case KEY_DOWN:  // flecha abajo
         tanque_amigo.proxima_dir = abajo;
         break;
      case ' ':       // dispara bala
         disparar_bala(tanque_amigo);
         break;
      case 'p':                       // pausa
      case 'P':
         presionar_pausa();
         break;
      case KEY_ESCAPE:            // salirse del juego
         salirse = true;
         break;
      }

      /// actualizar la pantalla
      wrefresh(tablero_juego);
      wrefresh(tablero_info);
   }
   /// Se libera la memoria asignada a las balas
   destruir_lista(&lista_balas);

   /// Se cierran las ventanas
   delwin(tablero_juego);
   delwin(tablero_info);
   endwin();    // finalice el modo NCURSES
   return EXIT_SUCCESS;
}

void inicializaciones(void)
{
   // el monitor soporta colores?
   if (has_colors() == FALSE)
   {
      endwin();
      puts("Su monitor no soporta colores");
      exit(EXIT_FAILURE);
   }

   resize_term(20,70);  // poner ventana de 20 filas, 70 columnas

   /// Se inicializan las ventanas del juego
   // newwin(nfilas, ncols, sup_izq_fil, sup_izq_col);
   tablero_juego = newwin(NFIL, NCOL, 4, 0);
   tablero_info  = newwin(4,    NCOL, 0, 0);

   box(tablero_info, 0, 0);  // 0, 0 pone los caracteres estándar del borde

   curs_set(0);         // no se muestra el cursor
   cbreak();            // no line buffering: lee letra a letra, no espera \n
   keypad(tablero_juego, true); // acepte flechas y otras teclas especiales
   wtimeout(tablero_juego, 1);  // wgetch() espera 1 ms si no hay tecla presionada
   noecho();            // no haga echo() con getch()
   srand(time(NULL));   // inicializar el generador de números aleatorios
   start_color();       // activar modo colores

   // definir colores            letra         fondo
   init_pair(COL_MURO_ACERO,     COLOR_WHITE,   COLOR_WHITE);
   init_pair(COL_MURO,           COLOR_WHITE,   COLOR_RED);
   init_pair(COL_PASILLO,        COLOR_WHITE,   COLOR_BLACK);
   init_pair(COL_BOSQUE,         COLOR_WHITE,   COLOR_GREEN);
   init_pair(COL_AGUA,           COLOR_WHITE,   COLOR_BLUE);

   init_pair(COL_TANQUE_AMIGO,   COLOR_BLACK,   COLOR_CYAN);
   init_pair(COL_TANQUE_1,       COLOR_RED,     COLOR_YELLOW);
   init_pair(COL_TANQUE_2,       COLOR_MAGENTA, COLOR_YELLOW);
   init_pair(COL_TANQUE_3,       COLOR_CYAN,    COLOR_YELLOW);
   init_pair(COL_TANQUE_4,       COLOR_BLUE,    COLOR_YELLOW);

   init_pair(COL_CAPSULA,        COLOR_RED,     COLOR_BLACK);
   init_pair(COL_AGUILA,         COLOR_RED,     COLOR_WHITE);
   init_pair(COL_BALA_AMIGA,     COLOR_WHITE,   COLOR_GREEN);
   init_pair(COL_BALA_ENEMIGA,   COLOR_WHITE,   COLOR_RED);
}

void pintar_el_laberinto(void)
{
   int letra, color;

   for (int f = 0; f < NFIL; f++)
      for (int c = 0; c < NCOL; c++)
      {
         switch(mapa[f][c])
         {
         case '|':
            color = COL_MURO_ACERO;
            letra = ACS_VLINE | A_BOLD;
            break;
         case '-':
            color = COL_MURO_ACERO;
            letra = ACS_HLINE | A_BOLD;
            break;
         case 'A':
            color = COL_MURO_ACERO;
            letra = ACS_ULCORNER | A_BOLD;
            break;
         case 'B':
            color = COL_MURO_ACERO;
            letra = ACS_URCORNER | A_BOLD;
            break;
         case 'C':
            color = COL_MURO_ACERO;
            letra = ACS_LRCORNER | A_BOLD;
            break;
         case 'D':
            color = COL_MURO_ACERO;
            letra = ACS_LLCORNER | A_BOLD;
            break;
         case '@':
            color = COL_AGUILA;
            letra = 'A' | A_BOLD;
            break;
         case ' ': // OJO debe coincidir con la variable CHAR_PASILLO
            color = COL_PASILLO;
            letra = ' ';
            break;
         case '#': // OJO debe coincidir con la variable CHAR_MURO
            color = COL_MURO;
            letra = ' ' | A_BOLD;
            break;
         case '*': // OJO debe coincidir con la variable CHAR_MURO_ACERO
            color = COL_MURO_ACERO;
            letra = ' ' | A_BOLD;
            break;
         // aquí se agrega el bosque y el agua
         default:
            delwin(tablero_juego);
            delwin(tablero_info);
            endwin();                 // finalice el modo NCURSES

            perror("Error en la especificación del laberinto");
            exit(EXIT_FAILURE);
         }
         // imprima el caracter + color
         mvwaddch(tablero_juego, f, c, letra | COLOR_PAIR(color));
      }
   //wrefresh(tablero_juego);    // imprimir en la pantalla física
}

// Muestrea un punto entre 0:n-1 con función de masa de probabilidades w
// y retorna el índice de la muestra en w
int muestrea_de_FMP(const int n, const double w[n])
{
   // muestrea un numero aleatorio en el intervalo [0,1)
   double random = ((double)rand())/RAND_MAX;

   // suma de pesos
   double sum_w = 0.0;
   for (int i = 0; i < n; i++)  sum_w += w[i];

   // se calcula la función de distribución de probabilidades acumulada (FDA)
   double cumsum_w = 0.0;
   for (int i = 0; i < n; i++)
   {
      cumsum_w += w[i]/sum_w;           // FDA empírica
      if (random <= cumsum_w) return i;
   }

   // Aquí nunca llegaremos (a menos que haya un error en el algoritmo)
   // perror("Error en muestrea_de_FMP()");
   // exit(EXIT_FAILURE);
   return 0;
}

void actualizar_el_tablero_de_informacion(void)
{
   mvwprintw(tablero_info, 1, 2, "Vidas    = %3d", tanque_amigo.vidas);
   mvwprintw(tablero_info, 2, 2, "Marcador = %3d", marcador);
   mvwprintw(tablero_info, 3, 2, "Enemigos = %3d", N_MAX_TANQUES-idx_tanque);
}

void presionar_pausa(void)
{
   WINDOW *ventana;
   char mensaje[] = "Presione 'P' para continuar";
   // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
   ventana = newwin(7, strlen(mensaje)+4, 1+NFIL/2, NCOL+3);
   box(ventana, 0, 0);	 // 0, 0 pone los caracteres estandar del borde
   wattron(ventana, A_BOLD);
   mvwprintw(ventana, 2, 2, "   *** Juego Pausado ***   ");
   wattroff(ventana, A_BOLD);
   mvwprintw(ventana, 4, 2, mensaje);
   wrefresh(ventana);
   flushinp();              // borre el buffer del teclado
   wtimeout(ventana, 1);    // wgetch() espera 1 milisegundo
   do {} while (toupper(wgetch(ventana)) != 'P');   // 'P' para continuar
   werase(ventana);         // borre los caracteres de la ventana
   wrefresh(ventana);
   delwin(ventana);
   touchwin(tablero_juego); // redibujar la ventana tablero_juego
}

double intervalo_tiempo_seg(struct timeval toc, struct timeval tic)
{
   return (toc.tv_sec - tic.tv_sec) + (toc.tv_usec - tic.tv_usec)/1000000.0;
}

void inicializar_tanque_amigo(void)
{
   tanque_amigo.tipo             = amigo;  // tanque amigo
   tanque_amigo.fil              = 7;
   tanque_amigo.col              = 13;
   tanque_amigo.dir              = quieto;
   tanque_amigo.id               = -1;

   // quédese quieto al principio del juego
   tanque_amigo.proxima_dir      = quieto;
   tanque_amigo.vidas            = 1000;
   tanque_amigo.potencia_disparo = 3;
   tanque_amigo.tiempo_entre_mov = 1.0/3; // muévase 5 cuadros por segundo

   // inicializar el cronómetro del tanque amigo
   gettimeofday(&tanque_amigo.tic, NULL);
}

void inicializar_tanques_enemigos(void)
{
   for(int i=0; i<N_MAX_TANQUES; i++)
   {
      int fil, col;
      // seleccione al azar fil y col hasta que encuentre una casilla vacía
      fil = 1; // los tanques enemigos siempre aparecen en la primera fila
      do
      {
         // fil = (double)rand()*NFIL/RAND_MAX;
         col = (double)rand()*NCOL/RAND_MAX;
      }
      while (mapa[fil][col] != ' ');

      tanque_enemigo[i].tipo   = enemigo;
      tanque_enemigo[i].fil    = fil;
      tanque_enemigo[i].col    = col;
      tanque_enemigo[i].id     = i;
      tanque_enemigo[i].dir    = (double)rand()*4.0/RAND_MAX + 1;
      tanque_enemigo[i].activo = false; // ya apareció o no el tanque en el tablero
      tanque_enemigo[i].caminados_misma_dir = 0;

      int tipo_tanque_enemigo = (double)rand()*4.0/RAND_MAX + 1;
      switch (tipo_tanque_enemigo)
      {
      case 1:
         tanque_enemigo[i].simbolo          = COLOR_PAIR(COL_TANQUE_1) | A_BOLD;
         tanque_enemigo[i].vidas            = 1;
         tanque_enemigo[i].potencia_disparo = 1;
         tanque_enemigo[i].tiempo_entre_mov = 1.0/3;
         tanque_enemigo[i].dps              = 0.5; // disparos por segundo
         break;
      case 2:
         tanque_enemigo[i].simbolo          = COLOR_PAIR(COL_TANQUE_2) | A_BOLD;
         tanque_enemigo[i].vidas            = 1;
         tanque_enemigo[i].potencia_disparo = 1;
         tanque_enemigo[i].tiempo_entre_mov = 1.0/3;
         tanque_enemigo[i].dps              = 1.0; // disparos por segundo
         break;
      case 3:
         tanque_enemigo[i].simbolo          = COLOR_PAIR(COL_TANQUE_3) | A_BOLD;
         tanque_enemigo[i].vidas            = 1;
         tanque_enemigo[i].potencia_disparo = 1;
         tanque_enemigo[i].tiempo_entre_mov = 1.0/3;
         tanque_enemigo[i].dps              = 0.1; // disparos por segundo
         break;
      case 4:
         tanque_enemigo[i].simbolo          = COLOR_PAIR(COL_TANQUE_4) | A_BOLD;
         tanque_enemigo[i].vidas            = 1;
         tanque_enemigo[i].potencia_disparo = 1;
         tanque_enemigo[i].tiempo_entre_mov = 1.0/3;
         tanque_enemigo[i].dps              = 0.2; // disparos por segundo
         break;
      default:
         delwin(tablero_juego);
         delwin(tablero_info);
         endwin();                 // finalice el modo NCURSES

         perror("Hay un error asignando el tipo de tanque");
         exit(EXIT_FAILURE);
      }

      // se calcula el tiempo para el siguiente disparo (ver nota arriba con
      // respecto a la FDP exponencial)
      tanque_enemigo[i].ted = -log(((double)rand())/RAND_MAX)/tanque_enemigo[i].dps;

      // inicializar los cronómetros de los tanques enemigos
      gettimeofday(&(tanque_enemigo[i].tic),  NULL); // cronometro movimiento
      gettimeofday(&(tanque_enemigo[i].ticd), NULL); // cronometro disparos
   }
}

void mover_tanque_amigo(direccion dir)
{
   int fil, col, fil_ant, col_ant;

   // guardar las posiciones anteriores
   fil_ant = fil = tanque_amigo.fil;
   col_ant = col = tanque_amigo.col;

   // incrementar las posiciones
   switch(dir)
   {
   case quieto:     break; // para hacer feliz al compilador
   case derecha:    if (col<NCOL-1) col++; break;
   case arriba:     if (fil>0)      fil--; break;
   case izquierda:  if (col>0)      col--; break;
   case abajo:      if (fil<NFIL-1) fil++;
   }

   switch(mapa[fil][col]) // si la nueva posición es:                                      /// FALTA REVISAR QUE NO ESTE AVANZANDO SOBRE TANQUE ENEMIGO
   {
//    case 'L':
//        AQUI SE PONE CONDICION LAGO
//    case 'B':
//        AQUI SE PONE CONDICION BOSQUE

   case ' ':  // espacio en blanco, se mueve
      tanque_amigo.col = col;
      tanque_amigo.fil = fil;
      tanque_amigo.dir = dir;

      // se borra el tanque_amigo de la posición anterior para escribirlo en
      // la nueva posición                                                                /// FALTA REVISAR QUE NO VENGA DEL BOSQUE
      mvwaddch(tablero_juego, fil_ant, col_ant, CHAR_PASILLO);
      break;
   }

   // se escribe el tanque_amigo en la nueva posición
   mvwaddch(tablero_juego, tanque_amigo.fil, tanque_amigo.col,
            flecha_dir[dir] | COLOR_PAIR(COL_TANQUE_AMIGO) | A_BOLD);
}

bool puede_moverse_tanque(tanque T, direccion dir)
{
   int fil = T.fil, col = T.col;

   // incrementar las posiciones
   switch(dir)
   {
      case quieto:     return false;
      case derecha:    if (col<NCOL-1) col++;  break;
      case arriba:     if (fil>0)      fil--;  break;
      case izquierda:  if (col>0)      col--;  break;
      case abajo:      if (fil<NFIL-1) fil++;  break;
   }

   // el agua no permite avanzar
   // if (mvwinch(tablero_juego, fil, col) == CHAR_AGUA) return false;

   // pero si avanza en caso que haya un pasillo
   // (o bosque o hielo)
   if (mapa[fil][col] == ' ') return true;

   // en cualquier otro caso no avance
   return false;
}

void mover_tanque_enemigo(tanque *T)
{
   int num_pos_puede_moverse = 0;

   // este vector almacena la función de masa de probabilidades (no
   // normalizadas) de avanzar en la dirección indicada
   // Ver: http://es.wikipedia.org/wiki/Función_de_probabilidad
   double fmp_dir[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

   // determinar las direcciones en las que el tanque enemigo se puede mover
   for (direccion dir = derecha; dir<= abajo; dir++) // derecha = 1, abajo = 4
   {
      if (puede_moverse_tanque(*T, dir))
      {
         num_pos_puede_moverse++;
         fmp_dir[dir] =  1.0;
      }
   }

   // se selecciona la dirección aleatoria
   direccion nueva_dir = quieto;
   if (num_pos_puede_moverse != 0)
   {
      direccion dir_contraria = quieto;
      if      (T->dir == derecha)   dir_contraria = izquierda;
      else if (T->dir == izquierda) dir_contraria = derecha;
      else if (T->dir == arriba)    dir_contraria = abajo;
      else if (T->dir == abajo)     dir_contraria = arriba;

      // se incrementan en 8 veces las probabilidades de moverse
      // hacia adelante o hacia atrás (esta ultima en caso en caso que se
      // hayan avanzado mas de 10 casillas en la misma dirección
      if (fmp_dir[T->dir]) fmp_dir[T->dir] *= 8;
      if (puede_moverse_tanque(*T, dir_contraria) &&
         (T->caminados_misma_dir > 10))
         fmp_dir[dir_contraria] *= 8;

      nueva_dir = muestrea_de_FMP(5, fmp_dir);

      if (nueva_dir == T->dir)
         T->caminados_misma_dir++;
      else
         T->caminados_misma_dir = 0;
   }

   T->dir = nueva_dir;    // actualizar la dirección del tanque enemigo            /// AQUI PROBABILISTICAMENTE AVANZAR EN DIR ALEATORIA O SOBRE DIR OPTIMA AGUILA

   // se borra el tanque enemigo de la posición actual
   mvwaddch(tablero_juego, T->fil, T->col, CHAR_PASILLO);

   // se avanza el tanque enemigo una posición
   switch(T->dir)
   {
      case quieto:     break; // para hacer feliz al gcc
      case derecha:    if (T->col < NCOL-1) T->col++;  break;
      case arriba:     if (T->fil > 0)      T->fil--;  break;
      case izquierda:  if (T->col > 0)      T->col--;  break;
      case abajo:      if (T->fil < NFIL-1) T->fil++;  break;
   }

   // FALTA IMPLEMENTAR QUE LOS TANQUES ENEMIGOS NO SE CHOQUEN ENTRE SI O
   // CHOQUEN EL TANQUE AMIGO

   // se pone el tanque enemigo en la nueva posición
   mvwaddch(tablero_juego, T->fil, T->col, flecha_dir[T->dir] | T->simbolo);
}

// Crear la lista enlazada
// Retorna el puntero al nodo creado
// Si no hay memoria retorna un NULL
nodo* crear_lista_enlazada(lista *L, tipo_nodo dato)
{
    nodo *punt_a_nuevo_nodo = (nodo*) malloc(sizeof(nodo));
    if (punt_a_nuevo_nodo == NULL)
    {
        perror("malloc() retornó un NULL");
        return NULL;
    }
    punt_a_nuevo_nodo->dato = dato;
    punt_a_nuevo_nodo->sgte = NULL;

    L->cabeza = punt_a_nuevo_nodo;

    return punt_a_nuevo_nodo;
}

// Agregar nodo a la cabeza de la lista enlazada
// Si la cabeza == NULL (o sea, si la lista está vacía), crea la lista enlazada
// Si no hay memoria retorna un NULL
// Retorna un puntero al principio de la lista
nodo* agregar_a_la_lista(lista *L, tipo_nodo dato)
{
    if(L->cabeza == NULL) return crear_lista_enlazada(L, dato);

    nodo *punt_a_nuevo_nodo = (nodo *) malloc(sizeof(nodo));
    if(punt_a_nuevo_nodo == NULL)
    {
        perror("malloc() retornó un NULL");
        return NULL;
    }

   // el nuevo nodo se agrega a la cabeza
   punt_a_nuevo_nodo->dato = dato;
   punt_a_nuevo_nodo->sgte = L->cabeza;
   L->cabeza = punt_a_nuevo_nodo;

   return punt_a_nuevo_nodo;
}

// Borra un nodo de la lista. Soporta las siguientes opciones
// Borra la cabeza
// Borra nodo intermedio
// Nodo a borrar es NULL
// Nodo a borrar no existe
// La lista está vacía
bool borrar_nodo_de_la_lista(lista *L, nodo *ptr_a_nodo_a_borrar)
{
   if (ptr_a_nodo_a_borrar == NULL) return false; // no borre nada

   if (L->cabeza == ptr_a_nodo_a_borrar) // se borrará la cabeza
   {
      L->cabeza = ptr_a_nodo_a_borrar->sgte;
      free(ptr_a_nodo_a_borrar);
      return true;
   }

   for(nodo *ptr = L->cabeza; ptr != NULL; ptr = ptr->sgte)
   {
      if(ptr->sgte == ptr_a_nodo_a_borrar) // se encontró el nodo
      {
         ptr->sgte = ptr_a_nodo_a_borrar->sgte;
         free(ptr_a_nodo_a_borrar);
         return true;
      }
   }

   puts("Nodo no encontrado o lista vacía");
   return false;
}

void destruir_lista(lista *L)
{
   nodo *sgte;
   for(nodo *ptr = L->cabeza; ptr != NULL; ptr = sgte)
   {
      sgte = ptr->sgte;
      free(ptr);
   }
}

void disparar_bala(tanque T)
{
// las balas siempre se disparan en la dirección actual de movimiento del tanque
   tipo_nodo proyectil =
   {
      .fil               = T.fil,
      .col               = T.col,
      .dir               = T.dir,
      .origen            = T.id,
      .poder_destructivo = T.potencia_disparo,
      .tiempo_entre_mov  = 1.0/5 // la bala se mueve 10 cuadros por segundo
   };
   gettimeofday(&proyectil.tic, NULL);

   // nodo* agregar_a_la_lista(lista *L, tipo_nodo dato)
   agregar_a_la_lista(&lista_balas, proyectil);
}

// mover_y_graficar_bala retorna
// true si el águila fue eliminada o si mataron al tanque amigo
// y false de lo contrario
bool mover_y_graficar_bala(nodo *ptr_a_bala)
{
   tipo_nodo *B = &(ptr_a_bala->dato);

   int COL_BALA = (B->origen == -1) ? COL_BALA_AMIGA : COL_BALA_ENEMIGA;

   /// quite la bala de la posición anterior
   switch(mapa[B->fil][B->col])
   {
   case ' ': mvwaddch(tablero_juego, B->fil, B->col, CHAR_PASILLO); break;
   // dibuje el agua en caso que la bala haya pasado por agua
   default:
      wgetch(tablero_juego);    // presione una tecla para terminar
      destruir_lista(&lista_balas);
      delwin(tablero_juego);
      delwin(tablero_info);
      endwin();                 // finalice el modo NCURSES

      perror("Error borrando la bala de su posición anterior");
      exit(EXIT_FAILURE);
   }

   /// mover la bala de acuerdo a la dirección de movimiento
   switch(B->dir)
   {
   case quieto:     break; // para hacer feliz al compilador
   case derecha:    if (B->col < NCOL-1) B->col++; break;
   case arriba:     if (B->fil > 0)      B->fil--; break;
   case izquierda:  if (B->col > 0)      B->col--; break;
   case abajo:      if (B->fil < NFIL-1) B->fil++;
   }

   /// revisar si la bala impactó al tanque amigo (siempre y cuando la bala no
   /// la haya disparado el mismo tanque amigo)
   if ((tanque_amigo.fil == B->fil) && (tanque_amigo.col == B->col) && B->origen != -1)
   {
      // quitarle una vida al tanque enemigo de acuerdo con el poder
      // destructivo de la bala
      tanque_amigo.vidas -= B->poder_destructivo;
      marcador++;

      // si mató al tanque amigo
      if (tanque_amigo.vidas <= 0)
      {
         mvwaddch(tablero_juego, B->fil, B->col, 'x' | COLOR_PAIR(COL_TANQUE_AMIGO));
         wrefresh(tablero_juego);

         WINDOW *ventana;
         char mensaje[] = "Presione 'C' para continuar";
         // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
         ventana = newwin(9, strlen(mensaje)+4, 1+NFIL/2, NCOL+3);
         box(ventana, 0, 0);	 // 0, 0 pone los caracteres estándar del borde
         wattron(ventana, A_BOLD);
         mvwprintw(ventana, 2, 2, "        Has  muerto        ");
         mvwprintw(ventana, 4, 2, "***  Perdiste el juego  ***");
         wattroff(ventana, A_BOLD);
         mvwprintw(ventana, 6, 2, mensaje);
         wrefresh(ventana);
         flushinp();              // borre el buffer del teclado
         wtimeout(ventana, 1);    // wgetch() espera 1 milisegundo
         do {} while (toupper(wgetch(ventana)) != 'C'); // 'C' para continuar
         werase(ventana);         // borre los caracteres de la ventana
         wrefresh(ventana);
         delwin(ventana);
         touchwin(tablero_juego); // redibujar la ventana tablero_juego
         return true;
      }
   }

   /// revisar si hay un tanque enemigo en la posición actual de la bala
   for (int i=0; i<N_MAX_TANQUES; i++)
   {
      // un tanque no se puede matar por su propia bala al momento de dispararla
      if (B->origen == i) continue;

      tanque *T = &tanque_enemigo[i];

      // si el tanque esta muerto o si no ha aparecido en el tablero continúe
      // con el siguiente
      if ((T->vidas <= 0) || (!T->activo)) continue;

      // si la bala impactó a un tanque enemigo
      if ((T->fil == B->fil) && (T->col == B->col))
      {
         // quitarle una vida al tanque enemigo de acuerdo con el poder
         // destructivo de la bala
         T->vidas -= B->poder_destructivo;

         // si mató al tanque enemigo
         if (T->vidas <= 0)
         {
            T->activo = false;

            // borrar el tanque enemigo del tablero
            switch(mapa[B->fil][B->col])
            {
            case ' ':  // si el tanque estaba en un pasillo
               mvwaddch(tablero_juego, T->fil, T->col, CHAR_PASILLO);
               break;
            // si el tanque estaba caminando en bosque
            }

            // eliminar la bala de la lista
            borrar_nodo_de_la_lista(&lista_balas, ptr_a_bala);
            return false;
         }
      }
   }

   /// revisar si hubo colisión entre dos balas
   // FALTA IMPLEMENTAR

   /// revisar si la bala impactó un muro, o circula por bosque, pasillo o lago
   switch (mapa[B->fil][B->col])
   {
      /// si la bala se mueve por un pasillo o por el agua
      case ' ':
      //case 'A': símbolo de agua
         if ((B->dir == izquierda) ||  (B->dir == derecha))
            mvwaddch(tablero_juego, B->fil, B->col, '-' | COLOR_PAIR(COL_BALA));
         else if ((B->dir == arriba) ||  (B->dir == abajo))
            mvwaddch(tablero_juego, B->fil, B->col, '|' | COLOR_PAIR(COL_BALA));
         else
            mvwaddch(tablero_juego, B->fil, B->col, 'x' | COLOR_PAIR(COL_BALA));
         break;

      /// si la bala impactó un muro
      case '#':
         // quite el muro y reemplácelo por un pasillo
         mapa[B->fil][B->col] = ' ';
         mvwaddch(tablero_juego, B->fil, B->col, CHAR_PASILLO);

      /// si la bala impactó un muro de acero (o si impactó un muro) o si
      /// impactó el borde del tablero
      case '*':
      case '|':
      case '-':
         // eliminar la bala de la lista
         borrar_nodo_de_la_lista(&lista_balas, ptr_a_bala);
         break;

      /// si le pegó al águila
      case '@':
      {
         mvwaddch(tablero_juego, B->fil, B->col, 'x' | COLOR_PAIR(COL_AGUILA));
         wrefresh(tablero_juego);

         WINDOW *ventana;
         char mensaje[] = "Presione 'C' para continuar";
         // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
         ventana = newwin(9, strlen(mensaje)+4, 1+NFIL/2, NCOL+3);
         box(ventana, 0, 0);	 // 0, 0 pone los caracteres estándar del borde
         wattron(ventana, A_BOLD);
         mvwprintw(ventana, 2, 2, " La base ha sido destruida ");
         mvwprintw(ventana, 4, 2, "***  Perdiste el juego  ***");
         wattroff(ventana, A_BOLD);
         mvwprintw(ventana, 6, 2, mensaje);
         wrefresh(ventana);
         flushinp();              // borre el buffer del teclado
         wtimeout(ventana, 1);    // wgetch() espera 1 milisegundo
         do {} while (toupper(wgetch(ventana)) != 'C'); // 'C' para continuar
         werase(ventana);         // borre los caracteres de la ventana
         wrefresh(ventana);
         delwin(ventana);
         touchwin(tablero_juego); // redibujar la ventana tablero_juego
         return true;
      }

      /// si la bala se mueve por el bosque
      case 'B':
         // en este caso no hay que hacer nada, la bala ya se movió
         break;
      default:
         destruir_lista(&lista_balas);
         delwin(tablero_juego);
         delwin(tablero_info);
         endwin();                 // finalice el modo NCURSES

         perror("Error moviendo balas");
         exit(EXIT_FAILURE);
   }
   return false;
}

bool hay_tanque_enemigo_en(int fil, int col)
{
   for (int i=0; i<N_MAX_TANQUES; i++)
   {
      if (tanque_enemigo[i].vidas <= 0) continue;
      if (!tanque_enemigo[i].activo)    continue;
      if ((tanque_enemigo[i].fil == fil) && (tanque_enemigo[i].col == col))
         return true;
   }
   return false;
}


void aparecen_los_tanques_al_azar(void)
{
   if((double)rand()/RAND_MAX < 0.01)
   {
      tanque_enemigo[idx_tanque].activo = true;
      if (idx_tanque <= N_MAX_TANQUES-1) idx_tanque++;
   }
}
