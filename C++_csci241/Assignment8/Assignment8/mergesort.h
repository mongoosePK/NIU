/*********************************************************************
PROGRAM:    CSCI 241 mergesort.h
PROGRAMMER: William Pulkownik
LOGON ID:   z-1805341
DUE DATE:   17 NOV 2016

FUNCTION:   This program defines list build and print functions
*********************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using std::vector;
// merge() merges two sorted subvectors and returns nothing
// it takes
// vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool(*compare)(const T&, const T&))
{
	// Create temporary vector to hold merged subvectors
	vector<T> temp(high - low + 1);

	int i = low; //subscript for start of left unsorted vector
	int j = mid + 1; // subscript for right unsorted vector
	int k = 0; // subscript for start of merged vector

	// while not at the end of either subvector
	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
		{
			temp[k] = set[j];
			j++;
			k++;
		}
		else
		{
			temp[k] = set[i];
			i++;
			k++;
		}
	}
	// copy over any remaining elements of the left subvector
	while (i <= mid)
	{
		temp[k] = set[i];
		i++; 
		k++; 
	}
	
	// copy over any remaining elements of the right subvector
	while (j <= high)
	{
		temp[k] = set[j];
		j++;
		k++;
	}
	// copy merged elements into original vector
	for (i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i];
}

// this recursive function divides a vector in to two subvectors, sorts them, and
// then merges them.
// it takes a vector template, ints for hi and lo, and a pointer to a comparison func()
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool(*compare)(const T&, const T&))
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		//divide and conquer
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid + 1, high, compare);
		//combine
		merge(set, low, mid, high, compare);
	}
}
// this mergeSort() takes the set that needs sorting and the comparison function
// that will be used. it passes these to the recursive mergeSort()
template <class T>
void mergeSort(vector<T>& set, bool(*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size() - 1, compare);
}

#endif
