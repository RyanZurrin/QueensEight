#include <iostream>
//#include "Queens8Solver.h"

const int SIZE = 8;



/// <summary>
/// a structure holding all the methods and variables needed to solve the queens
/// eight puzzle.
/// </summary>
struct QueensEight
{

	QueensEight();
	bool isValid(int r, int c);
	void queens8(int c);
	void printBoard();
	char board[SIZE][SIZE];
	int solutions;
	int moves;
};

int main()
{
	QueensEight solver;
	solver.queens8(0);
	return  0;
}

/// <summary>
/// Initializes a new instance of the <see cref="QueensEight"/> struct.
/// </summary>
QueensEight::QueensEight()
{
	solutions = 0;
	moves = 0;
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			board[r][c] = '*';
		}
	}
}//end no argument constructor

/// <summary>
/// Determines whether the specified move is indeed valid by checking that there
/// is no queen in the row and then both diagonal directions. And if all is
/// safe it returns true. columns do not need to be checked because the only way
/// it gets to a col is by a recursive call that adds one to the previous col.
/// <param name="row">The row.</param>
/// <param name="col">The col.</param>
/// <returns>
///   <c>true</c> if the specified arr is valid; otherwise, <c>false</c>.
/// </returns>
bool QueensEight::isValid(int row, int col)
{
	int r,c;
	// checking to see if there is already a queen in the column and if so
	// returning false
	c = 0;
	while (c < col)
	{
		if (board[row][c] != '*') {
			return false;
		}
		c++;
	}
	r = row;
	c = col;
	// checking the diagonal back and down for a queen attacking and returning false
	// if there is. It does this by checking all the spaces in the previous columns
	// looking for a queen in one of the diagonals.
	while ( r < SIZE && c >= 0)
	{
		if (board[r][c] != '*') {
			return false;
		}
		r++;
		c--;
	}

	r = row;
	c = col;
	// checking the diagonal back and up and if there is a queen attacking
	// return false.
	while (r >= 0 && c >= 0)
	{
		if (board[r][c] != '*') {
			return false;
		}
		r--;
		c--;
	}
	return true;
}//end method isValid

/// <summary>
/// This is the recursive method to place the queens on the board col by col.
/// Once it gets to col 8 it prints the board and then will backtrack to find
/// additional solutions only ending when every single possible move has been
/// made. It will discover 92 separate solutions taking 1951 moves in total to
/// find them all.
/// </summary>
/// <param name="col">The col to place a queen on.</param>
void QueensEight::queens8(int col)
{
	int row = 0;
	//if it makes it to the col of SIZE it means its placed queens in all the
	// col from 0 - 7 and therefore has finished placing all queens so print
	// out the solution and work on the next
	if (col == SIZE)
	{
		solutions++;
		printBoard();
		return;
	}

	//a loop to make sure it goes and try each row in the col
	while (row < SIZE)
	{
		// if no two queens threaten each other is valid returns true and a
		//queen is placed in the position of (row,col).
		if (isValid(row, col))
		{
			// laying down the queen in her new home
			board[row][col] = 'Q';
			//counting the total moves
			moves++;
			// recursive call to find a position in the next col that is free
			queens8(col + 1);

			// this is where the backtrack takes place, if it gets here it means
			// its popped out of the queen8 call and needs to back up
			board[row][col] = '*';
		}
		row++;
	}
}//end method queen8

void QueensEight::printBoard()
{
	std::cout << std::endl;
	std::cout << "moves: "<< moves << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			std::cout << board[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << "Solution # " << solutions << std::endl;
}//end method printBoard