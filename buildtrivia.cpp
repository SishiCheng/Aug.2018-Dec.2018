#include <iostream>
using namespace std;

bool getAnswer();

int main() {
    cout << "Let's build a trivia of true or false questions (enter \"done\" to finish)!\n";
    bool answer[10];
    string question[10];
    int x=1;
    string answerg;
    while (x<=10) {
        cout << "Question " << x <<endl;
        cin.ignore();
        getline(cin, question[x-1]);
        if (question[x-1]=="done") {
            cout << "\nLet's take the trivia of true or false questions!\n";
            int y=0, counter=0;
            while(y<x-1) {
                cout <<  "\nQuestion " << y+1 << "\n" << question[y] << "\nAnswer " << y+1 << "\n";
                if (getAnswer()==answer[y]) {
                    cout << "Correct!";
                    counter++;
                }
                else {
                    cout << "Incorrect!";
                }
                y++;
            }
            cout << "\n\nYou got " << counter << " out of " << x-1 << " questions correct.";
            return 0;
        }
        else if (x==10) {
            cout << "Answer " << x << "\nEnter a true or false answer: ";
            cin >> answerg;
            if (answerg=="t") {
                answer[x-1]=true;
            }
            else {
                answer[x-1]=false;
                
            }
            cout << "\nLet's take the trivia of true or false questions!\n";
            int y=0, counter=0;
            while(y<x-1) {
                cout <<  "\nQuestion " << y+1 << "\n" << question[y] << "\nAnswer " << y+1 << "\n";
                if (getAnswer()==answer[y]) {
                    cout << "Correct!";
                    counter++;
                }
                else {
                    cout << "Incorrect!";
                }
                y++;
            }
            cout << "\n\nYou got " << counter << " out of " << x-1 << " questions correct.";
            return 0;
        }   
        else {
            cout << "Answer " << x << "\nEnter a true or false answer: ";
            cin >> answerg;
            if (answerg=="t") {
                answer[x-1]=true;
            }
            else {
                answer[x-1]=false;
            }
            x++;
        }//Prompting the user and accepting user input to populate the questions and answers and quizzes them
    }
}
    bool getAnswer() {
        string answeru;
        cout << "Enter a true or false answer: ";
        cin >> answeru;
        while (answeru != "True" && answeru != "T" && answeru != "true" && answeru != "t" && answeru != "False" && answeru != "false" && answeru != "F" && answeru != "f") {
            cout << "Invalid entry, try again!\n" << "Enter a true or false answer: ";
            cin >> answeru;
        }
        if (answeru == "True" || answeru == "T" || answeru == "true" || answeru == "t") {
            return true;
        }
        else if (answeru == "False" || answeru == "F" || answeru == "false" || answeru == "f") {
            return false;
        }
    }//prompts the user to enter an answer, validates it, and returns a Boolean valuethat represents the user's choice of trueor false
/*
1.
Let's build a trivia of true or false questions (enter "done" to finish)!
Question 1
School buses are yellow
Answer 1
Enter a true or false answer: t
Question 2
Whiteboards are yellow
Answer 2
Enter a true or false answer: f
Question 3
Bananas are yellow
Answer 3
Enter a true or false answer: t
Question 4
Yellow paint is yellow
Answer 4
Enter a true or false answer: t
Question 5
done

Let's take the trivia of true or false questions!

Question 1
chool buses are yellow
Answer 1
Enter a true or false answer: t
Correct!
Question 2
Whiteboards are yellow
Answer 2
Enter a true or false answer: t
Incorrect!
Question 3
Bananas are yellow
Answer 3
Enter a true or false answer: t
Correct!
Question 4
Yellow paint is yellow
Answer 4
Enter a true or false answer: t
Correct!

You got 3 out of 4 questions correct.
2.
Let's build a trivia of true or false questions (enter "done" to finish)!
Question 1
CPU stands for "Central Park University"
Answer 1
Enter a true or false answer: f
Question 2
RAM stands for "Reserved Access Memory"
Answer 2
Enter a true or false answer: t
Question 3
HDD stands for "Hard Disk Drive"
Answer 3
Enter a true or false answer: t
Question 4
SSD stands for "Soft State Drive"
Answer 4
Enter a true or false answer: f
Question 5
done

Let's take the trivia of true or false questions!

Question 1
PU stands for "Central Park University"
Answer 1
Enter a true or false answer: false
Correct!
Question 2
RAM stands for "Reserved Access Memory"
Answer 2
Enter a true or false answer: tue
Invalid entry, try again!
Enter a true or false answer: T
Correct!
Question 3
HDD stands for "Hard Disk Drive"
Answer 3
Enter a true or false answer: F
Incorrect!
Question 4
SSD stands for "Soft State Drive"
Answer 4
Enter a true or false answer: true
Incorrect!

You got 2 out of 4 questions correct.

3.
Let's build a trivia of true or false questions (enter "done" to finish)!
Question 1
qq
Answer 1
Enter a true or false answer: t
Question 2
ww
Answer 2
Enter a true or false answer: t
Question 3
ee
Answer 3
Enter a true or false answer: f
Question 4
q e rew
Answer 4
Enter a true or false answer: t
Question 5
dsg gth j 
Answer 5
Enter a true or false answer: f
Question 6
sdaf gd
Answer 6
Enter a true or false answer: f
Question 7
yy
Answer 7
Enter a true or false answer: t
Question 8
gfdshn 
Answer 8
Enter a true or false answer: f
Question 9
gfdsn
Answer 9
Enter a true or false answer: f
Question 10
gfdbfb
Answer 10
Enter a true or false answer: t

Let's take the trivia of true or false questions!

Question 1
q
Answer 1
Enter a true or false answer: t
Correct!
Question 2
ww
Answer 2
Enter a true or false answer: true
Correct!
Question 3
ee
Answer 3
Enter a true or false answer: false
Correct!
Question 4
q e rew
Answer 4
Enter a true or false answer: f
Incorrect!
Question 5
dsg gth j 
Answer 5
Enter a true or false answer: f
Correct!
Question 6
sdaf gd
Answer 6
Enter a true or false answer: t
Incorrect!
Question 7
yy
Answer 7
Enter a true or false answer: T
Correct!
Question 8
gfdshn 
Answer 8
Enter a true or false answer: r
Invalid entry, try again!
Enter a true or false answer: True
Incorrect!
Question 9
gfdsn
Answer 9
Enter a true or false answer: t
Incorrect!

You got 5 out of 9 questions correct.
*/