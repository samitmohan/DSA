#include <bits/stdc++.h>
using namespace std;

// Question -> Given array 1,2,3,4 and target 4, find permutation answers (repetition allowed) such that sum of numbers in the array = target
/*
example -> {1,2,3,4} | target = 4
    1111
    112
    121
    13
    211
    22
    31
    4
*/


void target_sum(vector<int> &arr, int target, int sum, string ans) 
{
    // sum starts from 0 && answer string is empty. (keep appending both as we continue through the program)
    // base case -> sum = target, print the output.
    if (sum == target)
    {
        cout << ans << endl;
        return;
    }
    // Recursive case, go thorugh all numbers.
    for (auto i : arr)
    {
        // if i + sum (0 for now) <= target, then we can add i in our answer list.
        if (sum + i <= target) {
            // add i to our ans list, and do this again for new sum = sum + i.
            target_sum(arr, target, sum + i, ans + to_string(i));
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3};
    int target = 4;
    target_sum(arr, target, 0, "");
    return 0;
}


// Marble question -> starting from 0 marbles, you're given marbles of diff weights
// You need to find ways of marbles that add upto 10.

// Stairs question -> 6 stairs you can only go 1 / 2 / 3 steps at a time, tell number of distinct ways to travel.

// Same concept.

