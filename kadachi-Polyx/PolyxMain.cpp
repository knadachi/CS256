
#include <iostream>
#include "Polyx.h"

using namespace std;

int main()
{
   double c1[] = { 4, -5, 3 };
   Polyx p1(c1, sizeof(c1) / sizeof(double)), p2(p1);
   double eval = p1.f(5);
   cout << p1 << endl << "f(5) = " << p1.f(5) << endl;
   Polyx p3 = p1 + p2;
   cout << "p1 + p2 = " << p3 << endl;

   return 0;
}

