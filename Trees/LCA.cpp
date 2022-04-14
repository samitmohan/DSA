// Problem link -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case
        if (root == NULL || root == p || root == q) // root is empty, root = p or q -> answer = root
        {
            return root;
        }

        // recursive call for left and right
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL) // if left is null, answer = right
        {
            return right;
        }
        else if (right == NULL) // if right is null, answer = left
        {
            return left;
        }
        else
        {
            // both left and right are not null, we found our result
            return root;
        }
    }
};
