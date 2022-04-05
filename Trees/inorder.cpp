// Problem Link -> https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Inorder -> left, root, right

class Solution
{
public:
    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }
};

// Inorder using stack -> O(N) TC, SC 

// 1) keep a stack, push root initially
// 2) take left, keep moving left.
//    Basically keep moving left until you reach null, once null reached look for right (also keep printing whenever you reach null)
//    if right also null, backtrack (iteratively) and check for left
// 3) when stack empty -> program over.

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inorder; // ans
        while (true)
        {
            if (node != nullptr)
            {
                st.push(node); // push element to stack and move left
                node = node->left;
            }
            else 
            {
                // if node is null, pop and print
                // special case if stack empty then exit
                if (st.empty() == true)
                {
                    break;
                }
                // else if it's null, pop and print
                node = st.top();
                st.pop(); // print
                inorder.push_back(node->val); // pb value in answer
                node = node->right; // check for right
            }
        }
        return inorder;
    }
};
