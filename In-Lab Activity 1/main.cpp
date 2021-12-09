#include <iostream>
#include <string>
using namespace std;

int main() {
	int par;
	int strokes;
	string name;

	cin >> par;
	cin >> strokes;
   if(par > 5	|| par < 3 )
     {
      cout << "Error" << endl;
      }
	else if(strokes == par - 2)
	   {
	   cout << "Eagle" << endl;
	   }
	else if(strokes == par - 1)
	   {
	   cout << "Birdie" << endl;
	   }
	else if(strokes == par)
	   {
	   cout << "Par" << endl;
	   }
	else if(strokes == par + 1)
	   {
	   cout << "Bogey" << endl;
   	}
	else
	   {
	   cout << "Error" << endl;
	   }
	/* Type your code here */

	return 0;
}