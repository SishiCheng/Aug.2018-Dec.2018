#include <iostream>
#include <cmath>

using namespace std;

char Askloan();
double Askincome();
double Askamount();
bool Decideloan(double income, double loan);

int main() {
    if (Askloan() == 'y') {
        double loan = Askamount();
        double income = Askincome();
        bool dicision = Decideloan(income, loan);
        if (dicision == false) {
            int x = loan;
            int counter = 0;
            int y;
            while (x > 1000) {
                x=x/1000;
                counter++;
            }// Use the loop if the loan is bigger than 1000 to divide loan by 1000, and culculate the number of the loop.
            y = loan/pow(1000, counter);// 
            cout << "Sorry, your loan request for $"<< y;
            int z = loan - y*pow(1000, counter);
            while (counter>=1) {
                counter--;
                cout << ",";
                y = z/pow(1000, counter);
                if (y<10) {
                    cout << "00";
                }
                else if (y<100) {
                    cout << "0";
                }
                cout << y;
                z = z - y*pow(1000, counter);
            }// add the comma between each three numbers
            cout <<" has been rejected.\n";
            if (Askloan() == 'y') {
                double loan = Askamount();
                double income = Askincome();
                bool dicision = Decideloan(income, loan);
                if (dicision == false) {
                    int x = loan;
                    int counter = 0;
                    int y;
                    while (x > 1000) {
                        x=x/1000;
                        counter++;
                    }
                    y = loan/pow(1000, counter);
                    cout << "Sorry, your loan request for $"<< y;
                    int z = loan - y*pow(1000, counter);
                    while (counter>=1) {
                        counter--;
                        cout << ",";
                        y = z/pow(1000, counter);
                        if (y<10) {
                            cout << "00";
                        }
                        else if (y<100) {
                            cout << "0";
                        }
                        cout << y;
                        z = z - y*pow(1000, counter);
                    }
                    cout << " has been rejected.";
                }    
                else {
                    int x = loan;
                    int counter = 0;
                    int y;
                    while (x > 1000) {
                        x=x/1000;
                        counter++;
                    }
                    y = loan/pow(1000, counter);
                    cout << "Congratulations! Your loan request for $"<< y;
                    int z = loan - y*pow(1000, counter);
                    while (counter>=1) {
                        counter--;
                        cout << ",";
                        y = z/pow(1000, counter);
                        if (y<10) {
                            cout << "00";
                        }
                        else if (y<100) {
                            cout << "0";
                        }
                        cout << y;
                        z = z - y*pow(1000, counter);
                    }
                     cout << " has been accepted!";
                    }
            }
        } 
        else {
            int x = loan;
            int counter = 0;
            int y;
            while (x > 1000) {
                x=x/1000;
                counter++;
            }
            y = loan/pow(1000, counter);
            cout << "Congratulations! Your loan request for $"<< y;
            int z = loan - y*pow(1000, counter);
            while (counter>=1) {
                counter--;
                cout << ",";
                y = z/pow(1000, counter);
                if (y<10) {
                    cout << "00";
                }
                else if (y<100) {
                    cout << "0";
                }
                cout << y;
                z = z - y*pow(1000, counter);
                }
                cout << " has been accepted!";
        }
    }
    else {
        cout << "Thank you for visiting the bank";
    }
}//use different functions to help customer input their information of request a loan for the bank to decide whether the customer can request a loan 

char Askloan() {
    string l;
    cout << "Would you like to take out a loan?\n";
    cin >> l;
    while (l != "Y" && l != "y" && l != "Yes" && l != "yes" && l != "N" && l != "n" && l != "No" && l != "no")
    {
        cout << "Invalid choice; please enter yes or no.\nWould you like to take out a loan?\n";
        cin >> l;
    }
    if (l ==  "yes" || l == "Yes" || l == "Y" || l == "y") {
        return 'y';
    }
    else {
        return 'n';
    }
}//Ask customers if they want a loan, and give customers changes if he/she enter an invalid choice.

double Askamount() {
    double loan;
    cout << "How much would you like to borrow?\n";
    cin >> loan;
    return loan;
}// Ask customer how much he/she want to borrow

double Askincome() {
    double income;
    cout << "What is your yearly income?\n";
    cin >> income;
    return income;
}// Ask the amount of the customer's yearly income

bool Decideloan(double income, double loan) {
    if (income <= 10000) {
        return false;
    }
    else if (income > 10000 && income < 100000) {
        if (income * 5 >= loan) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }// make a decision according to the income amount
}
/*
1.
Would you like to take out a loan?
y
How much would you like to borrow?
5000000
What is your yearly income?
45000
Sorry, your loan request for $5,000,000 has been rejected.
Would you like to take out a loan?
Y
How much would you like to borrow?
50000
What is your yearly income?
45000
Congratulations! Your loan request for $50,000 has been accepted!
2.
Would you like to take out a loan?
yes
How much would you like to borrow?
500000
What is your yearly income?
500001
Congratulations! Your loan request for $500,000 has been accepted!
3.
Would you like to take out a loan?
Yes
How much would you like to borrow?
5000000
What is your yearly income?
100001
Congratulations! Your loan request for $5,000,000 has been accepted!
*/
