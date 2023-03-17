// Problem Link -> https://leetcode.com/problems/deepest-leaves-sum/
class Solution {
public:
    int max_level = 0;
    int sum = 0;

    void ans(TreeNode *node, int level) {
        if (!node) return;
        if (level > max_level) {
            // new max level found, update and update sum
            max_level = level;
            sum = node->val;
        } else if (level == max_level) {
            // last level reached, increment to sum
            sum += node->val;
        }
        // recursively for all
        ans(node->left, level + 1);
        ans(node->right, level + 1);
    }

    int deepestLeavesSum(TreeNode *root) {
        ans(root, 0);
        return sum;
    }
};

