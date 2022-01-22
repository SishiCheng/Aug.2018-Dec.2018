#include <iostream>

using namespace std;

int main() {
    int n, k, nmulti, multin_k, n_k, P, C, kmulti;
    cout << "Enter an integer value for n (between 2 and 12 inclusive): ";
    cin >> n;
    while (n < 2 || n > 12)
    {
        cout << "Invalid input, try again!\n" << "Enter an integer value for n (between 2 and 12 inclusive): ";
        cin >> n;
    }
    cout << "Enter an integer value for k (between 2 and n inclusive): ";
    cin >> k;
    while (k < 2 || k >n)
    {
        cout << "Invalid input, try again!\n" << "Enter an integer value for k (between 2 and n inclusive): ";
        cin >> k;
    }
    multin_k=1;
    n_k=n-k;
    while (n_k>=1)
    {
        multin_k=multin_k*(n_k);
        n_k=n_k-1;
    }
    nmulti=1;
    while (n>=1)
    {
        nmulti=nmulti*n;
        n=n-1;
    }
    
    P=nmulti/multin_k;
    kmulti=1;
    while (k>=1)
    {
        kmulti=kmulti*k;
        k=k-1;
    }
    C=nmulti/(kmulti*multin_k);
    cout << "n! = " << nmulti<< endl << "P(n, k) = " << P << endl << "C(n, k) = " << C;
}    
