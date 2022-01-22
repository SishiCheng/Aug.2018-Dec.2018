#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int inputVal(int, string);

int main() {
    vector <int> AWAY;
    vector <int> HOME;
    vector <int> difference;
    for (int i=1; i<=4; i++) {
        cout << i << "Q away team score:\n";
        //Stores the scores in parallel vectors
        AWAY.push_back(inputVal(0, "none"));
        while (AWAY.at(i-1)==-1) {
            cout << "Invalid input, try again!\n";
            AWAY.pop_back();
            AWAY.push_back(inputVal(0, "none"));
        }
        cout << i << "Q home team score:\n";
        //Stores the scores in parallel vectors
        HOME.push_back(inputVal(0, "none"));
        while (HOME.at(i-1)==-1) {
            cout << "Invalid input, try again!\n";
            HOME.pop_back();
            HOME.push_back(inputVal(0, "none"));
        }
    }
    int sum=0, sum1=0;
        for (int j=0;j<AWAY.size();j++) {
            sum+=AWAY.at(j);
            sum1+=HOME.at(j);
            difference.push_back(sum1-sum);
        }
    int z=5;
    //If the score is tied at the end of the 4th quarter, increase the size of thevectors by 1 and get scores for the additional quarter (repeat as many times as necessary until the tie is broken)
    while (sum==sum1) {
        cout << "It's a tie! Let's play another quarter.\n";
        cout << z << "Q away team score:\n";
        AWAY.push_back(inputVal(0, "none"));
        while (AWAY.at(z-1)==-1) {
            cout << "Invalid input, try again!\n";
            AWAY.pop_back();
            AWAY.push_back(inputVal(0, "none"));
        }
        cout << z << "Q home team score:\n";
        HOME.push_back(inputVal(0, "none"));
        while (HOME.at(z-1)==-1) {
            cout << "Invalid input, try again!\n";
            HOME.pop_back();
            HOME.push_back(inputVal(0, "none"));
        }
        int sum=0, sum1=0;
        for (int j=0;j<AWAY.size();j++) {
            sum+=AWAY.at(j);
            sum1+=HOME.at(j);
        }
        z++;
        if (sum!=sum1) {
            break;
        }
    }
    //Displaying awell-formattedgraph of the difference in total score of each team after each quarter
    cout << "     ";
    for (int x=1; x<=AWAY.size(); x++) {
        cout << "  " << x << "Q";
    }
    cout <<endl<< " AWAY ";
    for (int y=0; y<AWAY.size(); y++) {
        cout << setw(3) << right << AWAY.at(y) << " ";
    }
    cout << "-" << setw(5) << right << sum;
    cout <<endl<< " HOME ";
    for (int q=0; q<AWAY.size(); q++) {
        cout << setw(3) << right << HOME.at(q) << " ";
    }
    cout << "-" << setw(5) << right << sum1 << "\n ----";
    for (int w=0; w<AWAY.size(); w++) cout << "----";
    cout << "\n";
    int max=difference.at(0);
    for (int e=1;e<difference.size();e++) {
        if (difference.at(e)>max) {
            max=difference.at(e);
        }
    }
    int min=difference.at(0);
    for (int u=1;u<difference.size();u++) {
        if (difference.at(u)<min) {
            min=difference.at(u);
        }
    }
    for (int r=max; r>0; r--) {
        if (r<10) {
            cout << setw(3) << right << "+" << r;
        }
        else if (r>10 && r<100) {
            cout << setw(2) << right << "+" << r;
        }    
        else if (r>100 && r<1000) {
            cout << setw(1) << "+" << r;
        }
        for (int t=0; t<difference.size(); t++) {
            if (difference.at(t)>=r) cout << setw(4) << "**";
            else cout << setw(4) << "  ";
        }
        cout << "\n";
    }
    cout << "    0";
    for (int y=0; y<AWAY.size(); y++) {
        cout << "----";
    }
    cout << "\n";
    for (int o=-1; o>=min; o--) {
        cout << setw(4) << right << o;
        for (int t=0; t<difference.size(); t++) {
            if (difference.at(t)<=o) cout << setw(4) << "**";
            else cout << setw(4) << "  ";
        }
        cout << "\n";
    }
}

int inputVal(int min, string max) {
    int score;
    //prompt the user fora floating-point number 
    cout << "Please enter a number (min: " << min << ", max: no limit): ";
    cin >> score;
    //validate the number using the valid ranges given in the parameterset
    if (score >= min) {
        return score;
    }
    else return -1;
}
/*
1.
1Q away team score:
Please enter a number (min: 0, max: no limit): 23
1Q home team score:
Please enter a number (min: 0, max: no limit): 22
2Q away team score:
Please enter a number (min: 0, max: no limit): 19
2Q home team score:
Please enter a number (min: 0, max: no limit): 27
3Q away team score:
Please enter a number (min: 0, max: no limit): 33
3Q home team score:
Please enter a number (min: 0, max: no limit): 27
4Q away team score:
Please enter a number (min: 0, max: no limit): 18
4Q home team score:
Please enter a number (min: 0, max: no limit): 13
       1Q  2Q  3Q  4Q
 AWAY  23  19  33  18 -   93
 HOME  22  27  27  13 -   89
 --------------------
   +7      **        
   +6      **        
   +5      **        
   +4      **        
   +3      **        
   +2      **        
   +1      **  **    
    0----------------
   -1  **          **
   -2              **
   -3              **
   -4              **
 
2.
1Q away team score:
Please enter a number (min: 0, max: no limit): -1
Invalid input, try again!
Please enter a number (min: 0, max: no limit): 1
1Q home team score:
Please enter a number (min: 0, max: no limit): -2
Invalid input, try again!
Please enter a number (min: 0, max: no limit): 3
2Q away team score:
Please enter a number (min: 0, max: no limit): 5
2Q home team score:
Please enter a number (min: 0, max: no limit): 6
3Q away team score:
Please enter a number (min: 0, max: no limit): 56
3Q home team score:
Please enter a number (min: 0, max: no limit): 4
4Q away team score:
Please enter a number (min: 0, max: no limit): 5
4Q home team score:
Please enter a number (min: 0, max: no limit): 4
       1Q  2Q  3Q  4Q
 AWAY   1   5  56   5 -   67
 HOME   3   6   4   4 -   17
 ---------------------
   +3      **        
   +2  **  **        
   +1  **  **        
    0----------------
   -1          **  **
   -2          **  **
   -3          **  **
   -4          **  **
   -5          **  **
   -6          **  **
   -7          **  **
   -8          **  **
   -9          **  **
   -10         **  **
   -11         **  **
   -12         **  **
   -13         **  **
   -14         **  **
   -15         **  **
   -16         **  **
   -17         **  **
   -18         **  **
   -19         **  **
   -20         **  **
   -21         **  **
   -22         **  **
   -23         **  **
   -24         **  **
   -25         **  **
   -26         **  **
   -27         **  **
   -28         **  **
   -29         **  **
   -30         **  **
   -31         **  **
   -32         **  **
   -33         **  **
   -34         **  **
   -35         **  **
   -36         **  **
   -37         **  **
   -38         **  **
   -39         **  **
   -40         **  **
   -41         **  **
   -42         **  **
   -43         **  **
   -44         **  **
   -45         **  **
   -46         **  **
   -47         **  **
   -48         **  **
   -49         **  **
   -50             **
  
3.
1Q away team score:
Please enter a number (min: 0, max: no limit): 28
1Q home team score:
Please enter a number (min: 0, max: no limit): 23
2Q away team score:
Please enter a number (min: 0, max: no limit): 27
2Q home team score:
Please enter a number (min: 0, max: no limit): 24
3Q away team score:
Please enter a number (min: 0, max: no limit): 26
3Q home team score:
Please enter a number (min: 0, max: no limit): 30
4Q away team score:
Please enter a number (min: 0, max: no limit): 13
4Q home team score:
Please enter a number (min: 0, max: no limit): 17
It's a tie! Let's play another quarter.
5Q away team score:
Please enter a number (min: 0, max: no limit): 8
5Q home team score:
Please enter a number (min: 0, max: no limit): 8
It's a tie! Let's play another quarter.
6Q away team score:
Please enter a number (min: 0, max: no limit): 8
6Q home team score:
Please enter a number (min: 0, max: no limit): 6
       1Q  2Q  3Q  4Q  5Q  6Q
 AWAY  28  27  26  13   8   8 -   94
 HOME  23  24  30  17   8   6 -   94
 ----------------------------
    0------------------------
  -1  **  **  **    
  -2  **  **  **    
  -3  **  **  **    
  -4  **  **  **    
  -5  **  **        
  -6      **        
  -7      **        
  -8      **        
*/
