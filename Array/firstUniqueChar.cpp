#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// problem link : https://leetcode.com/problems/first-unique-character-in-a-string/

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1

// Input: s = "leetcode"
// Output: 0 (l)

// Input: s = "loveleetcode"
// Output: 2 (v)

// Input: s = "aabb"
// Output: -1 (none)

// USING ARRAY

int firstUniqChar(string s) {
    // initial thoughts -> store each letter with frequency in a map, if freq of letter = 1, return the index of that letter.
    // but it's a string, we know the max_len = 26.
    
    // using array of size 26 (len of string)
    
    vector<int> arr(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        // store count of letters
        arr[s[i] - 'a']++;
    }
    
    // if count of any letter = 1, return index
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    
    // answer not found
    return -1;
    
}

// USING HASHMAP

int firstUniqCharHash(string s)
{
	unordered_map<char, int> mp;
	for (int i = 0; i < s.length(); i++)
	{
	    // store freq (val)
	    mp[s[i]]++;
	}

	// if count of any letter = 1, return index
	for (int i = 0; i < s.length(); i++)
	{
	    if (mp[s[i]] == 1)
	    {
	        return i;
	    }
	}

	// answer not found
	return -1;

}


int main()
{
	cout << firstUniqChar("leetcode") << endl;
	cout << firstUniqCharHash("leetcode") << endl;
    
    return 0;
}
