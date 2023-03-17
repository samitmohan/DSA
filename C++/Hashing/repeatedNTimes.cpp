#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Link -> https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

// Given arr with properties ->
// 1) arr.length() == 2 * n
// arr contains n + 1 unique elements
// exactly one element of arr is repeated n times

// Return the element that is repeated n times.

// Input: nums = [1,2,3,3]

// arr length = 4
// contains 2 + 1 = 3 unique elements
// 3 is repeated 2(n) times

// Output: 3

int repeatedNTimes(vector<int> &arr)
{
    unordered_map<int, int> mp;

    // insert into map with freq
    for (int elem : arr)
    {
        mp[elem]++;
    }

    // for all elements in map
    for (auto elem : mp)
    {
        // if frequency of any num = arr.size() / 2
        // if freq of 3 (2) = 4 / 2 -> yes.
        if (elem.second == arr.size() / 2)
        {
            // return that element (key)
            return elem.first;
        }
    }

    // not found
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3};
    cout << repeatedNTimes(arr);
    return 0;
}
