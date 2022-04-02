#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Problem Link -> https://leetcode.com/problems/climbing-stairs/
// Solved without DP -> to understand recursion.

//                           (0,4)
//                   /                  \
//               (1,4)                  (2,4)
//             /        \               /     \
//         (2,4)         (3,4)        (3,4)  (4,4)
//          /  \         /    \       /    \
//       (3,4)  (4,4)   (4,4) (5,4)  (4,4) (5,4)
//       /   \
//    (4,4) (5,4)

// Answer = 5.

int fun(int step, int n)
{
    // BASE CASE
    // if on the last stage -> 1 step.
    if (step == n)
    {
        // (reached last staircase or just 1 before that so we cant jump 2)
        return 1;
    }
    // Agar exceed kar jaaye staircases, toh 0 return kardo.
    if (step > n)
    {
        return 0;
    }
    else
    {
        // add first and last step (first step + second step) = total number of steps to reach point xyz.
        return fun(step + 1, n) + fun(step + 2, n);
    }
}

int climbStairs(int n)
{
    return fun(0, n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << climbStairs(4);

    return 0;
}
