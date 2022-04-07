#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

//using inorder traversal code

// solution : https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23&ab_channel=takeUforward

void inorder(TreeNode *root, int x, int level, map<int, map<int, multiset<int>>> &nodes) 
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    // inorder -> left, root, right
    inorder(root->left, x - 1, level + 1, nodes);
    nodes[x][leve].insert(root->val);
    inorder(root->right, x + 1, level + 1, nodes);
}

// vertical traversal (answer)
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // base case
    if (root == nullptr)
    {
        return {};
    }
    nodes<int, nodes<int, multiset<int>>> nodes;
    inorder(root, 0, 0, nodes); // inorder
    // answer
    vector<vector<int>> ans;
    // traverse across the map
    // what is p -> int = p.first, map<int, multiset<int>> = p.second 
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second) // p.second? -> map<int, multiset<int>> (level and multiset)
        {
            // column.push_back (inserting entire mulitset (p.second))
            // 0 -> level 0, level 1. Got multiset for level 0, inserted, same for 1 and 2...
            col.insert(col.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
