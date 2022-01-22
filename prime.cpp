#include <iostream>

using namespace std;

bool isPrime(int);

int main() {
    cout << "The prime numbers between 1 and 100 are: \n";
    int parameter;
    int counter=0;
    for (parameter = 2; parameter <= 100; parameter++) {
        if (isPrime(parameter) == true) {
            counter++;
            if (counter==1) {
                cout << parameter;
            }
            else {
                cout << ", " << parameter;
            }
        }
    }
}//Calls the isPrime()function to generate a listof all prime numbers from 2 to 100 (inclusive)

bool isPrime(int parameter) {
    for (int x = 2; x < parameter; x++) {
        if (parameter % x == 0) {
            return false;
            break;
        }
    }
    return true;//if the parameter can aliquot the numbers which are bigger and equal 2 and smaeer than parameter, return false; otherwise, return true.
}

/*
The prime numbers between 1 and 100 are: 
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
*/