#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Input: arr = [1,2]
// Output: false

// thoughts -> keep a map (number, count)
// if any other number has same count -> true
// else -> false

// occurences are unique -> no duplicacy -> false
// use map set both

bool uniqueOccurrences(vector<int> &arr)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < arr.size(); i++)
	{
		// add number to map
		mp[arr[i]]++;
	}

	unordered_set<int> s;
	for (auto x : mp)
	{
		// x.first or x.second? -> second (Frequency)
		if (s.find(x.second) == s.end())
		{
			// not available in the set.
			// insert
			s.insert(x.second);
		}
		// if found
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> arr = {1, 2, 2, 1, 1, 3};

	return 0;
}
