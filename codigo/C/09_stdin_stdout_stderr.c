#include<stdio.h> 

// gcc -Wall 09_stdin_stdout_stderr.c -o 09_stdin_stdout_stderr

int main(void)
{
   int edad;
   fprintf(stdout, "Entre su edad = ");
   fscanf(stdin, "%d", &edad);
   fprintf(stdout, "Su edad mostrada por stdout es %d\n", edad);
   fprintf(stderr, "Su edad mostrada por stderr es %d\n", edad); 
   return 0;   
}

