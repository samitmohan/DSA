#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://www.geeksforgeeks.org/find-nth-magic-number/
// Find the nth Magic Number
// Amazon Question
/*

1 = 001 = 0*5^1 + 0 * 5^2 + 0 * 5^3 = 5
2 = 010 = 0 * pow(5,1) + 1 * pow(5,2) + 0 * pow(5,3) = 25
3 = 011 = 30
so on

n&1 = gives me the last digit in binary form. n >> 1 keeps shifting the number to right
keep doing the above in loop and multipling it by powers of 5 to get the Nth Magic Number

*/

int magicNumber(int n)
{
    int answer = 0;
    int base = 5;
    while (n > 0)
    {
        int last = n & 1;
        n = n >> 1;
        answer += last * base;
        base = base * 5; // 5^1, 5^2, 5^3
    }

    return answer;
}

int main()
{
    cout << magicNumber(6); // 150

    return 0;
}
