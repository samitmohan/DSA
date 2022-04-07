// Problem link -> https://leetcode.com/problems/symmetric-tree/submissions/
// Question : Impose left side on right side and if they're equal, it's symmetric.

// mirror, left looks at right, right looks at left.
// root->left and root->right
// preorder traversal -> root left right
// opp -> root right left
/* 

logic : for left sub tree -> run preorder traversal (root left right)
        for right sub tree -> run reverse preorder  (root right left)
        Do this simultaneously and compare, if equal(all of them), tree is symmetric.
*/

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        // if tree null return false OR return the answer 
        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }
    // writing isSymmetricHelp
    bool isSymmetricHelp(TreeNode* left, TreeNode* right)
    {
        // if either left / right are null, return t/f by checking left == right
        // if one guy is null, other should also by null for symmetric.
        if (left == nullptr || right == nullptr)
        {
            return left == right; // true / false
        }
        // check node's value, if not equal not symmetric
        if (left->val != right->val) return false; // not symm
        
        // preorder and reverse preorder simultaneously.
        // going left and right + left and right simultaneously
        // if both TRUE then only true.
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};

// TC -> O(N)
// SC -> O(N) skew 