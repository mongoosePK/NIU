
//*****************************************************************
// FILE:      BookStore.h
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   Contains the declaration for the BookStore class and its data members.
//************
#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "Book.h"
class BookStore
{
private:	
	Book books[30];
	int act; 

public:
	BookStore();
	BookStore(const char *);
	~BookStore();
	void print();
	void sortByISBN();
	int searchForISBN(const char* );
	void processOrders(const char*);
};


#endif