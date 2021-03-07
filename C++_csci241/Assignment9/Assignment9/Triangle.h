#ifndef TRIANGLE_H
#define TRIANGLE_H
/*************************************************
// William Pulkownik
// z-1805341
// csci_241_01
// triangle.h
// defines and implements the derived triangle class
// This serves as BOTH .H AND .CPP for triangle 
// DUE::29NOV2016
*************************************************/
#include "Shape.h"
class Triangle : public Shape
{
private:
	int height; // private data members
	int base;
public:
	// inline constructor calls base constructor for color assigns values 
	// default values 0 For EZ debug if broken
	Triangle(const std::string& colorArg, const int hv = 0, const int bv = 0)
		: Shape(colorArg), height(hv), base(bv)	{}
	// inline virtual destructor 
	virtual ~Triangle() {}
	// inline virtual print method
	virtual void print() const
	{
		Shape::print();
		cout << "triangle, height " << height << ", base " << base << ", area "
			<< get_area() << std::endl;
	}
	//inline virtual get_area function returns area of triangle as double
	virtual double get_area() const { return 0.5*base*height; }
};
#endif // !TRIANGLE_H