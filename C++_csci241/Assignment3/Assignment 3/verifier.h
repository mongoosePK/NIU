/*********************************************************************
PROGRAM:    CSCI 241 Assignment 3
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:  4 Oct 2016

FUNCTION:   This program defines the Verifier
class.
*********************************************************************/
#ifndef VERIFIER_H
#define VERIFIER_H

//include libraries
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <fstream>
using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::ios;
//using namespace std;

const int rows = 9;
const int cols = 9;

class Verifier
{
private:
	int grid[9][9];

public:
	Verifier();
	Verifier(const char*);
	void readGrid(const char*);
	void printGrid();
	bool verifySolution();

};

#endif
