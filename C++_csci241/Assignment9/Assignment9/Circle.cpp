/**************************
// William Pulkownik
// z-1805341
// csci_241_01
// Circle.cpp
// implements the derived circle class
// DUE::29NOV2016
**************************/

#include "Circle.h"


#include <iostream> //includes for 
#include <string>  // viewing pleasure

using std::string;
using std::endl;
using std::cout;
extern const double PI;//PI defined in main
//constructor which calls base class constructor for color
Circle::Circle(const string& colorArg, const int radiusArg) 
	: Shape(colorArg)
{
	radius = radiusArg;	
}
// virtual ~Destructor
Circle::~Circle() {}
// print() calls base print and adds circle data details
void Circle::print() const
{
	Shape::print();
	cout << "circle, radius " << radius << ", area " << get_area() << endl;
}
// get_area should calculate just that
double Circle::get_area() const
{
	return radius*radius*PI;
}