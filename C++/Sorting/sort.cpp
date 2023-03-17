#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// what is stability in sorting? https://en.wikipedia.org/wiki/Sorting_algorithm#Stability

// Stability -> Merge, Quick(not stable), Bubble, Selection(not stable), Insertion

// Bubble Sort (O(N^2)) -> Comparting adjacent elements and swapping
// Best case => O(N) -> Array is already sorted

// how swap works
// int temp = a;
// a = temp;
// b = a;

// Change it to O(N) complexity -> If array is already sorted -> bool swap (if already sorted dont swap/check for other numbers -> stop there)

int bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // printing
    for (int x : arr)
    {
        cout << x << ",";
    }

    return 0;
}

// Insertion Sort (O(N^2)) -> If array almost sorted, use this sort.
// Best Case -> When array already sorted
//   j j j j
// 1 2 3 4 5
// comparisions = n-1 -> O(N)

// Why use this sort -> Adaptive : Steps get reduced (Number of swaps reduced as compared to BS)
// Stable -> Yes.
// Shifts not swaps & real life example -> students in assembly line (height wise)

/*
12, 11, 13, 5, 6
Let us loop for i = 1 (second element of the array) to 4 (last element of the array)
i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12 
11, 12, 13, 5, 6
i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13 
11, 12, 13, 5, 6
i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position. 
5, 11, 12, 13, 6
i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position. 
5, 6, 11, 12, 13 
*/

int insertionSort(vector<int> &arr)
{
    // could also do for i = 1, i < arr.size(), same thing -> Assume first number -> To be sorted already
    for (int i = 0; i < arr.size() - 1; i++)
    {
        // J starts after i = > i + 1
        for (int j = i + 1; j > 0; j--)
        { // j keeps decrementing -> checking for the previous number (all of them)
            // if arr[number] < arr[previous number] -> out of order -> swap/shift
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            // else -> if arr[current number] > arr[previous number] -> don't check for other numbers -> it'll already be sorted -> break
            else
            {
                break;
            }
        }
    }

    // printing
    for (int x : arr)
    {
        cout << x << ",";
    }

    return 0;
}

// Selection Sort (O(N^2)) -> Select minimum element and swaps
// Best case complexity -> O(N^2) -> looking for the min element anyway
// Stable -> No.

int selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        // set minimum number to the current number(first) for now
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            // if j (which is the next element) < current minimum
            if (arr[j] < arr[min])
            {
                // We have found new minimum, update it.
                min = j;
            }
        }

        // Check if number that we have is already the minimum number.
        // if minimum number = i already, no need to replace/update. if min = i, then ignore, else keep updating
        if (min != i)
        {
            // Swap minimum and the current number -> keep doing this until array is sorted
            swap(arr[min], arr[i]);
        }
    }
    // printing

    for (int x : arr)
    {
        cout << x << ",";
    }

    return 0;
}

// Cyclic Sort -> O(N) complexity (worst and best case)

// IMPORTANT NOTE = When given numbers from range 1 to N -> Use Cyclic Sort.
// Should be in continous order in range (1-N);
// Applying one check to the first number and swapping it.
// Before Sorting (Worst Case example)

// 0 1 2 3 4
// 3 5 2 1 4

// After Sorting
// 0 1 2 3 4
// 3 5 2 1 4

// You can observe -> index = value - 1. (in sorted)

// Swap numbers into their correct index (value-1).
// 0 1 2 3 4
// 3 5 2 1 4

// is 3 placed at correct index (3-1 = 2) No : Swap it with it's correct index

// 0 1 2 3 4
// 2 5 3 1 4

// is 2 placed at correct index (2-1 = 1) No : Swap it with it's correct index

// 0 1 2 3 4
// 5 2 3 1 4

// is 5 placed at correct index (5-1 = 4) No : Swap it with it's correct index

// 0 1 2 3 4
// 4 2 3 1 5

// is 4 placed at correct index (4-1 = 3) No : Swap it with it's correct index

// 0 1 2 3 4
// 1 2 3 4 5
// is 1 placed at correct index (1-1 = 0) Yes : Stop.

int cyclicSort(vector<int> &arr)
{
    // start looking from i
    // swap with correct index
    // only move the i pointer when i is at the correct index
    int i = 0;
    while (i < arr.size())
    {
        // check if it's at correct index or not
        int correct = arr[i] - 1; // index = value - 1
        // if arr[i] = correct => sorted, else, swap.
        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            // move ahead
            i++;
        }
    }
    for (int x : arr)
    {
        cout << x << endl;
    }
    return 0;
}

// Merge Sort -> O(NlogN)

// 10 5 2 0 7 6 4
/*          start to mid || mid+1 to end
1) Divide the array into parts (from the mid) -> 10,5,2 and 0,7,6,4
2) Recursively sort the left and right part (MergeSort(left) and MergeSort(right))
                                                      2,5,10 and 0,4,6,7
3) Merge them into a single sorted array using two pointers.
    2 5 10   0 4 6 7
    i        j

// Create temp array
0 2 4 5 6 7 10

These elements are copied back in the original array -> Sorted
*/

// merge -> merge the arrays

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

// Quick Sort -> O(N^2)
/*

arr[] = {10, 80, 30, 90, 40, 50, 70}
Indexes:  0   1   2   3   4   5   6 

low = 0, high =  6, pivot = arr[h] = 70
Initialize index of smaller element, i = -1

arr[] = {10, 80, 30, 90, 40, 50, 70}
arr[] = {10, 30, 80, 90, 40, 50, 70}
arr[] = {10, 30, 40, 90, 80, 50, 70} 
arr[] = {10, 30, 40, 50, 80, 90, 70} 
arr[] = {10, 30, 40, 50, 70, 90, 80} // final
*/

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

// Heap Sort -> O(nlogn), space = O(1)

// heapify -> converting node to heap and placing it in the right diretion
// shifts in logN
// TIME COMPLEXITY OF BUILDING A HEAP -> O(N) *Important*

/*
        30(0)                 
       /   \         
    70(1)   50(2)

Child (70(1)) is greater than the parent (30(0))

Swap Child (70(1)) with the parent (30(0))
        70(0)                 
       /   \         
    30(1)   50(2)
*/

void heapify(int arr[], int n, int i)
{
    int largest = i; // in case of max heap
    int left = 2 * i;
    int right = 2 * i + 1;
    // check if left index is in bound
    // compare with largest element
    if (left <= n && arr[largest] < arr[left]) // why <= ? 1 based indexing.
    {
        largest = left; // update largest
    }
    // similiarily for right
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right; // update right
    }

    // check if largest has been updated or not, if updated then it != i
    if (largest != i)
    {
        // updated, swap(arr[largest], arr[i]) (node reached it's correct position)
        swap(arr[largest], arr[i]);
        // check for remaining
        heapify(arr, n, largest);
    }
}

// Heap sort wrt max heap (NlogN) (build heap (convert array to heap (O(N)) + call heap sort (logN))
//  step 1 : swap arr[1] (root) with arr[last] (so that biggest number is at end of array now.)
//  step 2 : only care about n-1 elements now since last element (greatest) is now sorted (so size--)
//  step 3 : bring root node to correct position (since you swapped it before) -> how? heapify.
//  repeat these steps until size = 1 (sorted)

/*
Input data: 4, 10, 3, 5, 1
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.
*/

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step 1
        swap(arr[size], arr[1]);
        // step 2
        size--;
        // step 3
        heapify(arr, size, 1);
    }
}


// Radix Sort


// Notes ->
void radix_sort(vector<int> &arr, int low, int high)
{

}

// print elememts
void display(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {3, 5, 2, 1, 4};
    // Sorting Using STL
    // sort(arr.begin(), arr.end());
    // Reverse Sorting
    // sort(arr.rbegin(), arr.rend());
    // Sorting in array -> sort(arr, arr+n) n = length
    // Sorting in string
    // string s = "Monkey";
    // sort(s.begin(), s.end());

    // int arr[] = {5,4,3,2,1};
    // mergesort(arr, 0, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
