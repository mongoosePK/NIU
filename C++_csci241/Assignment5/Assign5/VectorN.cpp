/*********************************************************************
PROGRAM:    CSCI 241 Assignment 5
			VectorN.cpp
PROGRAMMER: William Pulkownik
LOGON ID:   z-1805341
DUE DATE:   25OCT 2016
FUNCTION:   This program implements the VectorN
class.
*********************************************************************/

#include "VectorN.h"
/***************************************************
Functs: Con/Destructors: Default, Alternate, Copy, Destruct
Use: Methods to instantiate new objects.
Parameters: Varry (see methods)
**********************************************/
//default constructor creates a VectorN object from no arguments 
//set size=0, varray=NULL
VectorN::VectorN()
{
	vcap = 0;
	varray = nullptr;
}
//Alt constructor creates a VectorN object from an array of doubles and sizet int
VectorN::VectorN(const double values[], size_t n)
{
	vcap = n;
	//ternary memory allocation of varray
	varray = (vcap > 0) ? new double[vcap] : nullptr;
	vsize = vcap;
	//copy arg array in to new array
	copy(values, values + vcap, varray);
	
}
//copy constructor create VectorN from another VectorN
VectorN::VectorN(const VectorN& other)
{
	vcap = other.vcap;
	vsize = other.vsize;
	varray = (vcap > 0) ? new double[vcap] : nullptr;
	//copy arg array in to new array
	copy(other.varray, other.varray + vcap, varray);
	
}
VectorN::~VectorN()
{
	clear();
}
/***************************************************
Functions: size() const / clear()
Use: create size variable from vcap / Deallocate VectorN
Returns: size_t vsize / clears data from existing VectorN
**********************************************/
size_t VectorN::size() const
{
	size_t vsize = vcap;
	return vsize;
}
void VectorN::clear()
{
	delete[] varray;
	varray = nullptr;
	vcap = 0;

}
/********************************************
operator<<: standalone overload of <<
Use: insert vectorN objects into the output stream
Parameters: ostream cout object, VectorN Object
Returns: output stream object of vector contents
*******************************************/

ostream& operator<<(ostream& out, const VectorN& v)
{
	if (v.vcap > 0)
	{
		out << "(" << v[0];
		for (size_t i = 1; i < v.vsize; i++) {
			out << ", " << v[i] ;
		}
		out << ")";
	}
	else
		out << "()";
	return out;
}
/********************************************
operator=: method overload of assignment operator
Use: assignt one VectorN obj to another
Parameters: VectorN object 
Returns: pointer to address of calling object
*******************************************/
VectorN& VectorN::operator=(const VectorN& other) //use copy statement?
{
	if (this != &other) //prevent self assignment
	{
		delete[] varray;
		vcap = other.vcap;
		vsize = other.vsize;
		if (vcap > 0)
			varray = new double[vcap];
		else
			varray = nullptr;
		for (size_t i = 0; i < vsize; ++i)
			varray[i] = other.varray[i];
	}
	return *this;
}
/********************************************
operator+: standalone overload of addition
Use: add VectorN type objects, limit size to smaller of 2
Parameters: 2 vectorN objects
Returns: A new vectorN object
notes: used min() to compare 2 vArrays & return smallest
		Using min() similarly in other aritmetic functions
*******************************************/
VectorN operator+(const VectorN& v1, const VectorN& v2)
//returning a VectorN object with arguments created from func parameters
{
	size_t cap = std::min(v1.vcap, v2.vcap);
	double* result = new double[cap];
	
	for (size_t i = 0; i < cap; ++i)
		result[i] = (v1[i] + v2[i]);
	
	return VectorN(result, cap);
}
/********************************************
operator-: standalone overload of subtraction
Use: subtract VectorN type objects.limit size
Parameters: 2 vectorN objects
Returns: A new vectorN object
*******************************************/
VectorN operator-(const VectorN& v1, const VectorN& v2)
{

	size_t cap = std::min(v1.vcap, v2.vcap);
	double* result = new double[cap];

	for (size_t i = 0; i < cap; ++i)
		result[i] = (v1[i] - v2[i]);
	
	return VectorN(result, cap);
}
/********************************************
operator*: standalone overload of scalar multiplication
Use: Multiply and add components of 2 vectors. limit size
Parameters: 2 vectorN objects
Returns: A new vectorN object
*******************************************/
double operator*(const VectorN& v1, const VectorN& v2)
{
	size_t cap = std::min(v1.vcap, v2.vcap);
	double result = 0;
	for (size_t i = 0; i < cap; ++i)
		result += (v1[i] * v2[i]);
	
	return result;
}
/********************************************
operator*(const, VecN): standalone overload of *
Use: multiply a constant by all elements of vArray.
Parameters: constant double, VectorN object.
Returns: new VectorN object.
*******************************************/
VectorN operator*(const double k, const VectorN& v)
{
	double* result = new double[v.vcap];
	for (size_t i = 0; i < v.vcap; i++)
		result[i] = v[i] * k;
	return VectorN(result, v.vcap);
}
/********************************************
operator*(const, VecN): standalone overload of *
Use: multiply all elements of vArray by a constant.
Parameters: VectorN object,constant double.
Returns: new VectorN object.
*******************************************/
VectorN operator*(const VectorN& v, const double k)
{
	double* result = new double[v.vcap];
	for (size_t i = 0; i < v.vcap; i++)
		result[i] = v[i] * k;
	return VectorN(result, v.vcap);
}
/********************************************
operator==: standalone overload of equality 
Use: determine if 2 VectorN objects equal
Parameters: 2 VectorN Objects
Returns: boolean true if both VectorN dataMembers equal
*******************************************/
bool operator==(const VectorN& v1, const VectorN& v2)
{
	if (v1.vcap != v2.vcap)
		return false;
	for (size_t i = 0; i < v1.vcap; i++) 
		if (v1[i] != v2[i]) return false;
	return true;	
}
/********************************************
double at() : read method of subscript with error checking
Use: throw orex exception is subscript invalid
Parameters: integer as subscript value
Returns: error message or array subscript values
*******************************************/
double VectorN::at(int sub) const
{
	if (sub < 0 || sub > vcap)
		throw out_of_range("subscript out of range");
	return varray[sub];
}
/********************************************
double& at() : write method of subscript with error checking
Use: throw orex exception is subscript invalid
Parameters: integer as subscript value
Returns: error message or array subscript values
*******************************************/
double& VectorN::at(int sub)
{
	if (sub < 0 || sub >= vsize)
		throw out_of_range("subscript out of range");
	return varray[sub];
}