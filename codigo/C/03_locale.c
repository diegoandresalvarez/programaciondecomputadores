#include<stdio.h>
#include<locale.h>

int main(void)
{
    setlocale(LC_ALL, "spanish");
    puts("áÁ éÉ íÍ óÓ úÚ üÜ ñ Ñ");
    return 0;
}
