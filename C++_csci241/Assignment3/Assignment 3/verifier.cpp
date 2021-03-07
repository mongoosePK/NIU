/*********************************************************************
PROGRAM:    CSCI 241 Assignment 3
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:  4 Oct 2016

FUNCTION:   This program implements the Verifier
class.
*********************************************************************/

#include "verifier.h"
//default constructor and constructor with file
Verifier::Verifier()
{
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++)
			grid[r][c] = 0;
	}
}
void Verifier::readGrid(const char* fname)
{
	ifstream inFile;
	
	inFile.open(fname); //, ios::in);
	if (inFile.fail())
	{
		cout << "won't open\n";
		exit(-1);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			inFile >> grid[i][j];
	}
	
	inFile.close();
}
//print method for grids
void Verifier::printGrid()
{
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			cout << grid[r][c] << " ";
		}
		cout << endl;
	}
}
//verifier
bool Verifier::verifySolution()
{
	
	
	//check rows
	for (int r = 0; r < 9; r++) {
		
		int row[9];
		for (int c = 0; c < 9; c++) 
			row[c] = grid[r][c];
		int* end = row + 9;
		std::sort(row, end);
		bool hasDupe = (std::unique(row, end) != end);
		return !(hasDupe);
		
	}
	//check columns
	for (int c = 0; c < 9; c++){
		int col[9];
		for (int r = 0; r < 9; r++)
			col[r] = grid[r][c];
		int* end = col + 9;
		std::sort(col, end);
		bool hasDupe = (std::unique(col, end) != end);
		return !(hasDupe);
	}

	//check sub-grids
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int sub[9];

			for (int r = i * 3; r < i * 3 + 3; r++) {
				for (int c = j * 3; c < j * 3 + 3; c++)
					sub[c] = grid[r][c];
			}
			int* end = sub + 9;
			std::sort(sub, end);
			bool hasDupe = (std::unique(sub, end) != end);
			return !(hasDupe);
		}
	}
	bool hasDupe = true;
	return hasDupe;
}
	