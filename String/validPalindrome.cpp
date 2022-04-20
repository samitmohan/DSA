// Problem link -> https://leetcode.com/problems/valid-palindrome/

/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

// Fast approach.

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string str = ""; // empty string
        for (int i=0;i<s.size();i++) 
        {
            if (isalpha(s[i]) || isdigit(s[i]))  
            {
                // if char is alphabet or digit add into the string
                str += tolower(s[i]);   
            }
        }
		// to be a palindrome string must be same after being reversed
        
        // compare str with reverse of str,if they both are equal it returns true otherwise false
        return str == string(str.rbegin(), str.rend());                
    }
};
// compare str with reverse of str,if they both are equal it returns true otherwise false

// Two Pointer approach

bool isPalindrome(string s) 
{
    int left = 0, right = s.length() - 1;
    while(left < right)
    {
        if(!isalnum(s[left])) left++;
        else if(!isalnum(s[right])) right--;
        else if(tolower(s[left])!=tolower(s[right])) return false;
        else 
        {
            left++; 
            right--;
        }
    }
    return true;
}