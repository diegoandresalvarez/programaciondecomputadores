#ifdef PONER_INLINE
   // gcc 05_inline.c -o 05_inline -std=c99 -D PONER_INLINE
   #define INLINE1 inline
   #define INLINE2 __attribute__((always_inline))
#else // no ponga inline
   // gcc 05_inline.c -o 05_inline -std=c99
   #define INLINE1
   #define INLINE2
#endif
 
INLINE1 int a_mas_b_ala_2(int a, int b);

int main(void)
{
   for(int i = 0; i < 100000; i++)
      for(int j = 0; j < 100000; j++)
         a_mas_b_ala_2(i, j);

   return 0;
}

INLINE2 int a_mas_b_ala_2(int a, int b)
{
   return (a + b)*(a + b);
}

