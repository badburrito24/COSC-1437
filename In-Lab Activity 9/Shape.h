#ifndef SHAPE_H
#define SHAPE_H
using namespace std;

class Shape{
  public:
    Shape();
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
    //setCenter(float x, float y);
    virtual void setCenter(float x, float y);
    //draw();
    virtual void draw();

  private:
    float center_x;
    float center_y;
};

#endif