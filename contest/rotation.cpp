#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int number;
    cin >> number;
    int k;
    cin >> k;
    int rotate = 0;
    int d = numDigits(number); // number of digits.
    // every 4th gap -> starts again (1234, k = 4 = 1234)
    k = k % d;
    // if k is negative, make it positive -> 1 number forward is the same as 4 numbers backward.
    if (k < 0)
    {
        k += d;
    }
    int p = pow(10, k);
    int remainder = number % p;
    // rotating the number (similar to reverse number)
    rotate = remainder * pow(10, d - k) + number / p;
    cout << rotate;

    return 0;
}
