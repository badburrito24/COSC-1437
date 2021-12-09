//include the proper header file
#include "Circle.h"
#include "Cylinder.h"

Cylinder::Cylinder()
{
}


float Cylinder::getHeight()
{
   return height;
}

void Cylinder::setHeight(float _h)
{
   height = _h;
}


// Implement the other member functions

// constructor with four parameters
Cylinder::Cylinder(float x, float y, float _radius, float _height) : Circle(x,y,_radius){
   height = _height;
}

// override compArea()
void Cylinder::compArea(){
   setArea((2 * 3.14 * height * radius + 2 * 3.14 * radius * radius));
}

// override printArea()
void Cylinder::printArea(){
   cout << fixed << setprecision(2) << "The area of the cylinder is " << getArea() << endl;
}