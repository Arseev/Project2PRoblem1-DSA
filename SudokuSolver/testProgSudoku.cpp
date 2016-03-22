/**	COP 3530
**	Data Structures and Algorithms
**	Problem 1: Sudoku Solver
**	Authors:	Pete Lazano
**				Adam Seevers
**	March 20th 2016
**/

#include <iostream>
#include <cmath>
#include "sudoku.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//declare variables used for sudoku algorithm in main
	int currentProblem = 1;
	string nextProblem;
	string holdOpen;

	//open input stream to grab the sudoku problems from a file
	ifstream myfile;
	myfile.open("sudokuProblems.txt");

	//run through all the sudokus in the file
	while (myfile && currentProblem < 5)
	{
		//input the numbers for each sudoku box into the grid to be evaluated by sudoku solving algorithm
		int myarray[9][9];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				//grabs each number from the sudoku and puts into the next grid until the current 9x9 grid is full
				myarray[i][j] = (int)myfile.get() - 48; //(i + j + 1) % 9;
			}
		}

		
		//give myGrid datatype of sudoku
		sudoku myGrid(myarray);

		//prints the grid before its run through the solving algorithm
		cout << "Problem #" << currentProblem << " before Soduku solver" << endl;
		myGrid.printSudokuGrid();
		cout << endl;
		
		//pass the sudoku into solving algorithm
		myGrid.solveSudoku();

		//print the name of solved sudoku
		cout << "Problem #" << currentProblem << " after Soduku solver" << endl;

		//checks to see if there wasn't a solution for the problem
		if (!myGrid.solveSudoku())
		{
			cout << "There is not a solution for this problem!" << endl;
		}

		//print the solved sudoku
		myGrid.printSudokuGrid();
		
		//if the two sudokus are the same before and after, then there is not solution for the sudoku
		cout << endl;

		//get the next sudoku problem to fill into the grid
		getline(myfile, nextProblem);

		//keep track of which problem the program is currently on
		currentProblem++;
	}
	//close input stream
	myfile.close();

	//keep the program open to view results
	cin >> holdOpen;

	//end program successfully
	return 0;
}
