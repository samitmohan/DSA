#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/first-missing-positive/
// Amazon Question (Same missing number question -> Just add positive check and return index + 1 (and correct index = arr[i] - 1 since range is 1, N instead of 0, N))

int missingPositiveNumber(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {
        int correct = arr[i] - 1; // correct index = val - 1
        // add positive check too
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }

    // Search for first missing number

    for (int index = 0; index < arr.size(); index++)
    {
        if (arr[index] != index + 1)
        {
            return index + 1;
        }
    }

    return arr.size() + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {2, 3, 1, 5};
    cout << missingPositiveNumber(arr);
    return 0;
}