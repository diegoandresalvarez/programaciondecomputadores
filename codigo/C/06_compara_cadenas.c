#include <stdio.h>
#include <stdbool.h>

/*
Sin invocar a la librería string.h, escriba un programa que contiene una función
que reciba como argumento dos cadenas y retorne lo siguiente: si ambas cadenas son
iguales, retorne 0; si la primera cadena va antes que la segunda cadena al
ordenarlas alfabéticamente, retorne un número negativo. Si la primera cadena va
después que la segunda cadena al ordenarlas alfabéticamente, retorne un número
positivo.

gcc -Wall -o 06_compara_cadenas 06_compara_cadenas.c
*/

int compara(char *c1, char *c2);

char cad1[] = "abecedario";
char cad2[] = "abecedario";

int main(void)
{
    printf("compara(cad1,cad2) = %d\n", compara(cad1,cad2));

    return 0;
}

int compara(char *c1, char *c2)
{
    int i = 0;
    while (true)
    {
        if (c1[i] == c2[i])
        {
            i++;
            if (c1[i] == '\0' && c2[i] == '\0') return 0;
        }
        else
            return (c1[i] - c2[i]);
    }
}

