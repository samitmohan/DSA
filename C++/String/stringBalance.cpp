// https://leetcode.com/problems/split-a-string-in-balanced-strings/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int balancedString(string s)
{
    int counter = 0;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // L is in the string -> counter++
        if (s[i] == 'L')
        {
            counter++;
        }
        // R is in the string -> counter--
        else
        {
            counter--;
        }

        // L and R -> balanced -> counter = 0, result++

        if (counter == 0)
        {
            result++;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "RLRRLLRLRL";
    cout << balancedString(s);

    return 0;
}
