#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

// Palindrome using stack

bool isPalindrome(string s)
{
    int len = s.size();
    stack<char> st;

    // finding mid
    int mid = len / 2;
    int i;
    for (i = 0; i < mid; i++)
    {
        // push elements in the stack
        st.push(s[i]);
    }

    // check if len of string is odd -> neglect middle char
    if (len % 2 != 0)
    {
        i++;
    }

    char elem;

    // go through the string
    while (s[i] != '\0')
    {
        // keep popping elements
        elem = st.top();
        st.pop();

        // if char different, then string isn't palindrome
        if (elem != s[i])
        {
            return false;
        }
        i++;
    }

    // otherwise
    return true;
}

int main()
{
    string s = "samit";
    if (isPalindrome(s))
    {
        cout << "Palindrome!";
    }
    else
    {
        cout << "Not Palindrome!";
    }
    return 0;
}

