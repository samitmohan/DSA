// Problem link -> https://leetcode.com/problems/increasing-order-search-tree/
/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
and every node has no left child and only one right child.
*/
class Solution
{
public:
    void inorder(TreeNode *root, TreeNode *&ans)
    {
        if (root == nullptr)
            return; // base
        // traverse to left most node.
        inorder(root->left, ans);

        // assign value of leftmost node to right of ans (flatten BST)
        ans->right = new TreeNode(root->val);

        // move ans to newly appended node.
        ans = ans->right;

        // Traverse to right of the leftmost node, if not null, add it to the right of the ans.
        inorder(root->right, ans);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        // base case
        if (root == nullptr)
            return root;
        TreeNode *ans = new TreeNode(-1); // initially
        // create temp to keep track of the root node of ans. (to return it)
        TreeNode *temp = ans;
        inorder(root, ans);
        return temp->right; // return tree.
    }
};