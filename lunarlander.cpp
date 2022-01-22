#include <iostream>
#include <random>
#include <ctime>
using namespace std;

bool land(int *);

int main() {
    //Declares a 2D integer array of size 10*10 that represents the terrain
    int integer[10][10];
    srand(time(0));
    int x, y;
    //Uses random number generation to populate safe and unsafe locations of the terrain
    for (int i=0; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            //Safe locations are represented by the number 1
            //Unsafe locations are represented by the number 0
            integer[i][j]=rand() % 2;
        }
    }
    //Displays a well-formatted table that visualizes the terrain
    cout << "  | 0 1 2 3 4 5 6 7 8 9 \n" << "--+--------------------\n";
    for (int i=0; i<=9; i++) {
        cout << i << " |";
        for (int j=0; j<=9; j++) {
            if (integer[i][j]==0 || integer[i][j]==3) {
                cout << " " << integer[i][j];
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    cout << "Enter (x, y) coordinates: ";
    cin >> x >> y;
    //If the location is unsafe, displays a message to the user and prompts for another (x, y) coordinates to attempt a landing, until a successful one is entered.
    while (land(&integer[x][y])==false) {
        //Prompts the user to enter the (x, y) coordinates of the desired landing location
        cout << "Enter (x, y) coordinates: ";
        cin >> x >> y;
    }
        
    cout << "  | 0 1 2 3 4 5 6 7 8 9 \n" << "--+--------------------\n";
    for (int i=0; i<=9; i++) {
        cout << i << " |";
        for (int j=0; j<=9; j++) {
            if (integer[i][j]==0 || integer[i][j]==3) {
                cout << " " << integer[i][j];
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "SUCCESSFUL LANDING!\n";
}

bool land(int *location) {
    if (*location==1) {
        //If the location is safe, change its value to 3 (using int *location) to indicate the lunar lander has landed successfully
        *location=3;
        //true: if the location is safe
        return true;
    }
    else {
        cout << "CRASH! Try again!\n";
        //false: if the location is unsafe
        return false;
    }
}
/*
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0       0       0 0
1 |   0     0     0 0  
2 |   0 0   0          
3 | 0   0   0   0   0 0
4 |       0 0     0    
5 |   0 0     0 0   0  
6 | 0 0 0 0   0        
7 | 0           0     0
8 | 0 0 0 0   0        
9 | 0     0   0 0     0
Enter (x, y) coordinates: 3 0
CRASH! Try again!
Enter (x, y) coordinates: 4 0
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0       0       0 0
1 |   0     0     0 0  
2 |   0 0   0          
3 | 0   0   0   0   0 0
4 | 3     0 0     0    
5 |   0 0     0 0   0  
6 | 0 0 0 0   0        
7 | 0           0     0
8 | 0 0 0 0   0        
9 | 0     0   0 0     0
SUCCESSFUL LANDING!

2.
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0 0 0     0 0   0  
1 | 0 0       0   0   0
2 | 0     0 0 0        
3 | 0     0 0 0 0     0
4 | 0         0   0    
5 | 0   0 0   0 0      
6 | 0   0         0 0  
7 | 0 0 0   0   0   0  
8 | 0 0 0 0 0     0 0 0
9 |   0 0 0            
Enter (x, y) coordinates: 0 3
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0 0 0 3   0 0   0  
1 | 0 0       0   0   0
2 | 0     0 0 0        
3 | 0     0 0 0 0     0
4 | 0         0   0    
5 | 0   0 0   0 0      
6 | 0   0         0 0  
7 | 0 0 0   0   0   0  
8 | 0 0 0 0 0     0 0 0
9 |   0 0 0            
SUCCESSFUL LANDING!
*/
     
