#include <iostream>
using namespace std;

bool isPalindrome(string, int);

int main() {
    string input;
    cout << "Enter a string to find out if it is a palindrome: ";
    cin >> input;
    int size;
    size=input.size();
    if (isPalindrome(input, size)==true) {
        cout << input << " is a palindrome!";
    }
    else {
        cout << input << " is NOT a palindrome!";
    }
}

//determines whether a given string is a palindrome or not
bool isPalindrome(string input, int size) {
    //repeats until there are 0 or 1 character(s) left
    if (size<2) {
        if (size==0) {
            return true;
        }
        cout << "Checking: " << input <<endl;
        return true;
    }
    // the first and last character of the string are compared
    else {
        //If they are the same, then the string may be a palindrome, but the rest of it must be checked
        if (input[size-1]==input[0]) {
            //In each recursive case of the function, print out which remaining part of the character is being checked
            cout << "Checking: " << input <<endl;
            input.resize(size-1);
            for (int i=0; i<size-2; i++) {
                input[i]=input[i+1];
            }
            //Each recursion shrinks the string to be checked by 2
            input.resize(size-2);
            return isPalindrome(input, size-2);
        }
        //If the first and last character are different, then the string is not a palindrome
        else {
            cout << "Checking: " << input <<endl;
            return false;
        }
    }
}  

/*
1.
Enter a string to find out if it is a palindrome: racecar
Checking: racecar
Checking: aceca
Checking: cec
Checking: e
racecar is a palindrome!

2.
Enter a string to find out if it is a palindrome: racebar
Checking: racebar
Checking: aceba
Checking: ceb
racebar is NOT a palindrome!
*/
    
