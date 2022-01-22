#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int inputVal(int, string);

int main() {
    vector <int> AWAY;
    vector <int> HOME;
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
        if (sum!=sum1) {
            break;
        }
        z++;
    }
    //When the game is over (one team has more points than the other at the end of the fourth or later quarter), print a well-formatted box score table of the game, including the total score for each team
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
    cout << "-" << setw(5) << right << sum1;
}

int inputVal(int min, string max) {
    int score;
    //Uses the inputVal()function to prompt the user forthe scores of a basketball game for each quarter and each team
    cout << "Please enter a number (min: " << min << ", max: no limit): ";
    cin >> score;
    //validate the score using the valid ranges given in the parameterset
    if (score >= min) {
        return score;
    }
    else return -1;
}
/*
1.
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
Please enter a number (min: 0, max: no limit): 9
6Q home team score:
Please enter a number (min: 0, max: no limit): 9
It's a tie! Let's play another quarter.
7Q away team score:
Please enter a number (min: 0, max: no limit): 8
7Q home team score:
Please enter a number (min: 0, max: no limit): 6
       1Q  2Q  3Q  4Q  5Q  6Q  7Q 
 AWAY  28  27  26  13   8   9   8 -  117
 HOME  23  24  30  17   8   9   6 -  119

2.
1Q away team score:
Please enter a number (min: 0, max: no limit): -1
Invalid input, try again!
Please enter a number (min: 0, max: no limit): 0
1Q home team score:
Please enter a number (min: 0, max: no limit): -1
Invalid input, try again!
Please enter a number (min: 0, max: no limit): 0
2Q away team score:
Please enter a number (min: 0, max: no limit): 1
2Q home team score:
Please enter a number (min: 0, max: no limit): 2
3Q away team score:
Please enter a number (min: 0, max: no limit): 3
3Q home team score:
Please enter a number (min: 0, max: no limit): 4
4Q away team score:
Please enter a number (min: 0, max: no limit): 5
4Q home team score:
Please enter a number (min: 0, max: no limit): 6
       1Q  2Q  3Q  4Q
 AWAY   0   1   3   5 -    9
 HOME   0   2   4   6 -   12
 
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
*/
