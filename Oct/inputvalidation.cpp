#include <iostream>
#include <string>
using namespace std;

double inputVal(string, double);
double inputVal(double, string);
double inputVal(double, double);

int main() {
    while (inputVal("none", 32.0)==0) {
        cout << "Invalid input, try again!\n";
    }
    while (inputVal(32.0, 212.0)==0) {
        cout << "Invalid input, try again!\n";
    }
    while (inputVal(212.0, "none")==0) {
        cout << "Invalid input, try again!\n";
    }
}

double inputVal(string min, double max) {
    double number;
    //prompt the user fora floating-point number 
    cout << "Please enter a number (min:  no limit, max: " << max << "): ";
    cin >> number;
    //validate the number using the valid ranges given in the parameterset
    if (number <= max) {
        return number;
    }
    else return 0;
}

double inputVal(double min, string max) {
    double number;
    //prompt the user fora floating-point number 
    cout << "Please enter a number (min: " << min << ", max: no limit): ";
    cin >> number;
    //validate the number using the valid ranges given in the parameterset
    if (number >= min) {
        return number;
    }
    else return 0;
}

double inputVal(double min, double max) {
    double number;
    //prompt the user fora floating-point number 
    cout << "Please enter a number (min : " << min << ", max: " << max << "): ";
    cin >> number;
    //validate the number using the valid ranges given in the parameterset
    if (number >= min && number <= max) {
        return number;
    }
    else return 0;
}
/*
1.
Please enter a number (min:  no limit, max: 32): 100
Invalid input, try again!
Please enter a number (min:  no limit, max: 32): -123123
Please enter a number (min : 32, max: 212): 0
Invalid input, try again!
Please enter a number (min : 32, max: 212): 300
Invalid input, try again!
Please enter a number (min : 32, max: 212): 100
Please enter a number (min: 212, max: no limit): 100
Invalid input, try again!
Please enter a number (min: 212, max: no limit): -100
Invalid input, try again!
Please enter a number (min: 212, max: no limit): 212

2.
Please enter a number (min:  no limit, max: 32): 32
Please enter a number (min : 32, max: 212): 31
Invalid input, try again!
Please enter a number (min : 32, max: 212): 213
Invalid input, try again!
Please enter a number (min : 32, max: 212): 212
Please enter a number (min: 212, max: no limit): 0
Invalid input, try again!
Please enter a number (min: 212, max: no limit): 12222222
*/
