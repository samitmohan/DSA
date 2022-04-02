#include <bits/stdc++.h>
using namespace std;

int binary_conversion_recursive(int decimal)
{
    // base case
    if (decimal == 0)
        return 0;

    // recursive case
    return (decimal % 2 + 10 * binary_conversion_recursive(decimal / 2));
}

int main()
{
    int decimal = 7;
    cout << binary_conversion_recursive(decimal);

    return 0;
}
