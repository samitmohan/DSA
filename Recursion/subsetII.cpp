// based on prevs problem (just no duplicates)
// Problem Link -> https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    // recursive function, i -> ith element -> should be present/not
    // temp vector -> store elements to make a subset
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, bool prevs)
    {
        // base case if reached till end
        if (i == nums.size())
        {
            // store whatever there is in temp in answer
            ans.push_back(temp);
        }
        // recursive case
        // either consider it or not consider it
        else
        {
            // Case : not consider it -> ith element is not present (no push_back(nums[i]))
            // ('') and then solving for others ('', '2'), ('', '3'), ('', '2/3', '3/2') etc
            solve(i + 1, nums, temp, ans, false);
            // if current val = prevs val -> duplicate
            // also make sure i is in within boundries.
            // and if prevs value is ignored = this value should be ignored also
            if (i > 0 && nums[i] == nums[i - 1] && (!prevs))
            {
                return;
            }

            // continue
            // Case : consider it. ('1') [considering 1]

            temp.push_back(nums[i]);
            // recursive function for next element
            solve(i + 1, nums, temp, ans, true);
            // backtrack to undo our step and do this for next element (last element is reduced)
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        // to remove duplicates first sort the array and then compare with prevs number
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans, false);
        return ans;
    }
};
