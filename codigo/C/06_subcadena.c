#include <stdio.h>
#include <stdlib.h>

/*
 Sin invocar a la librería string.h, escriba un programa que contiene una
 función que reciba como argumento dos cadenas y retorne lo siguiente: si la
 primera cadena es una subcadena de la segunda, retorne un puntero a la primera
 ocurrencia de esta en el segundo argumento, de lo contrario retorne el
 puntero NULL.
*/

char *subcadena(char *c1, char *c2);

char cad1[] = "pila";
char cad2[] = "compilador";

int main(void)
{
    printf("subcadena(cad1,cad2) = %s\n", subcadena(cad1,cad2));

    return 0;
}

char *subcadena(char *c1, char *c2)
{
    int i = 0, j = 0;

    while (c2[j])
    {
        if (c1[i] == c2[j])
            i++;
        else
        {
            if (c1[i] == '\0') return (&c2[j-i]);
            i = 0;
        }
        j++;
    }

    // se llego al final de c2
    if (c1[i] == '\0') return (&c2[j-i]);
    return NULL;
}
