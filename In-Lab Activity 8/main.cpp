#include <iostream>
using namespace std;

#include "Cylinder.h"


int main()
{

   Shape s2d;
   s2d.printArea();
   
   Circle circ(3.4, -1, 3.0);
   
   // please fix the error below
   cout << "The center of the circle is: (" << circ.getCenter_x() << ", " << circ.getCenter_y() << ")." << endl;
   circ.compArea();
   circ.printArea();
   
   // fix the following to generate the expected output 
   Cylinder *cyl = new Cylinder (5, 6, 7, 8);  // Circle *cyl or Cylinder *cyl?
   cyl->compArea();
   cyl->printArea();
      
   return 0;
}
