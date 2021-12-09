// Simple class to hold student information
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;
 
Student::Student() {
   SetName("Louie");
   SetGPA(1);
   //FIXME: complete the constructor
}

void Student::SetName(string n) {
	//FIXME: complete SetName function
	name = n;
}
void Student::SetGPA(double n){
   gpa = n;
}
string Student::GetName(){
   return name;
}
double Student::GetGPA(){
   return gpa;
}
// FIXME: Add 3 more functions