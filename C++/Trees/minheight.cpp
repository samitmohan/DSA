#include <iostream>
#include <algorithm>
using namespace std;
// Given root of binary tree, return it's minimum depth
// Depth -> number of nodes along the longest path from the root node down to the farthest leaf node

// Problem link -> https://leetcode.com/problems/minimum-depth-of-binary-tree/
// example
//      3
//    /   \
//   9    20
//        / \ 
//       15  7
// input -> root = [3, 9, 20, null, null, 15, 7]
// output -> 2 (3, 9)

// 1) Wrong Approach

// can't do min(root->left, root->right)
//   9
//  /
// 11
// Answer = 2
// min(1, 0) = 1 (wrong answer)
// It will only work for perfect binary tree (if all levels are filled with 2 children)

class Solution
{
public:
    int fun(TreeNode *root)
    {
        if (root == nullptr)
        {
            return INT_MAX; // infinite
        }
        // for leaf node -> height = 1
        // leaf node = height = 1 (left inf, right inf = inf so we have to have another condition)
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return min(fun(root->left), fun(root->right)) + 1;
    }

    int minDepth(TreeNode *root)
    {
        // if empty tree, height = 0
        if (root == nullptr)
        {
            return 0;
        }
        return fun(root); // answer
    }
};
