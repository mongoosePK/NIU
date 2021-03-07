//********************************************
//AUTHOR: William Pulkownik
//DUE DATE: 13 OCT 2016
//CSCI 241-001
//Vector3.cpp
//This file implements the vector class
//********************************************

#include "Vector3.h"


// Constructors in class definition


// stream insertion overload[takes an  lvaue ostreasm object, rval vector3]
ostream& operator<<(ostream& out, const Vector3& v) 
{
	out << "(" << v[0] << "," << v[1] << "," << v[2] << ")";
	return out;
}
//Addition and subtraction [takes 2 vector3 objects]
Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
//multiplication(x 3) [first takes 2 vector3 objects, the other two
//use one vector3 and one constant floating point number ]
double operator*(const Vector3& v1, const Vector3& v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

Vector3 operator*(const Vector3& v1, const float k)
{
	return Vector3(v1[0] * k, v1[1] * k, v1[2] * k);
}

Vector3 operator*(const float k, const Vector3& v1)
{
	return Vector3(k * v1[0], k * v1[1], k * v1[2]);
}

//boolean == comparison overload. [takes two Vector3 objects and performs comparison
//returns TRUE if comparison successful, FALSE if any subscripts do not match]
bool operator==(const Vector3& v1, const Vector3& v2)
{
	return (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2]);
}