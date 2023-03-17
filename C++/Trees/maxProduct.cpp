// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

// split into ST such that sum1 and sum2 are equal / close to being equal -> for max result.
// find total_sum of tree, sum2 = total_sum - sum1.
// calculate max(sum1 * sum2) via postorder traversal of BT and return it.

class Solution {
public:
  long long ts = 0;
  long long ans = 0;
  long long mod = 1e9 + 7;

  int find(TreeNode *root) {
    if (!root) return 0;
    long long sum1 = find(root->left) + find(root->right) + root->val;
    ans = max(ans, (ts - sum1) * sum1);
    return sum1;
  }
  
  int maxProduct(TreeNode* root) {
    // calc total_sum before calling the function for ans since it'll return 0 (total_sum 0 init) so find total_sum and then do any other calculations.
    ts = find(root);
    find(root); 
    return ans % mod;
  }
};