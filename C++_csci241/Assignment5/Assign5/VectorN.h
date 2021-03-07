/***********************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER: William Pulkownik
LOGON ID:   z-1805341
DUE DATE:   25 Oct 2016
VectorN.h
FUNCTION:   This program defines the VectorN
class. 
***********************************************************************/

#ifndef VECTORN_H
#define VECTORN_H

#include <iostream>
#include <stdexcept>
#include <stdexcept>
#include <algorithm>

using namespace std;

class VectorN {
//creating friend statements for standalone functions in the class .cpp file
	friend ostream& operator<<(ostream&, const VectorN&);
	friend VectorN operator+(const VectorN&, const VectorN&);
	friend VectorN operator-(const VectorN&, const VectorN&);
	friend double operator*(const VectorN&, const VectorN&);
	friend VectorN operator*(const double k, const VectorN&);
	friend VectorN operator*(const VectorN&, const double k);
	friend bool operator==(const VectorN&, const VectorN&);
private:
	double* varray; //pointer to array of double
	size_t vcap;     //vectorCapacity
	size_t vsize;    //vectorSize
public:
	VectorN();
	VectorN(const double[], size_t);
	VectorN(const VectorN& other);
	~VectorN();
	void clear();
	size_t size() const;
	double operator [] (int index) const //reads subscript
	{
		return varray[index];
	}
	double& operator [] (int index) //write subscript
	{
		return varray[index];
	}
	VectorN& operator=(const VectorN& other);
//at() functs to read and write subscripts w/ error handlng
	double at(int sub) const;
	double& at(int sub);
};
#endif 

