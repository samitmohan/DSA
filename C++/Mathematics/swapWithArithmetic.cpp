#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int swapWithoutswap(int a, int b)
{
    cout << a << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << b << endl;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    swapWithoutswap(10, 20);

    return 0;
}