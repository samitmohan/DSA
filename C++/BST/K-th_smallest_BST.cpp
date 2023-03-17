#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

        3
       / \
      1   4
       \
        2
k = 1 (1st smallest integer) = 1.
k = 2 (2nd smallest integer) = 2.

       5
      / \
     3   6
    / \
   2   4
  /
1

k = 3 (3rd smallest number) = 3.

---Approach---

 BST Property -> inorder traversal is sorted.
 Idea -> Using this property, traverse in inorder fashion and keep a counter of elements you push in the stack
 Once count == k, (since it's sorted) you found your kth smallest element. Return the node->val for that.
 TC -> O(N), SC -> O(N)

*/

// Iterative Solution.
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        // create stack (for inorder traversal)
        // inorder -> Left, Node, Right
        stack<TreeNode *> st;
        TreeNode *node = root; // temp node to traverse.
        int count = 0;
        while (true)
        {
            if (node != nullptr)
            {
                // till it reaches last node, keep adding elements to stack (sorted order)
                st.push(node);
                node = node->left; // left
            }
            else
            {
                // reached the last element
                // sorted order BST.
                if (st.empty() == true)
                    break;
                node = st.top(); // keep popping elements and incrementing count, once count = k, we found our answer
                st.pop();
                count++;
                // if count == k, we found or kth smallest element.
                if (count == k)
                    return node->val;
                node = node->right; // right
            }
        }
        return -1; // if not found.
    }
};

// Recursive Solution. (Self Explanatory)

class Solution
{
public:
    void inorder(TreeNode *root, int &k, int &counter, int &ans)
    {
        if (root == nullptr)
            return;
        inorder(root->left, k, counter, ans);
        counter++;
        if (counter == k)
        {
            ans = root->val;
        }
        inorder(root->right, k, counter, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1; // initially.
        int counter = 0;
        inorder(root, k, counter, ans);
        return ans;
    }
};
