#include <iostream>

using namespace std;

int main() {
    char sign;
    char lettergrade;
    cout << "Please enter a letter grade(A, B, C, D or F): ";
    cin >> lettergrade;
    while (lettergrade != 'A' && lettergrade != 'B' && lettergrade != 'C' && lettergrade != 'D' && lettergrade != 'F' )
    {
        cout << "Invalid input, try again!\n" << "Please enter a letter grade(A, B or C): ";
        cin >> lettergrade;
    }
    switch (lettergrade)
    {
        case 'A': cout << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                  cin >> sign;
                  while (sign != 'x' && sign != '-')
                  {
                      cout << "Invalid input, try again!\n" << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                      cin >> sign;
                  }
                  switch (sign)
                  {
                      case 'x': cout << "93% or greater.\n ";
                                break;
                      case '-': cout << "Less than 93% and greater than or equal to 90%.\n";
                                break;
                    }
                    return 0;
        case 'B': cout << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                  cin >> sign;
                  while (sign != '+' && sign != 'x' && sign != '-')
                  {
                      cout << "Invalid input, try again!\n" << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                      cin >> sign;
                  }
                  switch (sign)
                  {
                      case '+': cout << "Less than 90% and greater than or equal to 87%.\n";
                                break;
                      case 'x': cout << "Less than 87% and greater than or equal to 83%.\n";
                                break;
                      case '-': cout << "Less than 83% and greater than or equal to 80%.\n";
                                break;
                    break;          
                    }
                    return 0;
        case 'C': cout << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                  cin >> sign;
                  while (sign != '+' && sign != 'x')
                  {
                      cout << "Invalid input, try again!\n" << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
                      cin >> sign;
                  }
                  switch (sign)
                  {
                      case '+': cout << "Less than 80% and greater than or equal to 77%.\n";
                                break;
                      case 'x': cout << "Less than 77% and greater than or equal to 70%.\n";
                                break;
                    break;         
                    }
                    return 0;
        case 'D': cout << "Less than 70% and greater than or equal to 60%.";
                  break;
                  return 0;
        case 'F': cout << "Less than 60%. ";
                  break;
        
    }
}