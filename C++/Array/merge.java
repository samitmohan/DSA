public class Main {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        // start filling from back of the array.
        int index1 = m - 1, index2 = n - 1, place = m + n - 1; // back of array.
        while (index1 >= 0 && index2 >= 0) {
            // whichever is the larger element (b/w nums1 and nums2 -> place at back of array)
            // and then decrement index of all three positions
            if (nums1[index1] >= nums2[index2]) {
                nums1[place] = nums1[index1];
                place--;
                index1--;
            } else {
                nums1[place] = nums2[index2];
                place--;
                index2--;
            }
        }
        // edge case -> size of m and n can be different which will give out of bound.
        // if nums2 has numbers which are smaller than the smallest number in nums1
        // nums1 = [4, 8, 9, 11] || nums2 = [2, 3, 5, 10, 12, 13]
        // first loop will end before the smaller elements of nums2 are copied into nums1.

        // copy those elements (the remaining ones)
        while (index2 >= 0) {
            nums1[place] = nums2[index2];
            place--;
            index2--;
        }
    }

    public static void main(String[] args) {
        int nums1[] = {1, 2, 3, 0, 0, 0};
        int m = 3, n = 3;
        int[] nums2 = {2, 5, 6};
        merge(nums1, m, nums2, n);
        for (int x : nums1) System.out.print(x);
    }
}
