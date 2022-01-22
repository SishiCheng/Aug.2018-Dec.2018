#include <iostream>
using namespace std;

int main() {
    int integer[7];
    cout << "Enter seven integers: ";
    for (int i=0; i<=6; i++) {
        cin >> integer[i];
    }//Prompts the user to enter7 integers
    for (int i=0; i<=6; i++) {
        if (integer[i]<1 || integer[i]>10) {
            i++;
            cout << "INVALID INTEGER, TRY AGAIN!\n" << "Enter seven integers: ";
            for (int j=0; j<=6; j++) {
                cin >> integer[j];
            }//Validatesthe user input for values between 1 and 10 (inclusive)
            i = 0;
        }
    }    
    cout << "Array Statistics:\n";
    int min=integer[0];
    for (int x=1;x<=6;x++) {
        if (integer[x]<min) {
            min=integer[x];
            }
        }
    cout << "The minimum is: " << min <<endl;
    int max=integer[0];
    for (int i=1;i<=6;i++) {
        if (integer[i]>max) {
            max=integer[i];
            }
        }
    cout << "The maximum is: " << max <<endl;   
    double sum=0.00,average;
    for (int j=0;j<=6;j++) {
        sum+=integer[j];
    }
    average=sum/7;
    cout << "The average is: " << showpoint << average << endl;        
}//Determines and displays the maximum, minimum, and arithmetic mean (average)of the integers
/*
1.
Enter seven integers: 8 3 4 4 2 4 5
Array Statistics:
The minimum is: 2
The maximum is: 8
The average is: 4.28571

2.
Enter seven integers: 8 -2 2 3 4 9 11
INVALID INTEGER, TRY AGAIN!
Enter seven integers: 1 2 3 4 5 6 7
Array Statistics:
The minimum is: 1
The maximum is: 7
The average is: 4.00000

*/