// https://leetcode.com/problems/remove-palindromic-subsequences/
// 3 conditions : if palindrome : return 1 (so you can remove everything in on pass)
//                if string empty or null : return 0 (answer)
//                all other cases return 2 (since there are only 2 letters 'a' and 'b', will take 2 passes to remove)

// there is a difference between sub array / substring / subsequence.

// TC -> O(N), SC -> O(1)

public class Solution {
    public static int removePalindromeSub(String s) {
        // case 1 : 0
        if (s.isEmpty()) {
            return 0;
        }
        // case 2 : check for palindrome
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } else {
                // case 3 : not palindrome
                return 2;
            }
        }
        // otherwise it's a palindrome
        return 1; // case 2
    }

    public static void main(String[] args) {
        String s1 = "ababa";
        String s2 = "abb";
        System.out.println(removePalindromeSub(s1)); // 1
        System.out.println(removePalindromeSub(s2)); // 2
    }
}