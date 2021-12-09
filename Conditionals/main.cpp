#include <iostream>

using namespace std;

int main()
{
    int currentHumidity;
    int currentTime; //0-23
    int targetTemp;

    cout << "Enter the current relative humidity: ";
    cin >> currentHumidity;
    cout << currentHumidity << "\n";
    cout << "Enter the current time: ";
    cin >> currentTime;
    cout << currentTime << "\n";

        if(currentTime >= 6 && currentTime < 8)
            {
                targetTemp = 76;
            }
        if(currentTime >= 8 && currentTime < 18)
            {
                targetTemp = 78;
            }
        if(currentTime >= 18 && currentTime < 21)
            {
                targetTemp = 75;
            }
        if(currentTime >= 21 && currentTime < 6)
            {
                targetTemp = 72;
            }
        
    cout << "The current target temperature is " << targetTemp << "F" << endl;

        if(currentHumidity > 65 && targetTemp == 78)
            {
                cout << "Changing target temperature to 73F" << endl;   
            }
        if(currentHumidity >= 60 && currentHumidity <= 65 && targetTemp == 78)
            {
                cout << "Changing target temperature to 76F" << endl;
            }
        if(currentHumidity < 60 && targetTemp == 76)
            {
                cout << "Changing target temperature to 78F" << endl;
            }
    return 0;
}