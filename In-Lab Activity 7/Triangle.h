#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
using namespace std;

class Triangle {
public:
	Triangle();
	Triangle(int b, int h);
   
   //Setters
   void setBase(int b);
   void setHeight(int h);

   //Getters
   int getBase() const;
   int getHeight() const;
   double getArea() const;
   
   void calculateArea();

   // Overloaded << operator declaration
   friend ostream& operator << (ostream&, const Triangle&);

      

   // Overloaded >> operator declaration
   friend istream& operator >> (istream&, Triangle&);

private:
   int base;
   int height;
   double area;
};

#endif