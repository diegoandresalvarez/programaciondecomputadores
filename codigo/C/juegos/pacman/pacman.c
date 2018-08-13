/*
 *
 * P A C M A N
 * Por:
 * Diego Andrés Alvarez Marín (daalvarez@unal.edu.co)
 * Ver el pacman original en: http://www.thepcmanwebsite.com/media/pacman_flash/
 *
 * INSTRUCCIONES:
 * Flechas mueven el pacman
 * ESPACIO pausa
 * ESCAPE  se sale del juego
 *
 * COMPILE CON:
 * WINDOWS : gcc -Wall -o pacman.exe pacman.c -lpdcurses
 * LINUX   : gcc -Wall -o pacman pacman.c -lncurses
 *
 */

#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// se definen las constantes
#define KEY_ESCAPE           27    // ASCII tecla ESCAPE
#define NFIL                 29    // filas mapa
#define NCOL                 43    // columnas mapa

// colores
#define COL_PARED             1
#define COL_MURO              2
#define COL_PASILLO           3
#define COL_PACMAN_NORMAL     4
#define COL_PACMAN_SAYAYIN    5

// colores de los fantasmas
#define COL_BLINKY            6
#define COL_PINKY             7
#define COL_INKY              8
#define COL_CLYDE             9

// se definen las enumeraciones
typedef enum {quieto, derecha, arriba, izquierda, abajo} direccion;

// se define la estructura fantasma
typedef struct
{
    int fil,col;              // posición actual (fila, columna)
    direccion dir;            // dirección hacia la que avanza
    int color;                // color del fantasma
    bool comido;              // se lo comio el pacman
    struct timeval tic, toc;  // para el cronometro
    double tiempo_entre_mov;  // tiempo entre movimientos
} fantasma;

// crear el pacman
struct
{
    int fil,col;              // posición actual (fila, columna)
    direccion dir;            // dirección hacia la que avanza
    int color;                // color del pacman
    bool invencible;          // se comió la pepita de la invencibilidad
    bool boca_abierta;        // tiene abierta 'C' o cerrada 'c' la boca?
    struct timeval tic, toc;  // para el cronometro
    double tiempo_entre_mov;  // tiempo entre movimientos
    int vidas;
} pacman =
{
    .fil          = 21,
    .col          = 21,
    .dir          = quieto,
    .color        = COL_PACMAN_NORMAL,
    .invencible   = false,
    .boca_abierta = false,
    .tiempo_entre_mov = 1.0/10, // muevase 10 cuadros por segundo
    .vidas        = 3
};

// crear los fantasmas
fantasma blinky = {
    .fil = 13,
    .col = 19,
    .color = COL_BLINKY,
    .dir = arriba,
    .comido = false,
    .tiempo_entre_mov = 1.0/8  // muevase 8 cuadros por segundo
};

fantasma pinky  = {
    .fil = 13,
    .col = 20,
    .color = COL_PINKY,
    .dir = arriba,
    .comido = false,
    .tiempo_entre_mov = 1.0/8  // muevase 8 cuadros por segundo
};

fantasma inky   = {
    .fil = 13,
    .col = 22,
    .color = COL_INKY,
    .dir = arriba,
    .comido = false,
    .tiempo_entre_mov = 1.0/8  // muevase 8 cuadros por segundo
};
fantasma clyde  = {
    .fil = 13,
    .col = 23,
    .color = COL_CLYDE,
    .dir = arriba,
    .comido = false,
    .tiempo_entre_mov = 1.0/8  // muevase 8 cuadros por segundo
};

char mapa[NFIL][NCOL] =     // tablero de juego
{
    "A-------------------BXA-------------------B",
    "|...................|X|...................|",
    "|.A-----B.A-------B.|X|.A-------B.A-----B.|",
    "|.|XXXXX|.|XXXXXXX|.|X|.|XXXXXXX|.|XXXXX|.|",
    "|.D-----C.D-------C.D-C.D-------C.D-----C.|",
    "|.........................................|",
    "|.A-----B.A-B.A-------------B.A-B.A-----B.|",
    "|.D-----C.|X|.D----BXXXA----C.|X|.D-----C.|",
    "|.........|X|......|XXX|......|X|.........|",
    "D-------B.|XD----B.|XXX|.A----CX|.A-------C",
    "XXXXXXXX|.|XA----C.D---C.D----BX|.|XXXXXXXX",
    "XXXXXXXX|.|X|.................|X|.|XXXXXXXX",
    "A-------C.D-C.A----MMMMM----B.D-C.D-------B",
    "|.............|             |.............|",
    "D-------B.A-B.D-------------C.A-B.A-------C",
    "XXXXXXXX|.|X|.................|X|.|XXXXXXXX",
    "XXXXXXXX|.|X|.A-------------B.|X|.|XXXXXXXX",
    "A-------C.D-C.D----BXXXA----C.D-C.D-------B",
    "|..................|XXX|..................|",
    "|.A-----B.A------B.|XXX|.A------B.A-----B.|",
    "|.D---BX|.D------C.D---C.D------C.|XA---C.|",
    "|.....|X|.........................|X|.....|",
    "D---B.|X|.A-B.A-------------B.A-B.|X|.A---C",
    "A---C.D-C.|X|.D----BXXXA----C.|X|.D-C.D---B",
    "|.........|X|......|XXX|......|X|.........|",
    "|.A-------CXD----B.|XXX|.A----CXD-------B.|",
    "|.D--------------C.D---C.D--------------C.|",
    "|.........................................|",
    "D-----------------------------------------C"
};

// prototipos de funciones
void inicializaciones(void);
void pintar_laberinto(void);
void mover_fantasma(fantasma *F);
void mover_pacman(direccion dir);
bool puede_moverse_pacman(int fil, int col, direccion dir);
bool puede_moverse_fantasma(int fil, int col, direccion dir);
inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic);

// procedimiento principal
int main(void)
{
    int i, ch;
    double tiempo;

    // array de punteros a fantasma
    fantasma *fant[4] = { &blinky, &pinky, &inky, &clyde };

    initscr();                  // empiece el modo NCURSES
    inicializaciones();         // inicializaciones de ncurses y de la semilla
    pintar_laberinto();         // pintar el laberinto

    bool salirse = false;             // ¿salirse del juego?
    direccion proxima_dir = quieto;   // quédese quieto al principio del juego

    // Inicializar el cronómetro del pacman y de los fantasmas
    gettimeofday(&pacman.tic, NULL);
    for (i=0; i<4; i++) gettimeofday(&(fant[i]->tic), NULL);

    while ((pacman.vidas > 0) && (!salirse))
    {
        // mover el pacman
        gettimeofday(&pacman.toc, NULL);
        tiempo = intervalo_tiempo_seg(pacman.toc, pacman.tic);
        if (tiempo > pacman.tiempo_entre_mov)
        {
            // si se puede mover en la proxima dirección hágalo, de lo contrario
            // siga la inercia
            if(puede_moverse_pacman(pacman.fil, pacman.col, proxima_dir))
                mover_pacman(proxima_dir);
            else
                mover_pacman(pacman.dir);

            gettimeofday(&pacman.tic, NULL);
        }

        // mover los fantasmas
        for (i=0; i<4; i++)
        {
            gettimeofday(&(fant[i]->toc), NULL);
            tiempo = intervalo_tiempo_seg(fant[i]->toc, fant[i]->tic);
            if (tiempo > fant[i]->tiempo_entre_mov)
            {
                mover_fantasma(fant[i]);
                gettimeofday(&(fant[i]->tic), NULL);
            }
        }

        // vaciamos el buffer del teclado, para que lea solo lo último
        // especificado: esto se hace porque si se presione siempre las flechas
        // no se reaccionaría inmediatamente a la última flecha
        flushinp();

        // pausa por el número de milisegundos especificados
        // delay_output(1); -> lo reemplacé con un timeout(1);

        // leer el teclado
        ch = getch();
        switch(ch)
        {
        case KEY_RIGHT:
            proxima_dir = derecha;
            break; // flecha derecha
        case KEY_UP:
            proxima_dir = arriba;
            break; // flecha arriba
        case KEY_LEFT:
            proxima_dir = izquierda;
            break; // flecha izquierda
        case KEY_DOWN:
            proxima_dir = abajo;
            break; // flecha abajo
        case ' ':              // pausa
            mvprintw(3, 50, "Juego pausado");
            nodelay(stdscr, FALSE);// getch() espera si no hay tecla presionada
            getch();
            nodelay(stdscr, TRUE); // getch() no espera si no hay tecla presionada
            mvprintw(3, 50, "             ");
            break;
        case KEY_ESCAPE:           // salirse del juego
            salirse = true;
            break;
        }
    }
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

    curs_set(0);         // no se muestra el cursor
    cbreak();            // no line buffering: lee letra a letra, no espera \n
    keypad(stdscr, TRUE);// acepte flechas y otras teclas especiales
    timeout(1);          // getch() espera 1 miliseg. si no hay tecla presionada
    noecho();            // no haga echo() con getch()
    srand(time(NULL));   // inicializar el generador de números aleatorios
    start_color();       // activar modo colores

    // definir colores            letra         fondo
    init_pair(COL_PARED,          COLOR_YELLOW,  COLOR_BLUE);
    init_pair(COL_MURO,           COLOR_BLUE,    COLOR_BLUE);
    init_pair(COL_PASILLO,        COLOR_WHITE,   COLOR_BLACK);
    init_pair(COL_PACMAN_NORMAL,  COLOR_YELLOW,  COLOR_BLACK);
    init_pair(COL_PACMAN_SAYAYIN, COLOR_RED,     COLOR_BLACK);
    init_pair(COL_BLINKY,         COLOR_RED,     COLOR_BLACK);
    init_pair(COL_PINKY,          COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COL_INKY,           COLOR_CYAN,    COLOR_BLACK);
    init_pair(COL_CLYDE,          COLOR_GREEN,   COLOR_BLACK);
}

// funcion que pinta el laberinto
void pintar_laberinto(void)
{
    int f, c, letra, color;

    for (f = 0; f < NFIL; f++)
        for (c = 0; c < NCOL; c++)
        {
            switch(mapa[f][c])
            {
            case '|':
                color = COL_PARED;
                letra = ACS_VLINE | A_BOLD;
                break;
            case '-':
                color = COL_PARED;
                letra = ACS_HLINE | A_BOLD;
                break;
            case 'M':               // muro que solo pueden atravesar fantasmas
                color = COL_PARED | A_BOLD;
                letra = '=';
                break;
            case 'A':
                color = COL_PARED;
                letra = ACS_ULCORNER | A_BOLD;
                break;
            case 'B':
                color = COL_PARED;
                letra = ACS_URCORNER | A_BOLD;
                break;
            case 'C':
                color = COL_PARED;
                letra = ACS_LRCORNER | A_BOLD;
                break;
            case 'D':
                color = COL_PARED;
                letra = ACS_LLCORNER | A_BOLD;
                break;
            case ' ':
                color = COL_PASILLO;
                letra = ' ';
                break;
            case 'X':
                color = COL_MURO;
                letra = ' ' | A_BOLD;
                break;
            case '.':
                color = COL_PASILLO;
                letra = '.';
                break;
            default:
                getch();     // presione una tecla para terminar
                endwin();    // finalice el modo NCURSES

                perror("Error en la especificación del laberinto");
                exit(EXIT_FAILURE);
            }
            // imprima el caracter + color
            mvaddch(f, c, letra | COLOR_PAIR(color));
        }
    refresh();               // imprimir en la pantalla física
}

void mover_fantasma(fantasma *F)
{
    // numero de direcciones en las que el fantasma se puede mover
    int num_dir_pos_mov = puede_moverse_fantasma(F->fil, F->col, derecha)   +
                          puede_moverse_fantasma(F->fil, F->col, arriba)    +
                          puede_moverse_fantasma(F->fil, F->col, izquierda) +
                          puede_moverse_fantasma(F->fil, F->col, abajo);

    if (num_dir_pos_mov == 1) // solo hay una posible dirección de movimiento
    {
        // se busca y se avanza a dicha posición
        int i;
        for (i=1; i<=4; i++)
            if (puede_moverse_fantasma(F->fil, F->col, i))
            {
                //    2
                F->dir = (direccion)i; //  3   1
                break;                 //    4
            }
    }
    else // si se puede mover en varias direcciones
    {
        direccion dir_contraria = quieto;
        direccion *pos_dir = NULL; // posibles direcciones de movimiento
        switch(F->dir)
        {
        case quieto:
            break; // para hacer feliz al compilador gcc (o si no warning!)
        case derecha:
            dir_contraria = izquierda;
            pos_dir = (direccion [])
            {
                abajo, derecha, arriba
            };
            break;
        case arriba:
            dir_contraria = abajo;
            pos_dir = (direccion [])
            {
                derecha, arriba, izquierda
            };
            break;
        case izquierda:
            dir_contraria = derecha;
            pos_dir = (direccion [])
            {
                arriba, izquierda, abajo
            };
            break;
        case abajo:
            dir_contraria = arriba;
            pos_dir = (direccion [])
            {
                izquierda, abajo, derecha
            };
            break;
        }

        if (puede_moverse_fantasma(F->fil, F->col, dir_contraria))
            num_dir_pos_mov--;

        // se selecciona la direccion aleatoria
        direccion diraleat = (direccion)(num_dir_pos_mov*(double)rand()/RAND_MAX);

        int i, j;
        for (i=0, j=0; i<3; i++)
            if (puede_moverse_fantasma(F->fil, F->col, pos_dir[i]))
            {
                if (diraleat == j)
                {
                    F->dir = pos_dir[i];
                    break;
                }
                j++;
            }
    }

    int fil = F->fil;
    int col = F->col;

    // incrementar las posiciones
    switch(F->dir)
    {
    case quieto:
        break; // para hacer feliz al gcc
    case derecha:
        if (col<NCOL-1) col++;
        break;
    case arriba:
        if (fil>0)      fil--;
        break;
    case izquierda:
        if (col>0)      col--;
        break;
    case abajo:
        if (fil<NFIL-1) fil++;
        break;
    }

    // se borra el fantasma de la posición actual
    switch(mapa[F->fil][F->col])
    {
    case 'M':
        mvaddch(F->fil, F->col, '=' | COLOR_PAIR(COL_PARED));
        break;
    case '.':
        mvaddch(F->fil, F->col, '.' | COLOR_PAIR(COL_PASILLO));
        break;
    case ' ':
        mvaddch(F->fil, F->col, ' ' | COLOR_PAIR(COL_PASILLO));
        break;
    }

    // se avanza el fantasma una posición
    F->col = col;
    F->fil = fil;

    // se pone el pacman en la nueva posición
    mvaddch(F->fil, F->col, 'A' | COLOR_PAIR(F->color) | A_BOLD);
    refresh();
}

void mover_pacman(direccion dir)
{
    int fil, col;
    static int marcador = -1;

    // guardar las posiciones anteriores
    int fil_ant = fil = pacman.fil;
    int col_ant = col = pacman.col;

    // incrementar las posiciones
    switch(dir)
    {
    case quieto:
        break; // para hacer feliz al gcc
    case derecha:
        if (col<NCOL-1) col++;
        break;
    case arriba:
        if (fil>0)      fil--;
        break;
    case izquierda:
        if (col>0)      col--;
        break;
    case abajo:
        if (fil<NFIL-1) fil++;
        break;
    }

    switch(mapa[fil][col])
    {
    case '.':
        marcador++;
    case ' ':
        mapa[fil][col] = ' ';
        pacman.col = col;
        pacman.fil = fil;
        pacman.dir = dir;

        // se borra el pacman
        mvaddch(fil_ant, col_ant, ' ' | COLOR_PAIR(COL_PASILLO));
        break;
    }

    // se escribe el pacman en la nueva posición
    pacman.boca_abierta = !pacman.boca_abierta;   // abrir y cerrar boca
    mvaddch(pacman.fil, pacman.col, (pacman.boca_abierta ? 'C' : 'c')
            | COLOR_PAIR(pacman.color) | A_BOLD);

    mvprintw(0, 50, "Vidas    = %2d", pacman.vidas);
    mvprintw(1, 50, "Marcador = %d",  marcador);

    refresh();                                    // imprimir en pantalla
}

bool puede_moverse_pacman(int fil, int col, direccion dir)
{
    // incrementar las posiciones
    switch(dir)
    {
    case quieto:
        break; // para hacer feliz al gcc
    case derecha:
        if (col<NCOL-1) col++;
        break;
    case arriba:
        if (fil>0)      fil--;
        break;
    case izquierda:
        if (col>0)      col--;
        break;
    case abajo:
        if (fil<NFIL-1) fil++;
        break;
    }

    if ((mapa[fil][col] == '.') || (mapa[fil][col] == ' '))
        return true;
    else
        return false;
}

bool puede_moverse_fantasma(int fil, int col, direccion dir)
{
    // incrementar las posiciones
    switch(dir)
    {
    case quieto:
        break; // para hacer feliz al gcc
    case derecha:
        if (col<NCOL-1) col++;
        break;
    case arriba:
        if (fil>0)      fil--;
        break;
    case izquierda:
        if (col>0)      col--;
        break;
    case abajo:
        if (fil<NFIL-1) fil++;
        break;
    }

    if ((mapa[fil][col] == '.') ||
            (mapa[fil][col] == ' ') ||
            (mapa[fil][col] == 'M'))
        return true;
    else
        return false;
}

inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic)
{
    return (toc.tv_sec - tic.tv_sec) + (toc.tv_usec - tic.tv_usec)/1000000.0;
}
