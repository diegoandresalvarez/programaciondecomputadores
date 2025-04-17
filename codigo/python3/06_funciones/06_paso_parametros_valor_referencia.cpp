#include <iostream>

using namespace std;

void intercambio_valor(int x, int y)        
{
   int tmp;   // x, y y tmp son variables locales
   tmp = x;
   x = y;
   y = tmp;
}

void intercambio_referencia(int &x, int &y) 
{
   int tmp;   // tmp es una variable local
   tmp = x;   // x, y son referencias
   x = y;
   y = tmp;
}

int main (void)
{
   int a = 100, b = 200; // a y b son variables locales a main()

   cout << "a = " << a << " b = " << b << endl;
   intercambio_valor(a,b);       // paso de parámetros por valor
   cout << "a = " << a << " b = " << b << endl;
   intercambio_referencia(a,b);  // paso de parámetros por referencia
   cout << "a = " << a << " b = " << b << endl;

   return 0;
}

