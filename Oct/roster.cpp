#include <iostream>
using namespace std;

int main() {
    string name[5];
    int counter=0;
    while(counter<=4) {
        cout << "Please enter a name: ";
        cin >> name[counter];
        counter++;
    }//Prompts the user to enterthe first names of 5 students
    for (int j = 0; j<=3; j++) {
        for (int i=j+1;i<=4;i++) { 
            if (name[j]==name[i]) {
                cout << name[i] << " is a duplicate name!";//Determines and displaysany duplicate names
            }
        }
    }
}
/*
1.
Please enter a name: John
Please enter a name: Joe
Please enter a name: James
Please enter a name: Jane
Please enter a name: John
John is a duplicate name!

2.
Please enter a name: Cici
Please enter a name: Harry
Please enter a name: Mary
Please enter a name: Lily
Please enter a name: Cici
Cici is a duplicate name!

3.
Please enter a name: Liz
Please enter a name: Brandon
Please enter a name: Ton
Please enter a name: Ton
Please enter a name: Mick
Ton is a duplicate name!
*/
