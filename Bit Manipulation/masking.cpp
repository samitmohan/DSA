#include <iostream>
#include <vector>

using namespace std;

// Masking

// Find ith bit.

int find(int n, int m)
{
    // create mask = (1 is at the mth bit and other bits are 0)
    int mask = (1 << (m - 1));
    // Simply AND it with n -> if original number is 1, answer = 1 (on). else answer = 0 (off)
    if ((n & mask) != 0)
    {
        cout << "On bit" << endl;
    }
    else
    {
        cout << "Off bit" << endl;
    }

    return 0;
}

// Set Bit (1001 given, m = 2, answer = 1011 (11))
// Left shift by (m-1) to get the mask -> OR it with the original number.

int setbit(int n, int m)
{
    int mask = 1 << (m - 1);
    int ans = n | mask;
    cout << "Answer : " << ans;

    return 0;
}

// Clearbit -> if it's 1 -> make it 0. if it's already 0 -> let it be.

int clearbit(int n, int m)
{
    if (m <= 0)
    {
        // it's already 0 (already off) -> let is be
        cout << "Already cleared";
    }
    else
    {
        // Left Shift m times.
        int mask = (1 << (m - 1));
        // Invert so mth bit becomes opposite. (0) (1's compliment). mask AND n, (1 & 0 = 0 [clear])
        int ans = (n & (~mask));
        cout << ans;
    }

    return 0;
}

// clearbit(11,2); // should be 9
// 11 = 1011
// 9 =  1001
// m = 2 (2nd bit OFF)

// Toggle (change it to 1 / 0)

void toggleBit()
{
    int n = 13, m = 3;
    int mask = (1 << (m - 1));
    // Use XOR so if its opposite, it'll become one, otherwise it'll become 0.
    int ans = (n ^ mask);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
