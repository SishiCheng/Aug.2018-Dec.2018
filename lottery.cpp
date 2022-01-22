#include <iostream>

using namespace std;

int main() {
    int nmulti, n, k, P, C, kmulti;
    float level1, level2, level3;
    nmulti=1;
    n=60;
    while (n>=56)
    {
        nmulti=nmulti*n;
        n=n-1;
    }
    
    P=nmulti;
    level1=1.0/P;
    kmulti=1;
    k=5;
    while (k>=1)
    {
        kmulti=kmulti*k;
        k=k-1;
    }
    C=nmulti/kmulti;
    level2=1.0/C-level1;
    
    level3=(5.0*56.0)/C-level1-level2; //C(5,4)*C(56,1)/C(60,5)
    cout << "The probability for level 1 winners: " << level1 <<endl << "The probability for level 2 winners: " << level2 <<endl<< "The probability for level 3 winners: " << level3;
    
}
