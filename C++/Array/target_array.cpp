#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/create-target-array-in-the-given-order/

// Target array in given order.

// Initially target array is empty.
// From left ro right read nums[i] and index[i], insert at index[i] the value nums[i] in target array.
// Repeat the previous step until there are no elements left
// Return the target array.

// Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
// Output: [0,4,1,3,2]
// Explanation:
// nums       index     target
// 0            0        [0]
// 1            1        [0,1]
// 2            2        [0,1,2]
// 3            2        [0,1,3,2]
// 4            1        [0,4,1,3,2]

int createTargetArray(vector<int> &nums, vector<int> &index)
{
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++)
    {
        answer.insert(answer.begin() + index[i], nums[i]);
    }

    // for(int x : answer){
    //     cout << x << " ";

    // }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<int> index = {0, 1, 2, 2, 1};

    createTargetArray(nums, index);

    return 0;
}