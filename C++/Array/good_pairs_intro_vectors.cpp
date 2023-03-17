#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Beginner Array Problem
// Good pair def = nums[i] = num[j] and i < j

// https://leetcode.com/problems/number-of-good-pairs/submissions/

int count_good_pairs(vector<int> &nums)
{
    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                answer++;
            }
        }
    }
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    count_good_pairs(nums);

    return 0;
}