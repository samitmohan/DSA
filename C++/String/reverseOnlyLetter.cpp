#include <iostream>
#include <vector>

using namespace std;
#define ll long long

//https://leetcode.com/problems/reverse-only-letters/

//Given a string s, reverse the string according to the following rules:

//All the characters that are not English letters remain in the same position.
//All the English letters (lowercase or uppercase) should be reversed.

string reverseOnlyLetters(string s)
{
    if (s.size() == 1)
    {
        return s; // empty string
    }

    // 2 pointer approach
    int low = 0, high = s.size() - 1;

    while (low < high)
    {
        while (!isalpha(s[low]) && low < s.size() - 1)
        {
            // skip the non english letter.
            low++;
        }
        while (!isalpha(s[high]) && high > 0)
        {
            // skip the non english letter.
            high--;
        }

        // simply swap all the other char
        if (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }

    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << reverseOnlyLetters(s);

    return 0;
}
