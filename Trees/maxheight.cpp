#include <iostream>
#include <algorithm>
using namespace std;
// Given root of binary tree, return it's maxiumum depth
// Depth -> number of nodes along the longest path from the root node down to the farthest leaf node

// Problem link -> https://leetcode.com/problems/maximum-depth-of-binary-tree/
// example
//      3
//    /   \
//   9    20
//        / \ 
//       15  7
// input -> root = [3, 9, 20, null, null, 15, 7]
// output -> 3

//   1
//  / \ 
//     2

// input -> root = [1, null. 2]
// output -> 2

// ans -> 1 + max(l, r)

int maxDepth(Node *root)
{
    // if empty tree, height = 0
    if (root == nullptr)
    {
        return 0;
    }
    int lefthalf = maxDepth(root->left);
    int righthalf = maxDepth(root->right);
    return 1 + max(lh, rh);

}

// leetcode solution (same solution just cleaner way to write)
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // if empty tree, height = 0
        if (root == nullptr)
        {
            return 0;
        }
        // else return maximum of left node / right node + 1 (for including the root node)
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};