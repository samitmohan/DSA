#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// remove duplicates from sorted array.
// return count of unique elements
// don't use extra space.

// easiest method -> use a set

int removeDuplicates(vector<int> &arr)
{
	set<int> s;
	for (int i = 0; i < arr.size(); i++)
	{
		// place all elements in the set
		s.insert(arr[i]);
	}

	int count = 0;
	for (auto x : s)
	{
		count += 1;
	}

	// should return 5
	return count;
}

// with O(1) memory -> inplace.

// Video solution -> https://www.youtube.com/watch?v=DEJAZBq0FDA

// O(N) Time, O(1) In-place Space
// Dry run for doubts
int removeDuplicates2(vector<int> &arr)
{
	// 2 pointer approach, keep both of them at 1st index and not 0 bcs the first number is obviously unique.
	int left = 1;
	// increment through right index
	for (int right = 1; right <= arr.size() - 1; right++)
	{
		// is it a new value or duplicate, compare it to prevs
		if (arr[right] != arr[right - 1])
		{
			// unique value, place it in the left pointer
			arr[left] = arr[right];
			// increment left pointer
			left++;
		}
		// always increment the right pointer -> already doing that in the for loop.
	}
	// numbers left in the array -> left index. (prob somewhere in the middle of array)
	// should return 5
	return left;
}



int main()
{
	vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
	cout << removeDuplicates(arr);
}
