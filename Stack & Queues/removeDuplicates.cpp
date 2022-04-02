#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

/*
 * Example 1:
 *
 * Input: s = "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
 * The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 * Example 2: 
 *
 * Input: s = "azxxzy"
 * Output: "ay"
 * */

// Solution -> Maintain a stack, empty ans string, let's say input string = s. Iterate through the stack while not empty AND stack.top != current element (in the string)
// Push to stack
// else, if stack.top() = x (any alphabet in the string) = pop that element, (that is not the answer for example aa or bb or cc)
//
// Now print all elements remaining in the stack (answer)
// while (stack is not empty) ans = ans + stack.top()
// pop elements, stack.pop()
// All the elements in the string ans are put in reversed order because they've been put from top, so just use reverse(ans.begin(), ans.end())
//
// return ans

int removeDuplicates(string s)
{
    stack<char> st;
    string ans = ""; // empty

    for (auto x : s)
    {
        // if not empty and curr element != stack top element
        if (st.empty() || st.top() != x)
        {
            // push element to the stack (ab or bc or ad)
            st.push(x);
        }

        else if (st.top() == x)
        {
            // aa or bb or cc -> remove
            st.pop();
        }
    }

    // Remaining elements in stack = answer.

    while (!st.empty())
    {
        ans = ans + st.top();
        // keep popping top to iterate.
        st.pop();
    }
    // answer is in reverse order so to fix that
    reverse(ans.begin(), ans.end());
    cout << ans;
    // return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    removeDuplicates("azxxzy");

    return 0;
}
