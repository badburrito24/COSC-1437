#ifndef functions_h
#define functions_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <fstream>

using namespace std;

struct movie{
  string name;
  int year;
  string genre;
};

void printMenu()
{
    cout << endl;
    cout << "Menu:" << endl;
    cout << "A - Add Movie" << endl;
    cout << "R - Remove Movie" << endl;
    cout << "O - Output Movie Info" << endl;
    cout << "C - Output Catalog Info" << endl;
    cout << "F - Read file" << endl; 
    cout << "W - Write file" << endl; 
    cout << "Q - Quit Program" << endl; 
    cout << "Choose an option: ";
}


void printMovieInfo(const string &mn, int yr, const string &gen)
{
    cout << endl;
    cout << "Name: " << mn << endl;
    cout << "Year: " << yr << endl;
    cout << "Genre: " << gen << endl;
}

// Write the definition and implementation of the printCatalog function here
void printCatalog(vector<movie> &movies){
  for(int i = 0; i < (int)movies.size(); i++){
    printMovieInfo(movies.at(i).name, movies.at(i).year, movies.at(i).genre);
  }
}
// Write the definition and implementation of the findMovie function here
int findMovie(const string &mn, vector<movie> &movies){
  for(int i = 0; i < (int)movies.size(); i++){
    if(movies.at(i).name == mn){
      return i;
    }
  }
   return -1;
}
// Write the definition and implementation of the addMovie function here
void addMovie(const string &mn, int yr, const string &gen, vector<movie> &movies){
  //struct movie m = new movie {mn, yr, gen};
  movie m;
  m.name = mn;
  m.year = yr;
  m.genre = gen;
  movies.push_back(m);
}
// Write the definition and implementation of the removeMovie function here
bool removeMovie(const string &mn, vector<movie> &movies){
  int index = findMovie(mn, movies);
  if(index == -1){
    return false;
  }else{
  if(movies.at(index).name == mn){
       movies.erase(movies.begin() + index);
       return true;
    }
  }
  return false;
}
// Write the definition and implementation of the movieInfo function here
void movieInfo(const string &mn, vector<movie> &movies){
  int index = findMovie(mn, movies);
  if(index == -1){
    cout << "Cannot find " << mn << endl;
  }else{
  if(movies.at(index).name == mn){
    printMovieInfo(movies.at(index).name, movies.at(index).year, movies.at(index).genre);
   }
  }
}


// Write the definition and implementation of the readFromFile function here
bool readFromFile(const string fileName , vector<movie> &movies){
  //ifstream IF;
  //IF.open(fileName);
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
  while (!myfile.bad() && !myfile.eof())
    {
      movie m;
      getline(myfile, m.name);
      myfile >> m.year;
      myfile.ignore(10, '\n');
      getline(myfile, m.genre);
      movies.push_back(m);
    }
    myfile.close();
    return true;
  }else{
    return false;
    //unable to open file
  }
}

// Write the definition and implementation of the writeToFile function here
bool writeToFile(const string fileName, vector<movie> &movies){
  ofstream myfile(fileName);
  //ofstream myfile(output.txt);
  if (myfile.is_open())
  {
    for(int i = 0; i < (int)movies.size(); i++){
    myfile << movies.at(i).name << endl;
    myfile << movies.at(i).year << endl;
    if( i < movies.size()-1){
      myfile << movies.at(i).genre << endl;
    }else{
      myfile << movies.at(i).genre;
    }
    }
    myfile.close();
    return true;
  }else{
    return false;
    //unable to open file
  } 
}
#endif