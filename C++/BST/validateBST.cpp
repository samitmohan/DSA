#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/validate-binary-search-tree/

/*
Given root of BT, determine if it's a valid BST (left ST of node contains only nodes with keys less than node's key and vice versa for right ST)

Both left and right subtrees must also be BSTs.
*/

// Thoughts :  do inorder traversal if it's in sorted order -> BST.

class Solution
{
public:
    vector<int> arr;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        // left node right
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            true;
        // inorder traversal
        inorder(root);
        // check if it's sorted or not.
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] <= arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
