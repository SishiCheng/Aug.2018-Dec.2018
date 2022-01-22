#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

struct Course {
    string coursename;
    int numberoflecturesperweek;
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
        }
    }
    
    //Displays a simplified version of it to the console window
    cout << "FNAME: " << s.firstname <<endl << "MINIT: " << s.middleinitial <<endl;
    cout << "LNAME: " << s.lastname <<endl << "ID:    " << s.digitpsuidnumber <<endl;
    cout << "USER:  " << s.psuusername <<endl <<endl;
    for (int j=0; j<s.enrolledcourses.size(); j++) {
        cout << s.enrolledcourses[j].coursename <<endl 
             << s.enrolledcourses[j].numberoflecturesperweek << " lectures" <<endl;
    }
}

/*
FNAME: Andrew
MINIT: S
LNAME: Yu
ID:    912345678
USER:  auy77

CMPSC121-002-003L
3 lectures
MATH140-001
4 lectures
PSU007-001
1 lectures
ENGL101-004
3 lectures
PHYS211-003-006L
3 lectures
*/
