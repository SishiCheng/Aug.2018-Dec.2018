#include <iostream>
#include <vector>
using namespace std;

struct Person{  
    int age;   
    bool license; 
};

class Car {
private:   
    int seats;   
    Person driver;   
    vector<Person> passengers; 
public:   
    bool setNumSeats(int s) {
        seats=s;
        if (seats<=0) return false;
        else return true;
    }
    
    void setDriver(Person d) {
        driver = d;
    }
    
    int count=0;
    bool addPassenger(Person p) {
        passengers.push_back(p);
        if (driver.age<=17) {
            if (passengers[passengers.size()-1].age<17 && passengers[passengers.size()-1].age!=-1) count+=1;
            
            if (count >1) {
                cout << "Too many minors!";
                return false;
            }
            else if (passengers.size()==seats-1) {
                cout << "There is no more rooms!\n" << "Have a safe drive!";
                return false;
            }
            else return true;
        }
        else {
            if (passengers.size()==seats-1) {
                cout << "There is no more rooms!\n" << "Have a safe drive!";
                return false;
            } 
            else return true;
        }
    }
    
    //determine if the driver can drive
    bool canDrive() {
        //If not, then end the program
        if (driver.age<16 || driver.license==0) return false;
        else return true;
    }
};

int main() {
    Car a;
    Person b;
    int s;
    //Prompting the user to enter the number of seats for a car 
    cout << "Enter the number of seats in the car: ";
    cin >> s;
    while (a.setNumSeats(s)==false) {
        cout << "Enter 1 or greater!\n" << "Enter the number of seats in the car: ";
        cin >> s;
    }
    
    //Prompting the user to enter information for the driver
    cout << "Enter the age of the driver: ";
    cin >> b.age;
    cout << "Does the driver have a license? (0 for no, 1 for yes) ";
    cin >> b.license;
    
    a.setDriver(b);
    
    if (a.canDrive()==false) {
        cout << "The driver is not allowed to drive!";
        return 0;
    }
    
    //prompting the user to enter information and add as many passengers as they wish unless the car is already full or if the restrictions on Junior drivers are violated 
    while (b.age!=-1) {
        
        cout << "Enter a passenger's age (-1 if done): ";
        cin >> b.age;
        
        //If the passenger should not have been added, then end the program
        if (a.addPassenger(b)==false) return 0;
    }
    cout << "Have a safe drive!";
}

/*
1.
Enter the number of seats in the car: 2
Enter the age of the driver: 18
Does the driver have a license? (0 for no, 1 for yes) 0
The driver is not allowed to drive!

2.
Enter the number of seats in the car: 6
Enter the age of the driver: 4
Does the driver have a license? (0 for no, 1 for yes) 0
The driver is not allowed to drive!

3.
Enter the number of seats in the car: 4
Enter the age of the driver: 16
Does the driver have a license? (0 for no, 1 for yes) 1
Enter a passenger's age (-1 if done): 16
Enter a passenger's age (-1 if done): 16
Too many minors!

4.
Enter the number of seats in the car: 4
Enter the age of the driver: 42
Does the driver have a license? (0 for no, 1 for yes) 1
Enter a passenger's age (-1 if done): 18
Enter a passenger's age (-1 if done): 16
Enter a passenger's age (-1 if done): 15
There is no more rooms!
Have a safe drive!

5.
Enter the number of seats in the car: 8
Enter the age of the driver: 16
Does the driver have a license? (0 for no, 1 for yes) 1
Enter a passenger's age (-1 if done): 35
Enter a passenger's age (-1 if done): 37
Enter a passenger's age (-1 if done): 12
Enter a passenger's age (-1 if done): 65
Enter a passenger's age (-1 if done): -1
Have a safe drive!
*/