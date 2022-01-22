#include <iostream>

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
            cout << "Sorry, your loan request for $"<< loan << " has been rejected.";
        }
        else {
            cout << "Congratulations! Your loan request for $"<< loan << " has been accepted!";
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
}//Ask customers if they want a loan and give customers changes if he/she enter an invalid choice.

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
maybe
Invalid choice; please enter yes or no.
Would you like to take out a loan?
y
How much would you like to borrow?
45000
What is your yearly income?
15000
Congratulations! Your loan request for $45000 has been accepted!

2.
Would you like to take out a loan?
No
Thank you for visiting the bank

3.
Would you like to take out a loan?
y
How much would you like to borrow?
60000
What is your yearly income?
10001
Sorry, your loan request for $60000 has been rejected.

4.
Would you like to take out a loan?
yes
How much would you like to borrow?
4000
What is your yearly income?
10000
Sorry, your loan request for $4000 has been rejected.
*/
