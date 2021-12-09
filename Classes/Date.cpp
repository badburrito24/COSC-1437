#include "Date.h"

//Default Constructor
Date::Date(){
  day = 1;
  month = 1;
  year = 0;

}
//Constructor with parameters
Date::Date(int _day, int _month, int _year){
  day = _day;
  month = _month;
  year = _year;
  if(_day < 1 || _day > 31){
    day = 0;
  }
  if(_month < 1 || _month > 12){
    month = 0;
  }
  if(_year < 0){
    year = 0;
  }
}


int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int h) { day = h; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int s) { year = s; }

//dateToDays
int Date::dateToDays() const
{
  return(day + (month * 31) + year * 372);
}
//daysToDate
const Date Date::daysToDate(int ndays)const{
  int years = ndays/372;
  ndays = ndays % 372;
  int months = ndays / 31;
  ndays = ndays % 31;
  int days = ndays;
  return(Date(days, months, years));
  
}
//toString
string Date::toString() const{
  return(to_string(day) + "/" + to_string(month) + "/" + to_string(year));
}
// +
const Date Date::operator+(int ndays) const{
  int totalDays = dateToDays() + ndays;
  return(daysToDate(totalDays));
}
// -
const Date Date:: operator-(int ndays) const{
  int totalDays;
  totalDays = dateToDays() - ndays;
  Date date = daysToDate(totalDays);
  if(date.day < 1){
    date.day = date.day + 31;
    date.month = date.month - 1;
    if(date.month < 1){
      date.year = date.year - 1;
      date.month = date.month + 12;
    }
  }
  return(date);
}
// <
bool Date::operator<(const Date& other) const{
  return(dateToDays() < other.dateToDays());
}
// >
bool Date::operator>(const Date& other) const{
  return(dateToDays() > other.dateToDays());
}
// ==
bool Date::operator==(const Date& other) const{
  return(dateToDays() == other.dateToDays());
}