#include <iostream>
#include <vector>
using namespace std;

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase
// typically using all the original letters exactly once.

// Input: s = "anagram", t = "nagaram"
// Output: true

// Input: s = "rat", t = "car"
// Output: false

// Using Array -> O(N) -> String -> 26 limit
// Store char of string s as an integer in arr1
// Store char of string t as an integer in arr2

// How to convert to integer -> string - 'a'
// Compare both arrays

bool isAnagram(string s, string t)
{
	vector<int> arr1(26, 0); // all filled with 0s
	vector<int> arr2(26, 0);
	// fill arr1
	for (int i = 0; i < s.length(); i++)
	{
		// keep a count of the letters (a -> 1, n -> 1, a -> 2, g -> 1, r -> 1, a -> 3, m -> 1) as integers
		arr1[s[i] - 'a']++;
	}

	// fill arr2
	for (int i = 0; i < t.length(); i++)
	{
		// keep a count of the letters (n -> 1, a -> 1, g -> 1, a -> 2, r -> 1, a -> 3, m -> 1) as integers
		arr2[t[i] - 'a']++;
	}

	// compare arr1 and arr2, if they have same integers -> valid anagram else not.
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << isAnagram("anagram", "nagaram"); // true

	return 0;
}
