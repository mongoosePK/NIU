/*********************************************************************
PROGRAM:    CSCI 241 Assignment 3
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:   4 Oct 2016

FUNCTION:   This program tests the functionality of the Verifier
class.
*********************************************************************/

#include <iostream>
#include <string>
#include "verifier.h"

using std::cout;
using std::endl;
using std::string;

#define NUM_FILES 7

int main()
{
	Verifier v;
	string fileName;
	
	cout << "Sudoku Verifier\n";

	for (int i = 1; i <= NUM_FILES; i++)
	{
		cout << endl;

		// Construct file pathname
		fileName = string("C:\\Users\\wpulk\\OneDrive\\documents\\visual studio 2015\\Projects\\Assignment 3\\Assignment 3\\solution")
			+ (char)('0' + i) + ".txt";

		// Read the solution file as input
		v.readGrid(fileName.c_str());

		// Print the Sudoku grid
		v.printGrid();

		// Verify whether or not the solution is correct
		if (v.verifySolution())
			cout << "\nThis is a valid Sudoku solution\n";
		else
			cout << "\nThis is not a valid Sudoku solution\n";
	}
	v.printGrid();
	return 0;
}