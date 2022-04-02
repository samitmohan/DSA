#include <bits/stdc++.h>
using namespace std;

// Question -> Given array and target, find combinations (repetition allowed) such that array numbers add upto target
/*
example -> {1,2,3,4} | target = 4
    1111
    112
    121 *NOT ALLOWED* -> permutation
    13
    211 *NOT ALLOWED* -> permutation
    22
    31 *NOT ALLOWED* -> permutation
    4

    real answers = 1111, 112, 13, 22, 4

Logic -> Keep an extra index parameter, once you visit a number with particular index
         Loop works from that index -> arr.size() and not from 0 -> arr.size() [like in permutation with repetition]
         Hence we will get repetition but only combination. 
        ONLY CHANGE -> extra parameter idx, for loop instead of for each starting from idx and not from 0.

Difference between for each and for loop. 

// for (auto x : arr) and for (int i = 0; i < arr.size(); i++) difference

void method1(vector<int> &arr)
    for (auto i : arr)
        cout << i << " "; // this will print actual numbers, no need to do arr[i]

void method2(vector<int> &arr)
    for (int i = 0; i < arr.size(); i++)
        // cout << i << " ";  (this will print index and not numbers)
        cout << arr[i] << " "; // this will give actual numbers
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
            target_sum(arr, target, sum + arr[i], ans + to_string(arr[i]), i);
        }
    }
}

int main()
{
    // vector<int> arr = {1,2,3,4};
    vector<int> arr = {2,3,6,7};
    int target = 7;
    // initially idx = 0
    target_sum(arr, target, 0, "", 0);
    return 0;
}
