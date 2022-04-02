#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

/*
Check for balance / valid parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

// Answer = Switch case, stack<char>, keep inserting in stack ({[. If }]) found in stack then pop
// Pop only if ([{ is present, otherwise return false.
// Keep adding and removing elements in stack, in the end if stack.empty = valid else not valid
// Keep adding open brackets. When closing brackets are matched, the element is popped.

// Corresponding closed bracket function.

char openBracket(char ch)
{
    if (ch == '{')
    {
        return '}';
    }
    else if (ch == '[')
    {
        return ']';
    }
    else
    {
        // ch == (
        return ')';
    }
}

// Valid Parantheses function.
void isValid()
{
    string s = "[()]";
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        // if open bracket = insert in stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // push that bracket
            st.push(i);
        }
        // closed bracket case
        else
        {
            // if entered '}]' then ?? OR if any of the bracket is not equal to the one in the stack
            if (st.size() == 0 || s[i] != openBracket(s[st.top()]))
            {
                // if stack size = 0, only closed brackets then it will never be balanced OR if bracket not matching the stack
                cout << "Not Balanced!" << endl;
                return;
            }
            // else, they are equal (meaning : s[i] == openBracket(s[st.top])) remove that element
            else
            {
                st.pop();
            }
        }
    }

    // Answer Check!
    // if stack empty, balanced!
    if (st.size() == 0)
    {
        // Answer!
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced!" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    stack<int> st;
    cin.tie(0);
    isValid();

    return 0;
}

// Alternate Method

/*
bool isValid(string s)
{
    stack<char> st;
    // for all characters in the string s
    for (auto i : s)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (st.top() == '{' && i == '}')
            {
                st.pop();
            }
            else if (st.top() == '(' && i == ')')
            {
                st.pop();
            }
            else if (st.top() == '[' && i == ']')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    return st.empty();
}
*/