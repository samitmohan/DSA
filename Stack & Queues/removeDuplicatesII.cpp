#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

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

string removeDuplicates(string& s, int k) 
{
	stack<pair<char, int> >stk; // It will store a character and its consecutive count
	stk.push({'#', 0}); // just to reduce extra condition checks.
	for (int i = 0; i < size(s); i++)
	{
		// if current character is equal to previous character, store it with incremented consecutive count
		stk.push({s[i], stk.top().first == s[i] ? stk.top().second + 1  : 1});
		// if consecutive count equals k, then delete that group of k characters.
		if (stk.top().second == k) 
		{
			while (stk.top().first == s[i]) 
				stk.pop();
			s.erase(i - k + 1, k);                
			i -= k;
		}                
	}
	return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << removeDuplicates("deedbbcccbdaa", 3);

    return 0;
}
