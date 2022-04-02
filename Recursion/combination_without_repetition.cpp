#include <bits/stdc++.h>
using namespace std;

// Question -> Given array and target, find combinations (repetition not allowed) such that array numbers add upto target
/*
example -> {1,2,3,4} | target = 4
    1111 *NOT ALLOWED* -> repetition (1 four times)
    112 *NOT ALLOWED* -> repetition (1 two times)
    121 *NOT ALLOWED* -> permutation
    13
    211 *NOT ALLOWED* -> permutation
    22 *NOT ALLOWED* -> repetition
    31 *NOT ALLOWED* -> permutation
    4

    real answers = 13, 4

Logic -> Can't include current index, need to start from next, index + 1
*/

void target_sum(vector<int> &arr, int target, int sum, string ans, int idx) 
{
    // sum starts from 0 && answer string is empty. (keep appending both as we continue through the program)
    // base case -> sum = target, print the output.
    if (sum == target)
    {
        cout << ans << endl;
        return;
    }
    // Recursive case, go thorugh all numbers.
    // change this loop (for auto i : arr) to (for i = idx; i < arr.size(); i++)
    for (int i = idx; i < arr.size(); i++)
    {
        // if i + sum (0 for now) <= target, then we can add i in our answer list.
        // we do arr[i] instead of i here because we're using for loop not for each.
        if (sum + arr[i] <= target) {
            // add i to our ans list, and do this again for new sum = sum + i.
            // change -> i to i + 1 (for index)
            target_sum(arr, target, sum + arr[i], ans + to_string(arr[i]), i+1);
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3,4};
    int target = 4;
    // initially idx = 0
    target_sum(arr, target, 0, "", 0);
    return 0;
}
