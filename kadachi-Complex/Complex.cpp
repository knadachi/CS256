
#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex(): a( 0 ), b( 0 ) {}

Complex::Complex( const Complex& c ): a( c.getA() ), b( c.getB() ) {}

Complex::Complex( double real, double i ): a( real ), b( i ) {}

double Complex::getA() const
{
   return a;
}

double Complex::getB() const
{
   return b;
}

bool Complex::equals( Complex rhs ) const
{
   return a == rhs.getA() && b == rhs.getB();
}

Complex Complex::multiply( Complex rhs )
{
   return Complex( a * rhs.getA() - b * rhs.getB(), a * rhs.getB() + b * rhs.getA() );
}

void Complex::print( string s ) const
{
   cout << s << a << " + " << b << "i" << endl;
}

Complex add( Complex lhs, Complex rhs )
{
   return Complex( lhs.getA() + rhs.getA(), lhs.getB() + rhs.getB() );
}

