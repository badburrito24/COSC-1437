#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
using namespace std;

class Triangle: public Shape{
  public:
    Triangle(int side);
    int getSide();
    void setSide(int side);
    void setCenter(float x, float y);
    void draw();
    
  private:
    int side;
    
};
#endif