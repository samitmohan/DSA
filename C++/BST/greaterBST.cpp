// Problem Link -> https://leetcode.com/problems/convert-bst-to-greater-tree/
// inorder traverse of BST will give an ascending sequence of all values.
// Inorder = L N R
// If it gives ascending sequence of all values (1 2 3 4 5), just run a loop til it reaches the last number and keep adding it by the next number (prefix sum) -> (1 3 5 ..)

// By modifying inorder search (doing opposite (R N L)) we can get the descending order of the tree.

// Now just add that value to the root. Before ocming back to current node we'll have visited all values that are greater than it.

/*
---Solution---

sum will store the sum of node-values higher than current node
counter of sum which keeps track of sum of elements greater than OG key.
travel right
add sum to the right most node recursively.
add values which are greater than OG key to the root->val (in place)
travel left

*/

class Solution
{
public:
    int sum = 0;

    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            convertBST(root->right);
            root->val += sum;
            sum = root->val;
            convertBST(root->left);
        }
        return root;
    }
};

// TC -> O(N)
// SC -> O(N)

/*
--- Explanation ---

While processing each node, we need to add the current node's val to the curr_sum ( curr_sum+=node->val ) and also update current node's val to curr_sum ( node->val=curr_sum ).

You can do this in one step also as done above ^
*/
