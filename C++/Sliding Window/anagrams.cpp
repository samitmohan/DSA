#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/find-all-anagrams-in-a-string/

/* Documentation
Put all letters of pattern_string in a map (a = 3, b = 1)
Traverse map, if a found, decrement in the map, similarity do for all, if a and b = 0, (element found), count--
Window size < k, j++
Window size == k, answer++
    Slide window
*/

// TC : O(n)
// SC : O(distinctChars(pattern_string))

int solve(string original_string, string pattern_string)
{
    // create a map of all char occurrence of 2nd string (char and count)
    unordered_map<char, int> map;
    for (auto x : pattern_string)
        // example : a = 3, b = 1
        map[x]++;

    // window size = length of 2nd string, anagrams will also be of this length.
    int k = pattern_string.length();
    // denotes distinc characters left in the window
    int count = map.size();

    int i = 0, j = 0;
    int ans = 0;

    while (j < original_string.length())
    {
        // if present in map
        if (map.find(original_string[j]) != map.end())
        {
            // decrease it's count.
            map[original_string[j]]--;
            // if count = 0, decrease 'count variable'
            if (map[original_string[j]] == 0)
                count--;
        }
        // less than window size, shift j
        if ((j - i + 1) < k)
            j++;
        // equal to window size (window hit) -> find answer -> slide window
        else if ((j - i + 1) == k)
        {
            // if count = 0, it means all the char needed for its anagram is here in it -> ans found -> ans++
            if (count == 0)
                ans++;
            // reverse operations (to remove last part [arr[i]] so that window can be shifted.)
            if (map.find(original_string[i]) != map.end())
            {
                // If the original_string[i] is present in map then increase its count.
                map[original_string[i]]++;
                // if it changes from 0->1 then increase the 'count' variable
                if (map[original_string[i]] == 1)
                    count++;
            }
            // slide window
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Given a string, and another string, find count of occurrence of all anagrams of 2nd one in 1st one.

    // Input : "forxxorfxdofr", "for"
    // Output : 3
    // Explanation : Anagrams of the word for - for, orf, ofr appear in the text and hence the count is 3.

    string original_string = "forxxorfxdofr";
    string pattern_string = "for";

    int ans = solve(original_string, pattern_string);
    cout << ans;

    return 0;
}
