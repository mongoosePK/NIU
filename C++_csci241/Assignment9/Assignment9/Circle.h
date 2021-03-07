#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
extern const double PI;
class Circle : public Shape //derived class 
{
private:
	int radius;
public:
	//constructor
	Circle(const string& color, const int radius);
	virtual ~Circle();
	virtual void print() const;
	virtual double
		
};

#endif