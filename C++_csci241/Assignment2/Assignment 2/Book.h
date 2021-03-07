//*****************************************************************
// FILE:      Book.h
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   Contains the declaration for the Book class and its data members.
//*****************************************************************
#ifndef BOOK_H
#define BOOK_H

#include <iomanip>
#include <iostream> 
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
class Book
{
private:	
	char ISBN[11]{};
	char title[41]{};
	double price = 0.0;
	int quant = 0;
public:
	//constructors/destructor
	Book();
	Book(char*, char*, double, int);
	~Book();
	//setters
	void setISBN(char*);
	void setTitle(char*);
	void setPrice(double);
	void setQuant(int);
	//getters 
	const char* getISBN() const;
	const char* getTitle() const;
	double getPrice();
	int getQuant();
	void print();
	int fulfillOrder(int);
	
};
#endif