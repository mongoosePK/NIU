//*****************************************************************
// FILE:      assign2.cpp
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   tests/debug/use Book class and its data members.
//*****************************************************************

#include "Book.h"
#include "BookStore.h"
using namespace std;
int main()
{	
	BookStore store1("bookdata");
	int act = (sizeof(BookStore) / sizeof(store1));
	store1.print();
	cout << endl;
	store1.processOrders("orders.txt");
	cout << endl;
	
	store1.print();
	return 0;
}