#include <iostream>
#include <ctype.h>
#include <cctype>
#include <stdio.h>
using namespace std;

bool isPalindrome(string, int);

int main() {
    string input;
    cout << "Enter a string to find out if it is a palindrome: " << endl;
    //ccepting spaces in the input string(use getline())
    getline(cin, input);
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
    if (size>0) {
        cout << "Checking: " << input <<endl;
    }
    if (size<=1) {
        return true;
    }
    // the first and last character of the string are compared
    else {
        //Ignoring the case of the characters
        if (((input[size-1]>='A' && input[size-1]<='Z') || (input[size-1]>='a' && input[size-1]<='z')) && ((input[0]>='A' && input[0]<='Z') || (input[0]>='a' && input[0]<='z'))) {
            string inputupper=input;
            for (int i=0; i<input.size(); i++) {
                if (inputupper[i]>='A' && inputupper[i]<='Z') inputupper[i]=inputupper[i]+32;
            }
            if (inputupper[size-1]==inputupper[0]) {
                //In each recursive case of the function, print out which remaining part of the character is being checked
                input.resize(size-1);
                for (int i=0; i<size-2; i++) {
                    input[i]=input[i+1];
                }
                //Each recursion shrinks the string to be checked by 2
                input.resize(input.size()-1);
                return isPalindrome(input, input.size());
            }
            //If the first and last character are different, then the string is not a palindrome
            else {
                return false;
            }
        }
        //Skipping any characters in the stringthat are not part of the alphabet
        else {
            if (isalpha(input[0])==false) {
                cout << "  Skipping first char '" << input[0] << "'" <<endl;
                for (int i=0; i<size-1; i++) {
                    input[i]=input[i+1];
                }
                input.resize(size-1);
                return isPalindrome(input, size-1);
            }
            else if (isalpha(input[size-1])==false) {
                cout << "  Skipping last char '" << input[size-1] << "'" <<endl;
                input.resize(size-1);
                return isPalindrome(input, size-1);
            }
        }
    }
}
/*
Enter a string to find out if it is a palindrome: 
Tell a mate, "Go fetch a mallet!"
Checking: Tell a mate, "Go fetch a mallet!"
  Skipping last char '"'
Checking: Tell a mate, "Go fetch a mallet!
  Skipping last char '!'
Checking: Tell a mate, "Go fetch a mallet
Checking: ell a mate, "Go fetch a malle
Checking: ll a mate, "Go fetch a mall
Checking: l a mate, "Go fetch a mal
Checking:  a mate, "Go fetch a ma
  Skipping first char ' '
Checking: a mate, "Go fetch a ma
Checking:  mate, "Go fetch a m
  Skipping first char ' '
Checking: mate, "Go fetch a m
Checking: ate, "Go fetch a 
  Skipping last char ' '
Checking: ate, "Go fetch a
Checking: te, "Go fetch 
  Skipping last char ' '
Checking: te, "Go fetch
Tell a mate, "Go fetch a mallet!" is NOT a palindrome!

2.
Enter a string to find out if it is a palindrome: 
A Toyota's a Toyota.
Checking: A Toyota's a Toyota.
  Skipping last char '.'
Checking: A Toyota's a Toyota
Checking:  Toyota's a Toyot
  Skipping first char ' '
Checking: Toyota's a Toyot
Checking: oyota's a Toyo
Checking: yota's a Toy
Checking: ota's a To
Checking: ta's a T
Checking: a's a 
  Skipping last char ' '
Checking: a's a
Checking: 's 
  Skipping first char '''
Checking: s 
  Skipping last char ' '
Checking: s
A Toyota's a Toyota. is a palindrome!
*/
