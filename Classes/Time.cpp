#include "Time.h"
#include <string> 

//Default Constructor
Time::Time(){
  second = 0;
  minute = 0;
  hour = 0; 
}
//Constructor with parameters
Time::Time(int hr, int min, int sec){
  //making sure input is valid
  if(sec <= 59 && sec >= 0){
    second = sec;
  }else{
    second = 0;
    //if input is invalid set to zero
  }
  if(min <= 59 && min >= 0){
    minute = min;
  }else{
    minute = 0;
  }
  if(hr <= 23 && hr >= 0){
    hour = hr;
  }else{
    hour = 0;
  }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }
void Time::setHour(int h) { hour = h; }
void Time::setMinute(int m) { minute = m; }
void Time::setSecond(int s) { second = s; }

int Time::timeToSeconds() const
{
    return (getSecond() + (getMinute() * 60) + (getHour() * 3600));
}

const Time Time::secondsToTime(int s) const
{
    int resultS = s % 60;
    s /= 60;
    int resultM = s % 60;
    s /= 60;
    int resultH = s % 24;
    return Time(resultH, resultM, resultS);
}

//toString
string Time::toString() const{
  // ^^ "const" will not modify the member variables ^^
  string str;
  //converting ints to strings
  std::string hrs = std::to_string(getHour());
  std::string min = std::to_string(getMinute());
  std::string sec = std::to_string(getSecond());
  //concatenation
  str = hrs + ":" + min + ":" + sec;
  return str;
  }

// +
const Time Time::operator+(const Time& other) const{
  int totalSeconds = timeToSeconds() + other.timeToSeconds();
  return(secondsToTime(totalSeconds));
}
// -
const Time Time::operator-(const Time& other) const{
  Time TotalTime;
  TotalTime.second = second - other.second;
  TotalTime.minute = minute - other.minute;
  TotalTime.hour = hour - other.hour;
  if(TotalTime.second < 0){
    TotalTime.second = 60 + TotalTime.second;
    TotalTime.minute = TotalTime.minute - 1;
    if(TotalTime.minute < 0){
      TotalTime.minute = 60 + TotalTime.minute;
      TotalTime.hour = TotalTime.hour - 1;
      if(TotalTime.hour < 0){
        TotalTime.hour = 24 + TotalTime.hour;
      }
    }
  }
  return TotalTime;
}
// <
bool Time::operator<(const Time& other) const{
  return(timeToSeconds() < other.timeToSeconds());
}
// >
bool Time::operator>(const Time& other) const{
  return(timeToSeconds() > other.timeToSeconds());
}
// ==
bool Time::operator==(const Time& other) const{
  return(timeToSeconds() == other.timeToSeconds());
}
