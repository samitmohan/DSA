#include <iostream>
#include <vector>
using namespace std;

// Merge function

void merge(int arr[], int start, int mid, int end)
{
    // take 2 vectors
    vector<int> first, second;
    // for left half
    for (int i = start; i <= mid; i++)
    {
        first.push_back(arr[i]);
    }
    // for right half
    for (int i = mid + 1; i <= end; i++)
    {
        second.push_back(arr[i]);
    }

    // two pointer approach
    int p1 = 0, p2 = 0, p3 = start;
    while (p1 < first.size() && p2 < second.size())
    {
        if (first[p1] < second[p2])
        {
            // place p1 first and also increment pointer1 and pointer3 (of final array)
            arr[p3++] = first[p1++];
        }
        else 
        {
            // place p2 first and also increment pointer2 and pointer3 (of final array)
            arr[p3++] = second[p2++];
        }
    }

    // 2 Cases -> only one of these will be executed
    // What if second array is exhausted and remaining elements of first arr need to be copied in the final array as it is.
    while (p1 < first.size()) 
    {
        arr[p3++] = first[p1++];
    }
    // What if first array is exhausted and remaining elements of second arr need to be copied in the final array as it is.
    while (p2 < second.size()) 
    {
        arr[p3++] = second[p2++];
    }
}

void mergesort(int arr[], int start, int end)
{
    // if only 1 element is remaining -> already sorted -> base case
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        // merge two arrays
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {5,4,3,2,1};
    // arr, start index, end index
    mergesort(arr, 0, sizeof(arr)/sizeof(arr[0]));

    // print elements
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Time complexity -> N comparsions at each level, number of levels = logN
// O(N * logn)
// Space complexity -> O(N)
