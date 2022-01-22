#include <iostream>
using namespace std;

int f(int n);

int main() {
    int n;
    cout << "Enter a number greater than or equal to 0: ";
    cin >> n;
    //Input validation in the main function for integers greater than or equal to 0
    while (n<0) {
        cout << "Please enter a valid number!\n" << "Enter a number greater than or equal to 0: ";
        cin >> n;
    }
    f(n);
}

int f(int n) {
    //Display on console output for each iteration of the factorial calculation, including 𝑓(0) and 𝑓(𝑛)
    //recursive case
    if (n>0) {
        int fn = 2*f(n-1)-3;
        cout << "f(" << n << "): " << fn <<endl;
        return fn;
    }
    //base case
    else {
        cout << "f(0): 5" <<endl;
        return 5;
    }
}
/*
1.
Enter a number greater than or equal to 0: 8
f(0): 5
f(1): 7
f(2): 11
f(3): 19
f(4): 35
f(5): 67
f(6): 131
f(7): 259
f(8): 515

2.
Enter a number greater than or equal to 0: 5
f(0): 5
f(1): 7
f(2): 11
f(3): 19
f(4): 35
f(5): 67
*/
