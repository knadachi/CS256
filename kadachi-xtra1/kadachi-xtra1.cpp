//
//   Name:      Adachi, Kristin
//   Project:   Extra #1
//   Due:       12/08/16
//   Course:    cs25601-f16
//
//   Description: This program implements a template-based function called frequency 
//      that returns the count of the occurrences of an item in an array of items.
//

#include <iostream>
#include <string>

using namespace std;

template <typename T>
int frequency( T arr[], int size, T item )
{
   int count = 0;
   for( int i = 0; i < size; i++ )
   {
      if( arr[i] == item )
         count++;
   }
   return count;
}

template <typename T>
void printArray( T arr[], int size )
{
   cout << "{ ";
   for( int i = 0; i < size; i++ )
   {
      if( i == size-1 )
         cout << arr[i] << " ";
      else
         cout << arr[i] << ", ";
   }
   cout << "}" << endl;
}

int main()
{
   cout << "Extra Credit Project #1 by Kristin Adachi" << endl << endl;

   int nums[] = { 1, 3, 5, 2, 3, 3, 1, 4 };
   int size1 = sizeof(nums)/sizeof(*nums);
   printArray( nums, size1 );
   cout << "Frequency of 3 is: " << frequency( nums, size1, 3 ) << endl << endl;

   double nums2[] = { 2.2, 1.5, 1.5, 3.7, 2.6, 2.2, 1.5, 3.9, 1.5 };
   int size2 = sizeof(nums2)/sizeof(*nums2);
   printArray( nums2, size2 );
   cout << "Frequency of 1.5 is: " << frequency( nums2, size2, 1.5 ) << endl << endl;

   string item = "apple";
   string words[] = { "apple", "pear", "peach", "apple", "orange" };
   int size3 = sizeof(words)/sizeof(*words);
   printArray( words, size3 );
   cout << "Frequency of \"apple\" is: " << frequency( words, size3, item ) << endl << endl;

   char letters[] = "dinosaurs";
   int size4 = sizeof(letters)-1;
   printArray( letters, size4 );
   cout << "Frequency of \"s\" is: " << frequency( letters, size4, 's' ) << endl << endl;

   return 0;
}

