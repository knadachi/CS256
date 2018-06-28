
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <assert.h>
#include "Polyx.h"

using namespace std;

Polyx::Polyx( double a[], int n )
{
   assert( n > 0 );
   assert( a != NULL );
   this->n = n;
   this->a = new double[n];
   for( int i = 0; i < n; i++ )
      this->a[i] = a[i];
}

Polyx::Polyx( const Polyx& p )
{
   this->n = p.n;
   this->a = new double[this->n];
   for( int i = 0; i < this->n; i++ )
      this->a[i] = p.a[i];
}

Polyx::~Polyx()
{
   delete []a;
}

double Polyx::f( double x ) const
{
   double sum = 0;
   for( int i = 0; i < n; i++ )
      sum += a[i] * pow( x, i );
   return sum;
}

Polyx Polyx::operator+( const Polyx& p )
{
   if( this->n > p.n )
   {
      double c[this->n];
      for( int i = 0; i < this->n; i++ )
      {
         if( i < p.n )
	    c[i] = this->a[i] + p.a[i];
	 else
	    c[i] = this->a[i];
      }
      Polyx poly( c, this->n );
      return poly;
   }
   else
   {
      double c[p.n];
      for( int i = 0; i < p.n; i++ )
      {
         if( i < this->n )
	    c[i] = this->a[i] + p.a[i];
	 else
	    c[i] = p.a[i];
      }
      Polyx poly( c, p.n );
      return poly;
   }
}

string Polyx::toString() const
{
   ostringstream strs;
   for( int i = n-1; i >= 0; i-- )
   {
      if( i == n-1 )
      {
         if( a[i] < 0 )
	    strs << "-" << abs( a[i] );
	 else
	    strs << a[i];
      }
      else
      {
         if( a[i] < 0 )
	    strs << " - " << abs( a[i] );
	 else
	    strs << " + " << a[i];
      }

      if( i == 1 )
         strs << "x";
      else if( i > 1 )  
	 strs << "x^" << i;
   }

   return strs.str();
}

ostream& operator<<( ostream& outs, const Polyx& p )
{
   return outs << p.toString();
}

