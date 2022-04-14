#include <iostream>
using namespace std;

// Problem link -> https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/

/*

---Problem Statement---
Given root of BT, containing digits 0 - 9
Each root-to-leaf path in tree represents a number
1->2->3 = 123.
Return total sum of all root-to-leaf numbers

     1
    / \
   2   3

Answer = 25
root-to-leaf path 1->2, represents 12.
root-to-leaf path 1->3, represents 13.
Sum = 12 + 13 = 25.

---Answer---

1) Current sum = current sum * 10 + root->val (1->2 = 12 (1 * 10 + 2))
2) Do the same for left and right (leftSum and rightSum)
3) ans = leftSum + rightSum, return ans.

*/

class Solution
{
private:
    int sum(TreeNode *root, int currSum) // currSum = 0 initially
    {
        // base case
        if (root == nullptr)
            return 0;
        currSum = currSum * 10 + root->val;
        // if leaf node reached, return currSum
        if (root->left == nullptr && root->right == nullptr)
        {
            return currSum;
        }
        // else keep moving left and keep moving right (to find leftSum and rightSum)
        int leftSum = sum(root->left, currSum);
        int rightSum = sum(root->right, currSum);
        int ans = leftSum + rightSum;
        return ans;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        return sum(root, 0);
    }
};