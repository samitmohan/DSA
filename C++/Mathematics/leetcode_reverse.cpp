#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
// Leetcode Question 7 -> Reverse a number

int rev(int num)
{
    int remainder, reverse = 0;
    while (num != 0)
    {
        // check if our number is inside the INT_MAX area and not greater or equal(int MIN) to that area
        // lets say number is 19999912 and it works till 199991 but when it reaches the last num 2 -> error. So for that we need to check for INT_MAX/10;
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
        {
            // then number is out of the 32 bit range and should return 0
            return 0;
        }
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    return reverse;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // out of range number
    cout << rev(19999999991) << endl;
    // in range number
    cout << rev(1233452302302932) << endl;

    return 0;
}
