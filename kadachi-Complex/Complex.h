
#include <string>

using namespace std;

#ifndef _INC_COMPLEX
#define _INC_COMPLEX

class Complex
{
   private:
      double a, b;
   public:
      Complex();
      Complex( const Complex& );
      Complex( double, double );
      double getA() const;
      double getB() const;
      bool equals( Complex ) const;
      Complex multiply( Complex );
      void print( string ) const;
};

Complex add( Complex, Complex );

#endif

