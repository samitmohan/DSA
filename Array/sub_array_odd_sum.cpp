#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/submissions/

// [1,4,2,5,3]
// [1,2]
// [10,11,12]

// Answers = 58, 3, 66

using namespace std;
typedef long long ll;

// Brute Force Solution

int sub_array_odd_sum(vector<int> &arr)
{

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size() + 1; j += 2)
        {
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
            }
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << sub_array_odd_sum(arr);
    return 0;
}
