#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/missing-number/
// Amazon Question

// Approach 1 : Math
int missingNumber(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int x = nums.size();
    return x * (x + 1) / 2 - sum;
}

// Approach 2 : Cyclic Sort (since hint is give -> Array containing n numbers in range (0,n))
// Tip : If range = 0, N
// every element will be at index = value

//If range = 1, N
// every element will be at index = value - 1; (like in regular cyclic sort)

// Input [3,0,1] for n = 2
// Output = 2

// Total Numbers = N+1

// [4 0 2 1], N = 4. -> [0,1,2,3,4] -> You can see that element == index

// 0 1 2 3
// 4 0 2 1

// index n does not exist
// i = 0, is 0 at correct index ? no
// 0 4 2 1

// Ignore when its at n,
// 0 1 2 4

// Ignore n
// loop over

// Answer = 0 1 2 4

// 0 1 2 3 (index)
// 0 1 2 4
// does 0 index contain 0 ? yes : does 3 index contain 3? No : Answer = 3.

int missingNumber_Cyclic(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {
        int correct = arr[i]; // correct index = same index
        if (arr[i] < arr.size() && arr[i] != arr[correct])
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
        if (arr[index] != index)
        {
            return index;
        }
    }

    return arr.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {2, 3, 1, 5};
    return 0;
}