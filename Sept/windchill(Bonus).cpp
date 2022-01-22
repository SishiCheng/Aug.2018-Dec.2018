#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float Twc;
    int startingtemp, endingtemp, tempinterval, startingwindspeed, endingwindspeed, windspeedinterval, temp, windspeed;
    cout << "Please enter the starting temperature, ending temperature, and temperature interval: ";
    cin >> startingtemp>> endingtemp>> tempinterval;
    cout << "Please enter the starting wind speed, ending wind speed, and wind speed interval: ";
    cin >> startingwindspeed>> endingwindspeed>> windspeedinterval;
    cout << setw(7) << right << "Temp" << " | -------------- Wind Speed --------------\n";
    cout << setw(7) << "";
    windspeed=startingwindspeed;
    while (windspeed <= endingwindspeed)
    {
        cout << setw (7) << right << windspeed;
        windspeed=windspeed+windspeedinterval;
    }
    
    cout <<endl;
    temp=startingtemp;
    while (temp <= endingtemp)
    {
        cout << setw(7) << right << temp;
        windspeed=startingwindspeed;
        while (windspeed <= endingwindspeed)
        {
            Twc=35.74+0.6215*temp-35.75*pow(windspeed, 0.16)+0.4275*temp*pow(windspeed,0.16);
            windspeed=windspeed+windspeedinterval;
            cout << setw(7) << right << fixed << setprecision(1) << showpoint << Twc;
        }
        temp=temp+tempinterval;
        cout <<endl;
    }
    
    
}
