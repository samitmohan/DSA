#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*
Naive Solution
    preorder -> root left right.
    preorder array, first number = root.
    everything smaller than root, goes to left, everything greater than root, goes to right (do this recursively.)

TC -> O(N * N) (N nodes, for every node you're determining left / right N times) (Skewed Tree)
SC -> O(N)

Optimised Solution
    Using preorder and inorder we can create a unique binary tree (property) which will be BST.
    How to get inorder? Sort the preorder. (NlogN) + O(N) [to create BST from the 2 traversals]
    SC -> O(N) to store in vector.
    Remove logN -> Efficient method O(N)

Idea :
        Node [-1M, 1M]
        /             \
    Left[-1M, node]    [node, 1M]

*/

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
    }
};
