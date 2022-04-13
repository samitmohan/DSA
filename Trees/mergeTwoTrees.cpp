// Problem link -> https://leetcode.com/problems/merge-two-binary-trees/

/*

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge the two trees into a new binary tree.
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.
Input: 
     Tree 1            Tree 2                  
       2                 3                             
      / \               / \
     1   4             6   1                        
    /                   \   \
   5                     2   7                  

Output: Merged tree:
         5
        / \
       7   5
      / \   \
     5   2   7

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
*/

class Solution 
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
    if (root1 == nullptr and root2 == nullptr) return nullptr; // base case
    // if only one of them null 
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    // else = both nodes exists
    // If both nodes exist, add their values then look at the next node.

    // make new tree with overlapped values
    TreeNode *node = new TreeNode(root1->val + root2->val);

    // left side -> mergeTrees(root1.left, root2.left)
    // right side -> mergeTrees(root1.right, root2.right)
    node->left = mergeTrees(root1->left, root2->left);
    node->right = mergeTrees(root1->right, root2->right);

    return node;
    }
};

// TC -> O(N)
// SC -> O(N)

// Optimisation : without using extra memory

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
