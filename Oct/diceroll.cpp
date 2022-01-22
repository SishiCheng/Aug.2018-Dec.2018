#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

int roll(int, double *);

int main() {
    int choice, x=2, y=2;
    string name;
    int sides=1;
    double *weights;
    double total=0;
    do {
        //Presents the user with a menu comprised of four choices.
        cout << "1.Enter the sides and weights for a die\n" << "2.Specify an output file" <<endl;
        cout << "3.Simulate a specified number of rolls of the weighted die\n" << "4.Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        if (choice!=1 && choice!=2 && choice!=3 && choice!=4) {
            continue;
        }
        if (choice==1) {
            while (sides<2) {
                //Prompt the user to enter the number of sides of a die and validate the input (≥2)
                cout << "Please enter the number of sides of a die: ";
                cin >> sides;
                if (sides<2) {
                    cout << "Invalid input, try again!\n";
                }
            }
            weights=new double[sides];
            for (int j=0; j<sides; j++) {
                //Prompt the user to enter the appropriate number of weights and validate the input (>0)
                cout << "Please enter the appropriate weight for side " << j+1 << ": ";
                cin >> weights[j];
                while (weights[j]<=0) {
                    cout << "Invalid input, try again!\n" << "Please enter the appropriate the appropriate weight for side " << j+1 << ": ";
                    cin >> weights[j];
                }
            }
            x=1;
        }
    
        else if (choice==2) {
            //Prompt the user for the name of a file to write all output in text format
            cout << "Please enter a name of a file to write all output in text format: ";
            cin >> name;
            y=1;
        }
    
        else if (choice==3) {
            int num;
            //Prompt the user for the number of rolls to perform and validate the input (≥1)
            cout << "Please enter the number of rolls to perform: ";
            cin >> num;
            while (num<1) {
                cout << "Invalid input, try again!\n" << "Please enter the number of rolls to perform: ";
                cin >> num;
            }
            if (x!=1) {
                //Present an error to the user if the number of sides and associated weights have not yet been entered
                cout << "Error.\n";
                continue;
                
            }
            else if (y!=1) {
                //Present an error to the user if no output file has been specified
                cout << "Error.\n";
                continue;
            }
            ofstream fout;
            fout.open(name, ios::app);
            //written to the file
            fout << "Please enter the number of rolls to perform: ";
            fout << num;
            srand(time(0));
            //display the output.
            cout << "          Sides        # Rolls    Probability\n";
            fout << "\n          Sides        # Rolls    Probability\n";
            int *times=new int[sides+1];
            for (int i=0; i<=sides; i++) {
                times[i]=0;
            }
            for (int u=0; u<num; u++) {
                times[roll(sides, weights)]+=1;
            }
            for (int p=0; p<sides; p++) {
                total+=weights[p];
            }
            for (int o=0; o<sides; o++) {
                cout << setw(15) << right << o+1 << setw(15) << right << times[o+1] << setw(15) << right << fixed << setprecision(2) <<showpoint<< 1.0*weights[o]/total <<endl;
                fout << setw(15) << right << o+1 << setw(15) << right << times[o+1] << setw(15) << right << fixed << setprecision(2) << 1.0*weights[o]/total <<endl;
            }
            
        }
        else {
            //End the program
            return 0;
        }
    }while (choice!=4);
    
}

//Implements a function named roll()that simulates a single roll of a weighted die.
int roll(int sides, double *weights) {
    int sum=0;
    for (int w=0; w<sides; w++) {
        sum+=*(weights+w);
    }
    
    int becomeint=1;
    for (int e=0; e<sides; e++) {
        while (weights[e]*becomeint!=static_cast<int>(weights[e]*becomeint)) {
            becomeint=becomeint*10;
        }
    }
          
    int sumint= sum*becomeint;
    int a=rand()%sumint+1;
    int accumulator=0;
    for (int t=0; t<sides; t++) {
        accumulator+=weights[t]*becomeint;
        if (a<accumulator) {
            return t+1;
        }
    }
}  
/*
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 1
Please enter the number of sides of a die: 4
Please enter the appropriate weight for side 1: 3.5
Please enter the appropriate weight for side 2: 1.5
Please enter the appropriate weight for side 3: 2
Please enter the appropriate weight for side 4: 3
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 2
Please enter a name of a file to write all output in text format: ro.txt
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 3
Please enter the number of rolls to perform: 100000
          Sides        # Rolls    Probability
              1          37587           0.35
              2          16729           0.15
              3          22151           0.20
              4          23533           0.30
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 4

2.
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 7
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 3
Please enter the number of rolls to perform: 3
Error.
1.Enter the sides and weights for a die
2.Specify an output file
3.Simulate a specified number of rolls of the weighted die
4.Exit
Please enter your choice: 4
*/
