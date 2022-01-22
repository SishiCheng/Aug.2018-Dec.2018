#include <iostream>

using namespace std;

int main() {
    char lettergrade;
    cout << "Please enter a letter grade(A, B, C, D, or F): ";
    cin >> lettergrade;
    char sign;
    cout << "Please enter a sign (+ or -) if it exists; otherwise enter 'x': ";
    cin >> sign;
    switch (lettergrade)
    {
        case 'A': switch (sign)
        {
            case 'x': cout << "93% or greater.\n ";
                      break;
            case '-': cout << "Less than 93% and greater than or equal to 90%.\n";
                      break;
            default: cout << "A+ is a not valid grade.\n";
                     break;
        break;
        }
        return 0;
        case 'B': switch (sign)
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
        case 'C': switch (sign)
        {
            case '+': cout << "Less than 80% and greater than or equal to 77%.\n";
                      break;
            case 'x': cout << "Less than 77% and greater than or equal to 70%.\n";
                      break;
            default: cout << "C- is a not valid grade.\n ";
                     break;
        break;         
        }
        return 0;
        case 'D': switch (sign)
        {
            case '+': cout << "D+ is a not valid grade.\n";
                      break;
            case 'x': cout << "Less than 70% and greater than or equal to 60%.\n";
                      break;
            case '-': cout << "D- is a not valid grade.\n";  
                      break;
        break;
        }
        return 0;
        case 'F': switch (sign)
        {
            case '+': cout << "F+ is a not valid grade.\n";
                      break;
            case 'x': cout << "Less than 60%.\n";
                      break;
            case '-': cout << "F- is a not valid grade.\n"; 
                      break;
        break;          
        }
    }
}