#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// given integer array of even length arr, return true if it is possible to reorder arr
// arr[2 * i + 1] = 2 * arr[2 * i] for all 0 <= i <= len(arr) / 2

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

// 2,4,-2,-4
// i = 0, arr[1] = 2 * arr[0] -> true.
// i = 1, arr[3] = arr[2] -> true.

// problem link -> https://leetcode.com/problems/array-of-doubled-pairs/

// Wrong approach.

// first item : 4; is 4 in map ? yes : is 4 * 2 avail? no, is 4 / 2 avail -> yes.
// map -> remove 4 and 4 / 2  (2 and 4)
// second item : -2, is -2 in map? yes : is -2 * 2 avail? yes
// map -> remove -2 and -4

// return true
// else return false

// Why wrong? 4, 2, 1, 8
// MAP; 2->1, 4->1, 1->1, 8->1
// remove 2 and 4 ; first iter
// 1 * 2 not avail, 1 / 2 avail no -> false
// but answer is true.

bool canReorderDoubled(vector<int> &arr)
{
	// first step : sort.
	sort(arr.begin(), arr.end());
	// second step : map and add items to it.
	unordered_map<int, int> mp;
	for (int x : arr)
	{
		mp[x]++;
	}

	//
	for (int x : arr)
	{
		// instead of removing, if map[elem] == 0, continue
		if (mp[x] == 0)
		{
			continue;
		}
		// if elem < 0 and elem is not even
		// sorted, {-10, -5} -10 < 0 yes, but it's even then you can find elem / 2
		// but if {-5, -3, 1, 2} -5 < 0 yes, but odd bcs -5/2 -> doesn't exist. and -5 * 2 = -10 which should've already been in the array since it's sorted, but it's not present.

		if (x < 0 && x % 2 != 0)
		{
			return false;
		}

		// even num
		// if greater than 0 -> check for elem * 2
		int num = 0;
		if (x > 0)
		{
			num = x * 2;
		}
		// if smaller than 0 (neg) -> check for elem / 2
		// eg -> -10, -10 * 2 can never be possible since the arr is sorted
		else
		{
			num = x / 2;
		}
		if (mp[num] == 0)
		{
			return false;
		}
		// reduce frequency when number and double found.
		mp[x]--;
		mp[num]--;
	}

	// if all this doesn't satisfy -> we have found answer.
	return true;
}

int main()
{
	vector<int> arr = {4, -2, 2, -4};

	return 0;
}
