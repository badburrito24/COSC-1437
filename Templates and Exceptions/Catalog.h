#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Catalog {
private:
   vector<Movie<T>> movies;
public:
   Catalog(vector<Movie<T>> movies);
   vector<Movie<T>> getCatalog();
   void printCatalog();
   void sortMoviesByRating(); // Write the definition of the sortMoviesByRating() function here
   Movie<T> getBestMovie();   // Write the definition of the getBestMovie() function here
   Movie<T> getWorstMovie();  // Write the definition of the getWorstMovie() function here
   void printMoviesWithRating(T thresh); // Write the definition of the printMoviesWithRating() function here
   void getMovieInfo(string _name);      // Write the definition of the getMovieInfo() function here
   void swap(T& x, T&y);
};

template <typename T>
Catalog<T>::Catalog(vector<Movie<T>> movies) {
   this->movies = movies;
}
template <typename T>
vector<Movie<T>> Catalog<T>::getCatalog() {
   return movies;
}
template <typename T>
void Catalog<T>::printCatalog() {
   for (Movie<T> m : movies) {
      m.printMovieInfo();
   }
}
template <typename T>
void swap (Movie<T>& x, Movie<T>& y)
{
    Movie<T> temp = x;
    x = y;
    y = temp;
    //return;
}
template <typename T> // Write the implementation of the sortMoviesByRating() function here
void Catalog<T>::sortMoviesByRating(){
   if(movies.empty()){
      throw runtime_error("No movies in catalog.");
   }
   for(int i = 0; i < (int)movies.size(); i++){
         for(int j = 0; j < (int)movies.size()-i-1; j++){
            if(movies.at(j).compareRating(movies.at(j+1))){
              // swap(movies.at(j), movies.at(j+1));
               Movie<T> temp = movies.at(j);
               movies.at(j) = movies.at(j+1);
               movies.at(j+1) = temp;
            }
            else if(movies.at(j).getRating() == movies.at(j+1).getRating()){
                  if(movies.at(j).getName() > movies.at(j+1).getName()){
                     //swap(movies.at(j), movies.at(j+1));
                        Movie<T> temp = movies.at(j);
                        movies.at(j) = movies.at(j+1);
                        movies.at(j+1) = temp;
                  }
            }
         }
      }
   }
   
template <typename T> // Write the implementation of the getBestMovie() function here
Movie<T> Catalog<T>::getBestMovie(){
   if(movies.empty()){
      throw  runtime_error("No movies in catalog.");
   }
   Movie<T> best = movies.at(0);
   for(int i = 0; i < (int)movies.size(); i++){
      //if(!(best.compareRating(movies.at(i)))){
      if(best.getRating() < movies.at(i).getRating()){
         best = movies.at(i);
      }
   }
   return best;
}
template <typename T> // Write the implementation of the getWorstMovie() function here
Movie<T> Catalog<T>::getWorstMovie(){
   //sortMoviesByRating();
   if(movies.empty()){
      throw  runtime_error("No movies in catalog.");
   }
   Movie<T> worst = movies.at(0);
   for(int i = 0; i < (int)movies.size(); i++){
      if(worst.compareRating(movies.at(i))){
         worst = movies.at(i);
      }
   }    
   return worst;
}
   
template <typename T> // Write the implementation of the printMoviesWithRating() function here
void Catalog<T>::printMoviesWithRating(T thresh){
      if(movies.empty()){
         throw  runtime_error("No movies in catalog.");
      }
      for(int i = 0; i < (int)movies.size(); i++){
         if(movies.at(i).getRating() > thresh){
            movies.at(i).printMovieInfo();
         
      }
   }
}
template <typename T> // Write the implementation of the getMovieInfo() function here
void Catalog<T>::getMovieInfo(string _name){
   int found = 0;
   if(movies.empty()){
         throw  runtime_error("No movies in catalog.");
   }
   for(int i = 0; i < (int)movies.size(); i++){
      if(movies.at(i).getName() == _name){
         movies.at(i).printMovieInfo();
         found = 1;
      }
         
   }
   if(found == 0)
      throw runtime_error("Movie not found in catalog.");
   
   }
#endif