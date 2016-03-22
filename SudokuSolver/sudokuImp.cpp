/**	COP 3530
**	Data Structures and Algorithms
**	Problem 1: Sudoku Solver
**	Authors:	Pete Lazano
**				Adam Seevers
**	March 20th 2016
**/

#include <iostream>
#include "sudoku.h"

using namespace std;

sudoku::sudoku()
{
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
			grid[row][col] = 0;
		
}

sudoku::sudoku(int g[][9])
{
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
			grid[row][col] = g[row][col];
}

void sudoku::initializeSudokuGrid()
{
	int userinput;
	bool valid = false;
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
		{
			do
			{
				cout << "Enter the number for grid slot: " << row << ", " << col << endl;
				cin >> userinput;
				if (userinput < 10 && userinput > 0)
				{
					valid = true;
				}
				else
				{
					valid = false;
					cout << "Input not valid: " << endl;
				}
			} while (!valid);
		}
}

void sudoku::initializeSudokuGrid(int g[][9])
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			grid[row][col] = g[row][col];
		}
	}
}

//prints the current sudoku grid by iterating through each row and column
void sudoku::printSudokuGrid()
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
			cout << '[' << grid[row][col] << ']';
		cout << endl;
	}
}

//backtracking algorithm that finds the next empty slot then inputs a valid number as long as it solves the sudoku
//otherwise it back tracks until it finds a path that is valid or returns the same grid if no solution exists
bool sudoku::solveSudoku()
{
	int row, col;

	if (findEmptyGridSlot(row, col))
	{
		for (int num = 1; num <= 9; num++)
		{
			if (canPlaceNum(row, col, num))
			{
				grid[row][col] = num;
				if (solveSudoku()) //recursive call
					return true;
				grid[row][col] = 0; //backtrack
			}
		}
		return false;
	}
	else
		return true; //there are no empty slots
}

//iterates through the sudoku to find the next empty spot to insert a number from the solver algorithm
bool sudoku::findEmptyGridSlot(int &row, int &col)
{
	row = 0, col = 0;
	while (row < 9)
	{
		while (col < 9)
		{
			if (grid[row][col] == 0)
			{
				return true;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return false;
}

//checks to see if the current number can be placed at current location
bool sudoku::canPlaceNum(int row, int col, int num)
{
	if (!numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) && !numAlreadyInBox(row / 3, col / 3, num))
	{
		return true;
	}
	return false;
}

//iterates through the current row to check if current number is already in the row
bool sudoku::numAlreadyInRow(int row, int num)
{
	for (int col = 0; col < 9; col++)
	{
		if (grid[row][col] == num)
			return true;
	}
	return false;
}

//iterates through the columns to check if the number is already in the current column
bool sudoku::numAlreadyInCol(int col, int num)
{
	for (int row = 0; row < 9; row++)
	{
		if (grid[row][col] == num)
			return true;
	}
	return false;
}

//check to see if the current location already has the number in it
bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol,
	int num)
{
	for (int row = smallGridRow * 3; row < smallGridRow * 3 + 3; row++)
	{
		for (int col = smallGridCol * 3; col < smallGridCol * 3 + 3; col++)
		{
			if (grid[row][col] == num)
				return true;
		}
	}
	return false;
}


