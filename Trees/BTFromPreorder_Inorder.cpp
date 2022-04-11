// Problem Link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Given 2 arrays -> preorder, inorder. Construct and return the binary tree.

// preorder = [3,9,20,15,7] and inorder = [9,3,15,20,7] || inorder -> left, root, right || preorder -> root, left, right
// if inorder and preorder traversals are given then the binary tree you create will always be an unique tree.

/*
inorder --> [40,20,50,10,60,30]
preorder --> [10,20,40,50,30,60]

root left right (preorder)
left root right (inorder)

Unique Binary Tree

          10
        /    \
       20     30
      / \     /
      40 50   60

Observation -> 10 will always be the root of the binary tree (acc to preorder and inorder)
[40,20,50,10,60,30] -> 10 is the node, so 40, 20, 50 will be left part of the subtreee (acc to inorder) and 60, 30 will be the right part of subtree
Figure out the root -> start element.
Segregrate left and right part.
Recursive function to place left on left subtree and right on right subtree.

*/

class Solution
{
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
  }
};
