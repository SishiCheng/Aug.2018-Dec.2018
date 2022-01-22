#include <iostream>
using namespace std;

class Trashcan {
private:
    string Name;
    //A max capacity of 0 indicates that the trash can does not have a size
    double Maxcapacity=0;
    //A current capacity of 0 indicates that the trash can does not have a trash bag
    double Currentcapacity=0;
    //A amountfilled of 0 indicates that the trash can does not have trash
    double Amountfilled=0;
public:
    //Set the name of the trash
    void setName(string N) {
        Name=N;
    }
    
    //Set the max capacity of trash canwith given size
    void setSize(double M) {
        Maxcapacity=M;
    }
    
    bool hasBag() {
        if (Currentcapacity==0) {
            cout << "no bag\n";
            return false;
        }
        //Return true if the trash can has a trash bag
        else {
            cout << "has bag\n";
            return true;
        }
    }
    
    bool addBag(double C ) {
        //fail if Max capacity has not been set
        if (Maxcapacity==0) {
            cout << Name << ": can't add bag (size not set)\n";
            return false;
        }
        //fail if The trash can already has a trash bag
        else if (Currentcapacity!=0) {
            cout << Name << ": can't add bag (be already there)\n";
            return false;
        }
        //Add trash of given amount, return true if successful
        else {
            //if the trash bag is smaller than the trash can, then it is limited to the size of the bag
            if (Maxcapacity>=C) {
                Currentcapacity=C;
            }
            //If the trash bag is larger than the trash can, then it is limited to the size of the trash can
            else Currentcapacity=Maxcapacity;
            cout << Name << ": add bag successful (capacity = " << Currentcapacity << " gal) \n";
            return true;
        }
    }
    
    bool addTrash(double A) {
        //fail if Max capacity has not been set
        if (Maxcapacity==0) {
            cout << Name << ": can't add trash (size not set)\n";
            return false;
        }
        //fail if The trash can has no trash bag
        else if (Currentcapacity==0) {
            cout << Name << ": can't add trash (no bag)\n";
            return false;
        }
        //fail if The trash can cannot fit the new trash
        else if (Currentcapacity<Amountfilled+A) {
            cout << Name << ": can't add trash (no room)\n";
            return false;
        }
        //Add trash of given amount, return true if successful
        else {
            Amountfilled=Amountfilled+A;
            double remain;
            remain=Currentcapacity-Amountfilled;
            cout << Name << ": add trash successful (space remaining = " << remain << " gal)\n";
            return true;
        }
    }
    
    bool isFull() {
        //Return true if the trash can is full
         if (Amountfilled==Currentcapacity) {
             cout << "is full\n";
             return true;
         }
         else return false;
    }
    
    bool isEmpty() {
        //Return true if the trash can is empty
        if (Amountfilled==0) {
            cout << "is empty\n";
            return true;
        }
        else return false;
    }
    
    double percentFull() {
        //Return current amount of trash in the trash can, in percentage of trash bag capacity
        return (Amountfilled/Currentcapacity)*100;
    }
    
    bool TakeOut() {
        //fail if Max capacity has not been set
        if (Maxcapacity==0) {
            cout << Name << ": can't take out the trash (size not set)\n";
            return false;
        }
        //fail if The trash can has no trash bag
        else if (Currentcapacity==0) {
            cout << Name << ": can't take out trash (no bag)\n";
            return false;
        }
        //fail if The trash can has a bag, but is empty
        else if (Amountfilled==0) {
            cout << Name << ": can't take out trash (already empty)\n";
            return false;
        }
        //Take out the trash (and the bag), return true if successful
        else {
            Currentcapacity=0;
            cout << Name << ": take out trash successful (taken out = " << Amountfilled << ") \n";
            Amountfilled=0;
            return true;
        }
    }
};

int main() {
    //Create a Trashcan object
    Trashcan k;
    //Set its name: "Kitchen"
    k.setName("kitchen");
    //Fail to add a bag of 10 gallons (because its size has not been set)
    k.addBag(10);
    //Set its size: 13 gallons
    k.setSize(13);
    //Confirm it does not have a bag
    k.hasBag();
    //Successfully add a bag of 10 gallons
    k.addBag(10);
    //Fail to add a bag of 10 gallons (because it already has a bag)
    k.addBag(10);
    //Confirm it has a bag
    k.hasBag();
    //Confirm it is empty
    k.isEmpty();
    //Add 5 gallons of trash
    k.addTrash(5);
    //Check its fill percentage
    cout << k.percentFull() << "% full" <<endl;
    //Add 3 gallons of trash
    k.addTrash(3);
    //Fail to add trash of 3 gallons (because it can't hold that much trash)
    k.addTrash(3);
    //Successfully add 2 gallons of trash
    k.addTrash(2);
    //Confirm it is full
    k.isFull();
    //Successfully take out the trash
    k.TakeOut();
    //Confirm it does not have a bag
    k.hasBag();
    //Fail to take out the trash (because it does not have a bag)
    k.TakeOut();
    //Successfully add a bag of 15 gallons
    k.addBag(15);
    //Fail to take out trash (because the bag is empty)
    k.TakeOut();
    //Fail to add trash of 15 gallons
    k.addTrash(15);
}

/*
1.
kitchen: can't add bag (size not set)
no bag
kitchen: add bag successful (capacity = 10 gal) 
kitchen: can't add bag (be already there)
has bag
is empty
kitchen: add trash successful (space remaining = 5 gal)
50% full
kitchen: add trash successful (space remaining = 2 gal)
kitchen: can't add trash (no room)
kitchen: add trash successful (space remaining = 0 gal)
is full
kitchen: take out trash successful (taken out = 10 gel) 
no bag
kitchen: can't take out trash (no bag)
kitchen: add bag successful (capacity = 13 gal) 
kitchen: can't take out trash (already empty)
kitchen: can't add trash (no room)
*/