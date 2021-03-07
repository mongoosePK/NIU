/*********************************************************************
PROGRAM:    CSCI 241 sorts.h
PROGRAMMER: William Pulkownik
LOGON ID:   z-1805341
DUE DATE:   17 NOV 2016

FUNCTION:   This program defines list build and print functions
*********************************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <fstream>
using std::ifstream;
using std::endl;
using std::cout;
using std::vector;
using std::setw;

// buildList() takes a template vector and a filename 
// it creates a vector of template items according to type
template <class T> void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;
	inFile.open(fileName);
	if (!inFile)
	{
		cout << "Unable to open input file " << fileName << endl;
		exit(1);
	}
	inFile >> item;
	while (inFile)
	{
		set.push_back(item);
		inFile >> item;
	}
	inFile.close();
}
// printList accepts a reference to a vector obj, an int for the width of each
// items ostream column, and an int limiting the number displayed on each line.
// printList displays items in the vector and returns nothing 
template <class T> 
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int i = 0;
	while (i < (int)set.size())
	{
		cout << setw(itemWidth) << set[i] << ' ';
		i++;
		if (i % numPerLine == 0)
			cout << endl;
	}
	if (i % numPerLine != 0)
		cout << endl;
}
// lessThan func returns true if item 1 is less than item 2.
template <class T> bool lessThan(const T& item1, const T& item2)
{
	//return (item1 < item2);
	if (item1 < item2)
		return true;
	else
		return false;
}

// greaterThan func returns true if item 1 is greater than item 2.
template <class T> bool greaterThan(const T& item1, const T& item2)
{
	return (item1 > item2);
}


#endif
