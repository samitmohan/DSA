#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Modified Binary Search to find the min element and then apply regular binary search
// https://leetcode.com/problems/search-in-rotated-sorted-array/

int pivotWithTarget(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        //pivot found
        if (arr[mid] == target)
        {
            return mid;
        }
        // if left side is sorted then
        if (arr[low] <= arr[mid])
            // figure out if target/element lies on left half or not
            if (target >= arr[low] && target <= arr[mid])
                high = mid - 1;
            else
                // not
                low = mid + 1;

        // if right half is sorted then
        else
            // figure out if target/element lies on right half or not
            if (target >= arr[mid] && target <= arr[high])
            low = mid + 1;
        else
            // not
            high = mid - 1;
    }

    // if element not present, return -1
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // answer = 4 if target =0
    cout << pivotWithTarget(nums, 0) << endl;

    return 0;
}