// Check if trees are identical
// Problem links -> https://leetcode.com/problems/same-tree/

// Do traversals of both tree, they should be equal, if they are -> True, else False.

// TC, SC -> O(N)

class Solution
{
public:
    // p and q are 2 trees
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // if either nulll -> return true / false depending on the other
        if (p == nullptr || q == nullptr)
        {
            return (p == q);
        }
        // preorder traversal -> root, left, right
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // if all returns true, they are equal
    }
};