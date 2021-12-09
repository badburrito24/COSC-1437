#include <iostream>
#include "Triangle.h"
using namespace std;

//Constructor
Triangle::Triangle(int s){
   side = s;
}

void Triangle::setSide(int s){
  side = s;
}

int Triangle::getSide(){
  return side;
}

//setCenter(float x, float y) 
void Triangle::setCenter(float x, float y){
    setX(x);
    setY(y);
   cout << "Triangle moved to [" << getX() << ", " << getY() << "]" << endl;
}

//draw()
void Triangle::draw(){
   cout << "Drawing Triangle at [" << getX() << ", " << getY() << "]" << endl;
   for(int i = 1; i <= side; i++){
      
     for(int j = 1; j <= i; j++){
        cout << "*";
     }
     cout << endl;
   }
}
        
