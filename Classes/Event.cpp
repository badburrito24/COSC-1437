#include "Event.h"
#include "Time.h"
#include "Date.h"

Event::Event(string descript, string loc, Time t, Date d){
  this->description = descript;
  this->location = loc;
  this->time = t;
  this->date = d;
}
bool Event::hasPassed(Date d, Time t){
  if((this->date < d) || (this->date == d)){
    if(this->time < t){
    return true;
    }
  }
  if((this->date > d) || (this->date == d)){
    if(this->time > t){
      return false;
    } 
  }
  return true;
}