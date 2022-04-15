// Problem Link -> https://leetcode.com/problems/trim-a-binary-search-tree/
/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
*/

/*

---Algorithm---
If the root value in the range [L, R]
      we need return the root, but trim its left and right subtree;
else if the root value < L
      because of binary search tree property, the root and the left subtree are not in range;
      we need return trimmed right subtree.
else
      similarly we need return trimmed left subtree.
      
*/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        // base case
        if (root == nullptr) return nullptr;

        if (root->val < low) 
        {
            // ans must be in right half
            return trimBST(root->right, low, high);
        }
        if (root->val > high) 
        {
            // ans must be in left half
            return trimBST(root->left, low, high);
        }
        else
        {
            // answer found. (in between low and high)
            // recursive solution.
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};