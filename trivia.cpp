#include <iostream>
using namespace std;

bool getAnswer();

int main() {
    string questions[5]={"CPU stands for \"Central Park University\"", "RAM stands for \"Reserved Access Memory\"", "HDD stands for \"Hard Disk Drive\"", "SSD stands for \"Soft State Drive\"", "CPP stands for \"C Plus Plus\""};
    bool correctanswer[5]={false, false, true, false, true};//Parallel arrays to hold questions and answers
    cout << "Let's take the trivia of true or false questions!\n";//output a prompt
    int x=1, counter=0, y=0, z=1;//declare variables
    while (x<=5) {
        cout <<  "\nQuestion " << x << "\n" << questions[y] << "\nAnswer " << z << "\n";//display the questions
        if (getAnswer()==correctanswer[x-1]) {
            cout << "Correct!";
            counter++;
        }
        else {
            cout << "Incorrect!";
        }
        x++;
        y++;
        z++;
    }
    cout << "\n\nYou got " << counter << " out of 5 questions correct.";
}//Determines and display whether the user entered the correct answer. Keepstrack of and displays how many questions the user answered correctly.

bool getAnswer() {
    string answer;
    cout << "Enter a true or false answer: ";
    cin >> answer;
    while (answer != "True" && answer != "T" && answer != "true" && answer != "t" && answer != "False" && answer != "false" && answer != "F" && answer != "f") {
        cout << "Invalid entry, try again!\n" << "Enter a true or false answer: ";
        cin >> answer;
    }
    if (answer == "True" || answer == "T" || answer == "true" || answer == "t") {
        return true;
    }
    else if (answer == "False" || answer == "F" || answer == "false" || answer == "f") {
        return false;
    }//prompts the user to enter an answer, validates it, and returns a Boolean valuethat represents the user's choice of trueor false
    
}
/*
1.
Let's take the trivia of true or false questions!

Question 1
CPU stands for "Central Park University"
Answer 1
Enter a true or false answer: nope
Invalid entry, try again!
Enter a true or false answer: false
Correct!
Question 2
RAM stands for "Reserved Access Memory"
Answer 2
Enter a true or false answer: true
Incorrect!
Question 3
HDD stands for "Hard Disk Drive"
Answer 3
Enter a true or false answer: T
Correct!
Question 4
SSD stands for "Soft State Drive"
Answer 4
Enter a true or false answer: False
Correct!
Question 5
CPP stands for "C Plus Plus"
Answer 5
Enter a true or false answer: f
Incorrect!

You got 3 out of 5 questions correct.

2.
Question 1
CPU stands for "Central Park University"
Answer 1
Enter a true or false answer: F
Correct!
Question 2
RAM stands for "Reserved Access Memory"
Answer 2
Enter a true or false answer: tru
Invalid entry, try again!
Enter a true or false answer: True
Incorrect!
Question 3
HDD stands for "Hard Disk Drive"
Answer 3
Enter a true or false answer: t
Correct!
Question 4
SSD stands for "Soft State Drive"
Answer 4
Enter a true or false answer: False
Correct!
Question 5
CPP stands for "C Plus Plus"
Answer 5
Enter a true or false answer: t
Correct!

You got 4 out of 5 questions correct.
*/