#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int sqrtRoot(ll n)
{
    ll x = n;
    // Infinite Loop
    while (true)
    {
        ll root = 0.5 * (x + (n / x));

        if ((root - x) < 1)
        {
            break;
        }
        else
        {
            x = root;
        }
        return root;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << sqrtRoot(16);

    return 0;
}