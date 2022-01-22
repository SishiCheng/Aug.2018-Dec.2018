#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int rows, columns, columnlabel, rowlabel, x;
    cout << "Enter the number of rows (1 to 12 inclusive):  ";
    cin >> rows;
    while (rows < 1 || rows > 12)
    {
        cout << "Invalid input; try again!\n" << "Enter the number of rows (1 to 12 inclusive):  ";
        cin >> rows;
    }
    cout << "Enter the number of columns (1 to 12 inclusive): ";
    cin >> columns;
    while (columns < 1 || columns > 12)
    {
        cout << "Invalid input; try again!\n" << "Enter the number of columns (1 to 12 inclusive):  ";
        cin >> columns;
    }
    cout <<endl << setw(4) << "";
    columnlabel=columns-columns+1;
    while (columnlabel <= columns)
    {
        cout << setw(4) << right << columnlabel;
        columnlabel=columnlabel+1;
    }
    cout <<endl;
    rowlabel=rows-rows+1;
    while (rowlabel <= rows)
    {
        cout << setw(4) << right << rowlabel;
        columnlabel=columns-columns+1;
        while (columnlabel <= columns)
        {
            x=columnlabel*rowlabel;
            columnlabel=columnlabel+1;
            cout << setw(4) << right << x;
        }
        rowlabel=rowlabel+1;
        cout <<endl;
    }
}