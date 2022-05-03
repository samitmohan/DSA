// Problem link -> https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> chk(nums.begin(), nums.end());              // copying into new vector
        sort(chk.begin(), chk.end());                          // sorting new vector
        int n = nums.size(), s = 0, e = n - 1;                // initalizing start and end
        while (s < n && nums[s] == chk[s]) {                 // counting size left sorted subarray
            s++;
        }
        while (e > s && nums[e] == chk[e]) {              // counting size right sorted subarray
            e--;
        }
        return e + 1 - s;                             // returning size of right subarray - left subarray
    }
};
