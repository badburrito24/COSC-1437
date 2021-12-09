#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;

template <typename T>
class Movie {
private:
   string name;
   int year;
   string genre;
   T rating;
public:
   Movie(string name = "name", int year = 0, string genre = "genre", T rating = 0);
   string getName();
   int getYear();
   string getGenre();
   T getRating();
   void printMovieInfo();
   // Write the definition of the compareRating() function here
   bool compareRating(Movie m);
   // Write the definition of the addRating() function here
   void addRating(T rating);
};

template <typename T>
Movie<T>::Movie(string n, int y, string g, T r) {
   name = n;
   year = y;
   genre = g;
   rating = r;
}
template <typename T>
string Movie<T>::getName() {
   return name;
}
template <typename T>
int Movie<T>::getYear() {
   return year;
}
template <typename T>
string Movie<T>::getGenre() {
   return genre;
}
template <typename T>
T Movie<T>::getRating() {
   return rating;
}
template <typename T>
void Movie<T>::printMovieInfo() {
   cout << "Name: " << name << endl;
   cout << "Year: " << year << endl;
   cout << "Genre: " << genre << endl;
   cout << "Rating: " << rating << endl;
}
// Write the implementation of the compareRating() function here
template <typename T>
bool Movie<T>::compareRating(Movie m){
   if(getRating() > m.getRating()){
         return true;
   }
   return false;
}
// Write the implementation of the addRating() function here
template <typename T>
void Movie<T>::addRating(T r){
     if(r < 0){
      throw  runtime_error("Invalid rating amount.");
     }else{
     rating = rating + r;
     }
  }


#endif