#include "Birthday.h"
#include "Time.h"
#include <iostream>

Birthday::Birthday(string de, string l, const Time &t, const Date &d, string g):Event(de,l,t,d),gifts(g){
    type = "birthday";
}

string Birthday::getGifts() const{
    return gifts;
}

string Birthday::getType() const {
    return type;
}

//Implement the printSummary() function
void Birthday::printSummary() const {
  cout << getDescription() << endl;
  cout << getLocation() << endl;
  cout << "Time: " << getTime().toString() << endl;
  cout << "Date: " << getDate().toString() << endl;
  cout << "Gifts: " << gifts << endl;
}