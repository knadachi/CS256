//
//   Name:     Adachi, Kristin
//   Project:  #1
//   Due:      10/12/16
//   Course:   CS256 01-f16
//
//   Description:
//   	This program solves for the roots of a quadratic equation.
//   	It prompts the user for 3 values a, b, and c. Then, it computes 
//   	the roots and prints them.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double a, b, c, x1, x2, discriminant;
   
   /* prints intro to program*/
   cout << "K. Adachi's Quadratic Equation" << endl;

   /* prompts the user for 3 values and prints the equation */
   cout << "\nPlease enter values for a, b, and c: ";
   cin >> a >> b >> c;
   cout <<  a << " x^2 + " << b << " x + " << c << " = 0" << endl;
   
   /* computes the discriminant */
   discriminant = ( b * b ) - ( 4 * a * c );
   
   /* checks for imaginary roots */
   if( discriminant < 0 )
   {
      cout << "Imaginary Roots" << endl;
      return 0;
   }

   /* computes x1 and x2 */
   x1 = (( -b ) + sqrt( discriminant )) / ( 2 * a );
   x2 = (( -b ) - sqrt( discriminant )) / ( 2 * a );

   /* prints the roots (x1 and x2) */
   cout << "x1 = " << x1 << endl;
   cout << "x2 = " << x2 << endl;

   return 0;
}

