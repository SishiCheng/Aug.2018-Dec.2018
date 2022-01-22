#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string item1;
    string item2;
    string item3;
    cout << "Please Enter names of 3 one-word items to purchase (each name must be less than 10 letters long): \n";
    cin >> item1;
    int length1;
    length1=item1.length();
    int length2;
    length2=item2.length();
    int length3;
    length3=item3.length();
    if (length1 < 10) {
        cin >> item2;
        length2=item2.length();
        if (length2 < 10) {
            cin >> item3;
            length3=item3.length();
            if (length3 < 10) {
                cout << "You have purchased 3 items. Enter their prices in US Dollars (must be less than $1,000):\n";
            }
            else {
                cout << "This item is 10 or more letters long";
            }
        }
        else { 
          cout << "This item is 10 or more letters long";
        }
    }
    else {
        cout << "This item is 10 or more letters long";
    }
    float price1;
    float price2;
    float price3;
    cin >> price1;
    if (price1 > 1000) {
        cout << "You entered an invalid price";
    }
    else {
        cin >> price2;
        if (price2 > 1000) {
            cout << "You entered an invalid price";
        }
        else {
            cin >> price3;
            if (price3 > 1000) {
                cout << "You entered an invalid price";
            }
            else {
                cout << "+---------+-------+" <<endl << "|      RECEIPT    |" <<endl << "+---------+-------+" <<endl;
            }
        }
    }
    if (price1 < 10) {
        cout << "|" << setw (9) << left << item1 << "|" << setw(3) << right << "$" << setw(4) << right << fixed << setprecision(2) << showpoint << price1 << "|" <<endl;
    }
    else if (price1 >= 100) {
        cout << "|" << setw (9) << left << item1 << "|" << "$" << setw(6) << right << fixed << setprecision(2) << showpoint << price1 << "|" <<endl;
    }
    else {
        cout << "|" << setw (9) << left << item1 << "|" << setw(2) << right << "$" << setw(5) << right << fixed << setprecision(2) << showpoint << price1 << "|" <<endl;
    }
    
    if (price2 < 10) {
        cout << "|" << setw (9) << left << item2 << "|" << setw(3) << right << "$" << setw(4) << right << fixed << setprecision(2) << showpoint << price2 << "|" <<endl;
    }
    else if (price2 >= 100) {
        cout << "|" << setw (9) << left << item2 << "|" << "$" << setw(6) << right << fixed << setprecision(2) << showpoint << price2 << "|" <<endl;
    }
    else {
        cout << "|" << setw (9) << left << item2 << "|" << setw(2) << right << "$" << setw(5) << right << fixed << setprecision(2) << showpoint << price2 << "|" <<endl;
    }
    
    if (price3 < 10) {
        cout << "|" << setw (9) << left << item3 << "|" << setw(3) << right << "$" << setw(4) << right << fixed << setprecision(2) << showpoint << price3 << "|" <<endl;
    }
    else if (price3 >= 100) {
        cout << "|" << setw (9) << left << item3 << "|" << "$" << setw(6) << right << fixed << setprecision(2) << showpoint << price3 << "|" <<endl;
    }
    else {
        cout << "|" << setw (9) << left << item3 << "|" << setw(2) << right << "$" << setw(5) << right << fixed << setprecision(2) << showpoint << price3 << "|" <<endl;
    }
    cout << "+---------+-------+" <<endl;
    float total;
    total=price1+price2+price3;
    if (total < 10) {
        cout << "|" << "TOTAL:" << setw(7) << right << "$" << setw(4) << right << total << "|" <<endl << "+---------+-------+" <<endl;
    }
    else if (total >= 10 and total <100) {
        cout << "|" << "TOTAL:" << setw(6) << right << "$" << setw(5) << right << total << "|" <<endl << "+---------+-------+" <<endl;
    }
    else if (total >= 100 and total < 1000) {
        cout << "|" << "TOTAL:" << setw(5) << right << "$" << setw(6) << right << total << "|" <<endl << "+---------+-------+" <<endl;
    }
    else {
        cout << "|" << "TOTAL:" << setw(4) << right << "$" << setw(7) << right << total << "|" <<endl << "+---------+-------+" <<endl;
    }
    
  
 
   
}