#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Question

// Pivot index -> binary search question
// 0, 1, 2, 3, 4, 5 -> already sorted, pivot index -> 0

// 4,5,0,1,2,3 -> pivot index -> 2

// Because it's not fully sorted we can't apply binary search directly.

// Brute force solution (O(N))

// check if previous element is > curr element (pivot), if yes then pivot found if no then traverse further
// if not found -> return 0;

int solve(vector<int> &arr)
{
    // pivot -> false
    int pivot = -1;
    if (arr.size() > 0)
    {
        // no pivot till now
        pivot = 0;
        // traverse through the list
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > arr[i + 1])
            {                  // if prevs elem > curr element
                pivot = i + 1; // index = pivot
                break;
            }
        }
    }
    return pivot;
}

// Binary Search method (O(logN))
// Logic

// 1. array[0] = arr[arr.size()-1] -> first and last number same, not rotated, return 0
// 2. Low = 0, High = arr.size()-1
// 3. till low<=high
//      a) set mid = (high+low)/2
//      b) if mid+1 is pivot, then break
//      c) if arr[low] <= arr[mid], it means from start to mid -> all elements are sorted in increasing order.
// set low = mid + 1 (so that we can check for pivot in second half of arr)
//      d) else (low>mid), it's unsorted, look for pivot in first half
// set high = mid=1;

int search(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return -1;
    }
    // case when array is not rotated = in increasing order = first element lowest
    // in this case, pivot = first index

    if (arr[0] <= arr[arr.size() - 1])
    { // first element <= last element
        return 0;
    }

    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // check if mid + 1 is pivot
        if (arr[mid] > arr[mid + 1])
        {
            // pivot found!
            return mid + 1;
        }
        else if (arr[low] <= arr[mid])
        {
            // from start to mid -> all elements are sorted order
            // so pivot -> is in second half
            low = mid + 1;
        }
        else
        {
            // from mid to end -> all elements are sorted
            // so pivot -> first half
            high = mid - 1;
        }
    }

    return 0;
}

// if number of rotations given in the question -> index of min element.
// Number of rotations = (pivot + 1)th index.
// find min element -> number of rotations -> same question -> compare with mid+1 and mid-1 using binary search

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << search(arr) << endl;
    // cout << solve(arr) << endl;

    return 0;
}