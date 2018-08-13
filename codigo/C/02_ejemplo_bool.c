#include <stdio.h>

int main(void)
{
   _Bool b = 1>0;
   if (b)
      printf("TRUE\n");
   else
      printf("FALSE\n");

   return 0;
}

#include <stdio.h>

typedef enum
{
  false,
  true
} bool;

int main(void)
{
   bool b = false;
   if (b)
      printf("TRUE\n");
   else
      printf("FALSE\n");

   return 0;
}


#include <stdio.h>
#include <stdbool.h>

int main(void)
{
   bool b = true;
   if (b)
      printf("TRUE\n");
   else
      printf("FALSE\n");

   return 0;
}


