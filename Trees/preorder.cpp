// Problem Link -> https://leetcode.com/problems/binary-tree-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// preorder -> root, left, right

class Solution
{
public:
    void preorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }
};

// Preorder using stack -> O(N) TC, SC

// 1) keep a stack, push root initially
// 2) pop root and print the value
// 3) push root's rightchild and then leftchild (why opposite dir? bcs stack is LIFO, if you enter right first and then left, left will be at the top and it'll be printed first (correct order))
// do the same for all -> *use while loop until stack is empty*
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == nullptr)
        {
            return preorder; // empty
        }
        stack<TreeNode *> st;
        st.push(root); // 1)
        while (!st.empty())
        {
            root = st.top();               // top element of stack -> curr root
            st.pop();                      // 2)
            preorder.push_back(root->val); // preorder vector = ans vector, pb all values in it after pop
            if (root->right != nullptr)    // 3)
            {
                st.push(root->right);
            }
            if (root->left != nullptr)
            {
                st.push(root->left);
            }
        }
        return preorder;
    }
};