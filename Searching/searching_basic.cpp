#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// What is linear search -> O(n) complexity, basic searching.

int linear_search(vector<int> &arr)
{
    int elem;
    cin >> elem;
    for (auto i : arr)
    {
        if (i == elem)
        {
            return true;
        }
    }
    // If not found
    return -1;
}

int binarySearch(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int element;
    cin >> element;
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        // better way -> mid = low+(high-low)/2 (Because integer has a fixed range so this is better)
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            cout << "Found!";
        }
        if (arr[mid] < element)
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

// Order Agnostic Binary Search

// You don't know if array is sorted in asc or desc order.

// Check first and last number, if first > last : dsc, if last number > first number : increasing order sorted
// Accordingly, apply binary search

int order_agnostic_binary_search(vector<int> &arr)
{
    // find whether array is sorted in asc / dsc
    int target;
    cin >> target;
    int low = 0, high = arr.size() - 1;
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

// Binary Search using STL (binary_search(arr.begin(), arr.end(), 15)
vector<int> arr = {10, 15, 20, 25, 30, 35};

// using binary_search to check if 15 exists
if (binary_search(arr.begin(), arr.end(), 15))
    cout << "15 exists in vector";
else
    cout << "15 does not exist";
cout << endl;

// Searching through an infinite list using binary search.

// [1,2,3,5,4,223,1, .........]
// we dont know the high value so we break the problem into sub problems. (1-2 then we increment it by 2^2 (exponentially), 2-4, 4-8,8-16)
// once we find the range, we make it our new low and new high and perform binary search.
// time complexity (logN) multiplying by 2
void infinite(int array[], int x)
{
    int low = 0;
    int high = 1;
    while (array[high] < x)
    {
        low = high;
        high = 2 * high;
    }
    return binarySearch(array, x, low, high);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Asc
    // vector<int> arr = {0, 20, 40, 50, 60, 70, 90};
    // Dsc
    vector<int> arr = {90, 80, 40, 30, 22, 11, 0};


    return 0;
}
