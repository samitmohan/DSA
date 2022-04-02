#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/

// change og problem to sub problem and then keep doing that and convert sub back to original once you get the answer
// converting sub -> og -> relation -> (x + k) % n (do on paper)

int winner(int n, int k)
{
    // base case (only 1 guy left)
    if (n == 1)
    {
        return 0;
    }

    // recursive case
    // (x + k) % n [why % n bcs in a cirlce if it reaches out of bound -> % n]
    // x = winner(n - 1, k)
    return (winner(n - 1, k) + k) % n;
}

int josephus(int n, int k)
{
    // since it's starting from 0, we need it to start from 1 (as there is no such thing as 0th person)
    // so add 1 to the final answer.
    // if not stated in question -> don't add 1 (LC)
    return winner(n, k) + 1;
}

int main()
{
    cout << josephus(5, 3);

    return 0;
}
