#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void *mi_memcpy(void *restrict dest, const void *restrict orig, size_t n);
void *mi_memmove(void *dest, const void *orig, size_t n);

int main(void)
{
   clock_t tic, toc;
   int n = 200*1024*1024; // copiaremos 100 Mbs
   char *orig, *dest;
   orig = malloc(n);
   dest = malloc(n);   
   if (orig==NULL || dest==NULL)
   {
      perror("No hay memoria suficiente");
      exit(EXIT_FAILURE);
   }     
   
   tic = clock();
   mi_memcpy(dest, orig, n);
   toc = clock();
   printf("Tiempo = %lf\n", (double)(toc-tic)/CLOCKS_PER_SEC);

   tic = clock();
   mi_memmove(dest, orig, n);
   toc = clock();
   printf("Tiempo = %lf\n", (double)(toc-tic)/CLOCKS_PER_SEC);
     
   free(orig);
   free(dest);
   
   return EXIT_SUCCESS;
}

void *mi_memcpy(void *restrict dest, const void *restrict orig, size_t n)
{
    char *d = dest;
    const char *s = orig;
    size_t i;
    for (i = 0; i != n; ++i) d[i] = s[i];
    return dest;
}
/* 
 * memmove() se necesita porque si nosotros tenemos direcciones de memoria que 
 * se traslapan tenemos un problema. Que tal el llamado:
 * memcpy(ptr+1, ptr, n); ??
 * en la primera iteración del ciclo for, el primer byte copiado sobreescribiría 
 * el segundo, el cual está presto a ser leído. Sin embargo, este código es muy
 * veloz, dada la promesa hecha por restrict.
 */

void *mi_memmove(void *dest, const void *orig, size_t n)
{
    char *d = dest;
    const char *s = orig;
    size_t i;
    if (d < s) 
        for (i = 0; i != n; ++i) d[i] = s[i];
    else
    {
        i = n;
        while (i--) d[i] = s[i];
    }
    return dest;
}

