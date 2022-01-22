#include <iostream>
using namespace std;

long long int f(int n);

int main() {
    int n;
    cout << "Enter a number greater than or equal to 0: ";
    cin >> n;
    //Input validation in the main function for integers greater than or equal to 0
    while (n<0) {
        cout << "Please enter a valid number!\n" << "Enter a number greater than or equal to 0: ";
        cin >> n;
    }
    //Implementing input validation to ensure that the resulting value will not be negative (up to 61)
    while (n>61) {
        cout << "Please enter a valid number!\n" << "Enter a number less than or equal to 61: ";
        cin >> n;
    }
    f(n);
}

//This requires the use of a data type that can handle very large numbers
long long int f(int n) {
    //Display on console output for each iteration of the factorial calculation, including 𝑓(0) and 𝑓(𝑛)
    //recursive case
    if (n>0) {
        long long int fn = 2*f(n-1)-3;
        cout << "f(" << n << "): " << fn <<endl;
        return fn;
    }
    //base case
    else {
        cout << "f(0): 5" <<endl;
        return 5;
    }
}
/*
1.
Enter a number greater than or equal to 0: 61
f(0): 5
f(1): 7
f(2): 11
f(3): 19
f(4): 35
f(5): 67
f(6): 131
f(7): 259
f(8): 515
f(9): 1027
f(10): 2051
f(11): 4099
f(12): 8195
f(13): 16387
f(14): 32771
f(15): 65539
f(16): 131075
f(17): 262147
f(18): 524291
f(19): 1048579
f(20): 2097155
f(21): 4194307
f(22): 8388611
f(23): 16777219
f(24): 33554435
f(25): 67108867
f(26): 134217731
f(27): 268435459
f(28): 536870915
f(29): 1073741827
f(30): 2147483651
f(31): 4294967299
f(32): 8589934595
f(33): 17179869187
f(34): 34359738371
f(35): 68719476739
f(36): 137438953475
f(37): 274877906947
f(38): 549755813891
f(39): 1099511627779
f(40): 2199023255555
f(41): 4398046511107
f(42): 8796093022211
f(43): 17592186044419
f(44): 35184372088835
f(45): 70368744177667
f(46): 140737488355331
f(47): 281474976710659
f(48): 562949953421315
f(49): 1125899906842627
f(50): 2251799813685251
f(51): 4503599627370499
f(52): 9007199254740995
f(53): 18014398509481987
f(54): 36028797018963971
f(55): 72057594037927939
f(56): 144115188075855875
f(57): 288230376151711747
f(58): 576460752303423491
f(59): 1152921504606846979
f(60): 2305843009213693955
f(61): 4611686018427387907

2.
Enter a number greater than or equal to 0: 62
Please enter a valid number!
Enter a number less than or equal to 61: 57
f(0): 5
f(1): 7
f(2): 11
f(3): 19
f(4): 35
f(5): 67
f(6): 131
f(7): 259
f(8): 515
f(9): 1027
f(10): 2051
f(11): 4099
f(12): 8195
f(13): 16387
f(14): 32771
f(15): 65539
f(16): 131075
f(17): 262147
f(18): 524291
f(19): 1048579
f(20): 2097155
f(21): 4194307
f(22): 8388611
f(23): 16777219
f(24): 33554435
f(25): 67108867
f(26): 134217731
f(27): 268435459
f(28): 536870915
f(29): 1073741827
f(30): 2147483651
f(31): 4294967299
f(32): 8589934595
f(33): 17179869187
f(34): 34359738371
f(35): 68719476739
f(36): 137438953475
f(37): 274877906947
f(38): 549755813891
f(39): 1099511627779
f(40): 2199023255555
f(41): 4398046511107
f(42): 8796093022211
f(43): 17592186044419
f(44): 35184372088835
f(45): 70368744177667
f(46): 140737488355331
f(47): 281474976710659
f(48): 562949953421315
f(49): 1125899906842627
f(50): 2251799813685251
f(51): 4503599627370499
f(52): 9007199254740995
f(53): 18014398509481987
f(54): 36028797018963971
f(55): 72057594037927939
f(56): 144115188075855875
f(57): 288230376151711747
*/
