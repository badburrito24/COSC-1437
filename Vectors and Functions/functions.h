#ifndef functions_h
#define functions_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 


using namespace std;

void printMenu()
{
    cout << endl;
    cout << "Menu:" << endl;
    cout << "A - Add Movie" << endl;
    cout << "R - Remove Movie" << endl;
    cout << "S - Sort Movies" << endl;
    cout << "O - Output Movie Info" << endl;
    cout << "C - Output Catalog Info" << endl;
    cout << "Q - Quit Program" << endl
         << endl;
    cout << "Choose an option: ";
}

void printMovieInfo(const string &mn, int yr, const string &gen){
    cout << endl;
    cout << "Name: " << mn << endl;
    cout << "Year: " << yr << endl;
    cout << "Genre: " << gen << endl;
}

// Write the definition and implementation of the printCatalog function here
void printCatalog(vector<string> &movieNames, vector<int> &movieYears, vector<string> &movieGenres){
  cout << "There are " << movieNames.size() << " movies in the catalog" << endl << endl;
  for(int i = 0; i < (int)movieNames.size(); i++){
      cout << "Name: " << movieNames.at(i) << endl;
      cout << "Year: " << movieYears.at(i) << endl;
      if(i == (int)movieNames.size() - 1){
      cout << "Genre: " << movieGenres.at(i) << endl;
      }
      else{
         cout << "Genre: " << movieGenres.at(i) << endl << endl;
    }
}
}

// Write the definition and implementation of the findMovie function here
int findMovie(string mn, vector<string> &movieNames){
   for(int i = 0; i < (int)movieNames.size(); i++){
        if(movieNames.at(i) == mn)
            return i;
        }
     return -1;
}

// Write the definition and implementation of the addMovie function here
void addMovie(string &mn, int &yr, string &gen, vector<string> &movieNames, vector<int> &movieYears, vector<string> &movieGenres){
  movieNames.push_back(mn);
  movieYears.push_back(yr);
  movieGenres.push_back(gen);
  cout << "Added " << mn << " to the catalog" << endl;

}
// Write the definition and implementation of the removeMovie function here
bool removeMovie(string mn, vector<string> &movieNames, vector<int> &movieYears, vector<string> &movieGenres){
  int index = findMovie(mn, movieNames);
  if(index != -1){
  movieNames.erase(movieNames.begin() + index);
  movieYears.erase(movieYears.begin() + index);
  movieGenres.erase(movieGenres.begin() + index);
  cout << "Removed " << mn << " from the catalog" << endl;
  }
  else{
     cout << "could not find " << mn << endl;

}
}
// Write the definition and implementation of the movieInfo function here
void movieInfo(string &mn, vector<string> &movieNames, vector<int> &movieYears, vector<string> &movieGenres){
  int index = findMovie(mn, movieNames);

  if(index != -1){
    printMovieInfo(movieNames.at(index), movieYears.at(index), movieGenres.at(index));
  }
  else{
      cout << "Cannot find " << mn << endl;
  }
}
   // You must use the following cout statement if the movie is not in the catalog:
   // cout << "Cannot find " << movie name variable identifier << endl;

// Write the definition and implementation of the sortCatalog function here
void swapInt(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

}
void swapStr(string &strA, string &strB){
    string temp = strA;
    strA = strB;
    strB = temp;

}
void sortCatalog(vector<string> &movieNames, vector<int> &movieYears, vector<string> &movieGenres){

   for (int i = 0; i < (int)movieYears.size()-1; i++){
    for (int j = 0; j < (int)movieYears.size()-1; j++){
        if (movieYears.at(j) > movieYears.at(j+1)){
            swapInt(movieYears[j], movieYears[j+1]);
            swapStr(movieNames[j], movieNames[j+1]);
            swapStr(movieGenres[j], movieGenres[j+1]);
            
        
    }
   }
}
cout << "Movies have been sorted by year." << endl;
}

#endif