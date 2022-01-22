#include <iostream>
#include <random>
#include <ctime>
using namespace std;

bool land(int *);
bool move(int *, int *);

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
    char direction;
    //In a loop, prompt the user to move the rover until it attempts an unsafe move
    while (true) {
        //Prompting the user to enter one of four directions in which to move: left, right, up, down
        cout << "Enter a move (L, R, U, or D): ";
        cin >> direction;
        //Validate the user input for one of the four possibilities
        while (direction!='L' && direction!='R' && direction!='U' && direction!='D') {
            cout << "Invalid move! Try again!\n" << "Enter a move (L, R, U, or D): ";
            cin >> direction;
        }
        
        //Making sure that the proposed move keeps the rover inside the grid
        while (x==0 && direction=='U') {
            cout << "Do not accept, try again!\n" << "Enter a move (L, R, U, or D): ";
            cin >> direction;
        }
        while (x==9 && direction=='D') {
            cout << "Do not accept, try again!\n" << "Enter a move (L, R, U, or D): ";
            cin >> direction;
        }
        while (y==0 && direction=='L') {
            cout << "Do not accept, try again!\n" << "Enter a move (L, R, U, or D): ";
            cin >> direction;
        }
        while (y==9 && direction=='R') {
            cout << "Do not accept, try again!\n" << "Enter a move (L, R, U, or D): ";
            cin >> direction;
        }
        
        int x1, y1;
        if (direction=='L') {
            y1=y-1;
            x1=x;
        }
        else if (direction=='R') {
            y1=y+1;
            x1=x;
        }
        else if (direction=='U') {
            x1=x-1;
            y1=y;
        }
        else {
            x1=x+1;
            y1=y;
        }
        if (move(&integer[x][y], &integer[x1][y1])==true) {
            x=x1;
            y=y1;
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
                cout <<endl;
            }
            continue;
        }
        else {
            return 0;
        }
    }
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

bool move(int *old_location, int *new_location) {
    //If the new location is safe, change its value to 3 and the old location to 1 to indicate a successful move, then return true
    if (*new_location==1) {
        *new_location=3;
        *old_location=1;
        return true;
    }
    //If the new location is unsafe, then return false
    else {
        cout << "CRASH! Game over!\n";
        return false;
    }
}
/*
1.
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0 0     0   0 0    
1 | 0   0 0       0   0
2 |       0 0   0 0    
3 |       0         0 0
4 | 0 0   0   0   0 0 0
5 |       0   0 0   0  
6 | 0   0         0 0  
7 |   0   0 0 0        
8 |   0     0 0   0 0  
9 |   0   0 0 0       0
Enter (x, y) coordinates: 0 2
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0 0 3   0   0 0    
1 | 0   0 0       0   0
2 |       0 0   0 0    
3 |       0         0 0
4 | 0 0   0   0   0 0 0
5 |       0   0 0   0  
6 | 0   0         0 0  
7 |   0   0 0 0        
8 |   0     0 0   0 0  
9 |   0   0 0 0       0
SUCCESSFUL LANDING!
Enter a move (L, R, U, or D): R
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0 0   3 0   0 0    
1 | 0   0 0       0   0
2 |       0 0   0 0    
3 |       0         0 0
4 | 0 0   0   0   0 0 0
5 |       0   0 0   0  
6 | 0   0         0 0  
7 |   0   0 0 0        
8 |   0     0 0   0 0  
9 |   0   0 0 0       0
Enter a move (L, R, U, or D): R
CRASH! Game over!

2.
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0     0 0     0 0  
1 | 0   0 0     0      
2 |     0       0 0 0  
3 |   0 0   0 0 0   0 0
4 |           0 0      
5 |     0   0   0 0 0 0
6 |     0 0 0 0 0 0 0  
7 | 0   0   0   0 0    
8 |   0 0              
9 |     0              
Enter (x, y) coordinates: 1 1
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0     0 0     0 0  
1 | 0 3 0 0     0      
2 |     0       0 0 0  
3 |   0 0   0 0 0   0 0
4 |           0 0      
5 |     0   0   0 0 0 0
6 |     0 0 0 0 0 0 0  
7 | 0   0   0   0 0    
8 |   0 0              
9 |     0              
SUCCESSFUL LANDING!
Enter a move (L, R, U, or D): D
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0     0 0     0 0  
1 | 0   0 0     0      
2 |   3 0       0 0 0  
3 |   0 0   0 0 0   0 0
4 |           0 0      
5 |     0   0   0 0 0 0
6 |     0 0 0 0 0 0 0  
7 | 0   0   0   0 0    
8 |   0 0              
9 |     0              
Enter a move (L, R, U, or D): L
  | 0 1 2 3 4 5 6 7 8 9 
--+--------------------
0 | 0     0 0     0 0  
1 | 0   0 0     0      
2 | 3   0       0 0 0  
3 |   0 0   0 0 0   0 0
4 |           0 0      
5 |     0   0   0 0 0 0
6 |     0 0 0 0 0 0 0  
7 | 0   0   0   0 0    
8 |   0 0              
9 |     0              
Enter a move (L, R, U, or D): U
CRASH! Game over!
*/
    
