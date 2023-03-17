// Problem link -> https://leetcode.com/problems/maximum-product-of-word-lengths/
// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".

public class maxProduct {
    public static int answer(String[] words) {
        int n = words.length;
        int[] bitmask = new int[n];
        int max = 0;

        for (int i = 0; i < n; i++) {
            // calculate bitmask for current word.
            for (int j = 0; j < words[i].length(); j++) {
                // index = a -> 0, b -> 1, c -> 2 (how to get this a - 'a', b - 'a' so on)
                int index = words[i].charAt(j) - 'a';
                // left shift 1 by index and OR with current bitmask (to get OR of all value (abc and not just a)
                bitmask[i] = bitmask[i] | (1 << index);
            }

            // compare bitmask of current string with previous strings bitmask
            for (int j = 0; j < i; j++) {
                /* If there is a 1 at the same index of current string {i} and {j},
                then bitmask of i and j string will result in a number greater than 0,
                else it will result in 0 */
                // then no common characters, we have found our answer = max.
                if ((bitmask[i] & bitmask[j]) == 0) {
                    max = Math.max(max, words[i].length() * words[j].length());
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        String[] words = new String[]{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        System.out.println(answer(words));
    }
}


// https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/2085553/C%2B%2B-solution-using-Hashmapvector
