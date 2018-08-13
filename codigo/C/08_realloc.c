#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int *p, i;
   size_t tam = 0;

   printf("Tamaño del vector: ");
   scanf("%d", &tam);

   p = (int *)malloc(tam*sizeof(int));
   if (p == NULL)
   {
         perror("malloc() no funcionó\n");
         exit(EXIT_FAILURE);
   }

   printf("p = %p\n", p);
   for(i=0; i<tam; i++)
   {
      p[i] = i;
      printf("%d, ", p[i]);      
   }
   printf("\b\b.\n");

   printf("Duplicaremos ahora el tamaño del vector: %d\n", tam);
   tam *= 2;
   p = (int *)realloc(p, tam*sizeof(int));   
   if (p==NULL)
   {
         perror("realloc() no funcionó\n");
         exit(EXIT_FAILURE);
   }   
   
   printf("p = %p\n", p);
   
   for(i=0; i<tam; i++)
      printf("%d, ", p[i]);
   printf("\b\b.\n");
   
   free(p);

   return 0;
}