#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int counter=0;
    float amount[100];
    while (amount[counter] != -1) {
        cout << "Enter the sale amount: $";
        cin >> amount[counter];//Prompts the user to enterfloating point numbers that represent daily sale amountsat a store
        if (amount[counter] == -1) {
            cout << "\nRESULTS:\n" <<"  Highest sale amount:" << " $";
            float max=amount[0];
            for (int i=1;i<counter;i++) {
                if (amount[i]>max) {
                    max=amount[i];
                }
            }
            cout << setw(4) << fixed << setprecision(2) << right << max <<endl;
            cout << "   Lowest sale amount:" << " $";
            float min=amount[0];
            for (int x=1;x<counter;x++) {
                if (amount[x]<min) {
                    min=amount[x];
                }
            }
            cout << setw(4) << fixed << setprecision(2) << right << min <<endl;
            cout << "  Average sale amount:" << " $";
            float sum=0,average;
            for (int j=0;j<counter;j++) {
                sum+=amount[j];
                average=sum/counter;
            }
            cout << setw(4) << fixed << setprecision(2) << right << average << "\nTnank you!";
            return 0;
        }//Allowsthe user to indicate the end of user inputs with -1. Determines and displays the maximum, minimum, and arithmetic mean (average) of the sale amounts
        while (amount[counter] < 0 && amount[counter] != -1) {
            cout << "INVALID AMOUNT, TRY AGAIN!\n" << "Enter the sale amount: $";
            cin >> amount[counter];
        }//Validatesthe user input for numbers greater than 0
        counter++;
    }
    cout << "\n\nThank you!";
}
/*
1.
Enter the sale amount: $2.00
Enter the sale amount: $-5.00
INVALID AMOUNT, TRY AGAIN!
Enter the sale amount: $1.00
Enter the sale amount: $3.00
Enter the sale amount: $4.00
Enter the sale amount: $5.00
Enter the sale amount: $-1

RESULTS:
  Highest sale amount: $5.00
   Lowest sale amount: $1.00
  Average sale amount: $3.00

Thank you!

2.
Enter the sale amount: $2.00
Enter the sale amount: $-3.00
INVALID AMOUNT, TRY AGAIN!
Enter the sale amount: $3.00
Enter the sale amount: $4.00
Enter the sale amount: $-1

RESULTS:
  Highest sale amount: $4.00
   Lowest sale amount: $2.00
  Average sale amount: $3.00
  
Tnank you!
*/