#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Given array of size, find smallest subarray that needs to be sorted such that entire array gets sorted
// If array already sorted -> return [-1.-1] else return [startIndex, endIndex] of smallest subarray
// 0 1 2 3 4 5 6 7 8 9 10
// a = [1,2,3,4,5,8,6,7,9,10,11]
// output = [5,7] (answer)

// Approach 1 -> Simply sort the array, compare it with previously unsorted array. (2 pointer)
// 1 2 3 4 5 8 6 7 9 10 11
// 1 2 3 4 5 6 7 8 9 10 11
// ->          |   |       <-
//             L   R

// Once you've found 2 extreme points, return the index of them (5,7)
// Complexity = O(NlogN)

int subarraySort_2pointer(vector<int> arr)
{
    vector<int> b(arr); // new arr *unsorted*
    sort(arr.begin(), arr.end());
    // do comparision
    int i = 0; // left pointer
    while (i < arr.size() and arr[i] == b[i])
    {
        // till both the arrays are same, keep incrementing the pointer from left
        i++;
    }
    int j = arr.size() - 1; // right pointer
    while (j >= 0 and arr[j] == b[j])
    {
        // keep decrementing the pointer from right
        j--;
    }
    // already sorted
    if (i == arr.size())
    { // i never stops anywhere, keeps incrementing because numbers are same in both arrays
        cout << "-1,-1";
    }

    cout << i << "," << j << endl;
    return 0;
}

// Better Approach -> O(N)
// 1) Find smallest and largest element out of order (a[i] > a[i+1] or a[i] < a[i-1])
//    Smallest = 8, Largest 8 -> Smallest = 6, Largest = 8.
// 2) What are the correct positions, place them in their correct positions.

bool outOforder(vector<int> arr, int i)
{
    int x = arr[i]; // curr elem
    if (i == 0)
    { // corner case (first element -> check only with next elem)
        return x > arr[1];
    }
    if (i == arr.size())
    { // corner case (last element -> check only with prevs elem)
        return x < arr[i - 1];
    }
    // out of order case
    return x > arr[i] or x < arr[i];
}

pair<int, int> subarraySort_linear(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        // current element is out of order or not?
        if (outOforder(arr, i))
        {
            // update smallest and largest
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    // Find the right index where smallest and largest lie (subarray for answer);
    if (smallest == INT_MAX)
    { // all are sorted
        cout << "-1,-1";
    }

    // two pointer method
    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    // return answer
    cout << left << "," << right;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    subarraySort_linear(arr);

    return 0;
}