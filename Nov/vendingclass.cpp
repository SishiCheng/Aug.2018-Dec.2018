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

class vendingMachine {
    public:
    vector<item> items;
    
    // return the total value of all items in the vending machine
    float totalValue() {
        float total=0.0;
        for (int i=0; i<items.size(); i++) {
            total+=items[i].price*items[i].stock;
        }
        return total;
    }
    
    //add “count” items to the vending machine with the given "name"
    void stock(string name, int count) {
        for (int i=0; i<items.size(); i++) {
            if (items[i].name==name) {
                items[i].stock+=count;
                cout << "You have added " << count << " units of " << name << ". Now there are "
                     << items[i].stock << " units in the machine\n";
                return;
            }
        }
    
        cout << "The item you are adding, " << name << ", was not in the machine." <<endl
             << "Please enter the following information for this item" <<endl << "code: ";
        items.push_back({name});
        cin >> items[items.size()-1].code;
        bool DoesItExist = false;
        for (int j=0; j<items.size()-1; j++) {
            if (items[j].code==items[items.size()-1].code) {
                DoesItExist = true;
                break;
            }
        }
    
        // if the code is already being used by the machine, prompt the user for a different code
        while (DoesItExist==true) {
            cout << "Enter a new code:\n";
            cin >> items[items.size()-1].code;
            for (int j=0; j<items.size()-1; j++) {
                if (items[j].code==items[items.size()-1].code) {
                    DoesItExist = true;
                    break;
                }
                else DoesItExist = false;
            }
        }

        // if the item to be added was not already in the machine, prompt the user for its code and price (in dollars)
        cout << "price: $";
        cin >> items[items.size()-1].price;
        items[items.size()-1].stock+=count;
        cout << "You have added " << count << " units of " << name << ". Now there are "
             << items[items.size()-1].stock << " units in the machine\n";
}
        
    void purchase(float balance, int code) {
        // if "code" is not mapped to an item, display error message
        bool DoesItExist = false;
        for (int j=0; j<items.size(); j++) {
            if (items[j].code==code) {
                DoesItExist = true;
            }
        }
        if (DoesItExist!=true) {
            cout << "Item not found!\n";
            return;
        }
    
        // if the item is more expensive than "balance", display error message
        for (int i=0; i<items.size(); i++) {
            if (items[i].code==code && items[i].price>balance) {
                cout << "You have selected to purchase " << items[i].name << ", which costs $" 
                     << fixed << setprecision(2) << items[i].price <<endl << "Your balance is $" 
                     << fixed << setprecision(2) << balance << ". Not enough money!\n";
                return;
            }
        }
    
        for (int i=0; i<items.size(); i++) {
            if (items[i].code==code && items[i].stock==0) {
                cout << "Item not found!\n";
                return;
            }
        }
    
        // if purchase is successful, display change to be returned in dollars and update the stock of that item.
        for (int i=0; i<items.size(); i++) {
            if (items[i].code==code) {
                cout << "You have selected to purchase " << items[i].name << ", which costs $" 
                     << fixed << setprecision(2) << items[i].price <<endl << "Thank you for purchasing! Your change is: $"
                     << fixed << setprecision(2) << balance-items[i].price <<endl;
                items[i].stock--;
                return;
            }
        }
    }
};

int main() {
    vendingMachine vendingMachine1;
    vendingMachine1.stock("Doublemint Gum", 1);
    cout << "-------------------" << endl;
    vendingMachine1.purchase(.50, 100);
    cout << "-------------------" << endl;
    vendingMachine1.stock("Chocolate Chip Cookies", 10);
    cout << "-------------------" << endl;
    vendingMachine1.stock("Chocolate Chip Cookies", 5);
    cout << "-------------------" << endl;
    vendingMachine1.purchase(.75, 100);
    cout << "-------------------" << endl;
    vendingMachine1.purchase(1.00, 100);
    cout << "-------------------" << endl;
    cout << "This vending machine now has $" << vendingMachine1.totalValue() << fixed << setprecision(2) << " worth of items" << endl;
    cout << "Press any key to continue . . .";
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
