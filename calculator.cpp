#include <iostream>
#include <cmath>

using namespace std;

double calc(double, char, double);

int main() {
    double x, y;
    char operater;
    double k;
    cout << "Welcome to the CMPSC-121 Function Calculator!\n\nPlease enter a mathematical expression to evaluate: ";
    cin >> x >> operater >> y;
    while (operater != '+' && operater != '-' && operater != '*' && operater != '/' && operater != '^') {
        cout << "Invalid operator, try again!\n" << "Please enter a mathematical expression to evaluate: ";
        cin >> x >> operater >> y;
    }// Validate the user input for the math operators
    while (operater == '/' && y == 0) {
        cout << "ERROR: divide by zero\n" << "Please enter a mathematical expression to evaluate: ";
        cin >> x >> operater >> y;//Validatethe user input for divide by 0 errors
        while (operater != '+' && operater != '-' && operater != '*' && operater != '/' && operater != '^') {
            cout << "Invalid operator, try again!\n" << "Please enter a mathematical expression to evaluate: ";
            cin >> x >> operater >> y;
        }
    }
    cout << x << " " << operater << " " << y << " = " << calc(x, operater, y) <<endl;
    char answer;
    cout << "Would you like to calculate another operation? ";
    cin >> answer;
    while (answer == 'y') {
        cout << "Please enter a mathematical expression to evaluate: ";
        cin >> x >> operater >> y;
        while (operater != '+' && operater != '-' && operater != '*' && operater != '/' && operater != '^') {
            cout << "Invalid operator, try again!\n" << "Please enter a mathematical expression to evaluate: ";
            cin >> x >> operater >> y;
        }
        while (operater == '/' && y == 0) {
            cout << "ERROR: divide by zero\n" << "Please enter a mathematical expression to evaluate: ";
            cin >> x >> operater >> y;
            while (operater != '+' && operater != '-' && operater != '*' && operater != '/' && operater != '^') {
                cout << "Invalid operator, try again!\n" << "Please enter a mathematical expression to evaluate: ";
                cin >> x >> operater >> y;
            }
        }
            cout << x << " " << operater << " " << y << " = " << calc(x, operater, y) <<endl;
            cout << "Would you like to calculate another operation? ";
            cin >> answer;
    }//Prompts the user to decide whether to calculate another operation or not
    if (answer == 'n') {
        return 0;
    }
}

double calc(double x, char operater, double y) {
    double k;
    if (operater == '+') {
        k = x+y;
    }
    else if (operater == '-') {
        k = x-y;
    }
    else if (operater == '*') {
        k = x*y;
    }
    else if (operater == '/') {
        k = x/y;
    }
    else {
        k = pow(x,y);
    }
    return k;//determines the result of the mathematical operation
}

/*
1.
Welcome to the CMPSC-121 Function Calculator!

Please enter a mathematical expression to evaluate: 9 + 4
9 + 4 = 13
Would you like to calculate another operation? y
Please enter a mathematical expression to evaluate: 20 / 0
ERROR: divide by zero
Please enter a mathematical expression to evaluate: 20 / 3
20 / 3 = 6.66667
Would you like to calculate another operation? y
Please enter a mathematical expression to evaluate: 19 % 3
Invalid operator, try again!
Please enter a mathematical expression to evaluate: 19 * 3
19 * 3 = 57
Would you like to calculate another operation? y
Please enter a mathematical expression to evaluate: 2 ^ 3
2 ^ 3 = 8
Would you like to calculate another operation? n

3.
Welcome to the CMPSC-121 Function Calculator!

Please enter a mathematical expression to evaluate: 20 / 1
20 / 1 = 20
Would you like to calculate another operation? y
Please enter a mathematical expression to evaluate: 20 / 0
ERROR: divide by zero
Please enter a mathematical expression to evaluate: 20 ) 0
Invalid operator, try again!
Please enter a mathematical expression to evaluate: 7 ^ 7
7 ^ 7 = 823543
Would you like to calculate another operation? n
*/
