#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Square root of a number using binary search

int sqrt(int x)
{
    ll low = 1, high = x, ans, mid;
    if (x == 0)
    {
        return 0;
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << sqrt(144);

    return 0;
}
