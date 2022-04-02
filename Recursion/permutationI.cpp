#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/permutations/

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


void solve(vector<vector<int>> &res, vector<int> &nums, int start, int end)
{
    // base case, if start == nums.size() or start == end.
    if (start == end)
    {
        // push back whatever is in nums to our result vector
        res.push_back(nums);
        return;
    }
    // recursive case.
    // go from left to right of the number
    for (int i = start; i <= end; i++)
    {
        // swap left with the ith number for a new permutation
        swap(nums[start], nums[i]);
        // do the same for all (the next number) (recursively)
        solve(res, nums, start + 1, end);
        // undo the change when you're going back -> backtrack;
        swap(nums[start], nums[i]);
    }
}

void display(vector<vector<int>> &res)
{
    // row traversal
    for (int i = 0; i < res.size(); i++)
    {
        // res[0].size = same row, column traversal
        for (int j = 0; j < res[0].size(); j++) 
        {
            cout << res[i][j] << ", ";
        }
        cout << "\n";
    }
}

void permute(vector<int> &nums)
{
    // res array
    vector<vector<int>> res;
    // solve for array, start point, end point
    solve(res, nums, 0, nums.size() - 1);
    // return ans
    // return res;
    display(res);
}

int main()
{
    vector<int> nums = {1,1,2};
    permute(nums);
    return 0;
}
