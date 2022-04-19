// Problem link -> https://leetcode.com/problems/recover-binary-search-tree/submissions/
/*
---Approach---
    Brute force solution -> Inorder traversal (sorted array) compare the sorted array to the tree. (swap if any changes)
*/

// TC-> O(NlogN), SC-> O(N)+O(N) [1 for vector, 1 for recursion space]
class Solution 
{
private:
    vector<int> ans;
    int i = 0;
public:
    // inorder
    void inorder(TreeNode *root) 
    {
        if (root == nullptr) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    // check if array is equal to the tree traversal 
    void check(TreeNode *root) 
    {
        if (root == nullptr) return;
        // check if ans[i] and root->val is same or not, if not, swap them.
        check(root->left);
        if (ans[i] != root->val) 
        {
            swap(ans[i], root->val);
        }
        i++; // next root
        check(root->right);
    }
    
    void recoverTree(TreeNode *root) 
    {
        // tree traversal [1,3,2]
        inorder(root);
        // sort the array [1,2,3]
        sort(ans.begin(), ans.end());
        // compare both
        check(root);    
    }
};

// Optimial -> TC -> O(N), SC -> O(N)
class Solution {
    TreeNode *first, *last, *prev;
public:
    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (prev != nullptr && (root->val < prev->val)) {
            if (first == nullptr) {
                first = prev;
                last = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root) {
        first = last = prev = nullptr;
        inorder(root);
        swap(first->val, last->val);
    }
};