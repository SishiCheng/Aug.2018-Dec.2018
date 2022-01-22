#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int rows, columns, columnlabel, rowlabel, x;
    char rowoder, columnoder;
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
        cout << "Invalid input; try again!\n" << "Enter .the number of columns (1 to 12 inclusive):  ";
        cin >> columns;
    }
    cout << "Enter 'i' to display the row labels in increasing order, 'd' for decreasing order: ";
    cin >> rowoder;
    while (rowoder!='i' && rowoder!='d')
    {
        cout << "Invalid input; try again!\n" << "Enter 'i' to display the row labels in increasing order, 'd' for decreasing order: ";
        cin >> rowoder;
    }
    bool browoder=(rowoder=='i');
    cout << "Enter 'i' to display the column labels in increasing order, 'd' for decreasing order: ";
    cin >> columnoder;
    while (columnoder!='i' && columnoder!='d')
    {
        cout << "Invalid input; try again!\n" << "Enter 'i' to display the column labels in increasing order, 'd' for decreasing order: ";
        cin >> rowoder;
    }
    bool bcolumnoder=(columnoder=='i');
    cout <<endl << setw(4) << "";
    switch (bcolumnoder)
    {
        case true: 
            columnlabel=1;
            while (columnlabel <= columns)
            {
                cout << setw(4) << right << columnlabel;
                columnlabel=columnlabel+1;
            }
            cout <<endl;
            switch (browoder)
            {
                case true:
                    rowlabel=1;
                    while (rowlabel <= rows)
                    {
                        cout << setw(4) << right << rowlabel;
                        columnlabel=1;
                        while (columnlabel <= columns)
                        {
                            x=columnlabel*rowlabel;
                            columnlabel=columnlabel+1;
                            cout << setw(4) << right << x;
                        }
                        rowlabel=rowlabel+1;
                        cout <<endl;
                    }
                    break;
                case false: 
                    rowlabel=rows;
                    while (rowlabel >= 1)
                    {
                        cout << setw(4) << right <<rowlabel;
                        columnlabel=1;
                        while (columnlabel <= columns)
                        {
                            x=columnlabel*rowlabel;
                            columnlabel=columnlabel+1;
                            cout << setw(4) << right << x;
                        }
                        rowlabel=rowlabel-1;
                        cout << endl;
                    }
            }
            break;
        case false: 
            columnlabel=columns;
            while (columnlabel >= 1)
            {
                cout << setw(4)<< right << columnlabel;
                columnlabel=columnlabel-1;
            }
                cout <<endl;
                switch (browoder)
                {
                    case true:
                        rowlabel=1;
                        while (rowlabel <= rows)
                        {
                            cout << setw(4) << right << rowlabel;
                            columnlabel=columns;
                            while (columnlabel >= 1)
                            {
                                x=columnlabel*rowlabel;
                                columnlabel=columnlabel-1;
                                cout << setw(4) << right << x;
                            }
                            rowlabel=rowlabel+1;
                            cout <<endl;
                        }
                        break;
                    case false:
                        rowlabel=rows;
                        while (rowlabel >= 1)
                        {
                            cout << setw(4) << right <<rowlabel;
                            columnlabel=columns;
                            while (columnlabel >= 1)
                            {
                                x=columnlabel*rowlabel;
                                columnlabel=columnlabel-1;
                                cout << setw(4) << right << x;
                            }
                            rowlabel=rowlabel-1;
                            cout << endl;  
                       }
                                            
               }
   }
}   
   