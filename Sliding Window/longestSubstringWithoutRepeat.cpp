#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/* 

pwwkew = 3 = wke

Documentation. 
Window Size -> high-low + 1 (j-i+1)

Map of char, integer -> check map.size and window.size. 
if map.size = window.size -> answer found.
if map.size < window.size -> shift the window

*/

int lengthOfLongestSubstring(string string1)
{
    // map to keep count of characters and it's frequencies.
    unordered_map<char, int> mp;

    // 2 pointers.
    // j - i + 1 = window size (high - low + 1)
    int i = 0;
    int j = 0;
    int ans = 0;

    // check for unique char
    int unique = 0;

    while (j < string1.size())
    {
        // add jth element to the map.
        mp[string1[j]]++;

        // if freq of all char = 1, unique element found.
        if (mp[string1[j]] == 1)
        {
            unique++;
        }

        // if mp.size() [unique element size] = window size
        if (unique == j - i + 1)
        {
            // answer found (max(mp.size(), window size))
            ans = max(ans, j - i + 1);
        }

        // if mp.size() < window size -> (wwe -> window size (3), but unique (mp.size()) (2))
        else if (unique < j - i + 1)
        {
            // remove first element
            mp[string1[i]]--;

            // if frequency = 0 (useless), decrement unique element.
            if (mp[string1[i]] == 0)
            {
                unique--;
            }

            // shift i to next
            i++;
        }

        // shift j to next (slide window)
        j++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);

    return 0;
}
