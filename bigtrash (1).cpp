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
            cout << Name << ": take out trash successful (taken out = " << Amountfilled << ")\n";
            Amountfilled=0;
            return true;
        }
    }
    
    bool TakeOut(Trashcan &T) {
        if (T.Currentcapacity-T.Amountfilled<Amountfilled) {
            cout << T.Name << ": can't add trash (no room)\n";
            return false;
        }
        else if (T.Currentcapacity==0) {
            cout << T.Name << ": can't add trash (no bag)\n";
            return false;
        }
        else {
            T.Amountfilled=T.Amountfilled+Amountfilled;
            double remain;
            remain=T.Currentcapacity-T.Amountfilled;
            cout << T.Name << ": add trash successful (space remaining = " << remain << " gal)\n";
            cout << Name << ": take out trash successful (take out = " << Amountfilled << ")\n";
        }
    }
};

int main() {
    //Create a Trashcan object
    Trashcan k;
    //Set its name: "Kitchen"
    k.setName("kitchen");
    //Set its size: 13 gallons
    k.setSize(13);
    //Successfully add a bag of 15 gallons
    k.addBag(15);
    //Create another Trashcan object
    Trashcan G;
    //Set its name: "Kitchen"
    G.setName("Garage");
    //Set its size: 55 gallons
    G.setSize(55);
    //Successfully add a bag of 55 gallons
    G.addBag(55);
    //Add 50 gallons of trash to the Garage trash can
    G.addTrash(50);
    //Add 10 gallons of trash to the Kitchen trash can
    k.addTrash(10);
    //Fail to take out Kitchen trash can to the Garage trash can (because it can't hold that much trash)
    k.TakeOut(G);
    //Successfully take out Garage trash
    G.TakeOut();
    //Successfully add a 55 gallon trash bag to the Garage trash can
    G.addBag(55);
    //Successfully take out Kitchen trash can to the Garage trash can
    k.TakeOut(G);
}