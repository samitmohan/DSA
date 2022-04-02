#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// See notes for process and code
// https://cppsecrets.com/users/1039649505048495348575464115971151161149746979946105110/C00-Quick-Sort.php

int partition(vector<int> &arr, int low, int high)
{
    // pick a pivot point (RIGHTMOST)
    int pivot = arr[high];
    // re arrange the array such that elements < pivot lie to the left of pivot and elements > pivot lie to the right of pivot
    // how to do thiS ? pointer is fixed at pivot element. pivot is compared with elements from beginning.
    int i = (low - 1);
    // if the element > pivot, second pointer is set for that element (j)
    // traverse each element of the array, compare them with the pivot
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            // if element smaller than pivot is found, swap it with greater element pointed by i
            i++;
            // swap element at i with element at j
            swap(arr[i], arr[j]);
        }
    }
    // i + 1 = partition point
    // swap pivot with greater element at i
    swap(arr[i + 1], arr[high]);
    // return partition point
    return (i + 1);
}

void quick_sort(vector<int> &arr, int low, int high)
{
    // keep doing this for all sub arrays (start -> mid and mid + 1 -> end)
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    quick_sort(arr, 0, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
