#include <iostream>
#include <vector>
#include <string>
#include "functions.h"



int main()
{
    
    vector<movie> movies; 
    char option;

   
    while (true)
    {
        printMenu();
        cin >> option;
        cin.ignore();
        switch (option)
        {
            case 'A':
            {
                string nm;
                int year;
                string genre;
                cout << "Movie Name: ";
                getline(cin, nm);
                cout << "Year: ";
                cin >> year;
                cout << "Genre: ";
                cin >> genre;
                
                //call you addMovie() here
                addMovie(nm, year, genre, movies);

                cout << "Added " << nm << " to the catalog" << endl;
                break;
            }
            case 'R':
            {     
                string mn;
                cout << "Movie Name:";
                getline(cin, mn);
                bool found;
                //call you removeMovie()here 
                found = removeMovie(mn, movies);
                if (found == false)
                    cout << "Cannot find " << mn << endl;
                else
                    cout << "Removed " << mn << " from catalog" << endl;
                break;
            }
            case 'O':
            {
                string mn;
                cout << "Movie Name: ";
                getline(cin, mn);
                cout << endl;
                //call you movieInfo function here
                movieInfo(mn, movies);
                break;

            }
            case 'C':
            {
                cout << "There are " << movies.size() << " movies in the catalog" << endl;
                 // Call the printCatalog function here
                 printCatalog(movies);
                break;
            }
            case 'F':
            {
                string inputFile; 
                bool isOpen;
                cin >> inputFile; 
                cout << "Reading catalog info from " << inputFile << endl;
                //call you readFromFile() in here
                isOpen = readFromFile(inputFile, movies);
                if (isOpen == false)
                    cout << "File not found" << endl;
                break;
            }
            case 'W':
            {   string outputFile; 
                bool isOpen;
                cin >> outputFile; 
                cout << "Writing catalog info to " << outputFile << endl;
                //call you writeToFile() in here
                isOpen = writeToFile(outputFile, movies);
                 if (isOpen == false)
                    cout << "File not found" << endl;
                break;
            }
        }
        if (option == 'Q')
        {
            cout << "Quitting Program";
            break;
        }
    }
}