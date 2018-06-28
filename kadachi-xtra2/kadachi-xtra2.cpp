//
//   Name:     Adachi, Kristin
//   Project:  Extra #2
//   Due:      12/08/16
//   Course:   cs25601-f16
//
//   Description: This program has a template-based class Stack that implements 
//      the stack data type. It is able to push and pop items from the stack. 
//      The program also utilizes error messages for certain cases when pushing 
//      and popping.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
class Stack
{
   private:
      T* stack;
      int size, top;

   public:
      Stack()
      {
         size = 16;
	 top = 0;
	 stack = new T[size];
      }
      
      Stack( int s )
      {
         size = s;
	 top = 0;
         stack = new T[size];
      }

      ~Stack()
      {
         delete[] stack;
      }
      
      void push( T const& item )
      {
         if( top == size )
	    throw( "Stack is full." );
	 else
	    stack[top++] = item;
      }

      T pop()
      {
      	 if( top == 0 )
	    throw( "Stack is empty." );
	 else
	    return stack[--top];
      }

      void operator>>( T &item )
      {
         item = pop();
      }
};

template <class T>
void operator>>( T item, Stack<T> &stack )
{
   stack.push( item );
}

int main()
{
   cout << "Extra Credit Project #2 by Kristin Adachi" << endl << endl;
   Stack<int> iStack(32);
   Stack<string> sStack;
   int item1 = 12;
   string item2 = "hello";

   try{
      cout << "Push 12 onto iStack." << endl;
      item1 >> iStack;
   }
   catch( char const *msg ){
      cerr << msg << endl;
      exit( EXIT_FAILURE );
   }

   try{
      cout << "Push 24 onto iStack." << endl;
      (item1 + 12) >> iStack;
   }
   catch( char const *msg ){
      cerr << msg << endl;
      exit( EXIT_FAILURE );
   }

   try{ 
      cout << "Pop from iStack: ";
      iStack >> item1;
      cout << item1 << endl;
   }
   catch( char const *msg ){
      cerr << msg << endl;
      exit( EXIT_FAILURE );
   }

   try{
      cout << "Testing if error message works when popping from empty sStack: " << endl;
      sStack >> item2;
      cout << item2 << endl;
   }
   catch( char const *msg ){
      cerr << msg << endl;
      //exit( EXIT_FAILURE );
   }

   try{
      cout << "Testing if error message works when pushing to full iStack: " << endl;
      for( int i = 0; i < 35; i++ )
         i >> iStack;
   }
   catch( char const *msg ){
      cerr << msg << endl;
      exit( EXIT_FAILURE );
   }

   return 0;
}

