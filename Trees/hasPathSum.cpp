// Problem Link -> https://leetcode.com/problems/path-sum/submissions/

/*
           5
          /  \
         4    8
        /    / \
       11    13 4
                 \ 
       /\         1
      7  2      
      
targetSum = 22,
5 + 4 + 11 + 2
Answer = true
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if tree empty
        if (root == nullptr) return false; // no answer
        targetSum = targetSum - root->val; // for every node it's different
        // target = 22, example : 22 - 5, 17 - 4, 13 - 11, 2 - 2 = 0 (ans found)
        // if target becomes 0 and it's a leaf node (leftchild = null, rightchild = null) return True
        if (targetSum == 0 and root->left == nullptr and root->right == nullptr) 
        {
            return true;
        }
        // else keep going left or right until you find answer
        return hasPathSum(root->left, targetSum)  or hasPathSum(root->right, targetSum);
    }
};