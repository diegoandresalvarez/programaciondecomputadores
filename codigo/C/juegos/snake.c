/*
 * S N A K E
 * Por:
 * Diego Andres Alvarez Marin (daalvarez@unal.edu.co)
 * Ver el juego en el que se inspira:
 * http://fullscreenflashgames.com/index.php?task=view&id=207
 *
 * INSTRUCCIONES:
 * Flechas (y las teclas A,S,D,W) mueven la serpiente
 * ESPACIO pausa
 * ESCAPE  se sale del juego
 *
 * COMPILE CON:
 * WINDOWS : gcc -Wall -o snake.exe snake.c -lpdcurses
 * LINUX   : gcc -Wall -o snake snake.c -lncurses
 */

/*
 * BUGS CONOCIDOS:
 * 1. A veces el buffer del teclado se pega (solucion: hacer el programa usando
 * threads; no lo hice, porque esto está fuera del alcance del curso.
 *
 * 2. En el diálogo de perdiste a veces se requiere dar dos veces espacio: este
 * es un problema de la libreria curses.h. Toca mirar en foros como implementar
 * el codigo de una forma alternativa que no presente dicho problema.
 */

#include<curses.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/time.h>

// se definen las constantes
#define KEY_ESCAPE           27    // ASCII tecla ESCAPE
#define NFIL                 25    // filas mapa
#define NCOL                 80    // columnas mapa
#define NSNAKES               2    // numero de serpientes
#define LONG_MAX_SNAKE  (200+2)    // longitud maxima de la serpiente mas dos
#define CELDAS_ALARGAR        5    // numero de celdas a alargar con la capsula

// colores del tablero
#define COL_PARED             1
#define COL_CAPSULA_ALARGAM   2
#define COL_VACIO             3
#define COL_TEXTO             4
#define COL_TUNEL             5

// colores de las serpientes
#define COL_SNAKE1            6
#define COL_SNAKE2            7

// caracteres utilizados en el mapa para identificar los objetos
#define SNAKE1               'S'
#define SNAKE2               'W'
#define CAPSULA_ALARGAMIENTO '*'
#define TUNEL                'T'

// se definen las enumeraciones
typedef enum {quieto, derecha, arriba, izquierda, abajo} direccion;

// se definen las estructuras
typedef struct
{
    bool comida;
    int f, c;
} capsula;

typedef struct
{
    int f, c;
} celda;

typedef struct
{
    int longitud;            // longitud maxima de la cola
    celda nodo[NFIL*NCOL];   // array de celdas
    int ini, fin;            // cabeza y cola de la cola
} cola;

typedef struct
{
    int fcabeza, ccabeza;     // posicion actual de la cabeza (fila, columna)
    cola cuerpo;              // cola (donde se almacena la serpiente)
    struct timeval tic, toc;  // para el cronometro
    int longitud;             // longitud de la serpiente
    int color;                // color de la serpiente
    bool atraviesa_muros;     // se comio la capsula atraveza muros
    double tiempo_entre_mov;  // tiempo entre movimientos
    int vidas;                // vidas de la serpiente
    int marcador;             // puntaje
    direccion dir;            // direccion hacia la que avanza
    int caracter_mapa;        // caracter que representa la serpiente en el mapa
    int alargar;              // numero de casillas a alargar
} serpiente;

// se definen las variables globales
serpiente sammy1, sammy2;   // crear las serpientes

capsula capsula_alargamiento;

char copia_mapa[NFIL][NCOL];
char mapa[NFIL][NCOL] =     // tablero de juego
{
"A------------------------------------------------------------------------------B",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"|                                                                              |",
"D------------------------------------------------------------------------------C"
};

// prototipos de funciones
bool cola_vacia(cola q);
void entrar_cola(cola *q, celda item);
bool salir_cola(cola *q, celda *item);
void inicializaciones(void);
void reiniciar_nivel(void);
void inicializar_serpientes_y_tablero(void);
void pintar_tablero(void);
void mover_serpiente(serpiente *S, direccion proxima_dir);
void poner_cabeza_serpiente(serpiente *S, celda c);
void quitar_cola_serpiente(serpiente *S);
inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic);
direccion mover_automaticamente(int f_ini, int c_ini);
capsula poner_capsula(char tipo_capsula);

// procedimiento principal
int main(void)
{
    int i, ch;
    double tiempo;
    direccion proxima_dir[NSNAKES];  // direcciones del proximo movimiento
    direccion dir_mov1, dir_mov2;    // direccion tentativa de movimiento

    // array de punteros a las serpientes
    serpiente *snake[NSNAKES] = { &sammy1, &sammy2 };

    // crear copia del tablero
    memcpy(copia_mapa, mapa, sizeof(mapa));

    initscr();                  // empiece el modo NCURSES
    inicializaciones();         // inicializaciones de ncurses y de la semilla
    inicializar_serpientes_y_tablero();

    proxima_dir[0] = sammy1.dir;
    proxima_dir[1] = sammy2.dir;

    bool salirse = false;       // ¿salirse del juego?

    // capsulas
    capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO);
    pintar_tablero();           // pintar el tablero

    // Inicializar el cronometro de las serpientes
    for (i=0; i<NSNAKES; i++) gettimeofday(&(snake[i]->tic), NULL);

    while ((sammy1.vidas > 0) && (sammy2.vidas > 0) && (!salirse))
    {
        // mover las serpientes
        for (i=0; i<NSNAKES; i++)
        {
            gettimeofday(&(snake[i]->toc), NULL);
            tiempo = intervalo_tiempo_seg(snake[i]->toc, snake[i]->tic);
            if (tiempo > snake[i]->tiempo_entre_mov)
            {
                mover_serpiente(snake[i], proxima_dir[i]);
                gettimeofday(&(snake[i]->tic), NULL);
            }
        }

        // si se comieron la capsula de alargamiento, generar una nueva
        if (capsula_alargamiento.comida)
        {
            capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO);
            mvaddch(capsula_alargamiento.f, capsula_alargamiento.c,
                    '*' | A_BOLD | COLOR_PAIR(COL_CAPSULA_ALARGAM));
        }

        // imprimir en pantalla
        refresh();

        // vaciamos el buffer del teclado, para que lea solo lo ultimo
        // especificado: esto se hace porque si se presione siempre las flechas
        // no se reaccionara inmediatamente a la ultima flecha
        flushinp();

        // pausa por el numero de milisegundos especificados
        // delay_output(1); // -> lo reemplace con un timeout(1);

        // leer el teclado
        ch = getch();
        switch(ch)
        {
        case KEY_RIGHT:        // flecha derecha
        case 'D':
        case 'd':
            dir_mov1 = derecha;
            break;
        case KEY_UP:           // flecha arriba
        case 'W':
        case 'w':
            dir_mov1 = arriba;
            break;
        case KEY_LEFT:         // flecha izquierda
        case 'A':
        case 'a':
            dir_mov1 = izquierda;
            break;
        case KEY_DOWN:         // flecha abajo
        case 'S':
        case 's':
            dir_mov1 = abajo;
            break;
        case ' ':              // pausa
            break;
        case KEY_ESCAPE:       // salirse del juego
            salirse = true;
            break;
        }

        // si la direccion tentativa de movimiento no es quieto, seguirla,
        // de lo contrario, seguir la inercia
        // dir_mov1 = mover_automaticamente(snake[0]->fcabeza, snake[0]->ccabeza);
        dir_mov2 = mover_automaticamente(snake[1]->fcabeza, snake[1]->ccabeza);
        if (dir_mov1 != quieto && dir_mov2 != quieto)
        {
            proxima_dir[0] = dir_mov1;
            proxima_dir[1] = dir_mov2;
        }
    }

    endwin(); // finalice el modo NCURSES

    return EXIT_SUCCESS;
}

// La cola esta vacia?
bool cola_vacia(cola q)
{
    return (q.fin == q.ini);
}

// Meter un elemento a la cola
void entrar_cola(cola *q, celda item)
{

    if(q->fin == (q->longitud - 1))
        q->fin = 0;
    else
        q->fin++;

    q->nodo[q->fin] = item;

    return;
}

// Sacar un elemento de la cola
bool salir_cola(cola *q, celda *item)
{
    if(cola_vacia(*q)) return false;

    if(q->ini == (q->longitud - 1))
        q->ini = 0;
    else
        q->ini++;

    *item = q->nodo[q->ini];

    return true;
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

    resize_term(25,80);  // poner ventana de 25 filas, 80 columnas
    curs_set(0);         // no se muestra el cursor
    cbreak();            // no line buffering: lee letra a letra, no espera \n
    keypad(stdscr,TRUE); // acepte flechas y otras teclas especiales
    timeout(1);          // getch() espera 1 miliseg. si no hay tecla presionada
    noecho();            // no haga echo() con getch()
    srand(time(NULL));   // inicializar el generador de numeros aleatorios
    start_color();       // activar modo colores

    init_pair(COL_PARED,           COLOR_YELLOW,  COLOR_BLUE);
    init_pair(COL_CAPSULA_ALARGAM, COLOR_WHITE,   COLOR_BLUE);
    init_pair(COL_VACIO,           COLOR_BLUE,    COLOR_BLUE);
    init_pair(COL_TEXTO,           COLOR_MAGENTA, COLOR_BLUE);
    init_pair(COL_TUNEL,           COLOR_GREEN,   COLOR_BLUE);
    init_pair(COL_SNAKE1,          COLOR_YELLOW,  COLOR_BLUE);
    init_pair(COL_SNAKE2,          COLOR_RED,     COLOR_BLUE);

    return;
}

void reiniciar_nivel(void)
{
    // poner el mapa original (borrar el tablero)
    memcpy(mapa, copia_mapa, sizeof(mapa));

    // inicializar sammy1
    sammy1.longitud = 0;
    sammy1.color = COL_SNAKE1;
    sammy1.atraviesa_muros = false;
    sammy1.tiempo_entre_mov = 1.0/8;  // muevase 8 cuadros por segundo
    sammy1.dir = arriba;
    sammy1.caracter_mapa = SNAKE1;

    sammy1.cuerpo.longitud = LONG_MAX_SNAKE;
    sammy1.cuerpo.ini      = 0;
    sammy1.cuerpo.fin      = 0;

    poner_cabeza_serpiente(&sammy1, (celda) { .f = 8, .c = 41 }); // cola
    poner_cabeza_serpiente(&sammy1, (celda) { .f = 8, .c = 40 });
    poner_cabeza_serpiente(&sammy1, (celda) { .f = 8, .c = 39 }); // cabeza

    // inicializar sammy2
    sammy2.longitud = 0;
    sammy2.color = COL_SNAKE2;
    sammy2.atraviesa_muros = false;
    sammy2.tiempo_entre_mov = 1.0/8;  // muevase 8 cuadros por segundo
    sammy2.dir = abajo;
    sammy2.caracter_mapa = SNAKE2;

    sammy2.cuerpo.longitud = LONG_MAX_SNAKE;
    sammy2.cuerpo.ini      = 0;
    sammy2.cuerpo.fin      = 0;

    poner_cabeza_serpiente(&sammy2, (celda) { .f = 16, .c = 39 }); // cola
    poner_cabeza_serpiente(&sammy2, (celda) { .f = 16, .c = 40 });
    poner_cabeza_serpiente(&sammy2, (celda) { .f = 16, .c = 41 }); // cabeza

    return;
}

void inicializar_serpientes_y_tablero(void)
{
    reiniciar_nivel();

    // inicializar vidas y marcador de serpientes
    sammy1.vidas    = 3;
    sammy1.marcador = 0;

    sammy2.vidas    = 3;
    sammy2.marcador = 0;

    return;
}

void pintar_tablero(void)
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
                color = COL_VACIO;
                letra = ' ';
                break;
            case SNAKE1:
                color = COL_SNAKE1;
                letra = ACS_CKBOARD | A_BOLD;
                break;
            case SNAKE2:
                color = COL_SNAKE2;
                letra = ACS_CKBOARD | A_BOLD;
                break;
            case CAPSULA_ALARGAMIENTO:
                color = COL_CAPSULA_ALARGAM;
                letra = '*' | A_BOLD;
                break;
            default:
                getch();     // presione una tecla para terminar
                endwin();    // finalice el modo NCURSES

                perror("Error en la especificacion del laberinto");
                exit(EXIT_FAILURE);
            }
            // imprima el caracter + color
            mvaddch(f, c, letra | COLOR_PAIR(color));
        }
    refresh();               // imprimir en la pantalla fi­sica

    return;
}

void mover_serpiente(serpiente *S, direccion proxima_dir)
{
    // coordenadas de la cabeza de la serpiente
    int f = S->fcabeza;
    int c = S->ccabeza;
    WINDOW *ventana;
    char mensaje[80];

    // actualizar direcciones (teniendo en cuenta que no se puede retroceder)
    switch(proxima_dir)
    {
    case quieto:
        return; // detener la serpiente
        break;
    case derecha:   if (S->dir != izquierda) S->dir = proxima_dir; break;
    case arriba:    if (S->dir != abajo)     S->dir = proxima_dir; break;
    case izquierda: if (S->dir != derecha)   S->dir = proxima_dir; break;
    case abajo:     if (S->dir != arriba)    S->dir = proxima_dir; break;
    }

    // actualizar los movimientos
    switch(S->dir)
    {
    case quieto:
        // no hacer nada
        break; // se pone para hacer feliz al gcc (evitar un warning)
    case derecha:    if (c<NCOL-1) c++; break;
    case arriba:     if (f>0)      f--; break;
    case izquierda:  if (c>0)      c--; break;
    case abajo:      if (f<NFIL-1) f++; break;
    }

    switch(mapa[f][c])
    {
    case SNAKE1:  // se choco con otra serpiente o con si misma
    case SNAKE2:
    case '-':     // se choco con un muro
    case '|':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
        // newwin(altura, ancho, coord_sup_izq_x, coord_sup_izq_y)
        strcpy(mensaje, "Presione espacio para continuar");
        ventana = newwin(7, strlen(mensaje)+4, NFIL/2-3, (NCOL-strlen(mensaje)-4)/2);
        box(ventana, 0 , 0);	 // 0, 0 pone los caracteres estandar del borde
        wrefresh(ventana);		 // muestre la ventana
        wattron(ventana, A_BOLD);
        mvwprintw(ventana, 2, 2, "        *** Perdiste ***       ");
        wattroff(ventana, A_BOLD);
        mvwprintw(ventana, 4, 2, mensaje);
        wrefresh(ventana);

        flushinp();              // borre el buffer del teclado
        do {} while (wgetch(ventana) != ' ');  // lea el espacio para continuar
        flushinp();

        delwin(ventana);    // borre la ventana (no borra los caracteres)

        // Aquí el NCURSES parece tener un bug, ya que a veces no se borra
        // la ventana antes de continuar
        touchwin(stdscr);   // la ventana stdscr se debe dibujar completamente
        refresh();

        // perdio una vida
        S->vidas--;

        if (S->vidas != 0)
        {
            reiniciar_nivel();
            capsula_alargamiento = poner_capsula(CAPSULA_ALARGAMIENTO);
            pintar_tablero();
        }
        break;
    case CAPSULA_ALARGAMIENTO:
        capsula_alargamiento.comida = true;
        S->alargar = CELDAS_ALARGAR;
        S->marcador++;
        // siga derecho (no break)
    case ' ':
        // poner la cabeza
         poner_cabeza_serpiente(S, (celda){.f = f, .c = c});

        // si la serpiente ya es muy larga no alargar mas
        if (S->longitud >= LONG_MAX_SNAKE-1)
            S->alargar = 0;

        // quitar la cola (o alargar si es necesario)
        if (S->alargar > 0)
            S->alargar--;
        else
            quitar_cola_serpiente(S);

        break;
    }

//    FALTA ACTUALIZAR CONTADORES DE VIDAS Y MARCADOR
//    mvprintw(0, 50, "Vidas    = %2d", S->vidas);
//    mvprintw(1, 50, "Marcador = %d",  S->marcador);
}

void poner_cabeza_serpiente(serpiente *S, celda c)
{
    entrar_cola(&(S->cuerpo), c);
    S->longitud++;

    S->fcabeza = c.f;
    S->ccabeza = c.c;

    mapa[c.f][c.c] = S->caracter_mapa;

    // imprima el caracter + color
    mvaddch(c.f, c.c, ACS_CKBOARD | A_BOLD | COLOR_PAIR(S->color));

    return;
}

void quitar_cola_serpiente(serpiente *S)
{
    celda c;
    salir_cola(&(S->cuerpo), &c);
    S->longitud--;

    mapa[c.f][c.c] = ' ';

    // imprima el caracter + color
    mvaddch(c.f, c.c, ' ' | A_BOLD | COLOR_PAIR(COL_VACIO));

    return;
}

inline double intervalo_tiempo_seg(struct timeval toc, struct timeval tic)
{
    return (toc.tv_sec - tic.tv_sec) + (toc.tv_usec - tic.tv_usec)/1000000.0;
}

// Aqui se esta implementando el algoritmo Breadth-first seach, para encontrar
// el camino mas corto entre la cabeza de la serpiente, la cual tiene coordenadas
// (f_ini, c_ini) y la capsula
// http://en.wikipedia.org/wiki/Breadth-first_search
direccion mover_automaticamente(int f_ini, int c_ini)
{
    // crear copia del tablero
    char L[NFIL][NCOL];
    memcpy(L, mapa, sizeof(mapa));

    int f_ant[NFIL][NCOL], c_ant[NFIL][NCOL];
    int dir;
    celda nodo_actual;

    // si esta a una casilla de distancia ...
    if (capsula_alargamiento.f == f_ini)
    {
       if (capsula_alargamiento.c - c_ini ==  1) return derecha;
       if (capsula_alargamiento.c - c_ini == -1) return izquierda;
    }
    if (capsula_alargamiento.c == c_ini)
    {
       if (capsula_alargamiento.f - f_ini ==  1) return abajo;
       if (capsula_alargamiento.f - f_ini == -1) return arriba;
    }

    // crear cola e inicializarla a una cola vacia
    cola q = {.ini = 0, .fin = 0, .longitud = 100};

    // El nodo [f_ini][c_ini] es el principio, no tiene un anterior
    f_ant[f_ini][c_ini] = c_ant[f_ini][c_ini] = -1;

    // agregar el principio a la cola
    entrar_cola(&q, (celda){ .f = f_ini, .c = c_ini });

    // hacer el ciclo hasta que no haya mas nodos vecinos que revisar
    while(!cola_vacia(q))
    {
        salir_cola(&q, &nodo_actual);

        //revisar los vecinos del nodo_actual
        for (dir=1; dir<=4; dir++)
        {
            int f_act, c_act;
            switch(dir)
            {
                case 1: f_act = nodo_actual.f;   c_act = nodo_actual.c+1; break;
                case 2: f_act = nodo_actual.f-1; c_act = nodo_actual.c;   break;
                case 3: f_act = nodo_actual.f;   c_act = nodo_actual.c-1; break;
                case 4: f_act = nodo_actual.f+1; c_act = nodo_actual.c;   break;
            }

            // si se salio del laberinto, siga con el siguiente ciclo
            if (f_act<0 || f_act==NFIL) continue; // (por arriba o por abajo)
            if (c_act<0 || c_act==NCOL) continue; // (por la izquierda o derecha)

            // si el nodo_actual no ha sido visitado, o encontramos la salida:
            if (L[f_act][c_act] == ' ' || L[f_act][c_act] == '*')
            {
                // almaceno posicion del padre:
                f_ant[f_act][c_act] = nodo_actual.f;
                c_ant[f_act][c_act] = nodo_actual.c;

                // si encontramos el final, retornar la direccion
                if (L[f_act][c_act] == '*')
                {
                    int pos_f = f_ant[f_act][c_act];
                    int pos_c = c_ant[f_act][c_act];
                    int oldpos_f, oldpos_c;
                    do
                    {
                        oldpos_f = pos_f;
                        oldpos_c = pos_c;
//                      mvaddch(pos_f,pos_c,'#');
//                      refresh();
                        pos_f = f_ant[oldpos_f][oldpos_c];
                        pos_c = c_ant[oldpos_f][oldpos_c];
                    }
                    while (f_ant[pos_f][pos_c] != -1 && c_ant[pos_f][pos_c] != -1);

                    if (pos_f < oldpos_f) return abajo;
                    if (pos_f > oldpos_f) return arriba;
                    if (pos_c < oldpos_c) return derecha;
                    if (pos_c > oldpos_c) return izquierda;
                }
                else // si es una celda vacia
                {
                    L[f_act][c_act] = '.';
//                    mvaddch(f_act,c_act,'.');
//                    refresh();
                    entrar_cola(&q, (celda){.f = f_act, .c = c_act});
                }
            }
        }
    }

    // se exploro todo el laberinto pero no se encontro la salida, por lo tanto
    // quedese quieta (esto quiere decir, no hay una salida)
    return quieto;
}

capsula poner_capsula(char tipo_capsula)
{
    capsula cap;

    // se pone la capsula aleatoriamente en el tablero
    cap.comida = false;
    do
    {
        cap.f = NFIL*(double)rand()/RAND_MAX;
        cap.c = NCOL*(double)rand()/RAND_MAX;
    } while(mapa[cap.f][cap.c] != ' ');

    // se pone el caracter en el tablero
    mapa[cap.f][cap.c] = tipo_capsula;

    // se retorna la capsula generada
    return cap;
}
