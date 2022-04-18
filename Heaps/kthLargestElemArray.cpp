// Problem link -> https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

*/

// You can also sort

int findKthLargest(vector<int> &nums, int k)
{
    // create max heap and fill with array numbers
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++)
    {
        // keep removing element until kth element is reached
        // return kth max element.
        pq.pop();
    }
    return pq.top();
}
int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest(nums, 2) << endl; // 5
}