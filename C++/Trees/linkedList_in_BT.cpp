// Problem Link -> https://leetcode.com/problems/linked-list-in-binary-tree/

/*
Given a binary tree root and a linked list with head as the first node.

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

             1
           /   \
          4      4
          \      /
           2    2
           /   / \
           1   6  8
                / \
                1  3

head = [4,2,8] answer = true
*/

// search in binary tree

void search(TreeNode *root, int target, vector<TreeNode *> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    search(root->left, target, ans);
    if (root->val == target)
    {
        ans.push_back(root);
    }
    search(root->right, target, ans);
}

// logic

bool solve(TreeNode *root, ListNode *head)
{
    // safety checks
    if (head == nullptr)
    {
        return true;
    }
    if (root == nullptr)
    {
        return false;
    }
    // answer
    if (root->val == head->val)
    {
        return (solve(root->left, head->next) || solve(root->right, head->next)); // check for next (recursive)
    }
    // else
    return false;
}

class Solution
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        vector<TreeNode *> ans;
        search(root, head->val, ans);
        for (auto x : ans)
        {
            if (solve(x, head))
            {
                return true;
            }
        }
        return false; // otherwise
    }
};