#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// Binary Search is for sorted arrays. -> biggest hint if in question -> Sorted array or Continuous Sequence (SquareRoot)

// Ceiling/Floor of a Number

// Given an array -> [2,3,4,9,14,16,18], Target Number = 15; (Sorted Array -> Apply b.s)

// Ceiling -> Smallest number in array that is greater or equal to target number (16);
// Condition -> while(low<=high) -> do binary search -> if no answer found -> return low (the nearest greatest number)

// Floor -> Greatest number smaller or equal to target number -> 15 (answer -> 14)
// Condition -> do bs -> if no answer found -> return high (the nearest smallest number)

int ceiling(vector<int> &arr)
{
    int target = 15;
    // If target > greatest number -> No ceiling
    if (target > arr[arr.size() - 1])
    {
        return -1;
    }

    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return arr[mid];
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // return the ceiling
    return arr[low];
}

// For floor -> just return arr[high] and if target is the smallest number -> No ceiling

// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Find smallest letter greater than target.
// It's the same as ceiling but strictly greater (not equal) and just alphabets

// Input -> Letters = ['c', 'f', 'j'], target = 'a' || Output -> 'c'
// Letters wrap around -> if no char is greater than the target -> Just return the 0th index (c,f,j), target = j, output -> c
// This means -> Start = Length of the array.
// Return the 0th index -> start % length of the array (0) -> first position (0) or if start == length of array { return 0 }

int nextGreatestLetter(vector<char> &letters, char target)
{
    int low = 0, high = letters.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (letters[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    //  Return the answer and if not then return the 0th index
    return letters[low % letters.size()];
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Find first and last position of element in sorted array (Sorted Array -> Binary Search)

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

/*
NOTE -> In C++ STL
lower bound will return pointer to first element not less than target
upper bound will return pointer to just greater than target
*/

// Returns the index value of target (Binary Searching)

int search(vector<int> &nums, int target, bool findStartIndex)
{
    // Default answer = -1
    int ans = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            // Potential Answer found (Occurrence found, can be the second/third occurrence too.)
            ans = mid; // update ans
            // May be possible that there is another answer on the left side (first occurrence)
            if (findStartIndex)
            { // if we need to find first occurrence
                // check on the left side too
                high = mid - 1;
            }
            else
            {
                // check on the right side (for the end occurrence)
                low = mid + 1;
            }
        }
    }
    return ans;
}

int searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};
    // Check for first occurrence if target first
    int low = search(nums, target, true);
    int high = search(nums, target, false);

    ans[0] = low;
    ans[1] = high;

    for (auto x : ans)
    {
        return x;
    }

    return 0;
}

// Binary Search in sorted array in infinite list.
// Size of array?

// Low = 0 (First Element) | High = 1 (Second Element)
// Compare key to high, if key > high then low = high (update) and high = 2*high
// if high > key, search between low and high till element is found (Simple Binary Search)

// Simple Binary Search Algo
int binarySearch_infinite(vector<int> &arr, int target, int low, int high)
{
    // int low = 0, high = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // if not found
    return -1;
}

// Position of low and high value
int position(vector<int> &arr, int target)
{
    int low = 0, high = 1;
    int temp = arr[0];
    // Finding high value
    while (temp < target)
    {
        low = high;       // high updated as low (new low found)
        high = 2 * high;  // double high val
        temp = arr[high]; // update new value
    }

    // DO simple binary search (after low and high point is found)
    return binarySearch_infinite(arr, target, low, high);
}

// Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Sorted Array -> binary search

int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            // decreasing part of array, this may be the ans, but look at left;
            // this is why high != mid-1;
            high = mid;
        }
        else
        {
            // you are in asc aprt of array
            // because we know that mid + 1 element > mid element
            low = mid + 1;
        }
    }
    // in the end, low = high, and pointing to the largest number, bcs of the 2 checks above
    // low and high are always trying to find the max element in the above 2 checks
    // when they're both pointing to the largest number -> that is the max number.
    return low; // or return high, it's the same thing (same number)
}

// Find in mountain array
// https://leetcode.com/problems/find-in-mountain-array/
// [1,2,3,4,5,6,3,1] target = 3, answer = 2. (3 exists in the array, at index 2 and index 5. Return the min index)
//

int search(vector<int> &arr, int target)
{
    int peak = peakIndexInMountainArray(arr);
    int firstTry = order_agnostic_binary_search(arr, target, 0, peak); // asc order first half
    if (firstTry != -1)
    {
        return firstTry;
    }
    // else try to search in second half.
    return order_agnostic_binary_search(arr, target, peak + 1, arr.size() - 1); // from mid+1 to end
}

// Previous Question
int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// binary search
int order_agnostic_binary_search(vector<int> &arr, int target, int low, int high)
{
    // find whether array is sorted in asc / dsc
    bool isAsc = arr[low] < arr[high]; // last element > first element = ascending order
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (isAsc)
        {
            if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        { // descending order -> searching on the other side
            if (arr[mid] > target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    // Not found
    return -1;
}

// --- Question
// Search in a rotated sorted array; (amazon google question)
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Sorted array given, ay any point K, it is rotated. Find that point.
// [4,5,6,7,0,1,2], target = 0, answer = 4. (return index of target)

// bruteforce -> if any prevs number greater than next in sorted array -> that is the answer
// for(i=0;i<len;i++){
//     if arr[i] > arr[i+1] -> if any prevs number greater than next number in sorted array -> answer.
//          pivot = i+1th index
//          break
// }

// NOTE
// pivot = from where your next numbers are ascending.
//    pivot = 7
// Rotated array [3,4,5,6,7,0,1,2]
// left and right side of pivot are sorted.

// Find Pivot
// Search in first half (0 -> Pivot)
// Search in second half (Pivot+1 -> End)

int rotated_array_search(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[low] <= arr[mid])
        { // asc order sorted list [0,1,2,3,4,5,6,7,8]
            if (arr[low] <= target && target < arr[mid])
            { // target = in the left part of the array
                high = mid - 1;
            }
            else
            { // in the right side of the array
                low = mid + 1;
            }
        }
        else
        { // dsc order sorted list [23,21,2,1,0]
            if (arr[mid] < target && target <= arr[high])
            { // target = right side of the array
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    // if not found
    return -1;
}

// Question2 -> Find Rotation count in rotated sorted array. (Find how many times array is rotated)

//arr = [4,5,6,7,0,1,2]
//array is rotated 'pivot' times.
//og_arr = [0,1,2,3,4,5,6,7]
//rotate 1 time -> [7,0,1,2,3,4,5,6], 2 times -> [6,7,0,1,2,3,4,5]
//similarly -> rotate 4 times from og_arr -> arr (also 4 = pivot + 1)

//Number of times rotated = pivot + 1

// Question 2
//

int countRotations(vector<int> &arr)
{
    int pivot = findPivot(arr);
    return pivot + 1;
}

int rotationCount(vector<int> &arr)
{
    cout << countRotations(arr);
}

// Rest is same as previous question

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};
    vector<char> letters = {'c', 'f', 'j'};
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> peak = {18, 29, 38, 59, 98, 100, 99, 98, 90};
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    
    return 0;
}
