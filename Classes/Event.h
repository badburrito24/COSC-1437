#ifndef EVENT
#define EVENT
#include "Time.h"
#include "Date.h"

#include <string>

using namespace std;

class Event{
  private:
    string description;
    string location;
    Time time;
    Date date;
  public:
    //Event();
    Event(string descript, string loc, Time t, Date d);
    bool hasPassed(Date d, Time t);
};
#endif