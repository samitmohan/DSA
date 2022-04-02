#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Time complexity of bitwise operations = O(1)

// Basic Gates -> AND OR NOT. XOR
// XOR -> Output is 1 when numbers are different. Output is 0 when numbers are same.
// a^1 = 0. a^0 = a. a^a = 0

// left shift -> <<  (shift the number to the left)
// Multiplies the number. (a << 1 = 2a) or (a << k = a * 2^k)

// right shift -> >> (shifts the number to the right)
// Divides the number (a >> 1 = a/2) or (a >> k = a/2^k)

// Find if a number is odd or even

// Odd numbers -> Binary form -> have 1 in the end.
// Even numbers -> Binary form -> have 0 in the end.
// Just & the number with 1 -> and check if last number is 1 or 0, if 1 (then it was previously 1 as well -> Odd) else Even

int odd_even(int n)
{
    if ((n & 1) == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    return 0;
}

// Swap 2 numbers without using third variable temp or a/b technique

int swapNum(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << "," << b;

    return 0;
}

// Also in binary representation -> First number -> MSB(Most significant bit) and last number is LSB (Least significant bit) (1000) 1 = msb, 0 = lsb

// 2's compliment = 1's compliment + 1

int main()
{
    odd_even(12);
    cout << endl;
    swapNum(1, 2);
}
