// Problem link -> https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // O(logN)
        if (root == nullptr)
            return nullptr; // base case
        if (root->val == val)
            return root; // ans found

        // recursive
        if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return searchBST(root->left, val);
        }
    }
};
