#include <bits/stdc++.h>
using namespace std;
// Problem Link -> https://practice.geeksforgeeks.org/problems/sum-tree/1#
/*
true : for every ndoe X in the tree other than leaves, val = sum of left ST and right ST ? false otherwise
      3
     /  \
    1    2

Answer : 1

          10
        /    \
      20      30
    /   \
   10    10

Answer : 0  (should be 40 + 30)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)
*/

// check for left and right (if true) check for curr node (root->data)
// left_sum + right_sum = curr_node_sum
// 2 things -> isSum(t/f) and sum(int)
// Similar to isBalanced question
class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *root)
    {
        // base case
        if (root == nullptr)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // don't check for leaves (corner case)
        if (root->left == nullptr && root->right == nullptr)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        // answer from left and answer from right
        // left sum = leftAns.second, true false -> leftAns.first
        // right sum = rightAns.second, true false -> rightAns.first
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        // check if left part is sumTree or not, similarily for right (isLeftSumTree and isRightSumTree)
        bool left = leftAns.first;
        bool right = rightAns.first;

        // check for condition (sum)
        bool condition = root->data == leftAns.second + rightAns.second;

        // answer
        pair<bool, int> ans;
        if (left && right && condition)
        {
            // it is a sum tree.
            ans.first = true;                                           // main answer
            ans.second = root->data + leftAns.second + rightAns.second; // total sum
        }
        else
        {
            ans.first = false;
            // doesn't matter for answer.second is as it's false
        }
        return ans;
    }

    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first; // returns true or false
    }
};
