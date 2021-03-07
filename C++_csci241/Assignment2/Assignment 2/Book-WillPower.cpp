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
	//ISBN[11] = '0';
	//title[41] = ' ';
	//price = 0.0;
	//quant = 0;
}
Book::Book(char* is, char* ti, double pr, int qu)
{
	strcpy(ISBN, is);//ISBN[11] = is;
	strcpy(title, ti);//title = ti;
	price = pr;
	quant = qu;
}
Book::~Book() { }

//mutators
void Book::setISBN(char* is)
{
	strcpy(ISBN, is);	//ISBN = is;
}
void Book::setTitle(char* ti)
{
	strcpy(title, ti);	//title = ti;
}
void Book::setPrice(double pr)
{
	if (pr < 0.0)
		price = 0.0;
	else
		price = pr;
}
void Book::setQuant(int qu)
{
	if (qu >= 0)
		quant = qu;
	else
		quant = 0;
}
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

void Book::print()
{
	cout << left << setw(14) << getISBN() << right << setw(44) << title << \
		fixed << setprecision(2) << setw(5) << price << setw(6) << quant << endl;
}