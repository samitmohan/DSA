// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// Using a helper function here to return the answer. Starts from 0.

int helper(int num, int steps)
{
    // Base Case
    if (num == 0)
    {
        return steps;
    }

    // Recursive Case
    if (num % 2 == 0)
    {
        return helper(num / 2, steps + 1);
    }
    return helper(num - 1, steps + 1);
}

int numberOfSteps(int num)
{
    // number is even divide by 2, otherwise subtract 1

    return helper(num, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << numberOfSteps(41);

    return 0;
}
