#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float temperature1;
    float temperature2;
    float temperature3;
    float temperature4;
    float temperature5;
    cout << "Please enter five temperature values in Fahrenheit:" <<endl;
    cin >> temperature1 >> temperature2 >> temperature3 >> temperature4 >> temperature5;
    float celsuius1;
    celsuius1=(temperature1-32)*5/9;
    float celsuius2;
    celsuius2=(temperature2-32)*5/9;
    float celsuius3;
    celsuius3=(temperature3-32)*5/9;
    float celsuius4;
    celsuius4=(temperature4-32)*5/9;
    float celsuius5;
    celsuius5=(temperature5-32)*5/9;
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << setw(15) << "Warning" <<endl;
    cout << setw(15) <<  right << fixed << setprecision(2) << showpoint << temperature1 << setw(15) << right << fixed << setprecision(2) << showpoint << celsuius1;
    if (celsuius1 <= 0) {
        cout << setw(15) << right << "<= Freezing!" <<endl;
    }
    else if (celsuius1 >= 100) {
        cout << setw(15) << right << ">= Boiling!" <<endl;
    }
    else {
        cout << setw(15) <<endl;
    }
    
    cout << setw(15) << right << fixed << setprecision(2) << showpoint << temperature2 << setw(15) << right << fixed << setprecision(2) << showpoint << celsuius2;
    if (celsuius2 <= 0) {
        cout << setw(15) << right << "<= Freezing!" <<endl;
    }
    else if (celsuius2 >= 100) {
        cout << setw(15) << right << ">= Boiling!" <<endl;
    }
    else {
        cout << setw(15) <<endl;
    }
    
    cout << setw(15) << right << fixed << setprecision(2) << showpoint << temperature3 << setw(15) << right << fixed << setprecision(2) << showpoint << celsuius3;
    if (celsuius3 <= 0) {
        cout << setw(15) << right << "<= Freezing!" <<endl;
    }
    else if (celsuius3 >= 100) {
        cout << setw(15) << right << ">= Boiling!" <<endl;
    }
    else {
        cout << setw(15) <<endl;
    }
    
    cout << setw(15) << right << fixed << setprecision(2) << showpoint << temperature4 << setw(15) << right << fixed << setprecision(2) << showpoint << celsuius4;
    if (celsuius4 <= 0) {
        cout << setw(15) << right << "<= Freezing!" <<endl;
    }
    else if (celsuius4 >= 100) {
        cout << setw(15) << right << ">= Boiling!" <<endl;
    }
    else {
        cout << setw(15) <<endl;
    }

    cout << setw(15) << right << fixed << setprecision(2) << showpoint << temperature5 << setw(15) << right << fixed << setprecision(2) << showpoint << celsuius5;
    if (celsuius5 <= 0) {
        cout << setw(15) << right << "<= Freezing!" <<endl;
    }
    else if (celsuius5 >= 100) {
        cout << setw(15) << right << ">= Boiling!" <<endl;
    }
    else {
        cout << setw(15) <<endl;
    }    
}
  
