/*
 * B O M B E R M A N
 *
 * Por:
 * Diego Andres Alvarez Marin (daalvarez@unal.edu.co)
 *
 * Ver el bomberman original en:
 * http://www.nintendo8.com/game/1/bomberman/
 * https://www.youtube.com/watch?v=3smytj9Bu_E
 *
 * INSTRUCCIONES:
 * Flechas mueven el bomberman
 * P       pausa
 * ESPACIO pone la bomba
 * ESCAPE  se sale del juego
 * ENTER   pone la bomba
 *
 ************************************************************
 *                 NOTA: COMPILE CON -std=c99
 ************************************************************
 *
 * COMPILE CON:
 * WINDOWS : gcc -Wall -o bomberman.exe main.c -lpdcurses -std=c99
 * LINUX   : gcc -Wall -o bomberman main.c -lncurses -std=c99
 */

#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

/// Se definen las constantes
#define KEY_ESCAPE           27    // codigo ASCII de la tecla ESCAPE
#define NFIL                 13    // filas mapa
#define NCOL                 43    // columnas mapa
#define N_MAX_GLOBOS         50    // numero maximo de globos en el tablero
#define N_MAX_BOMBAS         20    // numero maximo de bombas a arrojar

// colores
#define COL_PIEDRA            1    // muro indestructible
#define COL_LADRILLO          2    // muro que se puede destruir
#define COL_PASILLO           3
#define COL_BOMBERMAN         4
#define COL_GLOBO             5
#define COL_BOMBA             6
#define COL_PODER             7

const chtype DESTELLO       = ' ' | COLOR_PAIR(COL_BOMBA)     | A_BOLD | A_REVERSE;
const chtype CHAR_GLOBO     = 'G' | COLOR_PAIR(COL_GLOBO)     | A_BOLD;
const chtype CHAR_BOMBA     = '*' | COLOR_PAIR(COL_BOMBA)     | A_BOLD;
const chtype CHAR_BOMBERMAN = 'B' | COLOR_PAIR(COL_BOMBERMAN) | A_BOLD;
const chtype CHAR_PASILLO   = ' ' | COLOR_PAIR(COL_PASILLO)   | A_BOLD;

/// Se definen las enumeraciones
typedef enum {quieto, derecha, arriba, izquierda, abajo} direccion;

/// Se definen las estructuras
typedef struct
{
    int fil,col;              // posición actual (fila, columna)
    direccion dir;            // dirección hacia la que avanza
    bool vivo;                // vivo = true/muerto = false
    bool agonizando;          // si el globo esta agonizando
    int caminados_misma_dir;  // cuadros caminados en la misma direccion
    struct timeval tic, toc;  // para el cronometro
    double tiempo_entre_mov;  // tiempo entre movimientos
} globo;

typedef struct
{
    int fil,col;              // posición actual (fila, columna)
    bool activada;            // bomba puesta en el tablero (true/false)
    bool detonando;           // si la bomba esta en explosion
    int poder_explosivo;      // se cuenta en cuadros a la redonda
    int tamano_actual_onda;   // tamaño actual de la onda explosiva (en cuadros)
    struct timeval tic, toc;  // para el cronometro
    double tiempo_mecha;      // tiempo que demora en consumirse la mecha de la bomba
    double velocidad_onda;    // velocidad de la onda explosiva (cuadros/segundo)
    bool onda_viaja_hacia[5]; // direccion posible de la onda explosiva
    bool en_bodega;           // bomba en bodega = true/ en tablero = false
} bomba;

/// Se definen las variables globales
int marcador = 0;             // el marcador de juego
int n_globos;                 // numero actual de globos
globo glob[N_MAX_GLOBOS];     // vector de globos
int n_bombas = 1;             // numero actual de bombas
bomba bomb[N_MAX_BOMBAS];     // vector de bombas
WINDOW *tablero_juego;
WINDOW *tablero_info;

struct                        // el bomberman
{
    int fil,col;              // posición actual (fila, columna)
    direccion dir;            // dirección hacia la que avanza
    struct timeval tic, toc;  // para el cronometro
    double tiempo_entre_mov;  // tiempo entre movimientos
    int vidas;                // numero de vidas
} bomberman =
{
    .fil          = 1,
    .col          = 1,
    .dir          = quieto,
    .tiempo_entre_mov = 1.0/10, // velocidad = 10 cuadros por segundo
    .vidas        = 3,
};

char mapa[NFIL][NCOL] =       // el tablero de juego
{
    "A-----------------------------------------B",
    "|  %     %    %          %    %    %      |",
    "| X X X X X X X X X X X X X X X X X X X X |",
    "| %       %  %  %       %    %       % %  |",
    "|%X X X X X X X X X X%X X X X X X%X X X X |",
    "|  %         %   %       %  %    %  %     |",
    "| X X X X X X X X X X X X X X X X X X X X%|",
    "|    %    %    %    %%%    %              |",
    "| X X X X X X X X X X X X X X X X X X X X |",
    "|   %     %%%      %     %           %    |",
    "| X X X X X X X X X X X X X X X X X X X X |",
    "|   %%%    %    %     %     %   %        %|",
    "D-----------------------------------------C"
};

/// Prototipos de funciones
void inicializaciones(void);
void inicializar_globo(int i, int fil, int col, direccion dir);
void pintar_laberinto(void);
void mover_globo(globo *F);
void mover_bomberman(direccion dir);
bool puede_moverse_globo(int fil, int col, direccion dir);
bool puede_moverse_bomberman(int fil, int col, direccion dir);
double intervalo_tiempo_seg(struct timeval toc, struct timeval tic);
int muestrea_de_PMF(const int n, const double w[n]);
void actualizar_tablero_de_informacion(void);
void poner_onda_explosiva(bomba *B);
void quitar_onda_explosiva(bomba *B);

/// Procedimiento principal
int main(void)
{
    int ch;                     // contiene la letra leida desde el teclado
    double tiempo;              // utilizada por el cronometro

    initscr();                  // empiece el modo NCURSES

    inicializaciones();         // inicializaciones de ncurses y de la semilla
    pintar_laberinto();         // pintar el laberinto

    /// Inicializar los globos (al azar)
    n_globos = 10;              // numero actual de globos
    for (int i=0; i<n_globos; i++)
    {
       int fil, col, dir;
       // seleccione al azar fil y col hasta que encuentre una casilla vacia
       do {
         fil = (double)rand()*NFIL/RAND_MAX;
         col = (double)rand()*NCOL/RAND_MAX;
       } while (mapa[fil][col] != ' ');
      dir = (double)rand()*4/RAND_MAX + 1;
      inicializar_globo(i, fil, col, dir);
    }

    /// Inicializar las bombas
    // numero de bombas disponibles en bodega (es decir, numero de bombas que se
    // pueden colocar al mismo tiempo en el tablero)
    n_bombas = 3;
    for (int i=0; i<n_bombas; i++)
        bomb[i].en_bodega = true; // la bomba esta en la bodega, no en el tablero

    /// Inicializar el cronómetro del bomberman
    gettimeofday(&bomberman.tic, NULL);

    /// Inicializar los cronómetros de los globos
    for (int i=0; i<n_globos; i++) gettimeofday(&(glob[i].tic), NULL);

    bool salirse = false;             // ¿salirse del juego?
    direccion proxima_dir = quieto;   // quédese quieto al principio del juego

    while ((bomberman.vidas > 0) && (!salirse))
    {
        /// pintar el bomberman porque eventualmente un fantasma lo puede borrar
        mvwaddch(tablero_juego, bomberman.fil, bomberman.col, CHAR_BOMBERMAN);

        /// actualizar el tablero de informacion
        actualizar_tablero_de_informacion();

        /// mover el bomberman
        gettimeofday(&bomberman.toc, NULL);
        tiempo = intervalo_tiempo_seg(bomberman.toc, bomberman.tic);

        if (tiempo > bomberman.tiempo_entre_mov)
        {
            // si el bomberman ya puede avanzar al siguiente cuadrito
            // entonces intente moverse a la proxima direccion
            mover_bomberman(proxima_dir);

            // y despues quedese quieto
            proxima_dir = quieto;

            // finalmente active de nuevo el cronometro preparandose para el
            // siguiente movimiento
            gettimeofday(&bomberman.tic, NULL);
        }

        /// mover los globos
        for (int i=0; i<n_globos; i++)
        {
            // si el globo esta muerto continue con el siguiente
            if (!glob[i].vivo) continue;

            gettimeofday(&(glob[i].toc), NULL);
            tiempo = intervalo_tiempo_seg(glob[i].toc, glob[i].tic);
            if (tiempo > glob[i].tiempo_entre_mov)
            {
                mover_globo(&glob[i]);

                // si el globo no esta agonizando que el cronometro siga marchando
                if (!glob[i].agonizando)
                    gettimeofday(&(glob[i].tic), NULL);
            }
        }

        /// activar y detonar las bombas
        for (int i=0; i<n_bombas; i++)
        {
            // si la bomba no se ha colocado en el tablero, siga con la,
            // ya que esta almacenada en la bodega
            if (bomb[i].en_bodega) continue;

            if (bomb[i].activada)
            {
                mvwaddch(tablero_juego, bomb[i].fil, bomb[i].col, CHAR_BOMBA);

                // calcular el tiempo que se demora en consumirse la mecha
                gettimeofday(&(bomb[i].toc), NULL);
                tiempo = intervalo_tiempo_seg(bomb[i].toc, bomb[i].tic);

                // si se ha llegado al tiempo que dura la mecha, detonar la bomba
                if (tiempo > bomb[i].tiempo_mecha)
                {
                    // empieza el proceso de detonación
                    bomb[i].activada  = false;
                    bomb[i].detonando = true;
                    bomb[i].tamano_actual_onda = 1;
                    poner_onda_explosiva(&bomb[i]);

                    // ahora tic se inicializa para contar el tiempo que dura
                    // la explosion
                    gettimeofday(&(bomb[i].tic), NULL);
                }
                continue;
            }

            // poner la onda explosiva de las bombas detonadas
            if (bomb[i].detonando)
            {
                // calcular el tiempo que se demora en recorrer la onda explosiva
                gettimeofday(&(bomb[i].toc), NULL);
                tiempo = intervalo_tiempo_seg(bomb[i].toc, bomb[i].tic);

                // si se ha llegado al tiempo demora la onda en recorrer un
                // cuadrito, poner mas onda explosiva
                // (tiempo = espacio/velocidad)
                if (tiempo > 1.0/bomb[i].velocidad_onda)
                {
                    // incrementar el tamaño de la onda explosiva y dibujarla
                    bomb[i].tamano_actual_onda++;
                    poner_onda_explosiva(&bomb[i]);
                    gettimeofday(&(bomb[i].tic), NULL);

                    // ya terminó la explosion
                    if (bomb[i].tamano_actual_onda == bomb[i].poder_explosivo)
                        bomb[i].detonando = false;
                }
                continue;
            }

            // quitar la onda explosiva de las bombas detonadas
            if (bomb[i].tamano_actual_onda > 0)
            {
                // calcular el tiempo que se demora en recorrer la onda explosiva
                gettimeofday(&(bomb[i].toc), NULL);
                tiempo = intervalo_tiempo_seg(bomb[i].toc, bomb[i].tic);

                // si se ha llegado al tiempo demora la onda en recorrer un
                // cuadrito, quitar un recuadro de la onda explosiva
                // (tiempo = espacio/velocidad)
                if (tiempo > 1.0/bomb[i].velocidad_onda)
                {
                    quitar_onda_explosiva(&bomb[i]);
                    bomb[i].tamano_actual_onda--;
                    gettimeofday(&(bomb[i].tic), NULL);
                }

                // se retorna esta bomba a la bodega, ya que sale del tablero
                if (bomb[i].tamano_actual_onda == 0)
                    bomb[i].en_bodega = true;
            }
        } // end for

        // vaciamos el buffer del teclado, para que lea solo lo último
        // especificado: esto se hace porque si se presione siempre las flechas
        // no se reaccionaría inmediatamente a la última flecha
        flushinp();

        /// leer el teclado
        ch = wgetch(tablero_juego);
        switch(ch)
        {
        case KEY_RIGHT:                 // flecha derecha
            proxima_dir = derecha;
            break;
        case KEY_UP:                    // flecha arriba
            proxima_dir = arriba;
            break;
        case KEY_LEFT:                  // flecha izquierda
            proxima_dir = izquierda;
            break;
        case KEY_DOWN:                  // flecha abajo
            proxima_dir = abajo;
            break;
        case ' ':                       // poner la bomba
            for (int i=0; i<n_bombas; i++)
            {
                // si la bomba ya está puesta en el tablero busque otra bomba de
                // la bodega
                if (!bomb[i].en_bodega) continue;

                bomb[i] = (bomba) {
                    .fil = bomberman.fil,
                    .col = bomberman.col,
                    .activada  = true,
                    .detonando = false,
                    .poder_explosivo = 3,    // cuadros
                    .tamano_actual_onda = 0, // cuadros
                    .tiempo_mecha = 1.0,     // segundos
                    .velocidad_onda = 25,    // cuadros por segundo
                    .en_bodega = false       // la bomba sale hacia el tablero
                };
                gettimeofday(&(bomb[i].tic), NULL);
                break; // sale del for
            }
            break; // sale del switch
        case 'p':                       // pausa
        case 'P':
        {
            WINDOW *ventana;
            char mensaje[] = "Presione 'P' para continuar";
            // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
            ventana = newwin(7, strlen(mensaje)+4, 1+NFIL/2, (NCOL-strlen(mensaje)-4)/2);
            box(ventana, 0, 0);	 // 0, 0 pone los caracteres estandar del borde
            wattron(ventana, A_BOLD);
            mvwprintw(ventana, 2, 2, "   *** Juego Pausado ***   ");
            wattroff(ventana, A_BOLD);
            mvwprintw(ventana, 4, 2, mensaje);
            wrefresh(ventana);
            flushinp();              // borre el buffer del teclado
            do {} while (toupper(wgetch(ventana)) != 'P');  // lea el espacio para continuar
            flushinp();

            delwin(ventana);    // borre la ventana (no borra los caracteres)

            // Aquí el NCURSES parece tener un bug, ya que a veces no se borra
            // la ventana antes de continuar
            touchwin(tablero_juego); // redibujar la ventana tablero_juego
            break;
        }
        case KEY_ESCAPE:           // salirse del juego
            salirse = true;
            break;
        } // end switch

        wrefresh(tablero_juego);       // imprimir en pantalla
    } // end while

    /// Se cierran las ventanas
    delwin(tablero_juego);
    delwin(tablero_info);

    endwin();    // finalice el modo NCURSES
    return EXIT_SUCCESS;
}


void inicializaciones(void)
{
    // el monitor soporta colores?
    if (has_colors() == false)
    {
        endwin();
        puts("Su monitor no soporta colores");
        exit(EXIT_FAILURE);
    }

    resize_term(20,70);  // poner ventana de 20 filas, 70 columnas

    /// Se inicializan las ventanas del juego
    // newwin(nfilas, ncols, sup_izq_fil, sup_izq_col);
    tablero_juego = newwin(NFIL, NCOL,4,0);
    tablero_info  = newwin(4,    NCOL,0,0);

    box(tablero_info, 0, 0);  // 0, 0 pone los caracteres estandar del borde
    // box(tablero_juego,    0, 0);

    curs_set(0);         // no se muestra el cursor
    cbreak();            // no line buffering: lee letra a letra, no espera \n
    keypad(tablero_juego, true); // acepte flechas y otras teclas especiales
    wtimeout(tablero_juego, 1);  // getch() espera 1 miliseg. si no hay tecla presionada
    noecho();            // no haga echo() con getch()
    srand(time(NULL));   // inicializar el generador de números aleatorios
    start_color();       // activar modo colores

    // definir colores            letra          fondo
    init_pair(COL_PIEDRA,         COLOR_YELLOW,  COLOR_BLUE);
    init_pair(COL_LADRILLO,       COLOR_RED,     COLOR_BLUE);
    init_pair(COL_PASILLO,        COLOR_BLUE,    COLOR_BLUE);
    init_pair(COL_BOMBERMAN,      COLOR_GREEN,   COLOR_BLUE);
    init_pair(COL_GLOBO,          COLOR_CYAN,    COLOR_BLUE);
    init_pair(COL_BOMBA,          COLOR_WHITE,   COLOR_BLUE);
    init_pair(COL_PODER,          COLOR_WHITE,   COLOR_RED);
}


// funcion que pinta el laberinto
void pintar_laberinto(void)
{
    int letra, color;

    for (int f = 0; f < NFIL; f++)
        for (int c = 0; c < NCOL; c++)
        {
            switch(mapa[f][c])
            {
            case '|':
                color = COL_PIEDRA;
                letra = ACS_VLINE | A_BOLD;
                break;
            case '-':
                color = COL_PIEDRA;
                letra = ACS_HLINE | A_BOLD;
                break;
            case 'A':
                color = COL_PIEDRA;
                letra = ACS_ULCORNER | A_BOLD;
                break;
            case 'B':
                color = COL_PIEDRA;
                letra = ACS_URCORNER | A_BOLD;
                break;
            case 'C':
                color = COL_PIEDRA;
                letra = ACS_LRCORNER | A_BOLD;
                break;
            case 'D':
                color = COL_PIEDRA;
                letra = ACS_LLCORNER | A_BOLD;
                break;
            case 'X':
                color = COL_PIEDRA;
                letra = 'X' | A_BOLD;
//                  letra = ' ' | A_REVERSE;
                break;
            case ' ':
                color = COL_PASILLO;
                letra = ' ';
                break;
            case '%':
                color = COL_LADRILLO;
                letra = '%' | A_BOLD;
                break;
            default:
                wgetch(tablero_juego);     // presione una tecla para terminar
                delwin(tablero_juego);
                delwin(tablero_info);
                endwin();    // finalice el modo NCURSES

                perror("Error en la especificación del laberinto");
                exit(EXIT_FAILURE);
            }
            // imprima el caracter + color
            mvwaddch(tablero_juego, f, c, letra | COLOR_PAIR(color));
        }
    wrefresh(tablero_juego);    // imprimir en la pantalla física
}


void mover_globo(globo *G)
{
    // si el globo esta agonizando, este no se mueve y cambia de color
    if (G->agonizando)
    {
        gettimeofday(&G->toc, NULL);

        // despues de 2 segundos de agonizar el globo muere
        if (intervalo_tiempo_seg(G->toc, G->tic) > 2.0)
        {
            G->vivo = false;

            // se borra el globo de la posición actual
            mvwaddch(tablero_juego, G->fil, G->col, CHAR_PASILLO);
        }
        else
            mvwaddch(tablero_juego, G->fil, G->col, CHAR_GLOBO | A_REVERSE);

        return;
    }

    int num_pos_puede_moverse = 0;

    // este vector almacena la funcion de masa de probabilidades (no
    // normalizadas) de avanzar en la direccion indicada
    // Ver: http://es.wikipedia.org/wiki/Función_de_probabilidad
    double fmp_dir[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

    // determinar las direcciones en las que el globo se puede mover
    for (direccion dir = derecha; dir<= abajo; dir++) // derecha = 1, abajo = 4
    {
        if (puede_moverse_globo(G->fil, G->col, dir))
        {
            num_pos_puede_moverse++;
            fmp_dir[dir] =  1.0;
        }
    }

    // se selecciona la direccion aleatoria
    direccion nueva_dir = quieto;
    if (num_pos_puede_moverse != 0)
    {
        direccion dir_contraria = quieto;
        if      (G->dir == derecha)   dir_contraria = izquierda;
        else if (G->dir == izquierda) dir_contraria = derecha;
        else if (G->dir == arriba)    dir_contraria = abajo;
        else if (G->dir == abajo)     dir_contraria = arriba;

        // se incrementan en 8 veces las probabilidades de moverse
        // hacia adelante o hacia atras (esta ultima en caso en caso que se
        // hayan avanzado mas de 10 casillas en la misma direccion
        if (fmp_dir[G->dir]) fmp_dir[G->dir] *= 8;
        if (puede_moverse_globo(G->fil, G->col, dir_contraria) &&
            (G->caminados_misma_dir > 10))
            fmp_dir[dir_contraria] *= 8;

        nueva_dir = muestrea_de_PMF(5, fmp_dir);

        if (nueva_dir == G->dir)
            G->caminados_misma_dir++;
        else
            G->caminados_misma_dir = 0;
    }

    G->dir = nueva_dir;    // actualizar la direccion del bomberman

    int fil = G->fil;
    int col = G->col;

    // incrementar las posiciones
    switch(G->dir)
    {
        case quieto:     break; // para hacer feliz al gcc
        case derecha:    if (col<NCOL-1) col++;  break;
        case arriba:     if (fil>0)      fil--;  break;
        case izquierda:  if (col>0)      col--;  break;
        case abajo:      if (fil<NFIL-1) fil++;  break;
    }

    // se borra el globo de la posición actual
    mvwaddch(tablero_juego, G->fil, G->col, CHAR_PASILLO);

    // se avanza el globo una posición
    G->col = col;
    G->fil = fil;

    // se pone el globo en la nueva posición
    mvwaddch(tablero_juego, G->fil, G->col, CHAR_GLOBO);
}


void mover_bomberman(direccion dir)
{
    int fil, col;

    // guardar las posiciones anteriores
    int fil_ant = fil = bomberman.fil;
    int col_ant = col = bomberman.col;

    // si no se puede mover a proxima_dir, entonces salgase de esta funcion
    if (!puede_moverse_bomberman(fil, col, dir)) return;

    // incrementar las posiciones
    switch(dir)
    {
        case quieto:    return;
        case derecha:   if (col<NCOL-1) col++;  break;
        case arriba:    if (fil>0)      fil--;  break;
        case izquierda: if (col>0)      col--;  break;
        case abajo:     if (fil<NFIL-1) fil++;  break;
    }

    // si la nueva posicion del bomberman es un espacio en blanco, se mueve
    if (mapa[fil][col] == ' ')
    {
        bomberman.col = col;
        bomberman.fil = fil;
        bomberman.dir = dir;

        // se borra el bomberman de la posicion anterior
        mvwaddch(tablero_juego, fil_ant, col_ant, CHAR_PASILLO);
    }

    // se escribe el bomberman en la nueva posición
    mvwaddch(tablero_juego, bomberman.fil, bomberman.col, CHAR_BOMBERMAN);
}


bool puede_moverse_bomberman(int fil, int col, direccion dir)
{
    // incrementar las posiciones
    switch(dir)
    {
        case quieto:     return false;
        case derecha:    if (col<NCOL-1) col++;  break;
        case arriba:     if (fil>0)      fil--;  break;
        case izquierda:  if (col>0)      col--;  break;
        case abajo:      if (fil<NFIL-1) fil++;  break;
    }

    // la bomba no permite avanzar
    if (mvwinch(tablero_juego, fil, col) == CHAR_BOMBA) return false;

    // pero si avanza en caso que haya un pasillo
    if (mapa[fil][col] == ' ')          return true;

    // en cualquier otro caso no avance
    return false;
}


bool puede_moverse_globo(int fil, int col, direccion dir)
{
    // incrementar las posiciones
    switch(dir)
    {
        case quieto:     break; // para hacer feliz al gcc
        case derecha:    if (col<NCOL-1) col++;  break;
        case arriba:     if (fil>0)      fil--;  break;
        case izquierda:  if (col>0)      col--;  break;
        case abajo:      if (fil<NFIL-1) fil++;  break;
    }

    // el globo no es suicida y por lo tanto no se va a tirar al fuego de la
    // bomba
    if (mvwinch(tablero_juego, fil, col) == DESTELLO)   return false;

    // la bomba no permite avanzar tampoco
    if (mvwinch(tablero_juego, fil, col) == CHAR_BOMBA) return false;

    // pero si avance en caso que haya un pasillo
    if (mapa[fil][col] == ' ')         return true;

    // en cualquier otro caso no avance
    return false;
}


inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic)
{
    return (toc.tv_sec - tic.tv_sec) + (toc.tv_usec - tic.tv_usec)/1000000.0;
}


void inicializar_globo(int i, int fil, int col, direccion dir)
{
    assert(i<n_globos);           // si i>=n_globos hay un error en la asignación

    glob[i] = (globo) {
        .fil = fil,                // posición actual (fila, columna)
        .col = col,
        .dir = dir,                // dirección hacia la que avanza
        .vivo       = true,        // vivo = true/muerto = false
        .agonizando = false,       // si al globo lo acaba de matar una bomba
        .caminados_misma_dir = 0,  // casillas caminadas en la misma direccion
        // .tic = ***,             // para el cronometro
        // .toc = ***,             // tiempo entre movimientos
        .tiempo_entre_mov = 1.0/6  // muevase 8 cuadros por segundo
    };
}

// Muestrea un punto entre 0:n-1 con funcion de masa de probabilidades w
// y retorna el indice de la muestra en w
int muestrea_de_PMF(const int n, const double w[n])   // PMF
{
    // muestrea un numero aleatorio en el intervalo [0,1)
    double random = ((double)rand())/RAND_MAX;

    // suma de pesos
    double sum_w = 0.0;
    for (int i = 0; i < n; i++)  sum_w += w[i];

    // se calcula la funcion de distribución de probabilidades acumulada
    double cumsum_w = 0.0;
    for (int i = 0; i < n; i++)
    {
        cumsum_w += w[i]/sum_w;           // empirical CDF
        if (random <= cumsum_w) return i;
    }

    // Aquí nunca llegaremos (a menos que haya un error en el algoritmo)
    // endwin();
    // fprintf(stderr, "sum_w = %f\n", sum_w);
    // fprintf(stderr, "Error en muestrea_de_PMF().\n");
    // exit(EXIT_FAILURE);
    return 0;
}


void actualizar_tablero_de_informacion(void)
{
    mvwprintw(tablero_info, 1, 2, "Vidas    = %3d", bomberman.vidas);
    mvwprintw(tablero_info, 2, 2, "Marcador = %3d", marcador);
    wrefresh(tablero_info);    // imprimir en pantalla
}


void poner_onda_explosiva(bomba *B)
{
    // verifique que el tamaño actual de la onda sea un numero natural o sino
    // genere un error
    assert(B->tamano_actual_onda >= 1);

    if (B->tamano_actual_onda == 1)
    {
        mvwaddch(tablero_juego, B->fil, B->col, DESTELLO); // dibuje el DESTELLO en la posicion actual

        // vector que indica a que punto cardinal puede viajar la onda explosiva
        B->onda_viaja_hacia[quieto]    = false;
        B->onda_viaja_hacia[derecha]   = true;
        B->onda_viaja_hacia[arriba]    = true;
        B->onda_viaja_hacia[izquierda] = true;
        B->onda_viaja_hacia[abajo]     = true;
        return;                            // y salgase de la función
    }

    int t = B->tamano_actual_onda - 1;

    for (direccion dir=derecha; dir<=abajo; dir++) // derecho = 1, abajo = 4
    {
        int fil = B->fil, col = B->col;
        // calcule la posicion donde se debe colocar el destello; si me
        // salgo del tablero no siga dibujando la onda explosiva
        switch(dir)
        {
        case quieto:    break; // para hacer feliz al gcc
        case derecha:   if (col+t<NCOL-1) col+=t; else B->onda_viaja_hacia[dir] = false; break;
        case arriba:    if (fil-t>0)      fil-=t; else B->onda_viaja_hacia[dir] = false; break;
        case izquierda: if (col-t>0)      col-=t; else B->onda_viaja_hacia[dir] = false; break;
        case abajo:     if (fil+t<NFIL-1) fil+=t; else B->onda_viaja_hacia[dir] = false; break;
        }

        // si hay un muro duro no siga dibujando la onda explosiva
        if (mapa[fil][col] == 'X') B->onda_viaja_hacia[dir] = false;

        // si la onda explosiva puede viajar en la direccion dir, dibuje la
        // onda explosiva
        if (B->onda_viaja_hacia[dir])
        {
            mvwaddch(tablero_juego, fil, col, DESTELLO);

            // si la onda explosiva toco un muro suave, destruyalo, y
            // no continue la onda explosiva en la misma dirección
            if (mapa[fil][col] == '%')
            {
                mapa[fil][col] = ' ';
                B->onda_viaja_hacia[dir] = false;
            }

            // El globo que esta en la posicion del destello muere
            for (int i=0; i<n_globos; i++)
                if((fil == glob[i].fil) && (col == glob[i].col) && glob[i].vivo)
                    glob[i].agonizando = true;
        }
    } // end for
}

void quitar_onda_explosiva(bomba *B)
{
    // verifique que el tamaño actual de la onda sea un numero natural o sino
    // genere en error
    assert(B->tamano_actual_onda > 0);

    if (B->tamano_actual_onda == 1)
    {
        // dibuje el pasillo y salgase de la funcion
        mvwaddch(tablero_juego, B->fil, B->col, CHAR_PASILLO);
        return;
    }

    int t = B->tamano_actual_onda - 1;

    for (direccion dir=derecha; dir<=abajo; dir++) // derecho = 1, abajo = 4
    {
        int fil = B->fil, col = B->col;

        // calcule la posicion donde se puso posiblemente el destello;
        // teniendo en cuenta que no debo salirme del tablero
        switch(dir)
        {
            case quieto:    break; // para hacer feliz al gcc
            case derecha:
                if (col+t<NCOL-1)
                {
                    col+=t;
                    // si en (fil,col) tenemos un destello dibuje de nuevo
                    // el pasillo
                    if (mvwinch(tablero_juego, fil, col) == DESTELLO)
                        mvwaddch(tablero_juego, fil, col, CHAR_PASILLO);
                }
                break;
            case arriba:
                if (fil-t>0)
                {
                    fil-=t;
                    if (mvwinch(tablero_juego, fil, col) == DESTELLO)
                        mvwaddch(tablero_juego, fil, col, CHAR_PASILLO);
                }
                break;
            case izquierda:
                if (col-t>0)
                {
                    col-=t;
                    if (mvwinch(tablero_juego, fil, col) == DESTELLO)
                        mvwaddch(tablero_juego, fil, col, CHAR_PASILLO);
                }
                break;
            case abajo:
                if (fil+t<NFIL-1)
                {
                    fil+=t;
                    if (mvwinch(tablero_juego, fil, col) == DESTELLO)
                        mvwaddch(tablero_juego, fil, col, CHAR_PASILLO);
                }
                break;
        } // end switch
    } // end for
} // end function
