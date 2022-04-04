// Problem Link -> https://leetcode.com/problems/binary-tree-preorder-traversal/
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
class Solution
{
public:
    void preorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }
};
