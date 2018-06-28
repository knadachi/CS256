//
//   Name: Adachi, Kristin
//   Project: 3
//   Due: 11/10/16
//   Course: cs25601-f16
//
//   Description: This program reads a character maze from an input file. It then finds 
//      and marks the shortest path between the starting and finishing points. It outputs 
//      the maze with the solution if it exists, otherwise it prints "No Solution."
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_ROW = 24;
const int MAX_COL = 80;
const int START = 0;
const int OBSTACLE = -1;
const int PATH = -2;
const int FINISH = -3;

bool getMaze( char maze[][MAX_COL], string file_name, int &, int & );
bool solveMaze( char maze[][MAX_COL], int text[][MAX_COL + 2], int nrow, int ncol, int & );
void printMaze( char maze[][MAX_COL], int nrow, int ncol );
void convert( char maze[][MAX_COL], int text[][MAX_COL + 2], int nrow, int ncol );

int main()
{  
   int nrow, ncol, length;
   char maze[MAX_ROW][MAX_COL];
   int text[MAX_ROW + 2][MAX_COL + 2];
   string file_name;

   cout << "K. Adachi's A-Mazing!" << endl << endl;
   cout << "Enter the maze file name? ";
   cin >> file_name;

   if( !getMaze( maze, file_name, nrow, ncol ) )
   {
      cerr << "File not found." << endl;
      return 0;
   }
   
   cout << endl;
   cout << "Rows: " << nrow << endl;
   cout << "Columns: " << ncol << endl << endl;
    
   printMaze( maze, nrow, ncol );
   
   convert( maze, text, nrow, ncol );
   
   if( !solveMaze( maze, text, nrow + 2, ncol + 2, length ) )
   {
      cout << endl;
      cout << "No Solution." << endl;
      return 0;
   }

   cout << endl;
   cout << "Path: " << length << endl;
   
   printMaze( maze, nrow, ncol );
   
   return 0;
}

bool getMaze( char maze[][MAX_COL], string file_name, int &nrow, int &ncol )
{
   string line;
   ifstream inFile;
   
   inFile.open( file_name.c_str() );
   if( !inFile )
      return false;
   
   nrow = 0;
   ncol = 0;
   while( getline(inFile, line) )
   {  
      for( int i = 0; i < line.length(); i++ )
      {
         switch( line[i] )
         {
            case 'S':
            case 's': maze[nrow][i] = 'S';
               break;
            case 'X':
            case 'x': maze[nrow][i] = 'X';
               break;
            case ' ': maze[nrow][i] = ' ';
               break;
            case 'F':
            case 'f': maze[nrow][i] = 'F';
               break;
         }
      }
      ++nrow;
      if( line.length() > ncol )
         ncol = line.length();
   }
   
   inFile.close();
   return true;
}

bool solveMaze( char maze[][MAX_COL], int text[][MAX_COL + 2], int nrow, int ncol, int &length )
{
   bool foundFinish = false;
   bool neighborsLeft = true;
   int cur_row, cur_col;
   
   int i = 0; //current neighbor you're looking for
   
   while( !foundFinish && neighborsLeft)
   {
      neighborsLeft = false;
      for( int row = 0; row < nrow; row++ )
      {
         for( int col = 0; col < ncol; col++ )
         {
            if( text[row][col] == i )
            {
               neighborsLeft = true;
               
               if( text[row-1][col] == PATH )
                  text[row-1][col] = i + 1;
               else if( text[row-1][col] == FINISH )
	       {
                  cur_row = row-1;
		  cur_col = col;
		  foundFinish = true;
               }

               if( text[row][col+1] == PATH )
                  text[row][col+1] = i + 1;
               else if( text[row][col+1] == FINISH )
               {  
	          cur_row = row;
		  cur_col = col+1;
		  foundFinish = true;
               }

               if( text[row+1][col] == PATH )
                  text[row+1][col] = i + 1;
               else if( text[row+1][col] == FINISH )
               {
	          cur_row = row+1;
		  cur_col = col;
	          foundFinish = true;
               }

               if( text[row][col-1] == PATH )
                  text[row][col-1] = i + 1;
               else if( text[row][col-1] == FINISH )
               {
	          cur_row = row;
		  cur_col = col-1;
	          foundFinish = true;
               }
	    }
         }
      }
      i++;
   }
   
   i--;
   
   if( foundFinish )
   {
      while( i > 0 )
      {
         if( text[cur_row-1][cur_col] == i )
         {
            maze[cur_row-2][cur_col-1] = '.';
            cur_row--;
         }
         else if( text[cur_row][cur_col+1] == i )
         {
            maze[cur_row-1][cur_col] = '.';
            cur_col++;
         }
         else if( text[cur_row+1][cur_col] == i )
         {
            maze[cur_row][cur_col-1] = '.';
            cur_row++;
         }
         else if( text[cur_row][cur_col-1] == i )
         {
            maze[cur_row-1][cur_col-2] = '.';
            cur_col--;
         }
         length++;
         i--;
      }
   }
      
   return foundFinish;
}

void printMaze( char maze[][MAX_COL], int nrow, int ncol )
{
   for( int row = 0; row < nrow; row++ )
   {
      for( int col = 0; col < ncol; col++ )
      {
         cout << maze[row][col];
      }
      cout << endl;
   }
}

void convert( char maze[][MAX_COL], int text[][MAX_COL + 2], int nrow, int ncol )
{
   for( int row = 1; row <= nrow; row++ )
   {
      //left edge of invisible border
      text[row][0] = OBSTACLE;
      //actual maze
      for( int col = 1; col <= ncol; col++ )
      {
         switch( maze[row-1][col-1] )
         {
            case 'S': text[row][col] = START;
               break;
            case 'X': text[row][col] = OBSTACLE;
               break;
            case ' ': text[row][col] = PATH;
               break;
            case 'F': text[row][col] = FINISH;
               break;
         }
      }
      //right edge of invisible border
      text[row][ncol+1] = OBSTACLE;
   }
   //top and bottom edge of invisible border
   for( int col = 0; col < ncol + 2; col++ )
   {
      text[0][col] = OBSTACLE;
      text[nrow+1][col] = OBSTACLE;
   }
}

