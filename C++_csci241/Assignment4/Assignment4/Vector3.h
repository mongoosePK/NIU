//********************************************
//AUTHOR: William Pulkownik
//DUE DATE: 13 OCT 2016
//CSCI 241-001
//Vector3.h
//This file defines the vector class
//********************************************

#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
using namespace std;

class Vector3 {
	// friend functions to allow sharing of private data
	friend ostream& operator<<(ostream&, const Vector3&);
	friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
	friend double operator*(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator*(const Vector3& v1, const float k);
	friend Vector3 operator*(const float k, const Vector3& v1);
	friend bool operator==(const Vector3& v1, const Vector3& v2);
private:
	double vector[3];
public:
	//constructor [provides default values]
	Vector3(double x = 0.0, double y = 0.0, double z = 0.0)
	{
		vector[0] = x;
		vector[1] = y;
		vector[2] = z;

	}
	double operator [] (int index) const //reading subscripts
	{
		return vector[index];
	}
	double& operator [] (int index) // for writing
	{
		return vector[index];
	}
	
};
#endif

