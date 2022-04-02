#include <iostream>
#include <vector>
using namespace std;

// Problem Link : https://leetcode.com/problems/count-the-number-of-consistent-strings/

// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

// Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
// Output: 7
// Explanation: All strings are consistent.

int countConsistentStrings(string allowed, vector<string> &words)
{
    vector<int> arr(26, 0);
    for (int i = 0; i < allowed.length(); i++)
    {
        arr[allowed[i] - 'a']++;
    }
    // travel
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
        bool flag = true;
        // pick every word
        for (int j = 0; j < words[i].length(); j++)
        {
            if (arr[words[i][j] - 'a'] == 0)
            {
                // don't take
                flag = false;
                break;
            }
        }
        if (flag)
            ans++;
    }
    return ans;
}

int main()
{

    return 0;
}
