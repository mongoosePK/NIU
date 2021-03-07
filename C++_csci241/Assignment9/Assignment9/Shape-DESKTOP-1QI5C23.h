#ifndef SHAPE_H
#define SHAPE_H
/*************************************************
// William Pulkownik
// z-1805341
// csci_241_01
// shape.h
// defines and implements the abstract base class "Shape"
// this serves as BOTH .cpp AND .h for abstract shape class
// DUE::29NOV2016
*************************************************/
#include <string>
#include <iostream>

using std::cout;
class Shape //generic abstract class for specific shapes
{
private:
	std::string color;

public:
	//constructor
	Shape(const std::string& colorArgument = "null") : color(colorArgument) {}
	//destructor
	virtual ~Shape() {}
	// print method -> displays color
	virtual void print() const
	{
		cout << color << " ";
	}
	// pure virtual area function 
	virtual double get_area() const = 0;
};

#endif
