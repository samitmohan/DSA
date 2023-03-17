package com.samit;

import java.util.Stack;

public class Main {
    // brute force approach.
    public static boolean find132pattern(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j]) {
                        return true;
                    }
                }
            }
        }
        return false; // otherwise
    }

    // optimized approach.
    public static boolean find132patternOP(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int max = Integer.MIN_VALUE;
        for (int i = nums.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() < nums[i]) {
                max = stack.pop();
            }
            if (nums[i] > max) stack.push(nums[i]);
            if (nums[i] < max) return true;
        }
        return false;
    }


    public static void main(String[] args) {
        int[] arr = new int[]{3, 1, 4, 2};
		// System.out.println(find132pattern(arr));
        System.out.println(find132patternOP(arr));

    }
}

