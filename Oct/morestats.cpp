#include <iostream>
using namespace std;

int main() {
    int integer[7];
    cout << "Enter seven integers: ";
    for (int i=0; i<=6; i++) {
        cin >> integer[i];
    }//Prompts the user to enter 7 integers
    for (int i=0; i<=6; i++) {
        if (integer[i]<1 || integer[i]>10) {
            i++;
            cout << "INVALID INTEGER, TRY AGAIN!\n" << "Enter seven integers: ";
            for (int j=0; j<=6; j++) {
                cin >> integer[j];
            }
            i = 0;
        }
    }//Validatesthe user input for values between 1 and 10 (inclusive)  
    cout << "Array Statistics:\n";
    int x;
    for (int i=0; i<=5;i++) {
        for (int j=i+1; j<=6; j++) {
            if (integer[i]>integer[j]) {
                x=integer[i];
                integer[i]=integer[j];
                integer[j]=x;
            }
        }
    }//Sort the elements from the amallest to the biggest
    cout << "The minimum is: " << integer[0] << "\nThe maximum is: " << integer[6] <<endl;
    double sum=0.00,average;
    for (int j=0;j<=6;j++) {
        sum+=integer[j];
    }
    average=sum/7;//calculating the avarage
    int times[11]={};
    cout << "The average is: " << showpoint << average << endl;        
    for (int i=0; i<=6; i++) {
        for (int j=1; j<=10; j++) {
            if (integer [i]==j) {
                times[j]++;
                break; 
            }
        }
    }//calculating the times of appearence of the number from 1 to 10
    int max_=0, mode;
    for (int i=1;i<=10;i++) {
        if (times[i]>max_) {
            max_=times[i];
            mode = i;
        }
    }//finding the mode
    cout << "The mode is:    " << mode <<endl;
    cout << "The mean is:    " << integer[3];
}
/*
1.
Enter seven integers: 8 3 4 4 2 4 5
Array Statistics:
The minimum is: 2
The maximum is: 8
The average is: 4.28571
The mode is:    4
The mean is:    4

2.
Enter seven integers: 1 2 3 4 5 6 7
Array Statistics:
The minimum is: 1
The maximum is: 7
The average is: 4.00000
The mode is:    1
The mean is:    4

3.
Enter seven integers: 1 1 1 11 2 3 4
INVALID INTEGER, TRY AGAIN!
Enter seven integers: 1 2 3 3 4 5 6
Array Statistics:
The minimum is: 1
The maximum is: 6
The average is: 3.42857
The mode is:    3
The mean is:    3

*/
