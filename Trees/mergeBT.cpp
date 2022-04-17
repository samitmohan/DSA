// Problem link -> https://leetcode.com/problems/merge-two-binary-trees/submissions// https://leetcode.com/problems/merge-two-binary-trees/submissions//// https://leetcode.com/problems/merge-two-binary-trees/submissions/
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 and root2)
        {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        else // one node doens't exists, link it back to calling node
        {
            return root1 ? root1 : root2;
        }

        // return the first tree, which is now altered.
        return root1;
    }
};
