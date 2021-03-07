/**************************
// William Pulkownik
// z-1805341
// csci_241_01
// Main.cpp
// use <vectors> to store pointers to shape derived objects
// further manipulation of said objects
// DUE::29NOV2016
**************************/
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
//source files
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

extern const double PI;
const double PI = 3.14159;
using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	cout << fixed << setprecision(2);
	vector<Shape*> shapes(7);
	string colors[7] = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" };
	//loop through and create 7 shapes 
	for (int i = 0; i < 7; ++i)
	{
		(i < 2) ? (shapes[i] = (new Circle(colors[i], i)))
			: ((i < 4) ? (shapes[i] = new Rectangle(colors[i], i + 2, i + 3))
				: (shapes[i] = new Triangle(colors[i], i + 3, i + 1)));
	}
	cout << "Printing all shapes...\n"; //print all shapes
	for (unsigned int i = 0; i < shapes.size(); ++i) 
		shapes[i]->print();
	cout << endl;
	
	cout << "Printing only triangles...\n";
	for (unsigned int i = 0; i < shapes.size(); ++i) //print triangles
	{
		// downcast pointer
		Triangle* tri = dynamic_cast<Triangle *>(shapes[i]);
		if (tri != nullptr) { tri->print(); } //print if triangle
	}
	// loop through and delete shapes
	for (unsigned int i = 0; i < shapes.size(); ++i)
		delete shapes[i];

	return 0;
}