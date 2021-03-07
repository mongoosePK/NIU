//*****************************************************************
// FILE:      assign2.cpp
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   tests/debug/use Book class and its data members.
//*****************************************************************

#include "Book.h"
using namespace std;
int main()
{
	char isbn1[11] = "1111111111";
	char title1[41] = "Learn C++ Now";
	char isbn2[11] = "2222222222";
	char title2[41] = "Learn Java Later";
	int numShipped;

	Book book1;

	Book book2(isbn1, title1, 39.99, 5);

	// Test data validation
	Book book3(isbn2, title2, -22.99, -6);

	// Test print() method and whether constructors
	// properly initialized objects
	cout << "Printing book1\n\n";
	book1.print();
	cout << endl << endl;

	cout << "Printing book2\n\n";
	book2.print();
	cout << endl << endl;

	cout << "Printing book3\n\n";
	book3.print();
	cout << endl << endl;

	// Test accessor methods
	cout << book2.getISBN() << endl;
	cout << book2.getTitle() << endl;
	cout << book2.getPrice() << endl;
	cout << book2.getQuant() << endl;

	// Test the fulfillOrder() method
	numShipped = book2.fulfillOrder(-5);
	cout << "\nShipped " << numShipped << endl;
	cout << "Quantity now " << book2.getQuant() << endl;

	numShipped = book2.fulfillOrder(3);
	cout << "Shipped " << numShipped << endl;
	cout << "Quantity now " << book2.getQuant() << endl;

	numShipped = book2.fulfillOrder(4);
	cout << "Shipped " << numShipped << endl;
	cout << "Quantity now " << book2.getQuant() << endl;

	return 0;
}