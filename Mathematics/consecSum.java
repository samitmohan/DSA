// Problem link -> https://leetcode.com/problems/consecutive-numbers-sum/submissions/

class Solution {
    public int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int x = 1; x * (x + 1) / 2 <= n; x++) {
            int store = x * (x + 1) / 2;
            if ((n - store) % x == 0) {
                ans++;
            }
        }
        return ans;
    }
}
