#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cout << setw(7) << right << "Temp" << " | -------------- Wind Speed --------------\n";
    float Twc;
    int temp=-5;
    int windspeed=5;
    cout << setw(7) << "";
    while (windspeed <= 45)
    {
        cout << setw (7) << right << windspeed;
        windspeed=windspeed+5;
    }
    
    cout <<endl;
    while (temp <= 50)
    {
        cout << setw(7) << right << temp;
        windspeed=5;
        while (windspeed <= 45)
        {
            Twc=35.74+0.6215*temp-35.75*pow(windspeed, 0.16)+0.4275*temp*pow(windspeed,0.16);
            windspeed=windspeed+5;
            cout << setw(7) << right << fixed << setprecision(1) << showpoint << Twc;
        }
        temp=temp+5;
        cout <<endl;
    }
    
    
}
