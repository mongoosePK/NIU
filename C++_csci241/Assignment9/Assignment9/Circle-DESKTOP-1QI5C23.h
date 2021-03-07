#ifndef CIRCLE_H
#define CIRCLE_H
/*************************************************
// William Pulkownik
// z-1805341
// csci_241_01
// Circle.h
// defines the derived circle class
// DUE::29NOV2016
*************************************************/
#include "Shape.h"

class Circle : public Shape //derived class 
{
private:
	int radius;
public:
	//constructor
	Circle(const std::string&, const int );
	virtual ~Circle(); //destructor
	virtual void print() const; 
	virtual double get_area() const;
		
};

#endif