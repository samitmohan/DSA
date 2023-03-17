#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

// Given Size K -> Find all sub arrays of window size K, find sum of all of them and return max sum.

// Example -> 2,3,5,2,9,7,1. Size = 3.
// 2 3 5
// 3 5 2
// 5 2 9
// 2 9 7
// 9 7 1

// highest = 18 ( 2, 9, 7 )

int solve(vector<int> &arr, int K)
{
    int i = 0, j = 0;
    int current_sum = 0, max_sum = INT_MIN;
    while (j < arr.size())
    {
        // check for window size
        current_sum = current_sum + arr[i];
        // to find max sum we need to choose a particular window size
        if (j - i + 1 < K)
        {
            // shift window.
            j++;
        }
        else if (j - i + 1 == K)
        {
            // we have found our window
            max_sum = max(max_sum, current_sum);
            // keep shifting the window.
            i++;
            j++;
        }
    }
    return max_sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {100, 200, 300, 400};
    // answer should be : 700 (400, 300)
    cout << solve(arr, 2);

    return 0;
}
