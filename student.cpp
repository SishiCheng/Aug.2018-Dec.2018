#include "course.h"
#include "student.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

Student::Student() {}

Student::Student(string f, char m, string l, string I, string u) {
    fname = f;
    minit = m;
    lname = l;
    ID = I;
    user = u;
}

string Student::getID() {
    return ID;
}

void Student::printBasicInformationToConsole() {
    cout << "FNAME: " << fname << endl
         << "MINIT: " << minit << endl
         << "LNAME: " << lname << endl
         << "ID:    " << ID << endl
         << "USER:  " << user << endl << endl;
    return;
}

void Student::printBasicInformationTofile(string filename) {
    ofstream fout(filename+".txt");
    fout << "FNAME: " << fname << endl
         << "MINIT: " << minit << endl
         << "LNAME: " << lname << endl
         << "ID:    " << ID << endl
         << "USER:  " << user << endl << endl;
    fout.close();
    return;
}

void Student::addCourse(Course c) {
    courses.push_back(c);
}

void Student::removeCourse(Course c) {
    int whichone,
        size = courses.size();
    for (int i=0; i<size; i++) {
        if (courses[i].getName()==c.getName()) {
            whichone = i;
            break;
        }
    }
    for (int i=whichone; i<size-1; i++) {
        courses[i] = courses[i+1];
    }
    courses.pop_back();
    return;
}

void Student::removeCourse() {
    int whichone,
        size = courses.size();
    cout << "Select a course to remove:" << endl;
    for (int i=0; i<size; i++) {
        cout << i+1 << ". " << courses[i].getName() << endl;
    }
    cin >> whichone;
    whichone--;
        
    for (int i=whichone; i<size-1; i++) {
        courses[i] = courses[i+1];
    }
    courses.pop_back();
    return;
}

//Print information about all courses to console window
void Student::printAllCourseToConsole() {
    int size = courses.size();
    for (int i=0; i<size; i++) {
        courses[i].printCourseToConsole();
    }
    return;
}

//Print information about all courses to file
void Student::printAllCourseTofile(string filename) {
    int size = courses.size();
    for (int i=0; i<size; i++) {
        courses[i].printCourseToFile(filename);
    }
    return;
}

//Check whether the student will be available (not in class) at a certain time and day of the week
void Student::checkCertainAvailability(char weekday, int hour, int minute, string AMorPM) {
    int size_courses = courses.size(),
        size_lectures,
        starthour,
        startminute,
        endhour,
        endminute,
        originalhour,
        originalminute;
    string originalweekday,
           originalAMorPM;
    bool IsItAvailable = true;
           
    if (weekday=='U') originalweekday = "Sunday";
    else if (weekday=='M') originalweekday = "Monday";
    else if (weekday=='T') originalweekday = "Tuesday";
    else if (weekday=='W') originalweekday = "Wednesday";
    else if (weekday=='R') originalweekday = "Thursday";
    else if (weekday=='F') originalweekday = "Friday";
    else if (weekday=='S') originalweekday = "Saturday";
    
    if (hour>12) {
        originalhour = hour-12;
        originalAMorPM = "PM";
    }
    else {
        originalhour = hour;
        originalAMorPM = AMorPM;
    }
    originalminute = minute;
    
    if (AMorPM=="PM" && hour!=12) hour += 12;
    for (int i=0; i<size_courses; i++) {
        size_lectures = courses[i].getNumOfLectures();
        for (int j=0; j<size_lectures; j++) {
            if (courses[i].getLecture(j).getWeekday() == weekday) {
                if (courses[i].getLecture(j).getAMorPM()=="PM" && courses[i].getLecture(j).getHour()!=12) {
                    starthour = courses[i].getLecture(j).getHour()+12;
                }
                else starthour = courses[i].getLecture(j).getHour();
                startminute = courses[i].getLecture(j).getMinute();
                endhour = starthour+(courses[i].getLecture(j).getMinute()+courses[i].getLecture(j).getDuration())/60;
                endminute = (startminute+courses[i].getLecture(j).getDuration())%60;
                if (hour==starthour) {
                    if (minute==startminute) {
                        IsItAvailable = false;
                    }
                    else if (minute>startminute) {
                        if (endhour==hour) {
                            if (endminute<minute) {
                                //nothing
                            }
                            else if (endminute==minute) {
                                //nothing
                            }
                            else if (endminute>minute) {
                                IsItAvailable = false;
                            }
                        }
                        else if (endhour>hour) {
                            IsItAvailable = false;
                        }
                    }
                    else if (minute<startminute) {
                        //nothing
                    }
                }
                
                else if (hour==endhour) {
                    if (minute>endminute) {
                        //nothing
                    }
                    else if (minute==endminute) {
                        //nothing
                    }
                    else if (minute<endminute) {
                        if (starthour==hour) {
                            if (startminute==minute) {
                                IsItAvailable = false;
                            }
                            else if (startminute<minute) {
                                IsItAvailable = false;
                            }
                            else if (startminute>minute) {
                                //nothing
                            }
                        }
                        else if (starthour<hour) {
                            IsItAvailable = false;
                        }
                    }
                }
                
                else if (hour<starthour) {
                    //nothing
                }
                
                else if (hour>endhour) {
                    //nothing
                }
                
                else if (hour>starthour && hour<endhour) {
                    IsItAvailable = false;
                }
                
                if (IsItAvailable==false) {
                    cout << "---NOT AVAILABLE---" << endl
                         << "CLASS TIME: " << courses[i].getName() << endl;
                    courses[i].getLecture(j).printLectureToConsole();
                    cout << "REQUESTED TIME: " << originalweekday << " " << originalhour << ":";
                    if (originalminute<10) cout << "0" << originalminute;
                    else cout << originalminute;
                    cout << " " << originalAMorPM << endl;
                    break;
                }
            }
        }
        if (IsItAvailable==false) break;
    }
    if (IsItAvailable==true) {
        cout << "Student is available at: " << originalweekday << " " << originalhour << ":";
        if (originalminute<10) cout << "0" << originalminute;
        else cout << originalminute;
        cout << " " << originalAMorPM << endl;
    }
    return;
}

//Check whether the student is available right now
void Student::checkCurrentAvailability() {
    time_t now;
    time(&now);
    tm now_tm = *gmtime(&now);
    char weekday[7] = {'U', 'M', 'T', 'W', 'R', 'F', 'S'};
    int hour = now_tm.tm_hour-5,
        minute = now_tm.tm_min;
    if (hour<0) checkCertainAvailability(weekday[(now_tm.tm_wday-1+7)%7], hour+24, minute, "AM");
    else checkCertainAvailability(weekday[now_tm.tm_wday], hour, minute, "AM");
    return;
}

//If there are pre-existing scheduling conflicts, then remove one of the courses
bool Student::checkConflict() {
    int size_courses = courses.size(),
        size_lectures,
        size_lectures2,
        starthour,
        startminute,
        starthour2,
        startminute2,
        endhour,
        endminute,
        endhour2,
        endminute2;
    bool IsThereAConflict = false,
         WasCurrentCourseRemoved = false,
         AreThereChanges = false;
    for (int i=size_courses-1; i>-1; i--) {
        WasCurrentCourseRemoved = false;
        size_lectures = courses[i].getNumOfLectures();
        for (int j=0; j<size_lectures; j++) {
            if (courses[i].getLecture(j).getAMorPM()=="PM" && courses[i].getLecture(j).getHour()!=12) {
                starthour = courses[i].getLecture(j).getHour()+12;
            }
            else starthour = courses[i].getLecture(j).getHour();
            startminute = courses[i].getLecture(j).getMinute();
            endhour = starthour+(courses[i].getLecture(j).getMinute()+courses[i].getLecture(j).getDuration())/60;
            endminute = (startminute+courses[i].getLecture(j).getDuration())%60;
            
            for (int k=0; k<i; k++) {
                size_lectures2 = courses[k].getNumOfLectures();
                for (int l=0; l<size_lectures2; l++) {
                    if (courses[i].getLecture(j).getWeekday() == courses[k].getLecture(l).getWeekday()) {
                        if (courses[k].getLecture(l).getAMorPM()=="PM" && courses[k].getLecture(l).getHour()!=12) {
                            starthour2 = courses[k].getLecture(l).getHour()+12;
                        }
                        else starthour2 = courses[k].getLecture(l).getHour();
                        startminute2 = courses[k].getLecture(l).getMinute();
                        endhour2 = starthour2+(courses[k].getLecture(l).getMinute()+courses[k].getLecture(l).getDuration())/60;
                        endminute2 = (startminute2+courses[k].getLecture(l).getDuration())%60;
                        
                        //check the starting time of the new course
                        if (starthour==starthour2) {
                            if (startminute==startminute2) {
                                IsThereAConflict = true;
                            }
                            else if (startminute>startminute2) {
                                if (endhour2==starthour) {
                                    if (endminute2<startminute) {
                                        //nothing
                                    }
                                    else if (endminute2==startminute) {
                                        //nothing
                                    }
                                    else if (endminute2>startminute) {
                                        IsThereAConflict = true;
                                    }
                                }
                                else if (endhour2>starthour) {
                                    IsThereAConflict = true;
                                }
                            }
                            else if (startminute<startminute2) {
                                //nothing
                            }
                        }
                        
                        else if (starthour==endhour2) {
                            if (startminute>endminute2) {
                                //nothing
                            }
                            else if (startminute==endminute2) {
                                //nothing
                            }
                            else if (startminute<endminute2) {
                                if (starthour2==starthour) {
                                    if (startminute2==startminute) {
                                        IsThereAConflict = true;
                                    }
                                    else if (startminute2<startminute) {
                                        IsThereAConflict = true;
                                    }
                                    else if (startminute2>startminute) {
                                        //nothing
                                    }
                                }
                                else if (starthour2<starthour) {
                                    IsThereAConflict = true;
                                }
                            }
                        }
                        
                        else if (starthour<starthour2) {
                            //nothing
                        }
                        
                        else if (starthour>endhour2) {
                            //nothing
                        }
                        
                        else if (starthour>starthour2 && starthour<endhour2) {
                            IsThereAConflict = true;
                        }
                        
                        //check the starting time of the old course
                        if (starthour2==starthour) {
                            if (startminute2==startminute) {
                                IsThereAConflict = true;
                            }
                            else if (startminute2>startminute) {
                                if (endhour==starthour2) {
                                    if (endminute<startminute2) {
                                        //nothing
                                    }
                                    else if (endminute==startminute2) {
                                        //nothing
                                    }
                                    else if (endminute>startminute2) {
                                        IsThereAConflict = true;
                                    }
                                }
                                else if (endhour>starthour2) {
                                    IsThereAConflict = true;
                                }
                            }
                            else if (startminute2<startminute) {
                                //nothing
                            }
                        }
                        
                        else if (starthour2==endhour) {
                            if (startminute2>endminute) {
                                //nothing
                            }
                            else if (startminute2==endminute) {
                                //nothing
                            }
                            else if (startminute2<endminute) {
                                if (starthour==starthour2) {
                                    if (startminute==startminute2) {
                                        IsThereAConflict = true;
                                    }
                                    else if (startminute<startminute2) {
                                        IsThereAConflict = true;
                                    }
                                    else if (startminute>startminute2) {
                                        //nothing
                                    }
                                }
                                else if (starthour<starthour2) {
                                    IsThereAConflict = true;
                                }
                            }
                        }
                        
                        else if (starthour2<starthour) {
                            //nothing
                        }
                        
                        else if (starthour2>endhour) {
                            //nothing
                        }
                        
                        else if (starthour2>starthour && starthour2<endhour) {
                            IsThereAConflict = true;
                        }
                        
                        //check the ending time of the new course
                        if (endhour==starthour2) {
                            if (endminute==startminute2) {
                                //nothing
                            }
                            else if (endminute>startminute2) {
                                if (endhour2==endhour) {
                                    if (endminute2==endminute) {
                                        IsThereAConflict = true;
                                    }
                                    else if (endminute2>endminute) {
                                        IsThereAConflict = true;
                                    }
                                    else if (endminute2<endminute) {
                                        //nothing
                                    }
                                }
                                else if (endhour2>endhour) {
                                    IsThereAConflict = true;
                                }
                            }
                            else if (endminute<startminute2) {
                                //nothing
                            }
                        }
                        
                        else if (endhour==endhour2) {
                            if (endminute==endminute2) {
                                IsThereAConflict = true;
                            }
                            else if (endminute>endminute2) {
                                //nothing
                            }
                            else if (endminute<endminute2) {
                                if (starthour2==endhour) {
                                    if (startminute2==endminute) {
                                        //nothing
                                    }
                                    else if (startminute2>endminute) {
                                        //nothing
                                    }
                                    else if (startminute2<endminute) {
                                        IsThereAConflict = true;
                                    }
                                }
                                else if (starthour2<endhour) {
                                    IsThereAConflict = true;
                                }
                            }
                        }
                        else if (endhour<starthour2) {
                            //nothing
                        }
                        else if (endhour>endhour2) {
                            //nothing
                        }
                        else if (endhour>starthour2 && endhour<endhour2) {
                            IsThereAConflict = true;
                        }
                        
                        //check the ending time of the old course
                        if (endhour2==starthour) {
                            if (endminute2==startminute) {
                                //nothing
                            }
                            else if (endminute2>startminute) {
                                if (endhour==endhour2) {
                                    if (endminute==endminute2) {
                                        IsThereAConflict = true;
                                    }
                                    else if (endminute>endminute2) {
                                        IsThereAConflict = true;
                                    }
                                    else if (endminute<endminute2) {
                                        //nothing
                                    }
                                }
                                else if (endhour>endhour2) {
                                    IsThereAConflict = true;
                                }
                            }
                            else if (endminute2<startminute) {
                                //nothing
                            }
                        }
                        
                        else if (endhour2==endhour) {
                            if (endminute2==endminute) {
                                IsThereAConflict = true;
                            }
                            else if (endminute2>endminute) {
                                //nothing
                            }
                            else if (endminute2<endminute) {
                                if (starthour==endhour2) {
                                    if (startminute==endminute2) {
                                        //nothing
                                    }
                                    else if (startminute>endminute2) {
                                        //nothing
                                    }
                                    else if (startminute<endminute2) {
                                        IsThereAConflict = true;
                                    }
                                }
                                else if (starthour<endhour2) {
                                    IsThereAConflict = true;
                                }
                            }
                        }
                        else if (endhour2<starthour) {
                            //nothing
                        }
                        else if (endhour2>endhour) {
                            //nothing
                        }
                        else if (endhour2>starthour && endhour2<endhour) {
                            IsThereAConflict = true;
                        }
                        
                        if (IsThereAConflict==true) {
                            cout << "---SCHEDULING CONFLICT---" << endl
                                 << "EXISTING CLASS: " << courses[k].getName() << endl;
                            courses[k].getLecture(l).printLectureToConsole();
                            cout << "NEW CLASS: PHYS211-003 (NOT ADDED / REMOVED)" << endl;
                            courses[i].getLecture(j).printLectureToConsole();
                            removeCourse(courses[i]);
                            AreThereChanges = true;
                            WasCurrentCourseRemoved = true;
                            IsThereAConflict = false;
                            break;
                        }
                    }
                }
                if (WasCurrentCourseRemoved==true) break;
            }
            if (WasCurrentCourseRemoved==true) break;
        }
    }
    return AreThereChanges;
}