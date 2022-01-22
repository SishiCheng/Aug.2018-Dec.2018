#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;

class Lecture {
private:
    string dayoftheweek;
    int hour;
    int minute;
    string ampm;
    int duration;
    string whetheritisalaborlecturesession;

public:
    Lecture() {}
    Lecture(string d, int h, int m, string a, int u, string w) {
        dayoftheweek=d;
        hour=h;
        minute=m;
        ampm=a;
        duration=u;
        whetheritisalaborlecturesession=w;
    }
    
    string getDayoftheweek() {
        return dayoftheweek;
    }
    
    string getAmpm() {
        return ampm;
    }
    
    int getHour() {
        return hour;
    }
    
    int getMinute() {
        return minute;
    }
    
    int getDuration() {
        return duration;
    }
    
    //Print information about the meeting time to console window
    void printMeetingtime() {
        if (minute<9) {
           cout << "- " << dayoftheweek << right << setw(3) << hour << right << setw(2) << "0" << minute
                << " " << ampm << right << setw(4) << duration << " " << whetheritisalaborlecturesession <<endl; 
        }
        else {
            cout << "- " << dayoftheweek << right << setw(3) << hour << right << setw(3) << minute
                 << " " << ampm << right << setw(4) << duration << " " << whetheritisalaborlecturesession <<endl; 
        }
        
    }
    
    //Print information about the meeting time to file
    void printMeetingtime(ofstream &fout) {
        if (minute>9) {
           fout << "- " << dayoftheweek << right << setw(3) << hour << right << setw(3) << "0" << minute
                << " " << ampm << right << setw(4) << duration << " " << whetheritisalaborlecturesession <<endl; 
        }
        else {
            fout << "- " << dayoftheweek << right << setw(2) << hour << right << setw(3) << "0" << minute
                 << " " << ampm << right << setw(4) << duration << " " << whetheritisalaborlecturesession <<endl; 
        }
    }
};

class Course {
private:
    string coursename;
    vector<Lecture> enrolledlectures;
    
public:
    Course(string c, vector<Lecture> l) {
        coursename=c;
        enrolledlectures.swap(l);
    }
    Course() {}
    
    string getCoursename() {
        return coursename;
    }
    
    int getThenumberoflectures() {
        return enrolledlectures.size();
    }
    
    Lecture getLecture(int index) {
        return enrolledlectures[index];
    }
    
    //Print information about all meeting times (to console window)
    void printAllmeetingtime() {
        for (int t=0; t<getThenumberoflectures(); t++) {
            getLecture(t).printMeetingtime();
        }
    }
    
    //Print information about all meeting times (to file)
    void printAllmeetingtime(ofstream &fout) {
        for (int t=0; t<getThenumberoflectures(); t++) {
            getLecture(t).printMeetingtime(fout);
        }
    }
};

class Student {
private:
    string firstName;
    char middleInitial;
    string lastName;
    string digitpsuidnumber;
    string psuusername;
    vector<Course> enrolledcourses;

public:
    Student() {}
    Student(string f, char m, string l, string d, string p) {
        firstName=f;
        middleInitial=m;
        lastName=l;
        digitpsuidnumber=d;
        psuusername=p;
    }
    
    int getThenumberofcourse() {
        return enrolledcourses.size();
    }
    
    Course getCourse(int index) {
        return enrolledcourses[index];
    }
    
    //Add a course
    void addCourse(Course c) {
        enrolledcourses.push_back(c);
    }
    
    //Remove a course
    void removeCourse(int index) {
        for (int i=index; i<enrolledcourses.size()-1; i++) {
            enrolledcourses[i]=enrolledcourses[i+1];
        }
        enrolledcourses.pop_back();
    }
    
    //Check whether the student will be available (not in class) at a certain time and day of the week
    bool wetherAvailable(string theday, int thehour, int theminute, string theampm) {
        int starthour, endhour, endminute, startminute, becomeminutee, becomeminutes, becomeminutes2;
        bool whetherconflict = false;
        for (int t=0; t<getThenumberofcourse(); t++) {
            for (int i=0; i<enrolledcourses[t].getThenumberoflectures(); i++) {
                if (enrolledcourses[t].getLecture(i).getDayoftheweek()==theday) {
                    if (enrolledcourses[t].getLecture(i).getAmpm()=="PM") {
                        starthour=enrolledcourses[t].getLecture(i).getHour()+12;
                        endhour=(enrolledcourses[t].getLecture(i).getMinute()+enrolledcourses[t].getLecture(i).getDuration())/60+starthour;
                        endminute=(starthour+enrolledcourses[t].getLecture(i).getDuration())%60;
                        startminute=enrolledcourses[t].getLecture(i).getMinute();
                    }
                    
                    if ((theampm=="PM" || theampm == "pm") && thehour!=12) {
                        becomeminutes2=(thehour+12)*60+theminute;
                    }
                    else becomeminutes2=thehour*60+theminute;
                    
                    becomeminutes=starthour*60+startminute;
                    becomeminutee=endhour*60+endminute;

                    if (becomeminutes2>becomeminutes && becomeminutes2<becomeminutee) {
                        whetherconflict=true;
                    }

                    if (theday=="U") {
                        theday="Sunday";
                    }
                    else if (theday=="M") {
                        theday=="Monday";
                    }
                    else if (theday=="T") {
                        theday="Tuesday";
                    }
                    else if (theday=="W") {
                        theday="Wednesday";
                    }
                    else if (theday=="R") {
                        theday=="Thursday";
                    }
                    else if (theday=="F") {
                        theday="Friday";
                    }
                    else theday="Sunday";
                    
                    
                        
                    if (whetherconflict==false) {
                        cout << "Student is available at: " << theday << thehour << ":" << theminute 
                             << theampm <<endl <<endl;
                        return true;
                    }
                    else {
                        cout << "---NOT AVAILABLE---\n" << "CLASS TIME: " << enrolledcourses[i].getCoursename() <<endl; 
                        enrolledcourses[t].getLecture(i).printMeetingtime();
                        cout << "REQUESTED TIME: " << theday << " " << thehour << ":" << theminute 
                             << " " << theampm <<endl <<endl;
                        return false;
                    }
                }
            }
        }
    }
    
    //Check whether the student is available right now
    bool wetherAvailablerightnow() {
        string dayoftheweek;
        time_t now;
        time(&now);
        tm now_tm=*gmtime(&now);
        if (now_tm.tm_wday==1) {
            dayoftheweek="M";
        }
        else if (now_tm.tm_wday==2) {
            dayoftheweek="T";
        }
        else if (now_tm.tm_wday==3) {
            dayoftheweek="W";
        }
        else if (now_tm.tm_wday==4) {
            dayoftheweek="R";
        }
        else if (now_tm.tm_wday==5) {
            dayoftheweek="F";
        }
        else if (now_tm.tm_wday==6) {
            dayoftheweek="S";
        }
        else {
            dayoftheweek="U";
        }
        
        wetherAvailable(dayoftheweek, (now_tm.tm_hour - 5+24)%24, now_tm.tm_min, "AM");
    }
    
    bool checkConflict() {
        int starthour, starthour2, endhour, endhour2, endminute, endminute2, startminute;
        int startminute2, becomeminutes, becomeminutes2, becomeminutee, becomeminutee2;
        int coursesize=enrolledcourses.size(), lecturesize, lecturesize2;
        bool whetherconflict=false, CurrentRemoved = false, havechange=false;
        for (int t=coursesize-1; t>-1; t--) {
            CurrentRemoved = false;
            lecturesize=enrolledcourses[t].getThenumberoflectures();
            for (int k=0; k<lecturesize; k++) {
                if (enrolledcourses[t].getLecture(k).getAmpm()=="PM" && enrolledcourses[t].getLecture(k).getHour()!=12) {
                    starthour=enrolledcourses[t].getLecture(k).getHour()+12;
                    endhour=starthour+(enrolledcourses[t].getLecture(k).getMinute()+enrolledcourses[t].getLecture(k).getDuration())/60;
                    endminute=(starthour+enrolledcourses[t].getLecture(k).getDuration())%60;
                    startminute=enrolledcourses[t].getLecture(k).getMinute();
                }
                else {
                    starthour=enrolledcourses[t].getLecture(k).getHour();
                    endhour=(enrolledcourses[t].getLecture(k).getMinute()+enrolledcourses[t].getLecture(k).getDuration())/60+starthour;
                    endminute=(starthour+enrolledcourses[t].getLecture(k).getDuration())%60;
                    startminute=enrolledcourses[t].getLecture(k).getMinute();
                }
                for (int i=0; i<t; i++) {
                    lecturesize2=enrolledcourses[i].getThenumberoflectures();
                    for (int j=0; j<lecturesize2; j++) {
                        if (enrolledcourses[t].getLecture(k).getDayoftheweek()==enrolledcourses[i].getLecture(j).getDayoftheweek()) {
                            if (enrolledcourses[i].getLecture(j).getAmpm()=="PM" && enrolledcourses[i].getLecture(j).getHour()!=12) {
                                starthour2=enrolledcourses[i].getLecture(j).getHour()+12;
                                endhour2=starthour2+(enrolledcourses[i].getLecture(j).getMinute()+enrolledcourses[i].getLecture(j).getDuration())/60;
                                endminute2=(starthour2+enrolledcourses[i].getLecture(j).getDuration())%60;
                                startminute2=enrolledcourses[i].getLecture(j).getMinute();
                            }
                            else {
                                starthour2=enrolledcourses[i].getLecture(j).getHour();
                                endhour2=(enrolledcourses[i].getLecture(j).getMinute()+enrolledcourses[i].getLecture(j).getDuration())/60+starthour2;
                                endminute2=(starthour2+enrolledcourses[i].getLecture(j).getDuration())%60;
                                startminute2=enrolledcourses[i].getLecture(j).getMinute();
                            }
                            
                            becomeminutes=starthour*60+startminute;
                            becomeminutes2=starthour2*60+startminute2;
                            becomeminutee=endhour*60+endminute;
                            becomeminutee2=endhour2*60+endminute2;
                            if ((becomeminutes>becomeminutes2 && becomeminutee<becomeminutee2) || (becomeminutes<becomeminutes2 && becomeminutee>becomeminutee2)) {
                                whetherconflict=true;
                            }
                            else {
                                if (becomeminutes2-becomeminutes>=enrolledcourses[t].getLecture(k).getDuration()) {
                                    //nothing
                                }
                                else if (becomeminutes-becomeminutes2>=enrolledcourses[i].getLecture(j).getDuration()) {
                                    //nothing
                                }
                                else {
                                    whetherconflict=true;
                                }
                            }
                            if (whetherconflict==true) {
                                cout << "---SCHEDULING CONFLICT---" <<endl;
                                cout << "EXISTING CLASS: " << enrolledcourses[i].getCoursename() <<endl;
                                enrolledcourses[i].getLecture(j).printMeetingtime();
                                cout << "NEW CLASS: " << enrolledcourses[t].getCoursename()
                                     << " (NOT ADDED / REMOVED)" <<endl;
                                enrolledcourses[t].getLecture(k).printMeetingtime();
                                cout <<endl;
                                removeCourse(t);
                                havechange=true;
                                whetherconflict = false;
                                CurrentRemoved = true;
                                break;
                            }
                        }
                    }
                    if (CurrentRemoved) break;
                }
                if (CurrentRemoved) break;
            }
        }
        return true;
    }
    
    //Print information about all courses to console window
    void printAllcourses() {
        cout << "FNAME: " << firstName <<endl << "MINIT: " << middleInitial <<endl;
        cout << "LNAME: " << lastName <<endl << "ID:    " << digitpsuidnumber <<endl;
        cout << "USER:  " << psuusername <<endl <<endl;
        
        for (int i=0; i<enrolledcourses.size(); i++) {
            cout << enrolledcourses[i].getCoursename()<<endl;
            enrolledcourses[i].printAllmeetingtime();
        }
    }
    
    // Print information about all courses to file
    void printAllcourses(string filename) {
        ofstream fout(filename);
        fout << "FNAME: " << firstName <<endl << "MINIT: " << middleInitial <<endl;
        fout << "LNAME: " << lastName <<endl << "ID:    " << digitpsuidnumber <<endl;
        fout << "USER:  " << psuusername <<endl <<endl;
        
        for (int i=0; i<enrolledcourses.size(); i++) {
            fout << enrolledcourses[i].getCoursename() <<endl;
            enrolledcourses[i].printAllmeetingtime(fout);
        }
    }
};

int main() {
    int choice, hour, minute, duration;
    char createanewstudent, middleinitial, addordelete, addmeeting, whethercurrenttime;
    char whetherquit;
    string firstname, lastname, psuusername, temp, coursename, ampm, whetheritisalaborlecturesession;
    string digitpsuidnumber, dayoftheweek;
    Student s;
    Course c;
    vector<Lecture> l;
    bool isitexist=false, whethermodified=false, whethersave=false, havechange=false;
    cout << "Welcome to the scheduling program!\n"; 
    while (choice!=6 || whetherquit=='N') {
        cout << "\nChoose an option:\n" << "1. Select student" <<endl;
        cout << "2. Modify schedule\n" << "3. Check student availability\n" << "4. Display schedule" <<endl;
        cout << "5. Save to file\n" << "6. Quit\n";
        cin >> choice;
        
        //Select student by ID
        if (choice==1) {
            //The user is prompted to enter a PSU ID Number
            cout << "Enter the student's 9-digit PSU ID: ";
            cin >> digitpsuidnumber;
            
            //If a corresponding file (e.g. "912345678.txt") exists, then open it
            ifstream fin(digitpsuidnumber+".txt");
            if (!fin) {
                fin.close();
                cout << digitpsuidnumber << ".txt does not exist. Would you like to create a new student (Y/N)? ";
                cin >> createanewstudent;
            
                if (createanewstudent=='Y' || createanewstudent=='y') {
                    isitexist=true;
                    cout << "Enter the student's first name:";
                    cin >> firstname;
                
                    cout << "Enter the student's middle initial";
                    cin >> middleinitial;
                
                    cout << "Enter the student's last name:";
                    cin >> lastname;
                
                    cout << "Enter the student's psu username";
                    cin >> psuusername;
                    havechange=true;
                    //Create a new student object containing all the provided information 
                    Student x(firstname, middleinitial, lastname, digitpsuidnumber, psuusername);
                    s = x;
                }
                else continue;
            }
            else {
                isitexist=true;
                fin >> temp >> firstname
                    >> temp >> middleinitial
                    >> temp >> lastname
                    >> temp >> digitpsuidnumber
                    >> temp >> psuusername >> temp;
                
                Student x(firstname, middleinitial, lastname, digitpsuidnumber, psuusername);
                s = x;
                
                bool IsItAlpha;
                while (fin.eof()==false) {
                    IsItAlpha = isalpha(temp[0]);
                    if (IsItAlpha==true) {
                        coursename=temp;
                        fin >> temp;
                        if (fin.eof()==true) break;
                        while (temp=="-") {
                            fin >> dayoftheweek>> hour >> minute >> ampm 
                                >> duration >> whetheritisalaborlecturesession; 
                            Lecture L(dayoftheweek, hour, minute, ampm, duration, whetheritisalaborlecturesession);
                            l.push_back(L);
                            if (fin.eof()==true) break;
                            fin >> temp;
                            if (fin.eof()==true) break;
                        }
                        Course c(coursename, l);
                        s.addCourse(c);
                        l.clear();
                        if (fin.eof()==true) break;
                    }
                }
                fin.close();
                if (s.checkConflict()==true) havechange=true;
            }
        }
        
        //Modify schedule
        else if (choice==2) {
            havechange=true;
            whethermodified=true;
            if (isitexist==false) {
                cout << "No student has been selected!" <<endl;
                continue;
            }
            cout << "Add a new course or delete existing(A/D)? ";
            cin >> addordelete;
            if (addordelete=='D') {
                int removeone, i=0;
                cout << "Select a course to remove:\n";
                for (int i=1; i<=s.getThenumberofcourse(); i++) {
                    cout << i << ". " << s.getCourse(i-1).getCoursename() <<endl;
                }
                cin >> removeone;
                s.removeCourse(removeone);
            }
            else {
                cout << "Enter the course name: ";
                cin >> coursename;
                while (dayoftheweek!="N") {
                    cout << "Enter the day of week when have lecture or lab (M, T, W, R, F)";
                    cin >> dayoftheweek;
                    cout << "Enter the start hour of the lecture or lab: ";
                    cin >> hour;
                    cout << "Enter the start minute of the lecture or lab: "; 
                    cin >> minute;
                    cout << "If the lecture is in the morning, enter AM, otherwise, enter PM";
                    cin >> ampm;
                    cout << "Enter the duration of the lecture or lab";
                    cin >> duration;
                    cout << "It is a Lab or Lecture";
                    cin >> whetheritisalaborlecturesession;
                    cout << "Do you want to add meeting times? (Yes enter Y, No enter N)";
                    cin >> addmeeting;
                    Lecture L(dayoftheweek, hour, minute, ampm, duration, whetheritisalaborlecturesession);
                    l.push_back(L);
                    Course c(coursename, l);
                    s.addCourse(c);
                }
                s.checkConflict();
            }
        }
        
        //Check student availability
        else if (choice==3) {
            if (isitexist==false) {
                cout << "No student has been selected!" <<endl;
                continue;
            }
            cout << "Check current day and time (Y/N)? ";
            cin >> whethercurrenttime;
            if (whethercurrenttime=='Y') {
                s.wetherAvailablerightnow();
            }
            else {
                string adayoftheweek;
                int ahour, aminute, whetheravailable;
                string aampm;
                cout << "Enter day of the week(U, M, T, W, R, F, S): ";
                cin >> adayoftheweek;
                cout << "Enter hour: ";
                cin >> ahour;
                cout << "Enter minute: ";
                cin >> aminute;
                cout << "Enter AM or PM:";
                cin >> aampm;
        
                if (aampm=="am" || aampm=="AM") {
                    aampm="AM";
                    whetheravailable=ahour;
                }
                else if (aampm=="pm" || aampm=="PM") {
                    aampm="PM";
                    whetheravailable=ahour+12;
                }
                s.wetherAvailable(adayoftheweek, ahour, aminute, aampm);
            }
        }
        
        //Display Schedule
        else if (choice==4) {
            if (isitexist==false) {
                cout << "No student has been selected!" <<endl;
                continue;
            }
            s.printAllcourses();
        }
        
        //Write to file
        else if (choice==5) {
            if (isitexist==false) {
                cout << "No student has been selected!" <<endl;
                continue;
            }
            ofstream fout(digitpsuidnumber+".txt");
            s.printAllcourses(digitpsuidnumber+".txt");
            cout << "Changes written to \"" << digitpsuidnumber <<".txt\"";
            havechange=false;
        }
        
        //Quit
        else if (choice==6) {
            if (havechange==true) {
                cout << "You have unsaved changes. Quit anyways(Y/N)? ";
                cin >> whetherquit;
            }
            
            if (whetherquit=='N') continue;
            else {
                cout << "Thanks for using the scheduling program!";
                return 0;
            }
        }
    }
}
/*
1.

