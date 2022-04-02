#include <iostream>
#include <climits>
#include <unordered_set>
using namespace std;

// Time -> NlogN

// Problem Link -> https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// 0, 12, 4, 8
// Can you re-arrange in it such a way such that it's an AP
// -> 0, 4, 8, 12 = AP return true

// n = size of array

int checkAP(int arr[], int n)
{
	// global max and gloval min
	int maximum = INT_MIN;
	int minimum = INT_MAX;

	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(arr[i]); // insert all elements of array in the set (no duplicates)
		// find max and min of the array -> 0 and 12 in this case.
		maximum = max(maximum, arr[i]);
		minimum = min(minimum, arr[i]);
	}

	// find difference
	int diff = (maximum - minimum) / (n - 1);
	// (12 - 0) / 3 = 4 (common difference)
	// now check if the array is moving forward wrt common difference, if yes : true ? false

	// check if in AP or not
	while (maximum != minimum) // 12 != 0
	{
		if (s.find(minimum) != s.end())
		{
			// increment min with common diff till it reached max, if true then it's in AP else false
			// example -> (0, 0 + 4, 4 + 4, 8 + 4, now 12 reached)
			minimum += diff; // increment min with
		}
		else
		{
			return false;
		}
	}
	// Yes it is an AP.
	return true;
}

int main()
{
	int arr[] = {0, 12, 4, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << checkAP(arr, n); // return true

	return 0;
}
