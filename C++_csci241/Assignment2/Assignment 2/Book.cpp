//*****************************************************************
// FILE:      Book.cpp
// AUTHOR:    William Pulkownik
// LOGON ID:  z-1805341
// DUE DATE:  16 Sep 2016
// 
// PURPOSE:   Contains the implementation of the Book class and its data members.
//*****************************************************************

#include "Book.h"

Book::Book()
{
	
}
Book::Book(char* is, char* ti, double pr, int qu)
{
	strcpy(ISBN, is);
	strcpy(title, ti);
	setPrice(pr);
	setQuant(qu);
}
Book::~Book() { }

//mutators
void Book::setISBN(char* is)
{
	strcpy(ISBN, is);	
}
void Book::setTitle(char* ti)
{
	strcpy(title, ti);	
}
void Book::setPrice(double pr)
{
	price = (pr < 0.0) ? 0.0 : pr;
}
void Book::setQuant(int qu)
{
	if (qu >= 0)
		quant = qu;
	else if (qu < 0)
		quant = 0;
}
//getters
const char* Book::getISBN() const
{
	return ISBN;
}
const char* Book::getTitle() const
{
	return title;
}
double Book::getPrice()
{
	return price;
}
int Book::getQuant()
{
	return quant;
}
//takes an interger order#, verifies availablity, ships if available
int Book::fulfillOrder(int ord)
{
	int shipped;
	if (ord < 0) {
		shipped = 0;
	}
	else if (ord <= quant) {
		shipped = ord;
		quant -= shipped;
	}
	else {
		shipped = quant;
		quant = 0;
	}
	return shipped;
}
//prints book details
void Book::print()
{
	cout << left << setw(14) << getISBN() << setw(44) << getTitle() << right << \
		fixed << setprecision(2) <<  setw(5) << getPrice() << setw(6) <<\
		getQuant() << endl;
}