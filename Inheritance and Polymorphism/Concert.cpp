#include "Concert.h"
#include <iostream>

Concert::Concert(string de, string l, const Time &t, const Date &d, int ti):Event(de,l,t,d),tickets(ti){
    type = "concert";
}

int Concert::getTickets() const{
    return tickets;
}

string Concert::getType() const{
    return type;
}

//Implement the printSummary function
void Concert::printSummary() const {
  cout << getDescription() << endl;
  cout << getLocation() << endl;
  cout << "Time: " << getTime().toString() << endl;
  cout << "Date: " << getDate().toString() << endl;
  cout << "Tickets: " << tickets << endl;
}