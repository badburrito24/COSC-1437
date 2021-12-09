#include <iostream>
#include "Rectangle.h"
using namespace std;

//Constructor
Rectangle::Rectangle(int b, int h){
   base = b;
   height = h;
}

void Rectangle::setBase(int b){
  base = b;
}

void Rectangle::setHeight(int h){
  height = h;
}

int Rectangle::getBase(){
  return base;
}

int Rectangle::getHeight(){
  return height;
}


//setCenter(float x, float y) 
void Rectangle::setCenter(float x, float y){
   setX(x);
   setY(y);
   cout << "Rectangle moved to [" << getX() << ", " << getY() << "]" << endl;
}
//draw()
void Rectangle::draw(){
   cout << "Drawing Rectangle at [" << getX() << ", " << getY() << "]" << endl;
   for(int i = 0; i < height; i++){
      for(int j = 0; j < base; j++){
          cout << "*";
      }
      cout << endl;
   }
}
         
         
   
