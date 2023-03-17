#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// Search in range;

// [18,12,-7,3,14,28]
// Search for 3 in the range of index [1,4]

int linear_search_with_range(vector<int> arr, int start, int end)
{
    int elem;
    cin >> elem;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == elem)
        {
            return true;
        }
    }

    // Not found
    return -1;
}

// Minimum Number / Max Number (return the min value in arr)

int min_number(vector<int> arr)
{
    int ans = arr[0]; // set curr min number -> first number
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < ans)
        { // if any of the numbers < first number
            // update the answer (new min)
            ans = arr[i];
        }
    }
    return ans;
}

// Even Digits Question -> https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Given an array nums of integers, return how many of them contain an even number of digits.
// Input: nums = [555,901,482,1771]
// Output: 1
// Explanation:
// Only 1771 contains an even number of digits.

// To count the number of digits
// Better way -> int(log(num)+1) -> To count number of digits

int digits(int num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

// To check if the number of digits are even

int even(int num)
{
    int number_of_digits = digits(num);
    // If even number of digits -> return 1
    return number_of_digits % 2 == 0;
}

// Final Function

int findNumbers(vector<int> &nums)
{
    int count = 0;
    for (auto i : nums)
    {
        if (even(i))
        {
            count++;
        }
    }
    return count;
}

// Richest Wealth Problem -> https://leetcode.com/problems/richest-customer-wealth/

// Input: accounts = [[1,2,3],[3,2,1]]
// Output: 6
// Explanation:
// 1st customer has wealth = 1 + 2 + 3 = 6
// 2nd customer has wealth = 3 + 2 + 1 = 6
// Both customers are considered the richest with a wealth of 6 each, so return 6.
// Return the wealth that the richest customer has

int maximumWealth(vector<vector<int>> &accounts)
{
    // person = rol
    // account = col
    int ans = 0;
    for (int person = 0; person < accounts.size(); person++)
    {
        // when starting a new col, take a new sum for that row
        int sum = 0;
        for (int account = 0; account < accounts[person].size(); account++)
        {
            sum += accounts[person][account];
        }
        // we have sum of accounts of person
        // check with overall ans
        if (sum > ans)
        {
            ans = sum;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {18, 12, -7, 3, 14, 28};
    vector<int> nums = {555, 901, 482, 1771};
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};

    return 0;
}
