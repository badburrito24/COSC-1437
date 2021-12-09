#include <iostream>
#include "Shape.h"
using namespace std;

Shape::Shape(){
  center_x = 0;
  center_y = 0;
}

void Shape::setX(float x){
  center_x = x;
}

void Shape::setY(float y){
  center_y = y;
}

float Shape::getX(){
  return center_x;
}

float Shape::getY(){
  return center_y;
}


//setCenter(float x, float y) 
void Shape::setCenter(float x, float y){
 center_x = x;
 center_y = y;
 cout << "Figure moved to [" << getX() << ", " << getY() << "]" << endl;
}

//draw()
void Shape::draw(){
cout << "Drawing figure at [" << getX() << ", " << getY() << "]" << endl;
}

