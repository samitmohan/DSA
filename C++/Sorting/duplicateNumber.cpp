#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Microsoft Question
// https://leetcode.com/problems/find-the-duplicate-number/
// Given array of integers containing n+1 integers, where each integer is in range[1,n]

// Cyclic Sort -> Range {1,N} (Biggest Hint)

// Input = [1,3,4,2,2]
// Output = 2

// 0 1 2 3 4
// 1 3 4 2 2

// 0 1 2 3 4
// 1 2 2 3 4

// is 1 at correct index (value - 1) ? : Yes
// is 2 at correct index (value - 1) ? : Yes : is 2 at any other index? Yes -> Duplicate
// since index = value = duplicate Number.

int findDuplicate(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {

        if (arr[i] != i + 1)
        {
            // Do cyclic sort
            int correct = arr[i] - 1; // correct index = same index
            if (arr[i] != arr[correct])
            {
                swap(arr[i], arr[correct]);
            }
            else
            {
                return arr[i];
            }
        }
        else
        {
            i++;
        }
    }

    // if no duplicates.
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr);

    return 0;
}