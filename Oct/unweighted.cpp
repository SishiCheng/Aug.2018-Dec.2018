#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

int roll(int, double *);

int main() {
    int sides=0;
    double *weights;
    double total=0;
    
    while (sides>20 || sides<1) {
        //Prompt the user to enter the number of sides of a die and validate the input (20≥sides≥1)
        cout << "How many sides does your die have? ";
        cin >> sides;
        if (sides>20 || sides<1) {
            cout << "Invalid number! ";
        }
    }
    
    //Dynamically allocates an array of doubles representing the weights for each side
    weights=new double[sides];
    for (int j=0; j<sides; j++) {
        //Because the weights are for an unweighted die, all the weights can be set to 1.0
        weights[j]=1.0;
    }     
    
    int num;
    //Prompt the user for the number of rolls to perform and validate the input (≥1)
    cout << "How many rolls would you like to perform? ";
    cin >> num;
    while (num<1) {
        cout << "Invalid number!\n" << "How many rolls would you like to perform? ";
        cin >> num;
    }
    
    srand(time(0));
    //display the output.
    cout << "          Sides        # Rolls    Probability\n";
    int *times=new int[sides+1];
    for (int i=0; i<=sides; i++) {
        times[i]=0;
    }
    for (int u=0; u<num; u++) {
        //Calls the roll function as many times as requested by the user, keeping count of each roll
        times[roll(sides, weights)]+=1;
    }
    for (int p=0; p<sides; p++) {
        total+=weights[p];
    }
    for (int o=0; o<sides; o++) {
        cout << setw(15) << right << o+1 << setw(15) << right << times[o+1] << setw(15) << right << fixed << setprecision(2) <<showpoint<< 1.0*weights[o]/total <<endl;
    }
}

//Implements a function named roll that simulates a single roll of an unweighted die
int roll(int sides, double *weights) {
    return rand() % sides + 1;
}  
/*
How many sides does your die have? 10
How many rolls would you like to perform? 100000
          Sides        # Rolls    Probability
              1           9847           0.10
              2          10034           0.10
              3          10082           0.10
              4           9915           0.10
              5          10006           0.10
              6          10126           0.10
              7          10086           0.10
              8           9983           0.10
              9           9854           0.10
             10          10067           0.10
             
2.
How many sides does your die have? 6
How many rolls would you like to perform? 100000
          Sides        # Rolls    Probability
              1          16816           0.17
              2          16608           0.17
              3          16720           0.17
              4          16676           0.17
              5          16479           0.17
              6          16701           0.17
*/
