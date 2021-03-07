#ifndef RECTANGLE_H
#define RECTANGLE_H
/*************************************************
// William Pulkownik
// z-1805341
// csci_241_01
// Rectangle.h
// defines the derived rectangle class
// DUE::29NOV2016
*************************************************/
#include "Shape.h"
class Rectangle : public Shape
{
private:
	int height, width;

public:
	Rectangle(const std::string&, const int hv, const int wv);
	virtual ~Rectangle();
	virtual void print() const;
	virtual double get_area() const;
};
#endif