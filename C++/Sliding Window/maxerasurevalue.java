import java.util.HashSet;
import java.util.Set;

class Solution {
    public static int maximumUniqueSubarray(int[] nums) {
        Set<Integer> set = new HashSet();
        int sum = 0, ans = 0, i = 0, j = 0;
        while (i < nums.length && j < nums.length) {
            // not repeated
            if (!set.contains(nums[j])) {
                sum += nums[j];
                ans = Math.max(sum, ans);
                set.add(nums[j++]);
            } else {
                // repeated
                sum = sum - nums[i];
                set.remove(nums[i++]);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{4, 2, 4, 5, 6};
        System.out.println(maximumUniqueSubarray(arr));
    }
}

