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

-----------

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5


*/

/*
---Algorithm---
Take index element as root element. (first node) (0)
Find root element's position in inorder
    To check elements in left sub tree and right sub tree wrt root node.
    root->left (beginning to position of index - 1) [inorderStart -> posn - 1]
    root->right (position of index + 1 to end) [posn + 1 -> inorderEnd]
*/

class Solution
{
public:
    int index = 0; // index of preorder
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return createTree(preorder, inorder, 0, inorder.size() - 1);
    }

    // pass map also for optimised
    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        // start = inorderStart, end = inOrderEnd
        if (start > end)
        {
            return nullptr; // corner case / base case
        }
        // root element
        int element = preorder[index++];        // after finding element, index++ for next
        TreeNode *node = new TreeNode(element); // create node of that element
        int position;
        // finding the element in inorder (takes O(N) time, can do better if we use a map here)
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == node->val)
            {
                // found
                position = i;
                break;
            }
        }

        // recursive call for left and right
        node->left = createTree(preorder, inorder, start, position - 1);
        node->right = createTree(preorder, inorder, position + 1, end);
        return node;
    }
};

// Map O(1) instead of finding element iteratively O(N)
/*
    int createMapping(vector<int> &inorder, map<int, int> nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    in buildTree
    // map<int, int> nodeToIndex;
    // createMapping(inorder, nodeToIndex, n);
*/
