
//*****************************************************************
// FILE:      BookStore.cpp
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   Contains the implementation for the Bookstore class and its data members.
//************
#include "BookStore.h"
//default constructor

BookStore::BookStore()
{
	int act;

}
//
BookStore::BookStore(const char* fname)
{
	int act;
	ifstream inFile;
	inFile.open(fname, ios::binary);
	
	if (inFile.fail())
	{
		cout << "won't open\n";
		exit(-1);
	}
	
	inFile.read((char*) this, sizeof(BookStore));
	inFile.close();
	sortByISBN();
}
BookStore::~BookStore() {}
// sorts book objects in store by ISBN #

void BookStore::sortByISBN()
{
	int i, j;
	Book ibook;
	for (i = 1; i < act; i++)
	{
		ibook = books[i];

		for (j = i; (j > 0) && (strcmp(books[j - 1].getISBN(), ibook.getISBN()) > 0); j--)
			books[j] = books[j - 1];

		books[j] = ibook;
	}
}
// accepts a character array and finds among array of objects
int BookStore::searchForISBN(const char* searchISBN)
{
	int low = 0;
	int high = (act - 1);
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (strcmp(searchISBN, books[mid].getISBN()) == 0)
			return mid;
		else if (strcmp(searchISBN, books[mid].getISBN()) < 0)
			high = (mid - 1);
		else
			low = (mid + 1);
	}
		return -1;
}
//processOrders takes a txt file and reads order data, calls sort/search
//with that data, and if valid fulfills the order.
void BookStore::processOrders(const char* ordFile)
{
	ifstream iFile;
	char orderNumber[7];
	char isbn[11];
	int orderQuantity;
	int numShipped;

	iFile.open(ordFile);
	if (iFile.fail())
	{
		cout << "won't open\n";
		exit(-1);
	}
	iFile >> orderNumber;
	cout << "Order Listing\n" << endl;
	
	while (iFile)
	{
		iFile >> isbn;
		iFile >> orderQuantity;

		int index = searchForISBN(isbn);
		if (index == -1)
		{
			cout << "Order #" << orderNumber << ": ISBN " << isbn << \
				" Not Available\n";
		}
		else
		{
			numShipped = books[index].fulfillOrder(orderQuantity);

			cout << "Order #" << orderNumber << ": ISBN " << isbn << ", " << \
				numShipped << " of " << orderQuantity << \
				", order total: $" << fixed << setprecision(2) << \
				(numShipped * books[index].getPrice()) << endl;
		}
		iFile >> orderNumber;
	}
	iFile.close();
}
//prints book data
void BookStore::print()
{
	int reps = 0;
	int size = (sizeof(books) / sizeof(books[0]));
	cout << "Book inventory listing\n"<< endl;
	cout << left << setw(14) << "ISBN" << setw(44) << "Title" << right << \
		setw(5) << "Price" << setw(6) << "Qty." << endl << endl;
	for (int i = 0; i < size; i++)
	{
		if (books[i].getPrice() > 0)
		{
			books[i].print();
			reps++;
		}
	}
}