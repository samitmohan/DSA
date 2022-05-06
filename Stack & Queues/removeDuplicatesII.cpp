#include <bits/stdc++.h>
using namespace std;

// Array question (can be done using stacks also)

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

/*
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 *
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 * */

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/1161129/Multiple-Approach-Explained-w-Easy-Commented-Solutions-or-Beats-100

// vector.back() = gives the last element (1, 2, 3) = 3

void removeDuplicates(string s, int k) 
{
	vector<pair<int, char>> stack = {{0, '#'}}; // avoid empty stack
	for (char c : s) 
	{
		if (stack.back().second != c) 
		{
			// if next character c is not the same as last one, push (char, 1) into the stack
			stack.push_back({1, c});
		}
		else if (++stack.back().first == k)
		{
			// .first = count of occurence of a character
			stack.pop_back(); // increment stack.back and count is same as 
		}
	}

	string res;
	for (auto &x : stack) 
	{
		res.append(x.first, x.second);
	}

	// printing res
	for (auto i : res) 
	{
		cout << i << "\n";
	}
}

int main() 
{
	removeDuplicates("abcd", 2); // abcd
	cout << endl;
	removeDuplicates("deeedbbcccbdaa", 3); // aa
	return 0;
}

