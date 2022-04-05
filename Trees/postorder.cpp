// Problem Link -> https://leetcode.com/problems/binary-tree-postorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Postorder = left, right, root

class Solution
{
public:
    void postorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }
};


// Postorder using stack -> hard, left.
