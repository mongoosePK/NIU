/*************************************************
// William Pulkownik
// z-1805341
// csci_241_01
// Rectangle.cpp
// implements the derived rectangle class
// DUE::29NOV2016
*************************************************/
#include "Rectangle.h"
// constructor similar to circle's 
Rectangle::Rectangle(const std::string& colorArg, const int hv, const int wv)
	: Shape(colorArg)
{
	height = hv;
	width = wv;
}
// virtual ~Destructor
Rectangle::~Rectangle() {}
	
// print() calls base print and adds rectangle details
void Rectangle::print() const
{
	Shape::print();
	cout << "rectangle, height " << height << ", width " << width << ", area "
		<< get_area() << std::endl;
}
// get_area() returns the area as double
double Rectangle::get_area() const
{
	return height*width;
}