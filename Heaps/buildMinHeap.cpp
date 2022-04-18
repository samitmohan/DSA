#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/codestudio/problems/build-min-heap

// just change the sign when comparing left and right and change largest -> smallest.

/*
 * 0 based indexing = parent = i + 1 / 2, left = 2i + 1, right = 2i + 2.
*/

void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left; // update smallest
    }
    // similiarily for right
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right; // update right
    }

    // check if smallest has been updated or not, if updated then it != i
    if (smallest != i)
    {
        // updated, swap(arr[largest], arr[i]) (node reached it's correct position)
        swap(arr[smallest], arr[i]);
        // check for remaining
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
    return arr;
}
