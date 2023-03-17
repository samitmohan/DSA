#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// problem link -> https://leetcode.com/problems/two-sum/

int twosumLC(vector<int> &nums, int target)
{
    int i, j, size = nums.size();
    for (i = 0; i < size - 1; ++i)
    {
        for (j = i + 1; j < size; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

// Map -> 2, 11, 7, 15
// Target = 9. Is 9 - 2 present in map, no -> {2,0}
// 9 - 11 (-2) present? no -> {11,0}
// 9-7 (2) present? yes -> idx of 7 -> 2, is 2 present in map -> yes
// Corresponsding mapping of 2 -> 0 -> return {0, 2}


int two_sum_hashing(vector<int> &arr, int target)
{
    unordered_map<int,int> mp;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        // difference
        int diff = target - arr[i];
        // if diff present in map -> 
        if (mp.find(diff) != mp.end())
        {
            // push_back 0 (diff -> 2 in this case, corresponding val of 2 -> 0)
            ans.push_back(mp[diff]);
            // i -> idx of 7 -> 2 in this case
            ans.push_back(i);
            return ans; // {0, 2}

        }
        // if diff not present -> number, index in the mp
        mp[arr[i]] = i;
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
    // return ans;

}



int main()
{
    vector<int> nums = {2, 7, 11, 15};
    cout << twosumLC(nums, 9);
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    two_sum_hashing(arr, target);

    return 0;
}
