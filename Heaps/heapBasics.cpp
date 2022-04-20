#include <bits/stdc++.h>
using namespace std;

// C++ -> by default priority queue is max heap.
// Java -> by default priority queue is min heap.
// O(logN) for the world!

// https://www.cs.usfca.edu/~galles/visualization/Heap.html

// max heap (1 based index)
// left = 2i, right = 2i+1
// for 0 based index -> parent = (i + 1) /2
//                   -> left = 2i + 1
//                   -> right = 2i + 2

class heap
{
public:
	int arr[100];
	int size;
	// constructor
	heap()
	{
		arr[0] = -1; // for safety
		size = 0;	 // initially
	}

	// insertion.
	void insert(int value)
	{
		size = size + 1;
		int i = size;	// i = index.
		arr[i] = value; // at the end.
		while (i > 1)
		{
			int parent = i / 2;
			if (arr[parent] < arr[i])
			{
				swap(arr[parent], arr[i]);
				i = parent; // new parent.
			}
			else
			{
				return;
			}
		}
	}

	// deletion.

	void delete_from_heap()
	{
		if (size == 0)
		{
			// already empty
			cout << "Nothing to delete" << endl;
			return;
		}
		// step 1 : put last element into first index
		arr[1] = arr[size]; // first (root node)
		// step 2 : remove last element
		size--;
		// step 3 : take root node to it's correct position
		int i = 1;
		while (i < size)
		{
			int left = 2 * i;
			int right = 2 * i + 1;
			// compare
			/*
			IGNORE
			if (left < size && arr[i] < arr[left])
			{
				swap(arr[i], arr[left]);
				i = left;
			}
			else if (right < size && arr[i] < arr[right])
			{
				swap(arr[i], arr[right]);
				i = right;
			// }
			*/
			int larger = left > right ? 2 * i : 2 * i + 1;
			if (arr[larger] > arr[i])
			{
				swap(arr[i], arr[larger]);
				i = larger;
			}
			else
			{
				return;
			}
		}
	}

	// printing.
	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

// heapify -> converting node to heap and placing it in the right diretion
// shifts in logN
// TIME COMPLEXITY OF BUILDING A HEAP -> O(N) *Important*
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
// 	step 1 : swap arr[1] (root) with arr[last] (so that biggest number is at end of array now.)
//  step 2 : only care about n-1 elements now since last element (greatest) is now sorted (so size--)
//  step 3 : bring root node to correct position (since you swapped it before) -> how? heapify.
//  repeat these steps until size = 1 (sorted)

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

int main()
{
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print(); // largest elem = 55 (max heap)
	h.delete_from_heap();
	h.print(); // 53 deleted

	int arr[6] = {-1, 54, 53, 55, 52, 50};
	int n = 5; // sizeof(arr) / sizeof(arr[0])

	// heap creation
	for (int i = n / 2; i > 0; i--)
	{
		heapify(arr, n, i);
	}

	cout << "Printing the array : " << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// heap sort
	heapSort(arr, n);
	cout << "Printing the sorted array : " << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}