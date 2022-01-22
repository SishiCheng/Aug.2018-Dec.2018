#include <iostream>
using namespace std;

void reverse(string);

int main() {
    string s, input;
    char choice;
    //Prompts the user for a string input that may consist of multiple words
    cout << "Please enter a string with spaces:\n";
    getline(cin, s);
    int start=0, end=0;
    while (end<=s.size()) {
       if (s[end]==' ') {
            input=s.substr(start,end-start);
            //reversing each word by calling thereverse()function
            reverse(input);
            cout << " ";
            start=end+1;
        }
        end++; 
    }
    reverse(s.substr(start,s.size()-start));
    
    cout << "\nWould you like to go again (Y/N)? ";
    cin >> choice;
    //Validate the input using a loop
    while (choice!='N' && choice!='n' && choice!='Y' && choice!='y') {
        cout << "Invalid input, try again!\n" << "Would you like to go again (Y/N)? ";
        cin >> choice;
    }
    
    //Accept 'Y'and 'y'for yes, 'N'and 'n'for no
    while (choice=='Y' || choice=='y') {
        cout << "Please enter a string with spaces:\n";
        cin.ignore();
        getline(cin, s);
    
        int start=0, end=0;
        while (end<=s.size()) {
            if (s[end]==' ') {
                input=s.substr(start,end-start);
                reverse(input);
                cout << " ";
                start=end+1;
            }
            end++; 
        }
        reverse(s.substr(start,s.size()-start));
    
        cout << "\nWould you like to go again (Y/N)? ";
        cin >> choice;
        
        while (choice!='N' && choice!='n' && choice!='Y' && choice!='y') {
            cout << "Invalid input, try again!\n" << "Would you like to go again (Y/N)? ";
            cin >> choice;
        }
        if (choice=='Y' || choice=='y') continue;
        else return 0;
    }
    
    if (choice=='N' || choice=='n') return 0;
}

void reverse(string input) {
    if (input.size()>0) {
        cout << input[input.size()-1];
        reverse(input.substr(0,input.size()-1));
    }
    else return;
}

/*
1.
Please enter a string with spaces:
Pack my bag with five dozen liquor jugs
kcaP ym gab htiw evif nezod rouqil sguj
Would you like to go again (Y/N)? y
Please enter a string with spaces:
Pack my bag with five dozen liquor jugs
kcaP ym gab htiw evif nezod rouqil sguj
Would you like to go again (Y/N)? n

2.
Please enter a string with spaces:
A quick brown fox jumps over the lazy dog
A kciuq nworb xof spmuj revo eht yzal god
Would you like to go again (Y/N)? a
Invalid input, try again!
Would you like to go again (Y/N)? x
Invalid input, try again!
Would you like to go again (Y/N)? p
Invalid input, try again!
Would you like to go again (Y/N)? R
Invalid input, try again!
Would you like to go again (Y/N)? y
Please enter a string with spaces:
Pack my bag with five dozen liquor jugs
kcaP ym gab htiw evif nezod rouqil sguj
Would you like to go again (Y/N)? o
Invalid input, try again!
Would you like to go again (Y/N)? u
Invalid input, try again!
Would you like to go again (Y/N)? N
*/