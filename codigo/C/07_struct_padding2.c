#include <stdio.h>
#include <time.h>

#define N 10000000

struct struct_con_padding
{
   char a;
   int b;
   char c;
} x[N];


struct __attribute__((__packed__)) struct_con_packing
{
   char a;
   int b;
   char c;
   int tmp1;
   char tmp2;
   char tmp3;
} y[N];


int main(void)
{
   int i;
   clock_t tic, toc;
   
   printf("tamaño(x) = %d Mb, tamaño(y) = %d Mb\n", sizeof(x)/1024/1024, sizeof(y)/1024/1024);
   
   tic = clock();   
   for (i=0; i<N; i++) { x[i].a = 'Q';    x[i].b = 1000;    x[i].c = 'R'; }
   toc = clock();
   printf("Tiempo con padding = %lf segundos\n", (double)(toc-tic)/CLOCKS_PER_SEC);

   tic = clock();   
   for (i=0; i<N; i++) { y[i].a = 'Q';    y[i].b = 1000;    y[i].c = 'R'; }
   toc = clock();
   printf("Tiempo con packing = %lf segundos\n", (double)(toc-tic)/CLOCKS_PER_SEC);
   
   return 0;
}
