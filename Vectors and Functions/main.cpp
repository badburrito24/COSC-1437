#include <iostream>
#include <string>
#include <vector>
#include "functions.h"


using namespace std;

/*int find(vector<string> vect, string str) {
    for(int i = 0; i < (int)vect.size(); i++){
        if(vect.at(i) == str)
            return i;
    }
     return -1;


}*/
int main(){

vector<string> movieNames;
vector<int> movieYears;
vector<string> movieGenres;

char input;
string movieName;
string movieGenre;
int movieYear;
//int index;


while(input != 'Q'){
  printMenu();
  cin >> input;
    switch(input){
        case 'A':
            cout << "Movie Name: ";
            cin.ignore();
            getline(cin, movieName);
            //cout << endl;
            cout << "Year: ";
            cin >> movieYear;
            //cout << endl;
            cout << "Genre: ";
            cin.ignore();
            getline(cin, movieGenre);
            addMovie(movieName, movieYear, movieGenre, movieNames, movieYears, movieGenres);
            break;
        case 'R':
            cout << "Movie Name: ";
            cin.ignore();
            getline(cin, movieName);
            removeMovie(movieName, movieNames, movieYears, movieGenres);
            break;
        case 'S':
          sortCatalog(movieNames, movieYears, movieGenres);
          break; 
        case 'O':
            cout << "Movie Name: " << endl;
            cin.ignore();
            getline(cin, movieName);
            movieInfo(movieName, movieNames, movieYears, movieGenres);
            break;
        case 'C':
            printCatalog(movieNames, movieYears, movieGenres);
            break;
        case 'Q':
            cout << "Quitting Program";
            break;
        
}

}

}