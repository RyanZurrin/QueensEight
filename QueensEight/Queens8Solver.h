#pragma once
#include <stdlib.h>     /* srand, rand */
#include <time.h>

const int SIZE = 8;

class QueensEight
{
public:
	QueensEight();
	int isValid(char arr[SIZE][SIZE], int r, int c);
	void queens8(int c);
	void printArray();
	void printBoard(char b[SIZE][SIZE]);
	char board[SIZE][SIZE];


};

inline QueensEight::QueensEight()
{
	memset(board, '-', sizeof board);
}


inline int QueensEight::isValid(char arr[SIZE][SIZE], int row, int col)
{
	// return 0 if two queens share the same column
	for (int i = 0; i < row; i++)
	{
		if (arr[i][col] == 'Q') {
			return 0;
		}
	}

	// return 0 if two queens share the same `\` diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (arr[i][j] == 'Q') {
			return 0;
		}
	}

	// return 0 if two queens share the same `/` diagonal
	for (int i = row, j = col; i >= 0 && j < SIZE; i--, j++)
	{
		if (arr[i][j] == 'Q') {
			return 0;
		}
	}

	return 1;
}

inline void QueensEight::queens8(int row)
{
	// if `N` queens are placed successfully, print the solution
	if (row == SIZE)
	{
		printBoard(board);
		return;
	}

	// place queen at every square in the current row `r`
	// and recur for each valid movement
	for (int i = 0; i < SIZE; i++)
	{
		// if no two queens threaten each other
		if (isValid(board, row, i))
		{
			// place queen on the current square
			board[row][i] = 'Q';

			// recur for the next row
			queens8(row + 1);

			// backtrack and remove the queen from the current square
			board[row][i] = '-';
		}
	}
}

inline void QueensEight::printArray()
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			std::cout << board[i][j]<<" ";

		}
		std::cout << std::endl;
	}
}

inline void QueensEight::printBoard(char b[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
