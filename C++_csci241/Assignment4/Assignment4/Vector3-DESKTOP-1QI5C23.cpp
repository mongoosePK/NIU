//********************************************
//AUTHOR: William Pulkownik
//DUE DATE: 13 OCT 2016
//CSCI 241-001
//Vector3.cpp
//This file implements the vector class
//********************************************

#include "Vector3.h"


// Constructors in class definition


// stream insertion overload
ostream& operator<<(ostream& out, const Vector3& v) 
{
	out << "(" << v[0] << "," << v[1] << "," << v[2] << ")";
	return out;
}
//Addition and subtraction [these both take two Vector3 objects and use arithmetic]
Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
//multiplication and variants [function returning double multiplies vector elements
// the other two take one vector obj and multiply be a constant float]
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
// equality function [takes two vector objects and compares]
bool operator==(const Vector3& v1, const Vector3& v2)
{
	return (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2]);
}