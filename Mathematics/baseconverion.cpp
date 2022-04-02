#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

// Base conversion.

// Base 10 to Base 2


int decimalTobinary(int n)
{
    int answer = 0, count = 0;
    while (n != 0)
    {
        int remainder = n % 2;
        answer = pow(10, count) * remainder + answer; // conversion to base 2.
        count++;
        n = n / 2; // move on to the next digit
    }
    cout << "Decimal To Binary : " << n << " : " << answer << endl;
    return 0;
}

// Hence general form
/*
int general(int num){
    int answer = 0, int count = 0, int a, b;
    while(num!=0){
        // a -> final base, b -> initial base
        int remainder = num%a; // we do num%2 to convert it into base 2
        // basically we're doing reverse like we do in real conversion, it is the same code as in reverse
        int answer = pow(b,count) * remainder + answer; 
        count++;
        num=num/a; // keep dividing it, 98->49->24->12->6->3->1->0 (in base 2 conversion of 98 along with remainder)
    }
    //cout << answer << "\n";
}
*/

// Base 2 to Base 10

int binaryTodecimal(int n)
{
    int answer = 0, count = 0;
    while (n != 0)
    {
        int remainder = n % 10;                          // final base -> 10 (a)
        int answer = pow(2, count) * remainder + answer; // initial base -> 2 (b)
        count++;
        n = n / 10; // a
    }
    cout << "Binary To Decimal : " << n << " : " << answer << endl;
    return 0;
}

// Base 8 to Base 10

int octalTodecimal(int n)
{
    int answer = 0, count = 0;
    while (n != 0)
    {                                                    // write in for loop as well
        int remainder = n % 10;                          // final base -> 10 (a)
        int answer = pow(8, count) * remainder + answer; // initial base -> 8 (b) using reverse formula
        count++;
        n = n / 10;
    }
    cout << "Octal to Decimal" << n << " : " << answer << endl;
    return 0;
}

int decimalTooctal(int n)
{
    int answer = 0, count = 0;
    for (int i = 0; i <= n; i--)
    {
        int remainder = n % 8;                            // final base -> 8 (a)
        int answer = pow(10, count) * remainder + answer; // initial base -> 10 (b) using reverse formula
        count++;
        n = n / 8; // final base -> 8 (a)
    }
    cout << "Decimal to Octal" << n << " : " << answer << endl;
    return 0;
}

// Hex to Binary (for hex to decimal just change a and b)

int hexTobinary(int n)
{
    int answer = 0;
    int count = 0;
    while (n != 0)
    {
        int remainder = n % 2;                            // a (final)
        int answer = pow(10, count) * remainder + answer; // 10 -> initial -> b
        count++;
        n /= 2; // n=n/a
    }
    cout << "Hex to Decimal " << n << " : " << answer << endl;
    return 0;
}

// General code

// int general(int n){
//     int finalBase, initialBase; cin >> finalBase >> initialBase;
//     int answer = 0, count=0;
//     while(n!=0){
//         int remainder = n%finalBase;
//         int answer = pow(initialBase, count) * remainder + answer;
//         count++;
//         num/=initialBase;
//     }
//     cout << "Answer : " << answer << endl;
// }

int main()
{
}
