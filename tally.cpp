#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N=-2;
    int nums=0;
    int *tally;
    
    while (N<0) {
        //Prompts the user to enter an arbitrary number of integers within a given range (0 to N inclusive)
        cout << "Enter the range N: " ;
        cin >> N;
        //Nshould be 1 or greater
        if (N<0) {
           cout << "N must be greater than 0!Try again.\n";
        }
    }
    //Use dynamic memory allocationto declare the tallyarray
    tally=new int[N+1];
    
    //The other integers should be between 1 and Ninclusive
    while (nums!=-1) {
        cout << "Enter a number between 0 and " << N << ": ";
        cin >> nums;
        //Allows theuser to decide when they are done entering the integers
        if (nums==-1) {
            cout << "User input complete.\n";
            break;
        }
        else if (nums<0 || nums>N) {
            cout << "Invalid input! Try again.\n";
            continue;
        }
        else {
            //Uses an array named tally to keep track of the count of each value that was entered by the user
            *(tally+nums)=*(tally+nums)+1;
        }
    }
    
    for (int i=0; i<=N; i++) {
        //Displays a well-formatted table that contains each value that was entered at least once by the user
        if (*(tally+i)>0)
        cout << "The number " << setw(2) << right << i <<" occurs" << setw(5) << right << *(tally+i) << "." <<endl;
    }
}
/*
1.
Enter the range N: -3
N must be greater than 0!Try again.
Enter the range N: 10
Enter a number between 0 and 10: 3
Enter a number between 0 and 10: 3
Enter a number between 0 and 10: 10
Enter a number between 0 and 10: 15
Invalid input! Try again.
Enter a number between 0 and 10: 4
Enter a number between 0 and 10: 3
Enter a number between 0 and 10: 7
Enter a number between 0 and 10: 9
Enter a number between 0 and 10: -5
Invalid input! Try again.
Enter a number between 0 and 10: 9
Enter a number between 0 and 10: -1
User input complete.
The number  3 occurs    3.
The number  4 occurs    1.
The number  7 occurs    1.
The number  9 occurs    2.
The number 10 occurs    1.

2.
Enter the range N: 28
Enter a number between 0 and 28: 4
Enter a number between 0 and 28: 3
Enter a number between 0 and 28: 0
Enter a number between 0 and 28: 9
Enter a number between 0 and 28: 8
Enter a number between 0 and 28: -1
User input complete.
The number  0 occurs    1.
The number  3 occurs    1.
The number  4 occurs    1.
The number  8 occurs    1.
The number  9 occurs    1.
*/
