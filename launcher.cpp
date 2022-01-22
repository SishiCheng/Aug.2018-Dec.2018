#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double computeDistance(double, double, double);
double maxDistance(double, double, double);

int main() {
    double v0, d0, d;
    cout << "Enter a starting speed in m/s: ";
    cin >> v0;
    cout << "Enter a starting height in meters: ";
    cin >> d0;//Prompts the user for a value for v0and d0
    cout << "Time (s)  Height (m)" << endl;
    double t=0;
    while (computeDistance(v0, d0, t)>=0) {
        cout << setw(10) << left << fixed << setprecision(1) << t;
        cout << fixed << setprecision(2) << showpoint << computeDistance(v0, d0, t) <<endl;
        t+=0.1;
    }//Calls the computeDistance()function to display the values for the motion of a projectile in 0.1 second intervals starting at launch (t = 0) and until the projectile hits the ground
    cout << "PROJECTILE IMPACT AFTER " << t-0.1 << " SECONDS" <<endl;
    t= v0/(2*(1.0/2)*9.8);
    cout << "Max height was at " << t << " seconds with a height of " << maxDistance(v0, d0, t) << " meters.";
}//Calls the maxDistance()function to determine and display the max height of the projectileoReturn type: double(d)

double computeDistance(double v0, double d0, double t) {
    double d;
    d=((-1.0/2)*9.8*pow(t,2))+v0*t+d0;
    return d;
}//calculates the distance from ground

double maxDistance(double v0, double d0, double t) {
    double d;
    t= v0/(2*(1.0/2)*9.8);
    d=((-1.0/2)*9.8*pow(t,2))+v0*t+d0;
    return d;//calculatesthe maximum height of the projectile
}
/*
1.
Enter a starting speed in m/s: 10
Enter a starting height in meters: 0
Time (s)  Height (m)
0.0       0.00
0.1       0.95
0.2       1.80
0.3       2.56
0.4       3.22
0.5       3.77
0.6       4.24
0.7       4.60
0.8       4.86
0.9       5.03
1.0       5.10
1.1       5.07
1.2       4.94
1.3       4.72
1.4       4.40
1.5       3.97
1.6       3.46
1.7       2.84
1.8       2.12
1.9       1.31
2.0       0.40
PROJECTILE IMPACT AFTER 2.00 SECONDS
Max height was at 1.02 seconds with a height of 5.10 meters.

2.
Enter a starting speed in m/s: 11
Enter a starting height in meters: 1
Time (s)  Height (m)
0.0       1.00
0.1       2.05
0.2       3.00
0.3       3.86
0.4       4.62
0.5       5.28
0.6       5.84
0.7       6.30
0.8       6.66
0.9       6.93
1.0       7.10
1.1       7.17
1.2       7.14
1.3       7.02
1.4       6.80
1.5       6.47
1.6       6.06
1.7       5.54
1.8       4.92
1.9       4.21
2.0       3.40
2.1       2.49
2.2       1.48
2.3       0.38
PROJECTILE IMPACT AFTER 2.30 SECONDS
Max height was at 1.12 seconds with a height of 7.17 meters.
*/
