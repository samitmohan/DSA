#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int power(int a, int b)
{
    int answer = 1;
    for (int i = 1; i <= b; i++)
    {
        // Multiplying it by a, b number of times (10^2 = 10 * 10 (b times))
        answer = answer * a;
    }
    return answer;
}

int numDigits(int a)
{
    int count = 0;
    while (a != 0)
    {
        count++;
        a /= 10;
    }
    return count;
}

int rotatebyK(int number, int k)
{
    int rotate = 0;
    // d= number of digits
    int d = numDigits(number);
    // if the number is increased, it follows the same pattern (0,4,8,12..)
    // every 4th gap -> starts again
    k = k % d;
    // if k is negative, make it positive. -> 1 number forward is the same as 4 number backwards)
    if (k < 0)
    {
        k = k + d;
    }
    //int p = power(10, k);
    // using the built in function for power
    int p = pow(10, k);
    int remainder = number % p;
    // rotating the number
    rotate = remainder * pow(10, d - k) + number / p;

    return rotate;
}

int32_t main()
{
    //cout << power(10, 2) << endl;
    //cout << numDigits(959912) << endl;
    //cout << rotatebyK(1234,-1) << endl;
}
