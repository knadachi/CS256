
#include "Complex.h"

using namespace std;

int main()
{
   Complex c1( 1, 2 ), c2( 2, 3 ), c3( c1 ), prod, sum;
   bool same = c1.equals( c2 );
   prod = c1.multiply( c2 );
   sum = add( c1, c2 );
   c1.print( "c1 = " );

   return 0;
}

