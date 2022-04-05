// Problem Link -> https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

// Path -> sequence of ndoes where each pair of adjacent nodes has an edge connecting
// 1 node can only appear in the sequence at once.

// return max path sum.

/*
       -10
       / \
      9   20
          / \
         15  7

Out of multiple paths, pick which has max sum.
15 + 20 + 7 = 42 (highest)
9 + (-10) + 20 = no.
15 + 20 + (-10) + 9 = no.
7 + 20 + -10 + 9 = no.
*/

// Bruteforce -> travel every possible combination of A and B, max(A,B) = ans
// O(N^2) -> No.

// Using max height of binary tree / width of binary tree.

// Backtracking logic + max ht
// max(nodeVal + (maxL + maxR)) = answer (maxi)

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN; // intially
        maxPathDown(root, maxi);
        return maxi;
    }
    // real work
    int maxPathDown(TreeNode *node, int &maxi)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = max(0, maxPathDown(node->left, maxi));   // start from 0 -> ignore all negative values (find left max)
        int right = max(0, maxPathDown(node->right, maxi)); // ignore all negative and find right max
        maxi = max(maxi, left + right + node->val);         // formula for that node.
        // generalise this and return answer
        return max(left, right) + node->val;
    }
};
