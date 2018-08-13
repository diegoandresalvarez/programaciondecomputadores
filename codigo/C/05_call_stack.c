#include <stdio.h>

void fun1(void);
void fun2(void);
void fun3(void);

int main(void)
{
    puts("Llamo a fun1()");
    fun1();
    puts("fun1() se ha ejecutado");
    return 0;
}

void fun1(void)
{
    puts("Llamo a fun2()");
    fun2();
    puts("fun2() se ha ejecutado");
}

void fun2(void)
{
    puts("Llamo a fun3()");
    fun3();
    puts("fun3() se ha ejecutado");
}

void fun3(void)
{
    puts("Estoy dentro de fun3()");
}
