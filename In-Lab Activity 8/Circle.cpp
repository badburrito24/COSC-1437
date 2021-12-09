// include the proper header file
#include "Circle.h"
#include <iostream>

Circle::Circle()
{
}

float Circle::getRadius()
{
   return radius;
}

void Circle::setRadius(float _r)
{
   radius = _r;
}

// provide the implementation of the other member functions of Circle below

// Constructor with three parameters
Circle::Circle(float x, float y, float _radius) : Shape(x,y){
   radius = _radius;
}

// compArea()
void Circle::compArea(){
   setArea(3.14*radius*radius);
}


// printArea()
void Circle::printArea(){
   cout << fixed << setprecision(2)<< "The area of the circle is " << getArea() << endl;
}
   
   
   