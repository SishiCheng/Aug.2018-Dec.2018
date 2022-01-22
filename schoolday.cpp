#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

struct Course {
    string coursename;
    int numberoflecturesperweek;
    vector<string> detail;
};

struct Student {
    string firstname;
    char middleinitial;
    string lastname;
    string digitpsuidnumber;
    string psuusername;
    vector<Course> enrolledcourses;
};

int main() {
    ifstream fin;
    string temp;
    fin.open("HW13_912345678.txt");
    
    Student s;
    //Reads a text file
    fin >> temp >> s.firstname
        >> temp >> s.middleinitial
        >> temp >> s.lastname
        >> temp >> s.digitpsuidnumber
        >> temp >> s.psuusername;
    getline(fin,temp);
    getline(fin,temp);

    bool IsItAlpha;
    while (fin.eof()==false) {
        getline(fin, temp);
        IsItAlpha = isalpha(temp[0]);
        if (IsItAlpha==true) {
            s.enrolledcourses.push_back({temp,0});
        }
        else if (s.enrolledcourses.size()-1>=0 && temp[0]=='-') {
            s.enrolledcourses[s.enrolledcourses.size()-1].numberoflecturesperweek++; 
            s.enrolledcourses[s.enrolledcourses.size()-1].detail.push_back(temp);
        }
    }
 
    //Displays a simplified version of it to the console window
    cout << "FNAME: " << s.firstname <<endl << "MINIT: " << s.middleinitial <<endl;
    cout << "LNAME: " << s.lastname <<endl << "ID:    " << s.digitpsuidnumber <<endl;
    cout << "USER:  " << s.psuusername <<endl <<endl;
    
    char choice;
    //Accepting user input for a character representing a weekday:
    cout << "Select a weekday (M, T, W, R, F): ";
    cin >> choice;
    while (choice!='M' && choice!='T' && choice!='W' && choice!='R' && choice!='F') {
        cout << "Invalid input, try again!\n" << "Select a weekday (M, T, W, R, F): ";
        cin >> choice;
    }
    
    //Printing information about all lectures scheduled on that day
    cout <<endl;
    for (int j=0; j<s.enrolledcourses.size(); j++) {
        cout << s.enrolledcourses[j].coursename <<endl;
        for (int q=0; q<s.enrolledcourses[j].numberoflecturesperweek; q++) {
            if (s.enrolledcourses[j].detail[q][2]==choice) {
                cout << s.enrolledcourses[j].detail[q] << endl;
            }
        }
    }
}

/*
FNAME: Andrew
MINIT: S
LNAME: Yu
ID:    912345678
USER:  auy77

Select a weekday (M, T, W, R, F): T

CMPSC121-002-003L
- T 10 05 AM 110 Lab
MATH140-001
- T 12 25 PM  50 Lecture
PSU007-001
ENGL101-004
PHYS211-003-006L
- T  3 35 PM  90 Lecture

*/
