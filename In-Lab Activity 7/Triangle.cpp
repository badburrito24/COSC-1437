#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(){
   base = 0;
   height = 0;
}

Triangle::Triangle(int b, int h) : base(b), height(h) { }

void Triangle::setBase(int b){
   base = b;
}

void Triangle::setHeight(int h){
   height = h;
}

void Triangle::calculateArea(){
  // calculate Area correctly depending on shape type
  area = 0.5 * base * height;
}

int Triangle::getBase() const{
  return base;
}

int Triangle::getHeight() const{
  return height;
}

double Triangle::getArea() const{
  return area;
}

// Overloaded << operator declaration
ostream& operator << (ostream & OD, const Triangle &triangle){
    OD << "Triangle Object:" << endl;
    OD << "Base: " << triangle.getBase() << endl;
    OD << "Height: " << triangle.getHeight() << endl;
    OD << "Area is: " << triangle.getArea() << endl;
   return OD;
}

// Overloaded >> operator declaration
istream& operator >> (istream & IS, Triangle &triangle){
   IS >> triangle.base;
   IS >> triangle.height;
   triangle.calculateArea();
   return IS;
}