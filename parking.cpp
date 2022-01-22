// 9/8/2018 6:37 PM
#include <iostream>

using namespace std;

int main() {
    
    char type;
    cout << "Please enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): ";
    cin >> type;
    
    
    int hours;
    
    if (type == 'C') {
        cout << "Please enter the number of hours parked: ";
        cin >> hours;
    }
    else if (type == 'T') {
        cout << "Please enter the number of hours parked: ";
        cin >> hours;
    }
    else if (type == 'B'){
        cout << "Please enter the number of hours parked: ";
        cin >> hours;
    }
    else {
        cout << "That is an invalid vehicle type.";
    }
    
    float amountdue;
    
    if (type == 'C',hours <= 2) {
        amountdue = 1.25*hours;
    }
    else if (type == 'C',hours > 2) {
        amountdue = (1.25*2)+((hours-2)*1.5);
    }
    else if (type == 'T',hours <= 2) {
        amountdue = 2.75*hours;
    }
    else if (type == 'T',hours > 2) {
        amountdue = (2.75*2)+((hours-2)*3.75);
    }
    else if (type == 'B') {
        amountdue = 9.5+((hours-1)*6.75);
    }
    
    if (type == 'C') {
        cout << "Vehicle Type: Car" <<endl;
    }
    else if (type == 'T') {
        cout << "Vehicle Type: Truck" <<endl;
    }
    else if (type == 'B') {
        cout << "Vehicle Type: Bus" <<endl;
    }
    cout << "Times: " << hours << " hour(s)" <<endl << "Amount Due: $" << amountdue <<endl;
} 
    
    

    
