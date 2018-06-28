//
//   Name: Adachi, Kristin
//   Project: #4
//   Due: 12/08/16
//   Course: CS25601-f16
//
//   Description: This project demonstrates the concept of inheritance between the 
//      three classes Ship, CruiseShip, and CargoShip. CruiseShip and CargoShip are 
//      also expected to override the print function in the Ship class.
//

#include <iostream>
#include <string>

using namespace std;

class Ship
{
   protected:
      string name, year;

   public:
      Ship(): name( "N/A" ), year( "N/A" ){}
      Ship( string n, string y ): name( n ), year( y ){}
      virtual void print() const{  cout << "Name: " << name << endl << "Year: " << year << endl; }
};

class CruiseShip : public Ship
{
   private:
      int max_pass;

   public:
      CruiseShip(): Ship(), max_pass( 0 ){}
      CruiseShip( string n, string y, int p ): Ship( n, y ), max_pass( p ){}
      void print() const{ cout << "Name: " << name << endl << "Max Passengers: " << max_pass << endl; }
};

class CargoShip : public Ship
{
   private:
      int cargo_cap;

   public:
      CargoShip(): Ship(), cargo_cap( 0 ){}
      CargoShip( string n, string y, int c ): Ship( n, y ), cargo_cap( c ){}
      void print() const{ cout << "Name: " << name << endl <<  "Cargo Capacity: " << cargo_cap << endl; }
};

int main()
{
   int num_ships = 10;

   Ship *ships[ num_ships ] =
   { 
     new Ship( "Ship1", "2016" ),
     new CruiseShip( "Cruise1", "1997", 100 ),
     new CargoShip( "Cargo1", "2002", 150 ),
     new CargoShip( "Cargo2", "2005", 300 ),
     new Ship( "Ship2", "2012" ),
     new CruiseShip( "Cruise2", "1996", 500 ),
     new CargoShip( "Cargo3", "2010", 200 ),
     new CruiseShip( "Cruise3", "2015", 350 ),
     new CargoShip( "Cargo4", "1990", 400 ),
     new Ship( "Ship3", "1880" )
   };

   for( int i = 0; i < num_ships; i++ )
   {
      ships[i]->print();
      cout << endl;
   }
   
   return 0;
}

