#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> nums;
    vector <int> means;
    int x;
    //Prompts the user for an integer and validates it(1 and above), and then appendsit to the vector (using the push_back()member function)
    //Repeats the user input for integers until a -1is entered
    while (x!=-1) {
        cout << "Enter a positive integer (-1 to finish): ";
        cin >> x;
        if (x<1 && x!=-1) {
            cout << "That is not a valid number! Please try again.\n";
            continue;
        }
        else if(x>=1) {
            nums.push_back(x);
            float sum=0.00;
            float average;
            //Calculates and displays the arithmetic mean (average) of the vector WITH the new integer
            for (int j=0;j<nums.size();j++) {
                sum+=nums.at(j);
                average=sum/nums.size();
            }
            cout << "The new arithmetic mean is " << average;
            int averagei=average;
            if (averagei==average) {
                //Displays a message accepting the integer, Keeps the integer in the vector
                cout << "\nYour input has been accepted!\n\n";
                means.push_back(average);
            }
            else {
                //Removes the integer from the vector 
                nums.pop_back();
                //Displays a message rejecting the integer
                cout << "\nSorry, your input was rejected and will be removed!\n\n";
            }
        }
        
    }
    cout << "vector element:" <<endl;
    for (int i=0;i<nums.size();i++) {
        cout << "number[" << i << "] " << "= ";
        cout << nums.at(i) << "\n";
    }
    //displays themean of the first one element, first two elements, and so on, until the mean of the entire vector is calculatedand displayed
    for (int z=0; z<nums.size();z++) {
        cout << "\nMean of the first " << z+1 << " element(s): " << means.at(z);
    }
}
/*
1.
Enter a positive integer (-1 to finish): -5
That is not a valid number! Please try again.
Enter a positive integer (-1 to finish): 1
The new arithmetic mean is 1
Your input has been accepted!

Enter a positive integer (-1 to finish): 2
The new arithmetic mean is 1.5
Sorry, your input was rejected and will be removed!

Enter a positive integer (-1 to finish): 5
The new arithmetic mean is 3
Your input has been accepted!

Enter a positive integer (-1 to finish): 6
The new arithmetic mean is 4
Your input has been accepted!

Enter a positive integer (-1 to finish): 7
The new arithmetic mean is 4.75
Sorry, your input was rejected and will be removed!

Enter a positive integer (-1 to finish): 8
The new arithmetic mean is 5
Your input has been accepted!

Enter a positive integer (-1 to finish): -1
vector element:
number[0] = 1
number[1] = 5
number[2] = 6
number[3] = 8

Mean of the first 1 element(s): 1
Mean of the first 2 element(s): 3
Mean of the first 3 element(s): 4
Mean of the first 4 element(s): 5

2.
Enter a positive integer (-1 to finish): -2
That is not a valid number! Please try again.
Enter a positive integer (-1 to finish): 0
That is not a valid number! Please try again.
Enter a positive integer (-1 to finish): 1
The new arithmetic mean is 1
Your input has been accepted!

Enter a positive integer (-1 to finish): 2
The new arithmetic mean is 1.5
Sorry, your input was rejected and will be removed!

Enter a positive integer (-1 to finish): 3
The new arithmetic mean is 2
Your input has been accepted!

Enter a positive integer (-1 to finish): -1
vector element:
number[0] = 1
number[1] = 3

Mean of the first 1 element(s): 1
Mean of the first 2 element(s): 2

*/