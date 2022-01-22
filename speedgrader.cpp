#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float point;
    cout << "Please enter the student's final percentage points:";
    cin >> point;
    if (point >= 93 and point < 100) {
        cout << "The student's letter grade is A.";
    }
    else if (point < 93 and point >= 90) {
        cout << "The student's letter grade is A-.";
    }
    else if (point < 90 and point >= 87) {
        cout << "The student's letter grade is B+.";
    }
    else if (point < 87 and point >= 83) {
        cout << "The student's letter grade is B.";
    }
    else if (point < 83 and point >= 80) {
        cout << "The student's letter grade is B-.";
    }
    else if (point < 80 and point >= 77) {
        cout << "The student's letter grade is C+.";
    }
    else if (point < 77 and point >= 70) {
        cout << "The student's letter grade is C.";
    }
    else if (point < 70 and point >= 60) {
        cout << "The student's letter grade is D.";
    }
    else if (point < 60 and point >= 0) {
        cout << "The student's letter grade is F.";
    }
    else {
        cout << "That is not a valid grade!";
    }
    
}
