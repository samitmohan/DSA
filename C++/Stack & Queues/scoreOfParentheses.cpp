#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1. "()()" has score 2. "(())" has score 2 (1*2) s = "(()(()))" has score 6
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
*/

// https://leetcode.com/problems/score-of-parentheses/

/* Logic (using stack)
If you get (, push 0 to stack, if you get ) -> you have 2 cases.
    Either top element = 0, which means (), so you pop the element from stack and add 1 to answer.
    Either top element = 1, which means )) so you calculate
        Calculate = while (top != 0), st.pop(), ans+=1, when top = 0 reached finally ))(, ans = ans * 2. (according to the rules)
    
    return ans;
*/

int scoreOfParentheses(string s)
{
    stack<int> st;
    // for all parantheses in s
    for (int i = 0; i < s.length(); i++)
    {
        // open bracket = push 0.
        if (s[i] == '(')
        {
            st.push(0);
        }
        // closed bracket
        else
        {
            int count = 0;
            // if ) and st.top() != 0, example = )). 
            while (st.top() != 0)
            {
                // increment count and keep popping till you reach 0.
                count += st.top();
                st.pop();
            }
            // ) and st.top = 0, example = (), just pop.
            st.pop();
            // if count = 0, example = () (above), push 1 (count)
            if (count == 0)
            {
                count = 1;
            }
            // else (A) has a score = A * 2 case. example = (()) 
            else
            {
                count = count * 2;
            }
            // push count to the stack (answer till now)
            st.push(count);
        }
    }

    // final answer = sum of stack elements
    int ans = 0;
    while (st.size() != 0)
    {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << scoreOfParentheses("(()(()))");

    return 0;
}
