#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
using namespace std;

class Student {

    public:
       Student();
   	 void SetName(string n);
   	 string GetName();
   	 void SetGPA(double n);
   	 double GetGPA();
   	 // FIXME: Declare 3 more functions 
   	 
    private:
    string name;
    double gpa;
        // FIXME: Add 2 private data members
};

#endif /* STUDENT_H_ */