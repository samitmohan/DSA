#include <bits/stdc++.h>
using namespace std;

// Palindrome using recursion

// racecar
// aceca
// cec
// e (base case, when length = 1 or 0)

// if len = 1, return true, base condition
// else compare first and last char, if same -> do the same for substring

int palindrome_check(string inp, int start, int end)
{
    // base case
    if (end - start == 1 || start == end)
    {
        return 1;
    }
    else
    {
        // if first and last equal
        if (inp[start] == inp[end])
        {
            // recursive case
            return palindrome_check(inp, start + 1, end - 1);
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    string inp;
    cin >> inp;
    int n = inp.length();
    cout << palindrome_check(inp, 0, n - 1);

    return 0;
}
