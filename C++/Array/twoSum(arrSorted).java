// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// binary search (two pointers)

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0, end = numbers.length - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                break;
            }
            if (numbers[start] + numbers[end] < target) {
                start++;
            } else {
                end--;
            }
        }
        // return answer in new arr
        return new int[]{start + 1, end + 1};
    }
}
