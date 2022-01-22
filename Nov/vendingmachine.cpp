#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct item {
    string name;// name of the item
    int code;// numerical code entered to select the item
    float price; // price per unit of the item
    int stock;// number of items available in the machine
};

float totalValue(vector<item> vendingMachine);
void stock(string name, int count, vector<item> &vendingMachine);
void purchase(float balance, int code, vector<item> &vendingMachine);

int main() {
    vector<item> vendingMachine;
    stock("Doublemint Gum", 1, vendingMachine);
    cout << "-------------------" << endl;
    purchase(.50, 100, vendingMachine);
    cout << "-------------------" << endl;
    stock("Chocolate Chip Cookies", 10, vendingMachine);
    cout << "-------------------" << endl;
    stock("Chocolate Chip Cookies", 5, vendingMachine);
    cout << "-------------------" << endl;
    purchase(.75, 100, vendingMachine);
    cout << "-------------------" << endl;
    purchase(1.00, 100, vendingMachine);
    cout << "-------------------" << endl;
    cout << "This vending machine now has $" << totalValue(vendingMachine) << fixed << setprecision(2) << " worth of items" << endl;
    cout << "Press any key to continue . . .";
}

// return the total value of all items in the vending machine
float totalValue(vector<item> vendingMachine) {
    float total=0.0;
    for (int i=0; i<vendingMachine.size(); i++) {
        total+=vendingMachine[i].price*vendingMachine[i].stock;
    }
    return total;
}

//add “count” items to the vending machine with the given "name"
void stock(string name, int count, vector<item> &vendingMachine) {
    for (int i=0; i<vendingMachine.size(); i++) {
        if (vendingMachine[i].name==name) {
            vendingMachine[i].stock+=count;
            cout << "You have added " << count << " units of " << name << ". Now there are "
                 << vendingMachine[i].stock << " units in the machine\n";
            return;
        }
    }
    
    cout << "The item you are adding, " << name << ", was not in the machine." <<endl
         << "Please enter the following information for this item" <<endl << "code: ";
    vendingMachine.push_back({name});
    cin >> vendingMachine[vendingMachine.size()-1].code;
    bool DoesItExist = false;
    for (int j=0; j<vendingMachine.size()-1; j++) {
        if (vendingMachine[j].code==vendingMachine[vendingMachine.size()-1].code) {
            DoesItExist = true;
            break;
        }
    }
    
    // if the code is already being used by the machine, prompt the user for a different code
    while (DoesItExist==true) {
        cout << "Enter a new code:\n";
        cin >> vendingMachine[vendingMachine.size()-1].code;
        for (int j=0; j<vendingMachine.size()-1; j++) {
            if (vendingMachine[j].code==vendingMachine[vendingMachine.size()-1].code) {
                DoesItExist = true;
                break;
            }
            else DoesItExist = false;
        }
    }

    // if the item to be added was not already in the machine, prompt the user for its code and price (in dollars)
    cout << "price: $";
    cin >> vendingMachine[vendingMachine.size()-1].price;
    vendingMachine[vendingMachine.size()-1].stock+=count;
    cout << "You have added " << count << " units of " << name << ". Now there are "
         << vendingMachine[vendingMachine.size()-1].stock << " units in the machine\n";
}

void purchase(float balance, int code, vector<item> &vendingMachine) {
    // if "code" is not mapped to an item, display error message
    bool DoesItExist = false;
    for (int j=0; j<vendingMachine.size(); j++) {
        if (vendingMachine[j].code==code) {
            DoesItExist = true;
        }
    }
    if (DoesItExist!=true) {
        cout << "Item not found!\n";
        return;
    }
    
    // if the item is more expensive than "balance", display error message
    for (int i=0; i<vendingMachine.size(); i++) {
        if (vendingMachine[i].code==code && vendingMachine[i].price>balance) {
            cout << "You have selected to purchase " << vendingMachine[i].name << ", which costs $" 
                 << fixed << setprecision(2) << vendingMachine[i].price <<endl << "Your balance is $" 
                 << fixed << setprecision(2) << balance << ". Not enough money!\n";
            return;
        }
    }
    
    for (int i=0; i<vendingMachine.size(); i++) {
        if (vendingMachine[i].code==code && vendingMachine[i].stock==0) {
            cout << "Item not found!\n";
            return;
        }
    }
    
    // if purchase is successful, display change to be returned in dollars and update the stock of that item.
    for (int i=0; i<vendingMachine.size(); i++) {
        if (vendingMachine[i].code==code) {
            cout << "You have selected to purchase " << vendingMachine[i].name << ", which costs $" 
                 << fixed << setprecision(2) << vendingMachine[i].price <<endl << "Thank you for purchasing! Your change is: $"
                 << fixed << setprecision(2) << balance-vendingMachine[i].price <<endl;
            vendingMachine[i].stock--;
            return;
        }
    }
}

/*
1.
The item you are adding, Doublemint Gum, was not in the machine.
Please enter the following information for this item
code: 100
price: $0.75
You have added 1 units of Doublemint Gum. Now there are 1 units in the machine
-------------------
You have selected to purchase Doublemint Gum, which costs $0.75
Your balance is $0.50. Not enough money!
-------------------
The item you are adding, Chocolate Chip Cookies, was not in the machine.
Please enter the following information for this item
code: 100
Enter a new code:
101
price: $0.5
You have added 10 units of Chocolate Chip Cookies. Now there are 10 units in the machine
-------------------
You have added 5 units of Chocolate Chip Cookies. Now there are 15 units in the machine
-------------------
You have selected to purchase Doublemint Gum, which costs $0.75
Thank you for purchasing! Your change is: $0.00
-------------------
Item not found!
-------------------
This vending machine now has $7.50 worth of items
Press any key to continue . . .

2.
The item you are adding, Doublemint Gum, was not in the machine.
Please enter the following information for this item
code: 100
price: $0.75
You have added 1 units of Doublemint Gum. Now there are 1 units in the machine
-------------------
You have selected to purchase Doublemint Gum, which costs $0.75
Your balance is $0.50. Not enough money!
-------------------
The item you are adding, Chocolate Chip Cookies, was not in the machine.
Please enter the following information for this item
code: 101
price: $2.00
You have added 10 units of Chocolate Chip Cookies. Now there are 10 units in the machine
-------------------
You have added 5 units of Chocolate Chip Cookies. Now there are 15 units in the machine
-------------------
You have selected to purchase Doublemint Gum, which costs $0.75
Thank you for purchasing! Your change is: $0.00
-------------------
Item not found!
-------------------
This vending machine now has $30.00 worth of items
Press any key to continue . . .
*/
