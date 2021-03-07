/*********************************************************************
PROGRAM:    CSCI 241 sorts.h
	PROGRAMMER : William Pulkownik
	LOGON ID : z - 1805341
	DUE DATE : 17 NOV 2016

	FUNCTION : This program defines list build and print functions
	*********************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using std::vector;
// partition() takes a 'set' object, its start and end points, and a comparison 
// function as arguments. this func sets a midpoint pivot value, then 
// partitions the vector around that pivot
template <class T>
int partition(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue;
	mid = (start + end) / 2;
	std::swap(set[start], set[mid]); //call vector swap to swap elements start and mid

	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		{
			pivotIndex++;
			std::swap(set[pivotIndex], set[scan]);
		}
	}
	std::swap(set[start], set[pivotIndex]);

	return pivotIndex;
}


// this quicksort version performs recursive calls to the quick sort algorithim
// it finds a pivot point and sorts around it by calling itself
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;
	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare); //get pivot point
		quickSort(set, start, pivotPoint - 1, compare);   // sort first sublist
		quickSort(set, pivotPoint + 1, end, compare); // sort second sublist
	}
}
// this quicksort version sorts items in vector 'set'. 1st arg is reference to 
//'set' 2nd arg is a pointer to a comparison funct and compares two template items
// this func calls the second quicksort function 
template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&))
{
	quickSort(set, 0, (int)set.size() - 1, compare);
}

#endif

