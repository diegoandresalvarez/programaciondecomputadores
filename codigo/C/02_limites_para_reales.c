#include<stdio.h>
#include<float.h>
float f;
double d;
long double ld;

int main(void)
{
   printf("float:\n");
   printf("sizeof(f)   = %d\n", (int) sizeof(f));
   printf("FLT_DIG     = %d\n", FLT_DIG);
   printf("FLT_EPSILON = %g\n", FLT_EPSILON);        // ensaye con %f, %e
   printf("FLT_MIN     = %g\n", FLT_MIN);
   printf("FLT_MAX     = %g\n", FLT_MAX);
   
   printf("\n");
   printf("double:\n");
   printf("sizeof(d)   = %d\n", (int) sizeof(d));
   printf("DBL_DIG     = %d\n", DBL_DIG);
   printf("DBL_EPSILON = %g\n", DBL_EPSILON);        // ensaye con %f, %e
   printf("DBL_MIN     = %g\n", DBL_MIN);
   printf("DBL_MAX     = %g\n", DBL_MAX);
   printf("\n");
   printf("long double:\n");
   printf("sizeof(ld)   = %d\n",  (int) sizeof(ld));
   printf("LDBL_DIG     = %d\n",  LDBL_DIG);   
   printf("LDBL_EPSILON = %Lg\n", LDBL_EPSILON);     // ensaye con %Lf, %Le
   printf("LDBL_MIN     = %Lg\n", LDBL_MIN);
   printf("LDBL_MAX     = %Lg\n", LDBL_MAX);
   printf("\n");

   return 0;
}

