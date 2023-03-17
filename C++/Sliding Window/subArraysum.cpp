#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/subarray-sum-equals-k/
/*
Documentation
1,5,3,2 ,1 ,5 ,6
cumulative sum->  1,6,9,11,12,17,23
as it is running sum, we need is difference of k from sum at any index
*/

int subarraySum(vector<int> &arr, int k)
{
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> m;
    // traverse through the array
    for (int i = 0; i < arr.size(); i++)
    {
        // increment sum in map.
        m[sum]++;
        // sum = sum + arr[i] (running sum)
        sum += arr[i];
        // difference of K from sum at any index.
        if (m.find(sum - k) != m.end())
            // update answer
            ans += m[sum - k];
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    cout << subarraySum(arr, 3);

    return 0;
}