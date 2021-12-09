#include "Schedule.h"
#include <iostream>
#include "Birthday.h"
#include "Concert.h"

using namespace std;

Schedule::Schedule(int numEvents, Time t, Date d){
    size = numEvents;
    numBd = 0;
    numC = 0;
    for (int i=0;i<MAXNUMEVENTS;i++)
        events[i] = nullptr;
    time = t;
    date = d;
}

//Implement the destructor
Schedule::~Schedule(){
  for (int i = 0; i < MAXNUMEVENTS; i++) {
    if (events[i] != nullptr) {
        if (events[i]->getType() == "birthday") {
            delete (Birthday*)(events[i]);
        } else if (events[i]->getType() == "concert") {
            delete (Concert*)(events[i]);
        }
    }
}
}

//Implement the copy constructor
Schedule::Schedule(const Schedule &other){
  for (int i=0;i<MAXNUMEVENTS;i++){ 
     events[i] = nullptr;
  }
  size = other.size;
  numBd = other.numBd;
  numC = other.numC;
  time = other.time;
  date = other.date;
  setEvents(size, other.events);
}

//Implement the copy assignment operator
Schedule & Schedule::operator=(const Schedule &other){
if(this != &other){
  size = other.size;
  numBd = other.numBd;
  numC = other.numC;
  time = other.time;
  date = other.date;
  setEvents(size, other.events);
}
    return *this;

}

//Implement the setEvents function
void Schedule::setEvents(int s, Event * const newEvents[]){
  size = s;

  for (int i = 0; i < MAXNUMEVENTS; i++) {
    if (events[i] != nullptr) {
        if (events[i]->getType() == "birthday") {
            delete (Birthday*)(events[i]);
        } else if (events[i]->getType() == "concert") {
            delete (Concert*)(events[i]);
        }
        events[i] = nullptr;
    }
}

  for(int i = 0; i < size; i++){
    if(newEvents[i] != nullptr){
      if(newEvents[i]->getType() == "birthday"){
        //setting events[i] to a new birthday event with the implicit copy constructor. shallow copy is fine because there are no pointers in the Event class
        events[i] = new Birthday((Birthday&) *((Birthday*)newEvents[i]));
      }
      else if(newEvents[i]->getType() == "concert"){
        events[i] = new Concert((Concert&) *((Concert*)newEvents[i]));
      }
    }
  }
 }


Event** Schedule::getEvents(){
   return events;  
}

void Schedule::eventsFromInput(){
    string type;
    string description;
    string location;
    string blank;
    int hr, m, s;
    int d, mt, y;
    string unique;
    int tickets;
    for(int i = 0; i < size; i++){
        getline(cin, type);
        getline(cin, description);
        getline(cin, location);
        cin >> hr >> m >> s >> d >> mt >> y;
        getline(cin, blank);
        if(type == "birthday"){
            getline(cin, unique);
            events[i] = new Birthday(description,location,Time(hr,m,s),Date(d,mt,y),unique);
            numBd++;
        }
        else{
            cin >> tickets;
            getline(cin, blank);
            events[i] = new Concert(description,location,Time(hr,m,s),Date(d,mt,y),tickets);
            numC++;
        }
    }
}

Time Schedule::getTime() const{
    return time;
}

Date Schedule::getDate() const{
    return date;
}

Date Schedule::getFirstEventDate() const{
    int index =0;
    Event *firstEvent = nullptr;
    for(int i=0;i<size;i++)
    {
        if (events[i]!=nullptr)
        {
            index = i;
            break;
        }
    }
    if (index < size)
    {
        firstEvent = events[index];
        for(int i = index+1;i<size;i++)
        {
            if (events[i]!=nullptr)
            {
                if (*events[i] < *firstEvent)
                    firstEvent = events[i];
            }
        }
    }
    if (firstEvent!=nullptr)
        return firstEvent->getDate();
    else return Date();

}

//Implement the getLastEventDate function
Date Schedule::getLastEventDate() const{
    int index =0;
    Event *lastEvent = nullptr;
    //start at end of arr
    for(int i = size-1; i < size; i--)
    {
      //finds last non nullptr event element in arr
        if (events[i]!=nullptr)
        {
            index = i;
            break;
        }
    }
    if (index < size)
    {
        lastEvent = events[index];
        for(int i = 0;i<size;i++)
        {
            if (events[i]!=nullptr)
            {
                if (*events[i] > *lastEvent)
                    lastEvent = events[i];
            }
        }
    }
    if (lastEvent!=nullptr)
        return lastEvent->getDate();
    else return Date();
}

//Implement the eventsPassed funciton
int Schedule::eventsPassed() const{
  int eventsPassed = 0;
    for(int i = 0; i < size; i++){
      if(events[i]->hasPassed(this->getDate(), this->getTime())){
        eventsPassed++;
      }

    }
    return eventsPassed;
}

//Implement the printSummary function
void Schedule::printSummary() const{
  cout << "Today is " << getDate().toString()  << " " << getTime().toString() << endl;
  cout << getFirstEventDate().toString() << "---" << getLastEventDate().toString() << endl;
  cout << eventsPassed() << " events have passed." << endl << endl;
  for(int i = 0; i < size; i++){
    if (events[i] != nullptr) {
      if (events[i]->getType() == "birthday") {
        ((Birthday*)events[i])->printSummary();
        cout << endl;
      }
      else if(events[i]->getType() == "concert") {
         ((Concert*)events[i])->printSummary();
         cout << endl;
     }
    }
   }
  }


