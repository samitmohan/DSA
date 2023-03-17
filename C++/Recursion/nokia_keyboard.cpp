#include <bits/stdc++.h>
using namespace std;

// Problem Link ->  https://leetcode.com/problems/letter-combinations-of-a-phone-num/

// 2 3
// ans -> empty first
// idx -> 0 initially.
// loop (a b c),

// base case -> 2 reached.

// in string, length = string.length()

// without backtracking.
void nokiakeypad(vector<string> &arr, string ans, string number, int idx)
{
    // base case, if index = number.length() [for 23 -> 2 (len)]
    if (idx == number.length())
    {
        cout << ans << "\n";
        return;
    }
    // convert string into single character ('23' -> '2')
    char ch = number[idx]; // ch = '2'
    // convert this ch into an integer so we can loop on it.
    // int index = to_integer(ch);
    // Convert it into integer. char 2 - char 0 = integer form of the same. (x) (x+2) (x+2-x) = 2; where x is ASCII val of char 2

    int index = ch - '0';

    for (int i = 0; i < arr[index].size(); i++)
    {
        // arr[index] = 2 -> abc, arr[index][i] -> 0th char -> a, idx = 0 + 1
        // idx = 1, goes to def, ans + arr[index][i] = a + d, a + e, a + f
        // so on and so forth.
        nokiakeypad(arr, ans + arr[index][i], number, idx + 1);
    }
}

int main()
{
    vector<string> arr = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // string number; cin >> number;
    string number = "23";
    // initially ans = 0, index = 0
    nokiakeypad(arr, "", number, 0);

    return 0;
}

// Leetcode Solution (with backtracking -> original question)

class Solution
{
private:
    // actual answer
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
    {
        // base case -> index out of bound digit string
        if (index >= digit.length())
        {
            ans.push_back(output);
            return;
        }

        // find number that is pointing to index, seperate '2' from '23'
        // character converted to number (- '0') = 2 and not '2'
        int number = digit[index] - '0'; // ascii val
        // mapping ? if 2 -> mapped to abc
        string value = mapping[number]; // value = a,b,c
        // recursion call for all a b and c
        for (int i = 0; i < value.length(); i++)
        {
            // add 'a' to the output
            output.push_back(value[i]);
            // call for next
            solve(digit, output, index + 1, ans, mapping);
            // now to backtrack for b (after ad ae af we need output -> 0 for b char)
            // backtrack
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        // ans vector
        vector<string> ans;
        // if string empty -> ans = empty string
        if (digits.length() == 0)
            return ans;
        // output string
        string output;
        int index = 0;
        // mapping -> map numbers to characters
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};