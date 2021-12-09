#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(){
  base = 0;
  height = 0;
}

Square::Square(int b, int h) : base(b), height(h) { }

void Square::setBase(int b){
  base = b;
}

void Square::setHeight(int h){
  height = h;
}

void Square::calculateArea(){
  // calculate Area correctly depending on shape type
  area = base * height;
}

int Square::getBase() const{
  return base;
}

int Square::getHeight() const{
  return height;
}

double Square::getArea() const{
  return area;
}
// Overloaded << operator
ostream& operator << (ostream& OD, const Square& square){
    OD << "Square Object:" << endl;
    OD << "Base: " << square.getBase() << endl;
    OD << "Height: " << square.getHeight() << endl;
    OD << "Area is: " << square.getArea();
   return OD;
}
// Overloaded >> operator
istream& operator >> (istream& IS, Square& square){
   IS >> square.base;
   IS >> square.height;
   square.calculateArea();
   return IS;
}