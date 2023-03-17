// if any of left / right calls give you true -> return true
// if both calls give you false, backtrack and remove that element
// check for both left side and right side
// inorder traversal.
// moment you reach node and arr_node != node, insert into array (data structure)
// 1 2 5 7 -> Path

/*
     1
    / \
    2  3
    /\
   4  5
      /\
      6 7
*/

class Solution
{
public:
    bool getPath(TreeNode *root, vector<int> &arr, int x) // root, arr, value you're looking for
    {
        if (!root)
            return false; // base case
        arr.push_back(root->val);

        if (root->val == x)
        {
            return true; // ans found
        }
        // else go left, go right
        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        {
            // if any of them true -> answer true
            return true;
        }
        // else both left right false, backtrack and remove that element
        arr.pop_back();
        return false
    }

    // given node a and the value you have to find
    vector<int> Solution::solve(TreeNode *A, int B)
    {
        vector<int> arr;
        if (A == nullptr)
            return arr;
    }
    getPath(A, arr, B); // answer (B always exists so no need for check)
    return arr;
}

// TC -> O(N) inorder
// SC -> O(height of tree)

// Similarily root to leaf path

// Problem link -> https://leetcode.com/problems/binary-tree-paths/submissions/

class Solution
{
private:
    vector<string> ans;
    void toLeaf(TreeNode *root, string str)
    {
        // for each node, path from root to that node
        str += to_string(root->val); // convert to string bcs question asked
        // push string of path in the vector only when leaf node found
        if (!root->left && !root->right)
        {
            // leaf node found
            ans.push_back(str);
            return;
        }
        // else for left / right
        if (root->left)
        {
            toLeaf(root->left, str + "->");
        }
        if (root->right)
        {
            toLeaf(root->right, str + "->");
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        toLeaf(root, "");
        return ans;
    }
};