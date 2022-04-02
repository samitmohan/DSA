// Reverse a number
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int reverse(int num)
{
    int remainder, rev = 0;
    while (num != 0)
    {
        remainder = num % 10; // access last digit
        // Now have to put that last digit at first in reverse
        rev = rev * 10 + remainder;
        // Divide the number by 10 to get the second last number now.
        num /= 10;
    }
    cout << rev << endl;
    return 0;
}

int32_t main()
{
    reverse(9735);
    return 0;
}
