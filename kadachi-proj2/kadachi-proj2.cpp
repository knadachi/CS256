//
//   Name:    Adachi, Kristin
//   Project: 2
//   Due:     10/27/16
//   Course:  cs25601
//
//   Description:
//      This program generates a secret random number between 1 and 100. 
//      The user is prompted to guess the secret number in 8 tries 
//      where their guess must be between 1 and 100. After each incorrect 
//      guess, a hint is given to the user saying whether their number 
//      is high or low. If they guess correctly within 8 tries, the number 
//      of turns it took to guess the secret number is printed. The user 
//      also has the option to give up by entering 0 which then prints the 
//      secret number.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int validate( int guess );

int main()
{
   int count = 0, guess = -1, secretNum;
   
   cout << "K. Adachi's Guess-my-Number" << endl << endl << endl;
   cout << "A secret number between 1-100 generated..." << endl << endl << endl;

   srand(time(NULL));
   secretNum = rand() % 100 + 1;
   
   while( guess != secretNum && count < 8 )
   {
      cout << "Please enter your guess? ";
      cin >> guess;
      
      guess = validate( guess );

      if( guess == 0 )
      {
         cout << "The secret number is " << secretNum << "." << endl;
         return 0;
      }
      else if( guess > secretNum )
         cout << "Guess is high..." << endl;
      else if( guess < secretNum )
         cout << "Guess is low..." << endl;

      count++;
   }

   if( guess == secretNum )
   {
      if( count == 1 )
         cout << "Correct in " << count << " guess." << endl;
      else
         cout << "Correct in " << count << " guesses." << endl;
   }
   else
      cout << "Too many guesses, the secret number is " << secretNum << "." << endl;
   
   return 0;
}

int validate( int guess )
{
   while( guess < 0 || guess > 100 )
   {
      cout << "Invalid input." << endl;
      cout << "Please enter your guess? ";
      cin >> guess;
   }
   return guess;
}

