// TC -> O(N)
// SC -> O(height of tree)
// Recursively.

// Problem link -> https://leetcode.com/problems/binary-tree-right-side-view/
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

/*
     1
   /   \
  2     3
 / \     \
4  5      7
  /
 6


Answer -> 1 3 7 6
*/

// Use reverse preorder traversal
// preorder -> root, left, right
// reverse preorder -> root, right, left

// Recursive function -> f(node, level)
// f(node->right, level + 1) & f(node->left, level + 1)

// Data structure to store answer (ds) -> if (level == ds.size()) then only push_back answer. (Dry run on paper to check this condition)

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
    	vector<int> ans;
    	recursion(root, 0, ans); // level 0, node -> root initially
    	return ans;
    }

    // main logic
    void recursion(TreeNode* root, int level, vector<int> &ans)
    {
    	if (root == nullptr) return; // base case
	    // add to data structure only when level is same as ds size i.e this is the first time you've come across this level and val
	    // ds = ans
	    if (level == ans.size())
	    {
	    	// add to answer
	    	ans.push_back(root->val);
	    }
    	recursion(root->right, level + 1, ans);
    	recursion(root->left, level + 1, ans);
    }
};