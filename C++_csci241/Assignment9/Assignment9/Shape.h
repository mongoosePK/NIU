#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
class Shape //generic abstract class for specific shapes
{
private:
	string color;

public:
	//constructor
	Shape(const string& color = "null") : color(color) {}
	//destructor
	virtual ~Shape()
	{
		cout << "Shape destructor called.\n";
	}
	// print method -> displays color
	virtual void print() const
	{
		cout << color << "\n";
	}
	// pure virtual area function 
	virtual double get_area() const {}
};

#endif
