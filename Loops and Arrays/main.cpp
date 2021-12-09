#include <iostream>
#include <string>
#include <vector>


using namespace std;

int find(vector<string> vect, string str) {
    for(int i = 0; i < (int)vect.size(); i++){
        if(vect.at(i) == str)
            return i;
    }
     return -1;


}
int main(){

vector<string> movieNames;
vector<int> movieYears;
vector<string> movieGenres;

char input;
string movieName;
string movieGenre;
int movieYear;
int index;


while(input != 'Q'){

    cout << endl << "Menu:" << endl;
    cout << "A - Add Movie" << endl;
    cout << "R - Remove Movie" << endl;
    cout << "O - Output Movie Info" << endl;
    cout << "C - Output Catalog Info" << endl;
    cout << "Q - Quit Program" << endl << endl;
    cout << "Choose an option: ";
    cin >> input;

    switch(input){
        case 'A':
            cout << "Movie Name: ";
            cin >> movieName;
            movieNames.push_back(movieName);
            //cout << endl;
            cout << "Year: ";
            cin >> movieYear;
            movieYears.push_back(movieYear);
            //cout << endl;
            cout << "Genre: ";
            cin >> movieGenre;
            movieGenres.push_back(movieGenre);
            cout << "Added " << movieName << " to the catalog" << endl;
            break;

        case 'R':
            cout << "Movie Name:";
            cin >> movieName;
            index = find(movieNames, movieName);
            if(index != -1){
            movieNames.erase(movieNames.begin() + index);
            movieYears.erase(movieYears.begin() + index);
            movieGenres.erase(movieGenres.begin() + index);
            cout << "Removed " << movieName << " from catalog" << endl;
            }
            else{
               cout << "Cannot find " << movieName << endl;
            }
            
            break;

        case 'O':
            cout << "Movie Name: ";
            cin >> movieName;
            index = find(movieNames, movieName);
            if(index != -1){
            cout << endl << "Name: " << movieNames.at(index);
            cout << endl << "Year: " << movieYears.at(index);
            cout << endl << "Genre: " << movieGenres.at(index) << endl;
            }
            else{
                cout << endl << "Cannot find " << movieName << endl;
            }
            break;

        case 'C':
            if(movieNames.size() == 0) {cout << "There are " << movieNames.size() << " movies in the catalog" << endl;}
            else{cout << "There are " << movieNames.size() << " movies in the catalog" << endl << endl;}
            
                for(int i = 0; i < (int)movieNames.size(); i++){
                    cout << "Name: " << movieNames.at(i) << endl;
                    cout << "Year: " << movieYears.at(i) << endl;
                    cout << "Genre: " << movieGenres.at(i) << endl;
                    if((int)movieNames.size() > 1)
                        {
                           if(i < (int)movieNames.size()-1)
                           {
                              cout << endl;
                           }
                        }
                        
                }

            break;
        case 'Q':
            cout << "Quitting Program";
            break;
        
}

}

}
